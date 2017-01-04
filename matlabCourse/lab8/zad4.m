J = imread('czaple.bmp');

subplot(2,2,1);
imshow(J);
subplot(2,2,2);
imhist(J);
B = J >185;
subplot(2,2,3);
imshow(B);
subplot(2,2,4);

SE = ones(3, 3);
B2 = imerode(B, SE);
imshow(B2);