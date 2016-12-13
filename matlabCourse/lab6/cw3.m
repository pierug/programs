I = imread('krajobraz.bmp');
tolerancja = 0.2;
[X1, map1] = rgb2ind(I, tolerancja);
[X2, map2] = rgb2ind(I, 128);
imshow(I);
figure, imshow(X1, map1);
figure, imshow(X2, map2);