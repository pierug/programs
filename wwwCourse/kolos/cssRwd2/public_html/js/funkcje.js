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
    document.getElementById('blok').innerHTML = tresc;
}

function pokazOmnie() {
    tresc = '<h2><br />O mnie</h2> ';
    tresc += '<p>Lorem ipsum dolor pariatur,...</p>' +
            '<p class="srodek"><img src="images/obraz1.jpg" alt="Zdjęcie" /></p>' +
            '<article><h2>Moje hobby</h2><p>' +
            'Lorem ipsum dolor sit amet,...' +
            'mollit anim id est laborum.</p></article>';
    return tresc;
}

function pokazGalerie()
{
    tresc = '<h2><br />Moja galeria</h2>';
    tresc += ' <div class="galeria">';

    for (i = 1; i <= 10; i++)
    {
        tresc += '<div class="slajd"> <img src="images/obraz'+i+'.jpg" alt="Zdjęcie'+i+'"/></div>';
    }
    return tresc + '</div>';
}

function pokazKontakt()
{
    tresc = '<h2><br />Kontakt</h2>';
    tresc+= '<p>adam.piasecki@pollub.edu.pl</p>';
    return tresc;
}
function pokazDane()
{
    dane = "Następujące dane zostaną wysłane:\n";
    dane += "Email: " + document.getElementById('email').value + "\n";
    dane += "Nazwisko i imię: " + document.getElementById('name').value + "\n";
    dane += "Telefon: " + document.getElementById('tel').value + "\n";
    dane += "Zainteresowania: " + (document.getElementById('sport').checked ? "sport" : "") +
                                    (document.getElementById('muzyka').checked ? "muzyka" : "") +
                                    (document.getElementById('film').checked ? "film" : "") +
                                    (document.getElementById('inne').checked ? "inne" : "") + "\n";
    dane += "Wiek: " + document.getElementById('rd').value + "\n";
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
            
            'Zainteresowania:<br /><input type="checkbox" name="sport" value="sport" id="sport"/> sport <input type="checkbox" name="muzyka" value="muzyka"  id="muzyka"/> muzyka <input type="checkbox" name="film" value="film"  id="film"/> film <input type="checkbox" name="inne" value="inne"  id="inne"/> inne<br />' +
            
            'Wiek:<br /><input type="radio" name="rb" value="<10" id="rb"/> <10 <input type="radio" name="rb" value="10-20" id="rd"/> 10-20 <input type="radio" name="rb" value="21-30" id="rd"/> 21-30 <input type="radio" name="rb" value="31-40" id="rd"/> 31-40 <input type="radio" name="rb" value="41-50" id="rd"/> 41-50 <input type="radio" name="rb" value=">50" id="rd"/> >50<br />' +
            
            
            'Komentarz: <br /><textarea rows="3" cols="20" id="wiadomosc" name="wiadomosc" required></textarea>' +
            '<br /> <input type="submit" name="wyslij" value="Wyślij" />' +
            '</form></article>';
    return tresc;
}