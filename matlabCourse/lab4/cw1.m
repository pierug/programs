x = 0:0.2:12;
y1 = besseli(1, x);
y2 = besseli(2, x);
y3 = besseli(3, x);

figure(1)
subplot(2, 2, 1)

h = plot(x, y1, x, y2, x, y3);

set(h, 'LineWidth', 2, {'LineStyle'},{'-'; '--'; ':'})
set(h, {'Color'}, {'r'; 'g'; 'b'})

axis([0 12 -0.5 1])
grid on

xlabel('Czas'); ylabel('Amplituda')
legend(h, '1', '2', '3')
title('Funkcje Bessela')
[y, ix] = min(y1);
text(x(ix), y, 'Minimum \rightarrow','HorizontalAlignment', 'right')
print -dwinc -r200 wykres1






