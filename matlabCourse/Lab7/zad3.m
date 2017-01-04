I = imread('rtg_pluc.bmp');
J = histeq(I);
K = imread('usg_tarczycy.bmp');
L = histeq(K);

subplot(1,2,1);
imhist(J);
subplot(1,2,2);
imhist(L);