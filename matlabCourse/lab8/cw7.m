I = imread('czerniakBW.bmp');
BW3 = ~im2bw(I);
BW4 = bwfill(BW3, 'holes');
imshow(BW3)
figure, imshow(BW4)