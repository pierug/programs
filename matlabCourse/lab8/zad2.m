I = imread('jablko.bmp');
J = rgb2gray(I);
subplot(2,2,1);
imshow(J);
subplot(2,2,2);
imhist(J);
B = J > 245;
subplot(2,2,3);
imshow(B);
