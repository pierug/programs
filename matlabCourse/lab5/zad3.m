I = imread('grace.bmp');
size = input('podaj skalowanie= ');

if(size<=1.5 && size>=0.1)
    M = imresize(I,size);
    subplot(1,2,1);
    imshow(I)
    subplot(1,2,2);
    imshow(M)
end