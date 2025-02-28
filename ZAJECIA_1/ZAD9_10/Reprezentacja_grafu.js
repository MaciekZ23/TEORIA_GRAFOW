const fs = require("fs");

class Digraf 
{
    constructor(nazwaPliku) 
    {
        const dane = fs.readFileSync(nazwaPliku, "utf-8").trim().split("\n");
        const [n, m] = dane[0].split(" ").map(Number);

        this.liczbaWierzcholkow = n;
        this.liczbaKrawedzi = m;

        this.macierzSasiedztwa = Array.from({ length: n }, () => Array(n).fill(0));
        this.listaSasiedztwa = Array.from({ length: n }, () => []);
        this.listaKrawedzi = [];
        this.macierzIncydencji = Array.from({ length: n }, () => Array(m).fill(0));

        this.wczytajDane(dane.slice(1));
    }

    //Wczytywanie danych z pliku i tworzenie roznych reprezentacji grafu
    wczytajDane(krawedzie) 
    {
        krawedzie.forEach((linia, index) => {
            const [v, w] = linia.split(" ").map(x => Number(x) - 1);

            //Lista krawedzi
            this.listaKrawedzi.push([v + 1, w + 1]);

            //Macierz sasiedztwa
            this.macierzSasiedztwa[v][w] = 1; // Krawedz skierowana v → w

            //Lista sasiedztwa
            this.listaSasiedztwa[v].push(w + 1);

            //Macierz incydencji (v → w) → -1 w wierszu v, 1 w wierszu w
            this.macierzIncydencji[v][index] = -1;
            this.macierzIncydencji[w][index] = 1;
        });
    }

    //Wypisuje macierz sasiedztwa
    wypiszMacierzSasiedztwa() 
    {
        console.log("Macierz sasiedztwa:");
        this.macierzSasiedztwa.forEach(row => console.log(row.join(" ")));
    }

    //Wypisuje liste sasiedztwa
    wypiszListeSasiedztwa() 
    {
        console.log("\nLista sasiedztwa:");
        this.listaSasiedztwa.forEach((sasiedzi, i) => {
            console.log(`${i + 1}: ${sasiedzi.join(", ")}`);
        });
    }

    //Wypisuje liste krawedzi
    wypiszListeKrawedzi() 
    {
        console.log("\nLista krawedzi:");
        this.listaKrawedzi.forEach(([v, w]) => console.log(`(${v}, ${w})`));
    }

    //Wypisuje macierz incydencji
    wypiszMacierzIncydencji() 
    {
        console.log("\nMacierz incydencji:");
        this.macierzIncydencji.forEach(row => console.log(row.join(" ")));
    }

    //Wypisuje wszystkie reprezentacje
    wypiszReprezentacje() 
    {
        this.wypiszMacierzSasiedztwa();
        this.wypiszListeSasiedztwa();
        this.wypiszListeKrawedzi();
        this.wypiszMacierzIncydencji();
    }
}

const nazwaPliku = "dane.txt";
const digraf = new Digraf(nazwaPliku);
digraf.wypiszReprezentacje();
