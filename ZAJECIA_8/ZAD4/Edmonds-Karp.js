function edmondsKarp(graf, zrodlo, ujscie) {
    const n = graf.length;
    const grafRes = graf.map(row => row.slice());
    const rodzic = new Array(n);
    let maksPrzeplyw = 0;

    while (true) {
        rodzic.fill(-1);
        const kolejka = [zrodlo];
        while (kolejka.length > 0 && rodzic[ujscie] === -1) {
            const u = kolejka.shift();
            for (let v = 0; v < n; v++) {
                if (rodzic[v] === -1 && grafRes[u][v] > 0) {
                    rodzic[v] = u;
                    kolejka.push(v);
                }
            }
        }

        if (rodzic[ujscie] === -1) {
            break;
        }

        let przeplywSciezki = Infinity;
        for (let v = ujscie; v !== zrodlo; v = rodzic[v]) {
            const u = rodzic[v];
            przeplywSciezki = Math.min(przeplywSciezki, grafRes[u][v]);
        }
        for (let v = ujscie; v !== zrodlo; v = rodzic[v]) {
            const u = rodzic[v];
            grafRes[u][v] = grafRes[u][v] - przeplywSciezki;
            grafRes[v][u] = grafRes[v][u] + przeplywSciezki;
        }

        maksPrzeplyw = maksPrzeplyw + przeplywSciezki;
    }
    return maksPrzeplyw;
}

const graf =
    [
        // s  x   y   w  u  e  t
        [0, 20, 50, 0, 0, 0, 0],
        [0, 0, 0, 60, 50, 0, 0],
        [0, 10, 0, 30, 0, 0, 0],
        [0, 0, 0, 0, 10, 0, 20],
        [0, 0, 0, 0, 0, 80, 40],
        [0, 0, 0, 0, 0, 0, 40],
        [0, 0, 0, 0, 0, 0, 0]
    ];

const zrodlo = 0;
const ujscie = 6;
console.log("Maksymalny przeplyw:", edmondsKarp(graf, zrodlo, ujscie));