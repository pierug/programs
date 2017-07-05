BW1 = imread('powierzchnia.bmp');
SE = ones(50, 50);
BW2 = imdilate(BW1, SE);
BW3 = imerode(BW2, SE);
imshow(BW1)
figure, imshow(BW3)