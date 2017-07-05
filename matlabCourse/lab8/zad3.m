I = imread('jablko.bmp');
J = rgb2gray(I);
subplot(2,2,1);
imshow(J);
subplot(2,2,2);
imhist(J);
B = J > 245;
subplot(2,2,3);
imshow(B);
subplot(2,2,4);

B2 = bwperim(B, 8);
B2 = 1-B2;

SE = ones(4, 4);
B2 = imerode(B2, SE);
imshow(B2);