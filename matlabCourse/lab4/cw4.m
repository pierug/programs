figure(1)
[x, y] = meshgrid(-3*pi:0.5:3*pi, -3*pi:0.5:3*pi);
z= 600-x.*y+50*sin(x)+50*sin(y);
subplot(2,2,1);
mesh(x,y,z);
subplot(2,2,2);
surf(x,y,z);
subplot(2,2,3);
contourf(x,y,z);
subplot(2,2,4);
meshc(x,y,z);