function czyIdentyczneGrafy(graf1, graf2)
{
    if(graf1.length !== graf2.length)
    {
        return false;
    }
    for(let wierzcholek = 0; wierzcholek < graf1.length; wierzcholek++)
    {
        if(graf1[wierzcholek].length !== graf2[wierzcholek].length)
        {
            return false;
        }
        let licznik = new Map();
        for(let sasiad of graf1[wierzcholek])
        {
            licznik.set(sasiad, (licznik.get(sasiad) || 0) + 1);
        }
        for(let sasiad of graf2[wierzcholek])
        {
            if(!licznik.has(sasiad) || licznik.get(sasiad) === 0)
            {
                return false;
            }
            licznik.set(sasiad, licznik.get(sasiad) - 1);
        }
    }
    return true;
}

const graf1 = [[1, 2], [0, 2], [0, 1, 3], [2]];
const graf2 = [[1, 6], [0, 2], [0, 1, 3], [2]];

if(czyIdentyczneGrafy(graf1, graf2))
{
    console.log("Grafy sa identyczne");
}
else
{
    console.log("Grafy nie sa identyczne");
}