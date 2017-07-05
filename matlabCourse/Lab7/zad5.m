I = imread('czaple.bmp ');
J = histeq(I);
K = imadjust(I, [0.6 1], [0 0.4]);

subplot(3,2,1);
imshow(I);
subplot(3,2,2);
imhist(I);
subplot(3,2,4);
imhist(J);
subplot(3,2,3);
imshow(J);
subplot(3,2,5);
imshow(K);
subplot(3,2,6);
imhist(K);