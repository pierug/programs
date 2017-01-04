I = imread('szopa.tif');
J = imadjust(I, [0 0.01], [0.3 1]);
figure, imshow(I);
figure, imshow(J);