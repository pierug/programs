L = [1 2;3 4];
map = [1,0.5,0.3;0,0.6,0.2;0.1,1,0.3;1,0.9,1];

figure, imshow(L,map)

RGB = ind2rgb(L,map);
figure, imshow(RGB)