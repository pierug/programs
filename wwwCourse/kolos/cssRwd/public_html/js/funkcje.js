function pokaz(id)
{
    tresc = "";
    switch (id)
    {
        case 2:
            tresc += pokazGalerie();
            break;
        case 3:
            tresc += pokazPost();
            break;
        case 4:
            tresc += pokazKontakt();
            break;
        default:
            tresc += pokazOmnie();
    }
    //pobierz element o wskazanym id i ustaw jego nową zawartość:
    document.getElementById('blok').innerHTML = tresc;
}

function pokazOmnie() {
    tresc = '<h2><br />O mnie</h2> ';
    //operator += uzupełnia łańcuch kolejną porcją znaków:
    tresc += '<p>Lorem ipsum dolor pariatur,...</p>' +
            '<p class="srodek"><img src="images/baner.jpg" alt="Zdjęcie" /></p>' +
            '<article><h2>Moje hobby</h2><p>' +
            'Lorem ipsum dolor sit amet,...' +
            'mollit anim id est laborum.</p></article>';
    //przekaż wynik – gotową zawartość – do miejsca wywołania funkcji:
    return tresc;
}

function pokazGalerie()
{
    tresc = '<h2><br />Moja galeria</h2>';
    tresc += ' <div class="galeria">';

    for (i = 1; i <= 10; i++)
    {
        tresc += '<div class="slajd"> <src="images/obraz'+i+'.jpg" alt="Zdjęcie'+i+'"/></div>';
    }
    return tresc + '</div>';
}

function pokazKontakt()
{
    tresc = '<h2><br />Kontakt</h2>';
    //uzupełnij treść:
    tresc+= '<p>adam.piasecki@pollub.edu.pl</p>';
    return tresc;
}
function pokazDane()
{
    //Funkcja zbiera dane wpisane w pola formularza i wyświetla okienko
    //typu confirm do zatwierdzenia przez użytkownika:
    dane = "Następujące dane zostaną wysłane:\n";
    dane += "Email: " + document.getElementById('email').value + "\n";
    dane += "Nazwisko i imię: " + document.getElementById('name').value + "\n";
    dane += "Telefon: " + document.getElementById('tel').value + "\n";
    dane += "Komentarz: " + document.getElementById('wiadomosc').value + "\n";
    if (window.confirm(dane))
        return true;
    else
        return false;
}

function pokazPost()
{
    tresc = '<h2><br />Dodaj post</h2>';
    tresc += '<article class="srodek" ><form action="mailto:adam.piasecki@pollub.edu.pl" method="post" onsubmit="return pokazDane();">' +
            'Twój email:<br /> <input type="email" name="email" id="email" required /><br />' +
            'Nazwisko i imię:<br /><input type="text" name="name" id="name"/><br />' +
            'Telefon:<br /><input type="text" name="tel" id="tel"/><br />' +
            'Komentarz: <br /><textarea rows="3" cols="20" id="wiadomosc" name="wiadomosc" required></textarea>' +
            '<br /> <input type="submit" name="wyslij" value="Wyślij" />' +
            '</form></article>';
    return tresc;
}