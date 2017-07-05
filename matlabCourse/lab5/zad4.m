I = imread('grace.bmp');
kat = input('podaj kat= ');
M = imrotate(I,kat);
subplot(1,2,1);
imshow(I)
subplot(1,2,2);
imshow(M)