t = 0:0.01:4;
y = exp(t*(-2)).* sin(t*3);

plot(t,y,'r-o')
xlabel('Argumenty t')
ylabel('Wartosci y')
legend('y')
grid on

