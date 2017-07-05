clear, clc;
X = imread('tygrys.bmp');
[X1 map] = rgb2ind(X, 256);
imshow(X1, map);
[X2 newmap] = imapprox(X1, map, 16);
figure, imshow(X2, newmap);