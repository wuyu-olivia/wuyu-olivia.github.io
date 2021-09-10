using System.Collections;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace WindowsFormsApp1
{
    public class Grammar
    {

        private ArrayList production = new ArrayList();

        //private Arithmetic arithmetic = null;

        public ArrayList Production
        {
            get
            {
                return this.production;
            }
        }

       

        public int Amount
        {
            get
            {
                return this.production.Count;
            }
        }

        public string this[int index]
        {
            get
            {
                return (string)this.production[index];
            }
        }

        public void Add(string line)   //一行一行的读,分离|两边的式子
        {
            if (line != "")
            {
                int count = 0;

                int i = 0;

                int j = 0;

                for (i = 0; i < line.Length; i++)
                {
                    if (line[i] == '|')
                    {
                        count++;//是否存在空格符，若存在，接下来便开始分离
                    }
                }
                if (count != 0)
                {
                    string temp = null;

                    int index = 3;

                    int start = 3;

                    for (i = 0; i <= count; i++)
                    {
                        string str = line.Substring(0, 3);

                        start = index;

                        for (j = index; j < line.Length; j++)
                        {
                            if (line[j] == '|')
                            {
                                index = j + 1;

                                break;
                            }

                        }
                        temp = line.Substring(start, j - start);
                        str += temp;
                        production.Add(str);
                    }
                }
                else
                {
                    production.Add(line);
                }
            }
        }

        

    }
}
