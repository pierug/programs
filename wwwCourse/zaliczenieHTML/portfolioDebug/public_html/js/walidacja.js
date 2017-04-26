function sprawdzPole(pole_id, obiektRegex) {
    var obiektPole = document.getElementById(pole_id);
    if (!obiektRegex.test(obiektPole.value))
        return (false);
    else
        return (true);
}

function sprawdz()
{
    var ok = true;
    obiektTemat = /^[a-zA-Z]{2,20}$/;
    obiektemail =
            /^([a-zA-Z0-9])+([.a-zA-Z0-9_-])*@([a-zA-Z0-9_-])+(.[a-zA-Z0-9_-]+)+/;
    

    if (!sprawdzPole("subject", obiektTemat))
    {
        ok = false;
        window.alert("Proszę wpisać prawidłowy teamt");
    } 
    

    if (!sprawdzPole("email", obiektemail))
    {
        ok = false;
        window.alert("Proszę wpisać prawidłowy email");
    } 

    return ok;
}

