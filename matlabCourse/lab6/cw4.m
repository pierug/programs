I = imread('krajobraz.bmp');
tolerancja = 0.2;
[X1, map1] = rgb2ind(I, tolerancja);
[X2, map2] = rgb2ind(I, 32);
imshow(I);
figure, imshow(X1, map1);
figure, imshow(X2, map2);

[X3, map3] = rgb2ind(I, 128);
figure, imshow(X3, map3);