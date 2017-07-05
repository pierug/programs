licznik = 1;
a = rand(1,1);
b = round(a * 10);
disp('Wylosowano liczbe z przedzialu [1, 10]');
x = input('Zgadnij, jaka liczba zostala wylosowana: ');
while (x ~= b)
  x = input('Zgadnij jeszcze raz: ');
 licznik = licznik + 1;
end
disp(['Trafiiel za ', num2str(licznik),' razem']);