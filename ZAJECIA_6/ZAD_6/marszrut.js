function multiplyMatrices(A, B) {
    const n = A.length;
    const result = Array.from({ length: n }, () => Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            for (let k = 0; k < n; k++) {
                result[i][j] = result[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

function matrixPower(matrix, k) {
    let result = identityMatrix(matrix.length);
    let base = matrix;

    while (k > 0) {
        if (k % 2 === 1) {
            result = multiplyMatrices(result, base);
        }
        base = multiplyMatrices(base, base);
        k = Math.floor(k / 2);
    }

    return result;
}

function identityMatrix(n) {
    const identity = Array.from({ length: n }, (_, i) => Array.from({ length: n }, (_, j) => (i === j ? 1 : 0)));
    return identity;
}

function countRoutes(adjacencyMatrix, v, u, k) {
    const poweredMatrix = matrixPower(adjacencyMatrix, k);
    return poweredMatrix[v][u];
}

const adjacencyMatrix = [
    [0, 1, 1, 0, 0],
    [0, 0, 0, 1, 1],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0]
];

const v = 0;
const u = 4;
const k = 2;

console.log("Liczba marszrut:", countRoutes(adjacencyMatrix, v, u, k));