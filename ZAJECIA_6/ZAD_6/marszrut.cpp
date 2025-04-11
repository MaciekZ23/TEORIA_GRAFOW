#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

Matrix identityMatrix(int n)
{
    Matrix I(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        I[i][i] = 1;
    }
    return I;
}

Matrix multiplyMatrices(const Matrix &A, const Matrix &B)
{
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] = result[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

Matrix matrixPower(Matrix matrix, int k)
{
    int n = matrix.size();
    Matrix result = identityMatrix(n);
    Matrix base = matrix;

    while (k > 0)
    {
        if (k % 2 == 1)
        {
            result = multiplyMatrices(result, base);
        }
        base = multiplyMatrices(base, base);
        k = k / 2;
    }
    return result;
}

int countRoutes(const Matrix &adjacencyMatrix, int v, int u, int k)
{
    Matrix powered = matrixPower(adjacencyMatrix, k);
    return powered[v][u];
}

int main()
{
    int n, m;
    cout << "Podaj liczbe wierzcholkow: ";
    cin >> n;
    cout << "Podaj liczbe krawedzi: ";
    cin >> m;

    Matrix adjacendyMatrix(n, vector<int>(n, 0));

    cout << "Podaj krawedzie w postaci: start koniec:" << endl;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        adjacendyMatrix[from][to] = 1;
    }

    int v, u, k;
    cout << "Podaj wierzcholek poczatkowy, koncowy i dlugosc marszruty (v u k): ";
    cin >> v >> u >> k;

    int result = countRoutes(adjacendyMatrix, v, u, k);
    cout << "Liczba marszrut: " << result << endl;
    return 0;
}