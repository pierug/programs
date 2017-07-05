A = imread('powierzchnia.bmp');
imshow(A);
B = bwperim(A, 8);
figure, imshow(B)