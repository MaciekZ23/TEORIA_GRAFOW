#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

// Wyswietlenie macierzy odleglosci
void wyswietlMacierz(const vector<vector<int>> &macierz)
{
    int n = macierz.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (macierz[i][j] == INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << macierz[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Rekonstrukcja sciezki najkrotszej drogi
void odczytajSciezke(int i, int j, const vector<vector<int>> &poprzednik)
{
    if (poprzednik[i][j] == -1)
    {
        cout << "Brak sciezki" << endl;
        return;
    }
    vector<int> sciezka;
    while (j != -1)
    {
        sciezka.push_back(j);
        j = poprzednik[i][j];
    }
    reverse(sciezka.begin(), sciezka.end());
    cout << "Najkrotsza sciezka: ";
    for (int v : sciezka)
    {
        cout << v << " ";
    }
    cout << endl;
}

// Algorytm Floyda-Warshalla
void floydWarshall(vector<vector<int>> &graf, int n)
{
    vector<vector<int>> odleglosc = graf;
    vector<vector<int>> poprzednik(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graf[i][j] != INF && i != j)
            {
                poprzednik[i][j] = i;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (odleglosc[i][k] != INF && odleglosc[k][j] != INF && odleglosc[i][k] + odleglosc[k][j] < odleglosc[i][j])
                {
                    odleglosc[i][j] = odleglosc[i][k] + odleglosc[k][j];
                    poprzednik[i][j] = poprzednik[k][j];
                }
            }
        }
    }
    cout << "Najkrotsze odleglosci miedzy parami wierzcholkow:" << endl;
    wyswietlMacierz(odleglosc);
    int start, koniec;
    cout << "\nPodaj wierzcholki (i, j) dla odczytu sciezki: ";
    cin >> start >> koniec;
    odczytajSciezke(start, koniec, poprzednik);
    int wierzcholek;
    cout << "\nPodaj wierzcholek do znalezienia najkrotszego cyklu: ";
    cin >> wierzcholek;
    int minCykl = INF;
    for (int i = 0; i < n; i++)
    {
        if (i != wierzcholek && odleglosc[i][wierzcholek] != INF && odleglosc[wierzcholek][i] != INF)
        {
            minCykl = min(minCykl, odleglosc[i][wierzcholek] + odleglosc[wierzcholek][i]);
        }
    }
    if (minCykl == INF)
    {
        cout << "Brak cyklu przechodzacego przez wierzcholek " << wierzcholek << endl;
    }
    else
    {
        cout << "Najkrotszy cykl przechodzacy przez " << wierzcholek << " ma dlugosc: " << minCykl << endl;
    }
}

int main()
{
    int n, m;
    cout << "Podaj liczbe wierzcholkow i krawedzi: ";
    cin >> n >> m;
    vector<vector<int>> graf(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
    {
        graf[i][i] = 0;
    }
    cout << "Podaj krawedzie w formacie: u v w (skad, dokad, waga):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graf[u][v] = w;
    }
    floydWarshall(graf, n);
    return 0;
}
