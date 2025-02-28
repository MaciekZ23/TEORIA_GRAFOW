const input = require("readline-sync");

/**
 * Metoda Havla-Hakimiego ze zlozonoscia O(n²)
 */
function havlaHakimi(stopnie) 
{
    while(true) 
    {
        stopnie.sort((a, b) => b - a);
        if(stopnie[0] === 0) 
        {
            return true;
        }
        let najwyzszy = stopnie.shift();
        if(najwyzszy > stopnie.length) 
        {
            return false;
        }
        for(let i = 0; i < najwyzszy; i++) 
        {
            stopnie[i]--;
            if(stopnie[i] < 0) 
            {
                return false;
            }
        }
    }
}

/**
 * Metoda Erdosa-Gallai ze zlozonoscia O(n)
 */
function erdosGallai(stopnie) 
{
    stopnie.sort((a, b) => b - a);
    let sumaStopni = stopnie.reduce((acc, val) => acc + val, 0);
    if(sumaStopni % 2 !== 0) 
    {
        return false;
    }
    let sumaLewa = 0, n = stopnie.length;
    for(let k = 1; k <= n; k++) 
    {
        sumaLewa = sumaLewa + stopnie[k - 1];
        let pierwszaCzesc = k * (k - 1);
        let drugaCzesc = stopnie.slice(k).reduce((suma, stopien) => suma + Math.min(k, stopien), 0);
        let sumaPrawa = pierwszaCzesc + drugaCzesc;
        if(sumaLewa > sumaPrawa) 
        {
            return false;
        }        
    }
    return true;
}

const liczbaWierzcholkow = parseInt(input.question("Podaj liczbe wierzcholkow: "));
const stopnie = input.question("Podaj stopnie wierzcholkow: ").split(" ").map(Number);

if(stopnie.length !== liczbaWierzcholkow) 
{
    console.log("Blad: liczba podanych stopni nie zgadza sie z liczba wierzcholkow!");
} 
else 
{
    console.log("\nWynik metody Havla-Hakimiego:", havlaHakimi([...stopnie]) ? "CIAG JEST GRAFICZNY" : "CIAG NIE JEST GRAFICZNY");
    console.log("Wynik metody Erdosa-Gallai:", erdosGallai([...stopnie]) ? "CIAG JEST GRAFICZNY" : "CIAG NIE JEST GRAFICZNY");
}
