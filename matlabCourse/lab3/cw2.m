% Program do rozwi¹zywania równania kwadratowego
clear all, clc;
disp('Podaj wspolczynniki rownania kwadratowego:');
a = input('a = ');
b = input('b = ');
c = input('c = ');
delta = b * b - 4 * a * c;
if delta > 0
    disp('Dwa pierwiastki:')
    x1 = (-b - sqrt(delta)) / (2 * a);
    x2 = (-b + sqrt(delta)) / (2 * a);
    disp(['x1 = ', num2str(x1), ', x2 = ', num2str(x2)]);
elseif (delta == 0)
    disp('Jeden podojny pierwiastek:')
    x12 = -b / (2 * a);
    disp(['x12 = ', int2str(x12)]);
else
    disp('Brak pierwiastkow rzeczywistych');
end