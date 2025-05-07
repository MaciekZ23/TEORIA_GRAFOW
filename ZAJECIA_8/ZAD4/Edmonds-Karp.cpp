#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int edmonds_karp(vector<vector<int>> &graf, int zrodlo, int ujscie)
{
    int n = graf.size();
    vector<vector<int>> graf_residualny = graf;
    // Tablica rodzicow dla sciezki powiekszajacej
    vector<int> rodzic(n, -1);
    int maksymalnyPrzeplyw = 0;
    while (true)
    {
        queue<int> kolejka;
        kolejka.push(zrodlo);
        fill(rodzic.begin(), rodzic.end(), -1);
        while (!kolejka.empty() && rodzic[ujscie] == -1)
        {
            int u = kolejka.front();
            kolejka.pop();
            for (int v = 0; v < n; v++)
            {
                if (rodzic[v] == -1 && graf_residualny[u][v] > 0)
                {
                    rodzic[v] = u;
                    kolejka.push(v);
                }
            }
        }
        if (rodzic[ujscie] == -1)
        {
            break;
        }
        int przeplywSciezki = INT_MAX;
        for (int v = ujscie; v != zrodlo; v = rodzic[v])
        {
            int u = rodzic[v];
            przeplywSciezki = min(przeplywSciezki, graf_residualny[u][v]);
        }
        for (int v = ujscie; v != zrodlo; v = rodzic[v])
        {
            int u = rodzic[v];
            graf_residualny[u][v] = graf_residualny[u][v] - przeplywSciezki;
            graf_residualny[v][u] = graf_residualny[v][u] + przeplywSciezki;
        }
        maksymalnyPrzeplyw = maksymalnyPrzeplyw + przeplywSciezki;
    }
    return maksymalnyPrzeplyw;
}

int main()
{
    vector<vector<int>> graf =
        {
            // s  x   y   w  u  e  t
            {0, 20, 50, 0, 0, 0, 0},
            {0, 0, 0, 60, 50, 0, 0},
            {0, 10, 0, 30, 0, 0, 0},
            {0, 0, 0, 0, 10, 0, 20},
            {0, 0, 0, 0, 0, 80, 40},
            {0, 0, 0, 0, 0, 0, 40},
            {0, 0, 0, 0, 0, 0, 0}};
    int zrodlo = 0;
    int ujscie = 6;
    int maksymalnyPrzeplyw = edmonds_karp(graf, zrodlo, ujscie);
    cout << "Maksymalny przeplyw: " << maksymalnyPrzeplyw << endl;
    return 0;
}