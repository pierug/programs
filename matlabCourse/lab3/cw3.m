disp('Zadanie 1');
disp('podaj trzy liczby rzeczywiste');
X = zeros(1,3);
X[1] = input('a= ');
X[2] = input('b= ');
X[3] = input('c= ');

if a>b
    tmp = a;
    a = b;
    b = tmp;
    if c>b
        tmp = c;
        c = b;
        b = tmp;
    end
else
    tmp = b;
    b = a;
    a = tmp;
end
    