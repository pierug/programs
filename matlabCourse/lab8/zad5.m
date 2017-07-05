I = imread('okret.jpg');
J = rgb2gray(I);
subplot(2,2,1);
imshow(J);
subplot(2,2,2);
imhist(J);

B = (J > 120)&(J < 180);
subplot(2,2,3);
imshow(B);

