I = imread('zorza.jpg');
J = imadjust(I, [0 0.5 0; 1 0.8 1], [0.2 1]);
figure, imshow(I);
figure, imshow(J);