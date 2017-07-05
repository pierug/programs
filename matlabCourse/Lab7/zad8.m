I = imread('drzewa.jpg');
subplot(1,2,1), imshow(I);

J = imadjust(I, [], [],3);

subplot(1,2,2), imshow(J);