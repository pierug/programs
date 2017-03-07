input = imread('normal-ct-brain.jpg');
%input = imread('sec.jpg');
grayImage=rgb2gray(input);

figure,
imshow(grayImage);
title('Obraz w skali szarosci');
figure,
imhist(grayImage);
title('Histogram badanego obrazu');
histGrayImage=imhist(grayImage);
meanHistGrayImage = mean(histGrayImage)
minHistGrayImage = min(histGrayImage)
maxHistGrayImage = max(histGrayImage)



figure,
title('Obraz po wyrównaniu histogramu');
grayImageCorrect = histeq(grayImage);
imshow(grayImageCorrect);

figure,
title('Wyrównany histogram badanego obrazu');
imhist(grayImageCorrect);

for i=1:4 
    subplot(2,2,i);
    Y=medfilt2(grayImage,[i*5 i*5]);
    imshow(Y);
    str = sprintf('[%d %d]',i*5,i*5);
    title(str);
end


F=fft2(double(grayImage));
S=fftshift(F);
L=log2(S);
A=abs(L);
figure,

imagesc(A)
title('Transformacja Fouriera');
figure,

mesh(A);
title('Transformacja Fouriera');
cosTransImage = dct2(grayImage);
figure,

imshow(log(abs(cosTransImage)),[]) 
title('Transformacja Kosinusowa');