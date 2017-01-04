BW1 = imread('powierzchnia.bmp');
SE = ones(20, 20);
BW2 = imerode(BW1, SE);
BW3 = imdilate(BW2, SE);
imshow(BW1)
figure, imshow(BW3)