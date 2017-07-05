t = -pi:0.01:pi;
y1 = sin(t);
y2 = 2*cos(3*t+1);


plot(t,y1,'g--',t,y2,'r-o')
xlabel('Argumenty t')
ylabel('Wartosci y')
legend('y1','y2')
grid on

