function HEImage_Show (Image)
%{
    Function:
        HEImage_Show: to shouw the histogram of image.
    Parameters:
       Image:  The input image;          
    Return value:        
        NULL
%}
% figure;
x = 0:1:size(Image,2)-1;
bar(x,Image,0.1);
for i=0:length(Image)-1

    text(i,Image(i+1),num2str(Image(i+1)),'VerticalAlignment','bottom','HorizontalAlignment','center','FontSize',9,'color','r','FontWeight','bold');

end