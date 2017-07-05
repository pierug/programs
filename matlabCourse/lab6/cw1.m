clear, clc;
I = imread('tygrys.bmp');
figure, subplot(2, 2, 1);
imshow(I);
title('Obraz');
[Lw, Lk, N] = size(I);
X(Lw, Lk, N) = uint8(0);
X(:, :, 1) = I(:, :, 1);
subplot(2, 2, 2);
imshow(X);
title('Sk�adowa czerwona');
clear X;
[Lw, Lk, N] = size(I);
X(Lw, Lk, N) = uint8(0);
X(:, :, 2) = I(:, :, 2);
subplot(2, 2, 3);
imshow(X);
title('Sk�adowa zielona');
clear X;
[Lw, Lk, N] = size(I);
X(Lw, Lk, N) = uint8(0);
X(:, :, 3) = I(:, :, 3);
subplot(2, 2, 4);
imshow(X);
title('Sk�adowa niebieska');