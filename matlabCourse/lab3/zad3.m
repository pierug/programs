disp('podaj liczbe');
a = input('a= ');
b = round(a);
if a==b
    if mod(a,2)
        disp('nieparzysta');
    else
        disp('parzysta');
    end
else
    disp('niecalkowita');
end