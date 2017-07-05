BW1 = imread('kontur.bmp');
SE = ones(4, 4);
BW2 = imdilate(BW1, SE);
imshow(BW1)
figure, imshow(BW2)