I = imread('zorza.jpg');
J = imadjust(I, [0 0 0; 0.25 0.25 0.25], [0 1]);
figure, imshow(I);
figure, imshow(J);