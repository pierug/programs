L = [1 2;3 4];
map = ones(4,3)*0.5;

figure, imshow(L,map)

GRAY = ind2gray(L,map);
figure, imshow(GRAY)


