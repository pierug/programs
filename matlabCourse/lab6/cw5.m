RGB1 = imread('krajobraz.bmp');
imshow(RGB1);
RGB2 = imread('kwiaty.bmp');
[X1, map] = rgb2ind(RGB1, 100);
figure, imshow(X1, map);
X2 = rgb2ind(RGB2, map);
figure, imshow(X2, map);