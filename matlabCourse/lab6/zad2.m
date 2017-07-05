Kr = imread('krajobraz.bmp');
Kw = imread('kwiaty.bmp');
Ty = imread('tygrys.bmp');

[X1, map] = rgb2ind(Kw, 256);
figure, imshow(X1, map);
X2 = rgb2ind(Kr, map);
figure, imshow(X2, map);
X3 = rgb2ind(Ty, map);
figure, imshow(X3, map);