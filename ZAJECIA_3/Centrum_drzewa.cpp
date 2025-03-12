#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Wezel
{
    int id;
    vector<int> sasiedzi;
};

vector<int> znajdzCentrumDrzewa(int n, vector<pair<int, int>> &krawedzie)
{
    vector<Wezel> drzewo(n);
    vector<int> stopien(n, 0);
    for (int i = 0; i < n; i++)
    {
        drzewo[i].id = i;
    }
    for (auto &krawedz : krawedzie)
    {
        int u = krawedz.first;
        int v = krawedz.second;
        drzewo[u].sasiedzi.push_back(v);
        drzewo[v].sasiedzi.push_back(u);
        stopien[u]++;
        stopien[v]++;
    }

    queue<int> lisci;
    for (int i = 0; i < n; i++)
    {
        if (stopien[i] == 1)
        {
            lisci.push(i);
        }
    }
    int pozostale = n;
    while (pozostale > 2)
    {
        int liczbaLisci = lisci.size();
        pozostale -= liczbaLisci;
        for (int i = 0; i < liczbaLisci; i++)
        {
            int lisc = lisci.front();
            lisci.pop();
            for (int sasiad : drzewo[lisc].sasiedzi)
            {
                stopien[sasiad]--;
                if (stopien[sasiad] == 1)
                {
                    lisci.push(sasiad);
                }
            }
        }
    }
    vector<int> centrum;
    while (!lisci.empty())
    {
        centrum.push_back(lisci.front());
        lisci.pop();
    }
    return centrum;
}

int main()
{
    int n;
    cout << "Podaj liczbe wierzcholkow: ";
    cin >> n;
    vector<pair<int, int>> krawedzie(n - 1);
    cout << "Podaj " << n - 1 << " krawedzi:" << endl;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> krawedzie[i].first >> krawedzie[i].second;
    }

    vector<int> centrum = znajdzCentrumDrzewa(n, krawedzie);
    cout << "Wierzcholki centralne: ";
    for (int v : centrum)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}