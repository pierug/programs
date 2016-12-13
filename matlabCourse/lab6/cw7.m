clear, clc;
X = imread('tygrys.bmp');
[X1 map1] = rgb2ind(X, 8);
imshow(X1, map1);
[X2, map2] = rgb2ind(X, 8, 'nodither');
figure, imshow(X2, map2);