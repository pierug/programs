I = imread('tygrys.jpeg');
J = rgb2gray(I);
subplot(2,2,1);
imshow(J);
subplot(2,2,2);
imhist(J);
B = (J > 100)&(J < 240);
subplot(2,2,3);
imshow(B);
B = bwmorph(B,'majority');
subplot(2,2,4);
imshow(B);