clear all;
Ori_Im=imread('');
if size(Ori_Im,3)==3
    Ori_Im=rgb2gray(Ori_Im);
end
J=histeq(Ori_Im);
%H=adapthisteq(Ori_Im);
figure;
subplot(221);imshow(Ori_Im);title('original image');
subplot(222);imshow(J);title('Histogram equalization image');

subplot(223);imhist(Ori_Im);title('original image histogram');
subplot(224);imhist(J);title('HQ image histogram');