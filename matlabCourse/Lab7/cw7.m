I = imread('szopa.tif');
J = imadjust(I, [0 0.1], [0 1]);
figure, imshow(I);
figure, imshow(J);