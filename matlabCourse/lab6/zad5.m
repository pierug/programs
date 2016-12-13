X = rand(3,3);
X = round(X*256);
XX = mat2gray(X);
[Xind,map] = gray2ind(XX,256);

Xrgb = ind2rgb(Xind,map);

figure, imshow(XX);
figure, imshow(Xind,map);
figure, imshow(Xrgb);