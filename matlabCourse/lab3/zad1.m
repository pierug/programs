x(1) = input('a= ');
x(2) = input('b= ');
x(3) = input('c= ');

for i=1:3
    for j=1:2
        if x(j+1)<x(j)
            tmp = x(j);
            x(j) = x(j+1);
            x(j+1) = tmp;
        end
    end 
end
disp(x)