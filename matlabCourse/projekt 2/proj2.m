input = imread('obr1.png');
grayImage=rgb2gray(input);

noiseImage = imnoise(grayImage,'salt & pepper',0.1);

%figure,
%title('Zaszumiony obraz');
%imshow(noiseImage);

%figure,
%subplot(1,2,1)
%Y=medfilt2(noiseImage,[4 4]);
%imshow(Y);
%title('Filtracja medianowa [4 4]');
%subplot(1,2,2)
%imshow(grayImage);
%title('Oryginal');

%figure,
%subplot(1,2,1)
%Z=imgaussfilt(noiseImage,3);
%imshow(Z);
%title('Filtracja Gaussa');
%subplot(1,2,2)
%imshow(grayImage);
%title('Oryginal');


%figure,
%subplot(1,2,1)
%Zwiener=wiener2(noiseImage,[8 8]);
%imshow(wiener);
%title('Filtracja Paróweczkowa');
%subplot(1,2,2)
%imshow(grayImage);
%title('Oryginal');

figure,
subplot(1,2,1)
filter=filter2(fspecial('average',10),noiseImage)/255;
imshow(filter);
title('Filtracja Uœredniaj¹ca');
subplot(1,2,2)
imshow(grayImage);
title('Oryginal');
