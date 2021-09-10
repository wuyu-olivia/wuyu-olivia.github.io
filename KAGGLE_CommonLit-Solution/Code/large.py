#学习率调整参考https://www.kaggle.com/andretugan/pre-trained-roberta-solution-in-pytorch
import os
import math
import random
import time
import sys
import numpy as np
import pandas as pd

import torch
import torch.nn as nn
from torch.utils.data import Dataset
from torch.utils.data import DataLoader

from torch.cuda.amp import autocast, GradScaler
from transformers import AdamW
from transformers import AutoTokenizer
from transformers import AutoModel
from transformers import AutoConfig
from transformers import get_cosine_schedule_with_warmup
from transformers import RobertaTokenizer, RobertaModel
from sklearn.model_selection import KFold

os.environ["TOKENIZERS_PARALLELISM"] = "false"
import warnings
warnings.simplefilter('ignore')
import gc
gc.enable()

NUM_FOLDS = 10
NUM_EPOCHS = 3
BATCH_SIZE = sys.argv[1]
MAX_LEN = 256
SEED = 100
lr_type = sys.argv[2] # s, m, l
if lr_type == 's':
    LR = 1e-5
elif lr_type == 'm':
    LR = 2e-5
else:
    LR = 3e-5
EVAL_SCHEDULE = [(0.50, 16), (0.49, 12), (0.48, 12), (0.47, 6), (-1., 6)]
NAME = sys.argv[3] #deberta, roberta, electra
DEVICE = "cuda" if torch.cuda.is_available() else "cpu"
DATA_PATH = '/home/nankai01/deep_learning/CommonLit/train.csv'
WarmUp = sys.argv[4]
HEAD = sys.argv[5] #att_la, att_l1, att_l2, att_l4, att_l2_1, att_l4_1, cnn_la, cnn_l1, cnn_l2, cnn_l4, cnn_l2_1, cnn_l4_1
          #dense_la, dense_l1, dense_l2, dense_l4, dense_l2_1, dense_l4_1, wp_l2, wp_l4, wp_l9
if NAME == 'deberta':
    ROBERTA_PATH = "microsoft/deberta-large"
    TOKENIZER_PATH = "microsoft/deberta-large"
elif NAME == 'roberta':
    ROBERTA_PATH = "roberta-large"
    TOKENIZER_PATH = "roberta-large"
else:
    ROBERTA_PATH = "google/electra-large-discriminator"
    TOKENIZER_PATH = "google/electra-large-discriminator"

def set_random_seed(random_seed):
    random.seed(random_seed)
    np.random.seed(random_seed)
    os.environ["PYTHONHASHSEED"] = str(random_seed)
    torch.manual_seed(random_seed)
    torch.cuda.manual_seed(random_seed)
    torch.cuda.manual_seed_all(random_seed)
    torch.backends.cudnn.deterministic = True

train_df = pd.read_csv(DATA_PATH)
train_df.drop(train_df[(train_df.target == 0) & (train_df.standard_error == 0)].index, inplace=True)
train_df.reset_index(drop=True, inplace=True)
tokenizer = AutoTokenizer.from_pretrained(TOKENIZER_PATH)

class LitDataset(Dataset):
    def __init__(self, df, inference_only=False):
        super().__init__()

        self.df = df        
        self.inference_only = inference_only
        self.text = df.excerpt.tolist()

        if not self.inference_only:
            self.target = torch.tensor(df.target.values, dtype=torch.float32)        
    
        self.encoded = tokenizer.batch_encode_plus(
            self.text,
            padding = 'max_length',            
            max_length = MAX_LEN,
            truncation = True,
            return_attention_mask=True
        )        
 

    def __len__(self):
        return len(self.df)

    
    def __getitem__(self, index):        
        input_ids = torch.tensor(self.encoded['input_ids'][index])
        attention_mask = torch.tensor(self.encoded['attention_mask'][index])
        
        if self.inference_only:
            return (input_ids, attention_mask)            
        else:
            target = self.target[index]
            return (input_ids, attention_mask, target)

### AttentionModel

class AttentionModel_la(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.attention = nn.Sequential(            
            nn.Linear(config.hidden_size, 512),            
            nn.Tanh(),                       
            nn.Linear(512, 1),
            nn.Softmax(dim=1)
        )        

        self.regressor = nn.Linear(config.hidden_size, 1)                        

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)  
        hs = roberta_output['hidden_states']      
        last_layer_hidden_states = torch.mean(torch.stack(hs), 0)
        weights = self.attention(last_layer_hidden_states)
        context_vector = torch.sum(weights * last_layer_hidden_states, dim=1)      
        return self.regressor(context_vector)

class AttentionModel_l1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.attention = nn.Sequential(            
            nn.Linear(config.hidden_size, 512),            
            nn.Tanh(),                       
            nn.Linear(512, 1),
            nn.Softmax(dim=1)
        )        

        self.regressor = nn.Linear(config.hidden_size, 1)                        

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)  
        hs = roberta_output['hidden_states'][-1]      
        last_layer_hidden_states = hs#torch.mean(torch.stack(hs), 0)
        weights = self.attention(last_layer_hidden_states)
        context_vector = torch.sum(weights * last_layer_hidden_states, dim=1)      
        return self.regressor(context_vector)

class AttentionModel_l2(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.attention = nn.Sequential(            
            nn.Linear(config.hidden_size, 512),            
            nn.Tanh(),                       
            nn.Linear(512, 1),
            nn.Softmax(dim=1)
        )        

        self.regressor = nn.Linear(config.hidden_size, 1)                        

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)  
        hs = roberta_output['hidden_states']      
        last_layer_hidden_states = torch.mean(torch.stack([hs[-1], hs[-2]]), 0)
        weights = self.attention(last_layer_hidden_states)
        context_vector = torch.sum(weights * last_layer_hidden_states, dim=1)      
        return self.regressor(context_vector)

class AttentionModel_l4(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.attention = nn.Sequential(            
            nn.Linear(config.hidden_size, 512),            
            nn.Tanh(),                       
            nn.Linear(512, 1),
            nn.Softmax(dim=1)
        )        

        self.regressor = nn.Linear(config.hidden_size, 1)                        

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)  
        hs = roberta_output['hidden_states']      
        last_layer_hidden_states = torch.mean(torch.stack([hs[-1], hs[-2], hs[-3], hs[-4]]), 0)
        weights = self.attention(last_layer_hidden_states)
        context_vector = torch.sum(weights * last_layer_hidden_states, dim=1)      
        return self.regressor(context_vector)

class AttentionModel_l2_1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.attention = nn.Sequential(            
            nn.Linear(config.hidden_size, 512),            
            nn.Tanh(),                       
            nn.Linear(512, 1),
            nn.Softmax(dim=1)
        )        

        self.regressor = nn.Linear(config.hidden_size, 1)                        

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)  
        hs = roberta_output['hidden_states']      
        last_layer_hidden_states = torch.mean(torch.stack([hs[-1], hs[-2], hs[-1]]), 0)
        weights = self.attention(last_layer_hidden_states)
        context_vector = torch.sum(weights * last_layer_hidden_states, dim=1)      
        return self.regressor(context_vector)

class AttentionModel_l4_1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.attention = nn.Sequential(            
            nn.Linear(config.hidden_size, 512),            
            nn.Tanh(),                       
            nn.Linear(512, 1),
            nn.Softmax(dim=1)
        )        

        self.regressor = nn.Linear(config.hidden_size, 1)                        

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)  
        hs = roberta_output['hidden_states']      
        last_layer_hidden_states = torch.mean(torch.stack([hs[-1], hs[-2], hs[-3], hs[-4], hs[-1]]), 0)
        weights = self.attention(last_layer_hidden_states)
        context_vector = torch.sum(weights * last_layer_hidden_states, dim=1)      
        return self.regressor(context_vector)

### CNNModel
class CNNModel_la(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                      
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.conv1 = nn.Conv1d(config.hidden_size, 512, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        self.conv2 = nn.Conv1d(512, 1, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        

    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states
        #x = hs[-2]
        x = torch.stack(hs)
        x = torch.mean(x, 0)
        conv1_logits = self.conv1(x.transpose(1, 2))
        conv2_logits = self.conv2(conv1_logits)
        logits = conv2_logits.transpose(1, 2)
        x = torch.mean(logits, 1)
        return x

class CNNModel_l1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                      
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.conv1 = nn.Conv1d(config.hidden_size, 512, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        self.conv2 = nn.Conv1d(512, 1, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        

    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states
        x = hs[-1]
        #x = torch.stack(hs)
        #x = torch.mean(x, 0)
        conv1_logits = self.conv1(x.transpose(1, 2))
        conv2_logits = self.conv2(conv1_logits)
        logits = conv2_logits.transpose(1, 2)
        x = torch.mean(logits, 1)
        return x

class CNNModel_l2(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                      
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.conv1 = nn.Conv1d(config.hidden_size, 512, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        self.conv2 = nn.Conv1d(512, 1, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        

    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states
        #x = hs[-1]
        x = torch.stack([hs[-1], hs[-2]])
        x = torch.mean(x, 0)
        conv1_logits = self.conv1(x.transpose(1, 2))
        conv2_logits = self.conv2(conv1_logits)
        logits = conv2_logits.transpose(1, 2)
        x = torch.mean(logits, 1)
        return x

class CNNModel_l4(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                      
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.conv1 = nn.Conv1d(config.hidden_size, 512, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        self.conv2 = nn.Conv1d(512, 1, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        

    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states
        #x = hs[-1]
        x = torch.stack([hs[-1], hs[-2], hs[-3], hs[-4]])
        x = torch.mean(x, 0)
        conv1_logits = self.conv1(x.transpose(1, 2))
        conv2_logits = self.conv2(conv1_logits)
        logits = conv2_logits.transpose(1, 2)
        x = torch.mean(logits, 1)
        return x

class CNNModel_l2_1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                      
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.conv1 = nn.Conv1d(config.hidden_size, 512, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        self.conv2 = nn.Conv1d(512, 1, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        

    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states
        #x = hs[-1]
        x = torch.stack([hs[-1], hs[-2], hs[-1]])
        x = torch.mean(x, 0)
        conv1_logits = self.conv1(x.transpose(1, 2))
        conv2_logits = self.conv2(conv1_logits)
        logits = conv2_logits.transpose(1, 2)
        x = torch.mean(logits, 1)
        return x

class CNNModel_l4_1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                      
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
            
        self.conv1 = nn.Conv1d(config.hidden_size, 512, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        self.conv2 = nn.Conv1d(512, 1, 3, stride=1, padding=1, dilation=1, groups=1, bias=True, padding_mode='zeros')
        

    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states
        #x = hs[-1]
        x = torch.stack([hs[-1], hs[-2], hs[-3], hs[-4], hs[-1]])
        x = torch.mean(x, 0)
        conv1_logits = self.conv1(x.transpose(1, 2))
        conv2_logits = self.conv2(conv1_logits)
        logits = conv2_logits.transpose(1, 2)
        x = torch.mean(logits, 1)
        return x

### denseModel
class DenseModel_la(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, "hidden_dropout_prob": 0.0, 'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)     
        nn.init.normal_(self.fc.weight, std=0.02)
        nn.init.normal_(self.fc.bias, 0)

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)   
        hs = roberta_output['hidden_states']       

        x = torch.stack(hs)
        x = torch.mean(x, (0, 2))
        x = self.fc(x)
        return x

class DenseModel_l1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, "hidden_dropout_prob": 0.0, 'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)     
        nn.init.normal_(self.fc.weight, std=0.02)
        nn.init.normal_(self.fc.bias, 0)

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)   
        hs = roberta_output['hidden_states']       

        #x = torch.stack(hs)
        x = torch.mean(hs[-1], 1)
        x = self.fc(x)
        return x

class DenseModel_l2(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, "hidden_dropout_prob": 0.0, 'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)     
        nn.init.normal_(self.fc.weight, std=0.02)
        nn.init.normal_(self.fc.bias, 0)

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)   
        hs = roberta_output['hidden_states']       

        x = torch.stack([hs[-1], hs[-2]])
        x = torch.mean(x, (0, 2))
        x = self.fc(x)
        return x

class DenseModel_l4(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, "hidden_dropout_prob": 0.0, 'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)     
        nn.init.normal_(self.fc.weight, std=0.02)
        nn.init.normal_(self.fc.bias, 0)

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)   
        hs = roberta_output['hidden_states']       

        x = torch.stack([hs[-1], hs[-2], hs[-3], hs[-4]])
        x = torch.mean(x, (0, 2))
        x = self.fc(x)
        return x

class DenseModel_l2_1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, "hidden_dropout_prob": 0.0, 'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)     
        nn.init.normal_(self.fc.weight, std=0.02)
        nn.init.normal_(self.fc.bias, 0)

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)   
        hs = roberta_output['hidden_states']       

        x = torch.stack([hs[-1], hs[-2], hs[-1]])
        x = torch.mean(x, (0, 2))
        x = self.fc(x)
        return x


class DenseModel_l4_1(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, "hidden_dropout_prob": 0.0, 'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)     
        nn.init.normal_(self.fc.weight, std=0.02)
        nn.init.normal_(self.fc.bias, 0)

    def forward(self, input_ids, attention_mask):
        roberta_output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)   
        hs = roberta_output['hidden_states']       

        x = torch.stack([hs[-1], hs[-2], hs[-3], hs[-4], hs[-1]])
        x = torch.mean(x, (0, 2))
        x = self.fc(x)
        return x

### WeightPoolModel
class WeightedLayerPooling(nn.Module):
    def __init__(self, num_hidden_layers, layer_start: int = 4, layer_weights = None):
        super(WeightedLayerPooling, self).__init__()
        self.layer_start = layer_start
        self.num_hidden_layers = num_hidden_layers
        self.layer_weights = layer_weights if layer_weights is not None \
            else nn.Parameter(
                torch.tensor([1] * (num_hidden_layers+1 - layer_start), dtype=torch.float)
            )

    def forward(self, all_hidden_states):
        all_layer_embedding = all_hidden_states[self.layer_start:, :, :, :]
        weight_factor = self.layer_weights.unsqueeze(-1).unsqueeze(-1).unsqueeze(-1).expand(all_layer_embedding.size())
        weighted_average = (weight_factor*all_layer_embedding).sum(dim=0) / self.layer_weights.sum()
        return weighted_average

class WeightPoolModel_l2(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)
        self.pool = WeightedLayerPooling(
                        config.num_hidden_layers, 
                        layer_start=config.num_hidden_layers-2, layer_weights=None
                    )
    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states   

        x = torch.stack(hs)
        x = self.pool(x)
        x = torch.mean(x, 1)
        x = self.fc(x)
        return x

class WeightPoolModel_l4(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)
        self.pool = WeightedLayerPooling(
                        config.num_hidden_layers, 
                        layer_start=config.num_hidden_layers-4, layer_weights=None
                    )
    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states   

        x = torch.stack(hs)
        x = self.pool(x)
        x = torch.mean(x, 1)
        x = self.fc(x)
        return x

class WeightPoolModel_l9(nn.Module):
    def __init__(self):
        super().__init__()

        config = AutoConfig.from_pretrained(ROBERTA_PATH)
        config.update({"output_hidden_states":True, 
                "hidden_dropout_prob": 0.0,
                'return_dict':True})                       
        
        self.roberta = AutoModel.from_pretrained(ROBERTA_PATH, config=config)  
        self.fc = nn.Linear(config.hidden_size, 1)
        self.pool = WeightedLayerPooling(
                        config.num_hidden_layers, 
                        layer_start=config.num_hidden_layers-9, layer_weights=None
                    )
    def forward(self, input_ids, attention_mask):
        output = self.roberta(input_ids=input_ids, attention_mask=attention_mask)        
        hs = output.hidden_states   

        x = torch.stack(hs)
        x = self.pool(x)
        x = torch.mean(x, 1)
        x = self.fc(x)
        return x

def eval_mse(model, data_loader):
    model.eval()            
    mse_sum = 0

    with torch.no_grad():
        for batch_num, (input_ids, attention_mask, target) in enumerate(data_loader):
            input_ids = input_ids.to(DEVICE)
            attention_mask = attention_mask.to(DEVICE)                        
            target = target.to(DEVICE)           
            pred = model(input_ids, attention_mask)                       
            mse_sum += nn.MSELoss(reduction="sum")(pred.flatten(), target).item()

    return mse_sum / len(data_loader.dataset)

def predict(model, data_loader):
    model.eval()
    result = np.zeros(len(data_loader.dataset))    
    index = 0
    with torch.no_grad():
        for batch_num, (input_ids, attention_mask) in enumerate(data_loader):
            input_ids = input_ids.to(DEVICE)
            attention_mask = attention_mask.to(DEVICE)  
            pred = model(input_ids, attention_mask)                        
            result[index : index + pred.shape[0]] = pred.flatten().to("cpu")
            index += pred.shape[0]
    return result

def train(model, model_path, train_loader, val_loader, optimizer, scheduler=None, num_epochs=NUM_EPOCHS):    
    best_val_rmse = None
    best_epoch = 0
    step = 0
    last_eval_step = 0
    eval_period = EVAL_SCHEDULE[0][1]    
    scaler = GradScaler()

    start = time.time()

    for epoch in range(num_epochs):                           
        val_rmse = None         

        for batch_num, (input_ids, attention_mask, target) in enumerate(train_loader):
            input_ids = input_ids.to(DEVICE)
            attention_mask = attention_mask.to(DEVICE)            
            target = target.to(DEVICE)                        
            with autocast():
                optimizer.zero_grad()
                model.train()
                pred = model(input_ids, attention_mask)                                      
                mse = nn.MSELoss(reduction="mean")(pred.flatten(), target)
                scaler.scale(mse).backward()
                scaler.step(optimizer)
                scaler.update()
                if scheduler:
                    scheduler.step()
            
            if step >= last_eval_step + eval_period:
                elapsed_seconds = time.time() - start
                num_steps = step - last_eval_step
                print(f"\n{num_steps} steps took {elapsed_seconds:0.3} seconds")
                last_eval_step = step
                val_rmse = math.sqrt(eval_mse(model, val_loader))                            
                print(f"Epoch: {epoch} batch_num: {batch_num}", f"val_rmse: {val_rmse:0.4}")

                for rmse, period in EVAL_SCHEDULE:
                    if val_rmse >= rmse:
                        eval_period = period
                        break                               
                
                if not best_val_rmse or val_rmse < best_val_rmse:                    
                    best_val_rmse = val_rmse
                    best_epoch = epoch
                    torch.save(model.state_dict(), model_path)
                #    print(f"New best_val_rmse: {best_val_rmse:0.4}")
                #else:       
                #    print(f"Still best_val_rmse: {best_val_rmse:0.4}",
                #          f"(from epoch {best_epoch})")                                    
                    
                start = time.time()
                                            
            step += 1
                        
    
    return best_val_rmse

def create_optimizer(model):
    named_parameters = list(model.named_parameters())    
    
    roberta_parameters = named_parameters[:389]    
    attention_parameters = named_parameters[391:395]
    regressor_parameters = named_parameters[395:]
        
    attention_group = [params for (name, params) in attention_parameters]
    regressor_group = [params for (name, params) in regressor_parameters]

    parameters = []
    parameters.append({"params": attention_group})
    parameters.append({"params": regressor_group})

    for layer_num, (name, params) in enumerate(roberta_parameters):
        weight_decay = 0.0 if "bias" in name else 0.01

        lr = LR

        if layer_num >= 129:        
            lr = LR+1e-5

        if layer_num >= 250:
            lr = LR+2e-5

        parameters.append({"params": params,
                           "weight_decay": weight_decay,
                           "lr": lr})

    return AdamW(parameters)

def train_folds(head='', model_name=None):
    torch.cuda.empty_cache()
    gc.collect()
    
    list_val_rmse = []

    kfold = KFold(n_splits=NUM_FOLDS, random_state=SEED, shuffle=True)

    for fold, (train_indices, val_indices) in enumerate(kfold.split(train_df)):    
        print(f"\nFold {fold + 1}/{NUM_FOLDS}")
        model_path = f"{NAME}_large_bs{BATCH_SIZE}_lr{lr_type}_warm{WarmUp}_{head}_f{fold + 1}.pth"
        set_random_seed(SEED + fold)
        
        train_dataset = LitDataset(train_df.loc[train_indices])    
        val_dataset = LitDataset(train_df.loc[val_indices])    
            
        train_loader = DataLoader(train_dataset, batch_size=BATCH_SIZE, drop_last=True, shuffle=True, num_workers=8)    
        val_loader = DataLoader(val_dataset, batch_size=BATCH_SIZE, drop_last=False, shuffle=False, num_workers=8)    
        model = model_name().to(DEVICE)
        optimizer = create_optimizer(model)                        
        scheduler = get_cosine_schedule_with_warmup(
            optimizer,
            num_training_steps=NUM_EPOCHS * len(train_loader),
            num_warmup_steps=WarmUp)    
        
        list_val_rmse.append(train(model, model_path, train_loader, val_loader, optimizer, scheduler=scheduler))

        del model
        gc.collect()
        
        print("\nPerformance estimates:")
        print(list_val_rmse)
        print("Mean:", np.array(list_val_rmse).mean())
    return list_val_rmse
#att_la, att_l1, att_l2, att_l4, att_l2_1, att_l4_1, cnn_la, cnn_l1, cnn_l2, cnn_l4, cnn_l2_1, cnn_l4_1
          #dense_la, dense_l1, dense_l2, dense_l4, dense_l2_1, dense_l4_1, wp_l2, wp_l4, wp_l9
if HEAD == 'att_la':
    cv = train_folds(head=HEAD, model_name=AttentionModel_la)
elif HEAD == 'att_l1':
    cv = train_folds(head=HEAD, model_name=AttentionModel_l1)
elif HEAD == 'att_l2_1':
    cv = train_folds(head=HEAD, model_name=AttentionModel_l2_1)
elif HEAD == 'cnn_la':
    cv = train_folds(head=HEAD, model_name=CNNModel_la)
elif HEAD == 'cnn_l1':
    cv = train_folds(head=HEAD, model_name=CNNModel_l1)
elif HEAD == 'cnn_l2_1':
    cv = train_folds(head=HEAD, model_name=CNNModel_l2_1)
elif HEAD == 'cnn_l4_1':
    cv = train_folds(head=HEAD, model_name=CNNModel_l4_1)
elif HEAD == 'dense_la':
    cv = train_folds(head=HEAD, model_name=DenseModel_la)
elif HEAD == 'dense_l1':
    cv = train_folds(head=HEAD, model_name=DenseModel_l1)
elif HEAD == 'dense_l2_1':
    cv = train_folds(head=HEAD, model_name=DenseModel_l2_1)
elif HEAD == 'dense_l4_1':
    cv = train_folds(head=HEAD, model_name=DenseModel_l4_1)
cv.append(np.mean(cv))
pd.Series(cv).to_csv(f'cv_{NAME}_large_bs{BATCH_SIZE}_lr{lr_type}_warm{WarmUp}_{HEAD}.csv', index=False)