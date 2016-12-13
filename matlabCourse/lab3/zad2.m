disp('podaj dl bokow trojkata');
x(1) = input('a= ');
x(2) = input('b= ');
x(3) = input('c= ');

if x(1)+x(2)>x(3)
    if x(1)+x(3)>x(2)
        if x(3)+x(2)>x(1)
            disp('istnieje dany trojkat');
        else
            disp('nie istnieje dany trojkat');
        end
    else
        disp('nie istnieje dany trojkat');
    end
else
    disp('nie istnieje dany trojkat');
end