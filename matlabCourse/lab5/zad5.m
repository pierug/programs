I = imread('grace.bmp');
M = rgb2gray(I);

figure(1)
subplot(1,2,1);
imshow(I)
subplot(1,2,2);
imshow(M)


I = fliplr(I);
figure(2)
subplot(1,2,1);
imshow(I)
M = flipud(M)
subplot(1,2,2);
imshow(M)