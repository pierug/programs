I = imread('jezioro.bmp');
M = rgb2gray(I);
subplot(3,3,1);
imshow(M,[0 256])

subplot(3,3,2);
imshow(M,[0 224])

subplot(3,3,3);
imshow(M,[0 192])

subplot(3,3,4);
imshow(M,[0 160])

subplot(3,3,5);
imshow(M,[0 128])

subplot(3,3,6);
imshow(M,[0 64])

subplot(3,3,7);
imshow(M,[0 32])

subplot(3,3,8);
imshow(M,[0 16])

subplot(3,3,9);
imshow(M,[0 8])

