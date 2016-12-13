a = input('1-prostokat, 2- kolo, 3- trojkat ');
switch a
case 1 
   x = input('a =  ');
   y = input('b =  ');
   fprintf('P = %f',x*y);
case 2 
   x = input('r =  ');  
   fprintf('P = %f',pi*(x^2));   
case 3
   x = input('h =  ');
   y = input('a =  ');
   fprintf('P = %f',x*y*0.5);
otherwise 
  disp('cos nie tak');
end 