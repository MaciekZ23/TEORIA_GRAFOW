#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Wezel
{
    int id;
    vector<int> sasiedzi;
};

// BFS zwracajacy najdalszy wierzcholek i jego odleglosc
pair<int, int> bfsNajdalszy(const vector<Wezel> &drzewo, int start)
{
    int n = drzewo.size();
    vector<int> odleglosc(n, -1);
    queue<int> kolejka;
    kolejka.push(start);
    odleglosc[start] = 0;
    int najdalszy = start;
    while (!kolejka.empty())
    {
        int wezel = kolejka.front();
        kolejka.pop();
        for (int sasiad : drzewo[wezel].sasiedzi)
        {
            if (odleglosc[sasiad] == -1)
            {
                odleglosc[sasiad] = odleglosc[wezel] + 1;
                kolejka.push(sasiad);
                if (odleglosc[sasiad] > odleglosc[najdalszy])
                {
                    najdalszy = sasiad;
                }
            }
        }
    }
    return {najdalszy, odleglosc[najdalszy]};
}

// Znalezienie najdluzszej sciezki w drzewie
vector<int> znajdzNajdluzszaSciezke(vector<Wezel> &drzewo)
{
    int n = drzewo.size();
    pair<int, int> koniec1 = bfsNajdalszy(drzewo, 0);
    pair<int, int> koniec2 = bfsNajdalszy(drzewo, koniec1.first);

    vector<int> poprzednik(n, -1);
    vector<int> odleglosc(n, -1);
    queue<int> kolejka;
    kolejka.push(koniec1.first);
    odleglosc[koniec1.first] = 0;

    while (!kolejka.empty())
    {
        int wezel = kolejka.front();
        kolejka.pop();
        for (int sasiad : drzewo[wezel].sasiedzi)
        {
            if (odleglosc[sasiad] == -1)
            {
                odleglosc[sasiad] = odleglosc[wezel] + 1;
                poprzednik[sasiad] = wezel;
                kolejka.push(sasiad);
            }
        }
    }
    vector<int> sciezka;
    int obecny = koniec2.first;
    while (obecny != -1)
    {
        sciezka.push_back(obecny);
        obecny = poprzednik[obecny];
    }
    return sciezka;
}

int main()
{
    int n;
    cout << "Podaj liczbe wierzcholkow: ";
    cin >> n;
    vector<Wezel> drzewo(n);
    for (int i = 0; i < n; i++)
    {
        drzewo[i].id = i;
    }
    cout << "Podaj " << n - 1 << " krawedzi w formacie u v:" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        drzewo[u].sasiedzi.push_back(v);
        drzewo[v].sasiedzi.push_back(u);
    }
    vector<int> najdluzszaSciezka = znajdzNajdluzszaSciezke(drzewo);
    int m = najdluzszaSciezka.size();
    cout << "Najdluzsza sciezka ma dlugosc: " << m - 1 << endl;
    cout << "Sciezka: ";
    for (int v : najdluzszaSciezka)
    {
        cout << v << " ";
    }
    cout << endl;
    if (m % 2 == 1)
    {
        cout << "Wierzcholek srodkowy: " << najdluzszaSciezka[m / 2] << endl;
    }
    else
    {
        cout << "Wierzcholki srodkowe: " << najdluzszaSciezka[m / 2 - 1] << " i " << najdluzszaSciezka[m / 2] << endl;
    }
    return 0;
}