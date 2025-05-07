function dfs(u, ujscie, przeplyw, graf, rodzic, odwiedzone) {
    if (u === ujscie) {
        return przeplyw;
    }
    odwiedzone[u] = true;
    for (let v = 0; v < graf.length; v++) {
        if (!odwiedzone[v] && graf[u][v] > 0) {
            rodzic[v] = u;
            const przeplywWKrawedzi = Math.min(przeplyw, graf[u][v]);
            const sciezkaPrzeplywu = dfs(v, ujscie, przeplywWKrawedzi, graf, rodzic, odwiedzone);
            if (sciezkaPrzeplywu > 0) {
                return sciezkaPrzeplywu;
            }
        }
    }
    return 0;
}

function fordFulkerson(graf, zrodlo, ujscie) {
    const n = graf.length;
    const grafRes = graf.map(row => row.slice());
    const rodzic = new Array(n).fill(-1);
    let maksymlanyPrzeplyw = 0;

    while (true) {
        const odwiedzone = new Array(n).fill(false);
        const sciezkaPrzeplywu = dfs(zrodlo, ujscie, Infinity, grafRes, rodzic, odwiedzone);
        if (sciezkaPrzeplywu === 0) {
            break;
        }
        maksymlanyPrzeplyw = maksymlanyPrzeplyw + sciezkaPrzeplywu;

        for (let v = ujscie; v !== zrodlo; v = rodzic[v]) {
            const u = rodzic[v];
            grafRes[u][v] = grafRes[u][v] - sciezkaPrzeplywu;
            grafRes[v][u] = grafRes[v][u] + sciezkaPrzeplywu
        }
    }
    return maksymlanyPrzeplyw;
}

const graf = [
    [0, 20, 50, 0, 0, 0, 0],
    [0, 0, 0, 60, 50, 0, 0],
    [0, 10, 0, 30, 0, 0, 0],
    [0, 0, 0, 0, 10, 0, 20],
    [0, 0, 0, 0, 0, 80, 40],
    [0, 0, 0, 0, 0, 0, 40],
    [0, 0, 0, 0, 0, 0, 0]
];

const zrodlo = 0; // s
const ujscie = 6; // t

const maksymalnyPrzeplyw = fordFulkerson(graf, zrodlo, ujscie);
console.log("Maksymalny przeplyw:", maksymalnyPrzeplyw);