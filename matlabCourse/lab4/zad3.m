t = 0:0.01:10;

y1 = exp(t*(-0.5)).* sin(1*t);
y2 = exp(t*(-0.5)).* sin(3*t);
y3 = exp(t*(-0.5)).* sin(10*t);

plot(t,y1,'r-o',t,y2,'bo',t,y3,'k-')
xlabel('Argumenty t')
ylabel('Wartosci y')
legend('y1','y2','y3')
grid on