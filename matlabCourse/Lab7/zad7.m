I = imread('owoce1.jpg');
J = rgb2gray(I);
[cs, h] = imcontour(J, 6);
clabel(cs, h);
