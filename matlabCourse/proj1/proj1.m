input = imread('normal-ct-brain.jpg');
grayImage=rgb2gray(input);
%figure, imshow(input);
subplot(2,2,1);
imshow(grayImage);

subplot(2,2,2);
imhist(grayImage);
histGrayImage=imhist(grayImage);
%todo: wpisac w plota
meanHistGrayImage = mean(histGrayImage)
minHistGrayImage = min(histGrayImage)
maxHistGrayImage = max(histGrayImage)

subplot(2,2,3);
grayImageCorrect = histeq(grayImage);
imshow(grayImageCorrect);

subplot(2,2,4);
imhist(grayImageCorrect);

%figure, 
%imshow(grayImage);

%figure, 
%Y=medfilt2(grayImage,[1 1]);
%imshow(Y);

%figure, 
%z=medfilt2(grayImage,[36 36]);
%imshow(z);

for i=1:9 
    subplot(3,3,i);
    Y=medfilt2(grayImage,[i*5 i*5]);
    imshow(Y);
end


F=fft2(double(grayImage));
S=fftshift(F);
L=log2(S);
A=abs(L);
figure,
imagesc(A)

%figure,
%subpolt(2,2,1);
%imshow(abs(S),[24 100000]), colormap gray
%subpolt(2,2,2);
%imshow(angle(S),[-pi pi]), colormap gray

cosTransImage = dct2(grayImage);
figure,
imshow(log(abs(cosTransImage)),[]) 