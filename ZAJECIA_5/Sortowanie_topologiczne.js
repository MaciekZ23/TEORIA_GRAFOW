function sortowanieTopologiczne(n, graf) {
    let stopienWejsciowy = new Array(n).fill(0);
    for (let listaSasiadow of graf) {
        for (let sasiad of listaSasiadow) {
            stopienWejsciowy[sasiad]++;
        }
    }
    console.log("Stopnie wejsciowe:");
    console.log(stopienWejsciowy.join(" "));
    let kolejka = [];
    for (let i = 0; i < n; i++) {
        if (stopienWejsciowy[i] == 0) {
            kolejka.push(i);
        }
    }
    let wynik = [];
    while (kolejka.length > 0) {
        let v = kolejka.shift();
        wynik.push(v);
        for (let sasiad of graf[v]) {
            stopienWejsciowy[sasiad]--;
            if (stopienWejsciowy[sasiad] == 0) {
                kolejka.push(sasiad);
            }
        }
    }
    console.log("Sortowanie topologiczne:")
    console.log(wynik.join(" "));
}

let n = 7;
let graf = [[4, 2], [0, 4], [], [1], [2], [1, 4], [2]];
sortowanieTopologiczne(n, graf);