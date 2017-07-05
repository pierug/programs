I = imread('owoce.jpg');
J = imadjust(I, [], [],5.5);
subplot(1,2,1), imshow(I);
subplot(1,2,2), imshow(J);

imwrite(J,'owoce1.jpg');