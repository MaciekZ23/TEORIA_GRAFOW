class Graf 
{
    constructor(wierzcholki, krawedzie) 
    {
        this.wierzcholki = wierzcholki;
        this.krawedzie = krawedzie;
        this.macierzSasiedztwa = Array.from({ length: wierzcholki }, () => Array(wierzcholki).fill(0));
        this.listaSasiedztwa = Array.from({ length: wierzcholki }, () => []);
        this.listaKrawedzi = [];
        this.konwertuj();
    }

    konwertuj() 
    {
        for(let [u, v] of this.krawedzie) 
            {
            this.macierzSasiedztwa[u - 1][v - 1] = 1;
            this.macierzSasiedztwa[v - 1][u - 1] = 1; 
            
            this.listaSasiedztwa[u - 1].push(v);
            this.listaSasiedztwa[v - 1].push(u);
            
            this.listaKrawedzi.push([u, v]);
        }
    }

    wypiszMacierzSasiedztwa() 
    {
        console.log("\nMacierz sasiedztwa:");
        this.macierzSasiedztwa.forEach(wiersz => console.log(wiersz.join(" ")));
    }

    wypiszListeSasiedztwa() 
    {
        console.log("\nLista sasiedztwa:");
        this.listaSasiedztwa.forEach((sasiedzi, i) => {
            console.log(`${i + 1}: ${sasiedzi.join(", ")}`);
        });
    }

    wypiszListeKrawedzi() 
    {
        console.log("\nLista krawedzi:");
        this.listaKrawedzi.forEach(([u, v]) => console.log(`(${u}, ${v})`));
    }
}

function main() 
{
    const input = require("readline-sync");
    const [wierzcholki, liczbaKrawedzi] = input.question("Podaj liczbe wierzcholkow i krawedzi: ").split(" ").map(Number);
    let krawedzie = [];
    console.log("Podaj krawedzie (u v):");
    for(let i = 0; i < liczbaKrawedzi; i++) 
        {
        let [u, v] = input.question().split(" ").map(Number);
        krawedzie.push([u, v]);
    }

    const graf = new Graf(wierzcholki, krawedzie);
    graf.wypiszMacierzSasiedztwa();
    graf.wypiszListeSasiedztwa();
    graf.wypiszListeKrawedzi();
}

main();
