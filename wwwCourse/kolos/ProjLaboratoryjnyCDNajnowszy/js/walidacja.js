function sprawdzPole(pole_id, obiektRegex) {
    var obiektPole = document.getElementById(pole_id);
    if (!obiektRegex.test(obiektPole.value))
        return (false);
    else
        return (true);
}
function sprawdz_radio(nazwa_radio) {
    var obiekt = document.getElementsByName(nazwa_radio);
    for (i = 0; i < obiekt.length; i++)
    {
        wybrany = obiekt[i].checked;
        if (wybrany)
            return true;
    }
    return false;
}

function sprawdz_box(box_id)
{
    var obiekt = document.getElementById(box_id);
    if (obiekt.checked)
        return true;
    else
        return false;
}
function sprawdz()
{
    var ok = true;
    obiektNazw = /^[a-zA-Z]{2,20}$/;
    obiektemail =
            /^([a-zA-Z0-9])+([.a-zA-Z0-9_-])*@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-]+)+/;
    obiektWiek = /^[1-9][0-9]{1,2}$/;

    if (!sprawdzPole("nazw", obiektNazw))
    {
        ok = false;
        document.getElementById("nazw_error").innerHTML =
                "Wpisz poprawnie nazwisko!";
    } else
        document.getElementById("nazw_error").innerHTML = "";
    if (!sprawdzPole("wiek", obiektWiek))
    {
        ok = false;
        document.getElementById("wiek_error").innerHTML =
                "Wpisz poprawnie wiek!";
    } else
        document.getElementById("wiek_error").innerHTML = "";

    if (!sprawdzPole("email", obiektemail))
    {
        ok = false;
        document.getElementById("email_error").innerHTML =
                "Wpisz poprawnie mail!";
    } else
        document.getElementById("nazw_error").innerHTML = "";


    if (!sprawdz_radio("zaplata"))
    {
        ok = false;
        document.getElementById("zaplata_error").innerHTML =
                "Zaznacz sposób zapłaty!";
    } else
        document.getElementById("zaplata_error").innerHTML = "";

    if ((sprawdz_box("php") || sprawdz_box("c") || sprawdz_box("java")))
    {
        document.getElementById("produkt_error").innerHTML = "";
    } else{
        ok = false;
        document.getElementById("produkt_error").innerHTML =
                "Zaznacz tutorail z jakiegoś języka!";
    }
 

    pokazDane();
    return ok;

}

function pokazDane()
{
    dane = "Następujące dane zostaną wysłane:\n";
    dane += "Email: " + document.getElementById('email').value + "\n";
    dane += "Nazwisko: " + document.getElementById('nazw').value + "\n";
    dane += "Wiek: " + document.getElementById('wiek').value + "\n";
    dane += "Zamawiam tutorial z języka: " + (document.getElementById('php').checked ? "PHP" : "") +
            (document.getElementById('c').checked ? "C/C++" : "") +
            (document.getElementById('java').checked ? "Java" : "") + "\n";
    dane += "Sposób zapłaty: " + (document.getElementById('zaplata').value) + "\n";
    if (window.confirm(dane))
        return true;
    else
        return false;
}