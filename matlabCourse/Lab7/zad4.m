I = imread('rtg_zebow.bmp ');
J = histeq(I);

subplot(2,2,1);
imshow(J);
subplot(2,2,2);
imhist(J);
subplot(2,2,4);
imhist(I);
subplot(2,2,3);
imshow(I);

imwrite(J,'rtg_zembow_hist.bmp');