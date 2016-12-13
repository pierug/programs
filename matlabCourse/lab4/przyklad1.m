X = 1:200;
Y = X.^2;
plot(X,Y)

[X Y] = meshgrid(1:100,1:100);
Z= X.*Y;
surf(X,Y,Z)