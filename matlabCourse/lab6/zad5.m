X = rand(3,3);
X = round(X*256);

[Lw, Lk, N] = size(X);
XX(Lw, Lk, N) = uint8(0);
XX(:, :, 1) = X(:, :, 1);
imshow(XX);