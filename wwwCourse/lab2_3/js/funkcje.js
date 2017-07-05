
function oblicz()
{
    var k = parseInt(document.getElementById('kwota').value);
    var pr = parseFloat(document.getElementById('procent').value)/100;
    var n = parseInt(document.getElementById('rat').value);
    var pr_mc=pr/12;
    var miesieczna = document.getElementById('miesieczna');
    var odsetkami = document.getElementById('odsetkami');
    miesieczna.value = (k*pr_mc)/(1-(1/Math.pow((1+pr_mc),n)));
    odsetkami.value = parseFloat(miesieczna.value)*n;
}

