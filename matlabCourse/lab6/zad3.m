Kr = imread('krajobraz.bmp');

[X1, map] = rgb2ind(Kr, hsv);
figure, imshow(X1, map);
clear X1;
clear map;

[X1, map] = rgb2ind(Kr, gray);
figure, imshow(X1, map);
clear X1;
clear map;

[X1, map] = rgb2ind(Kr, hot);
figure, imshow(X1, map);
clear X1;
clear map;

[X1, map] = rgb2ind(Kr, cool);
figure, imshow(X1, map);
clear X1;
clear map;

[X1, map] = rgb2ind(Kr, copper);
figure, imshow(X1, map);
clear X1;
clear map;

[X1, map] = rgb2ind(Kr, pink);
figure, imshow(X1, map);