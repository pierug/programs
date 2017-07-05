Kr = imread('krajobraz.bmp');

z=256;
while z~=1
    clear X1;
    clear map;
    [X1, map] = rgb2ind(Kr, z);
    figure, imshow(X1, map);
    z=z/2;
end
clear X1;
clear map;
[X1, map] = rgb2ind(Kr, 1);
figure, imshow(X1, map);