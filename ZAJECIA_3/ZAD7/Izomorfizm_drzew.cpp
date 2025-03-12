#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Wezel
{
    int id;
    vector<Wezel *> dzieci;
};

// Funkcja przypisujaca indeksy wierzcholkom na podstawie struktury drzewa
int przypiszIndeks(Wezel *korzen, map<multiset<int>, int> &mapaIndeksow, int &biezacyIndeks)
{
    if (!korzen)
    {
        return -1;
    }
    multiset<int> indeksyDzieci;
    for (Wezel *dziecko : korzen->dzieci)
    {
        indeksyDzieci.insert(przypiszIndeks(dziecko, mapaIndeksow, biezacyIndeks));
    }

    if (mapaIndeksow.find(indeksyDzieci) == mapaIndeksow.end())
    {
        mapaIndeksow[indeksyDzieci] = biezacyIndeks++;
    }
    return mapaIndeksow[indeksyDzieci];
}

// Funkcja sprawdzajaca czy dwa drzewa sa izomorficzne
bool czyIzomorficzne(Wezel *korzen1, Wezel *korzen2)
{
    map<multiset<int>, int> mapaIndeksow;
    int biezacyIndeks = 0;
    return przypiszIndeks(korzen1, mapaIndeksow, biezacyIndeks) == przypiszIndeks(korzen2, mapaIndeksow, biezacyIndeks);
}

// Funkcja tworzaca drzewo na podstawie listy krawedzi
Wezel *zbudujDrzewo(vector<pair<int, int>> &krawedzie, int idKorzenia)
{
    map<int, Wezel *> wezly;
    for (auto &krawedz : krawedzie)
    {
        if (wezly.find(krawedz.first) == wezly.end())
        {
            wezly[krawedz.first] = new Wezel{krawedz.first};
        }
        if (wezly.find(krawedz.second) == wezly.end())
        {
            wezly[krawedz.second] = new Wezel{krawedz.second};
        }
        wezly[krawedz.first]->dzieci.push_back(wezly[krawedz.second]);
    }
    return wezly[idKorzenia];
}

int main()
{
    vector<pair<int, int>> krawedzie1 = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}};
    vector<pair<int, int>> krawedzie2 = {{10, 20}, {10, 30}, {20, 40}, {20, 50}, {30, 60}, {30, 70}};

    Wezel *korzen1 = zbudujDrzewo(krawedzie1, 1);
    Wezel *korzen2 = zbudujDrzewo(krawedzie2, 10);

    if (czyIzomorficzne(korzen1, korzen2))
    {
        cout << "Drzewa sa izomorficzne" << endl;
    }
    else
    {
        cout << "Drzewa nie sa izomorficzne" << endl;
    }
    return 0;
}