#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool czy_dwukolorowy(vector<vector<int>> &graf, int liczba_wierzcholkow)
{
    vector<int> kolor(liczba_wierzcholkow, -1);
    for(int start = 0; start < liczba_wierzcholkow; start++)
    {
        if(kolor[start] == -1)
        {
            queue<int> kolejka;
            kolejka.push(start);
            //Kolorujemy pierwszym kolorem
            kolor[start] = 0;

            while(!kolejka.empty())
            {
                int wierzcholek = kolejka.front();
                kolejka.pop();
                for(int sasiad : graf[wierzcholek])
                {
                    //Jeszcze nie pokolorowany 
                    if(kolor[sasiad] == -1)
                    {
                        //Kolor przeciwny
                        kolor[sasiad] = 1 - kolor[wierzcholek];
                        kolejka.push(sasiad);
                    }
                    //Konflikt kolorow
                    else if(kolor[sasiad] == kolor[wierzcholek])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int liczba_wierzcholkow, liczba_krawedzi;
    while(cin >> liczba_wierzcholkow) 
    {
        cin >> liczba_krawedzi;
        vector<vector<int>> graf(liczba_wierzcholkow);
        for(int i = 0; i < liczba_krawedzi; i++)
        {
            int u, v;
            cin >> u >> v;
            graf[u].push_back(v);
            graf[v].push_back(u);
        }
        if(czy_dwukolorowy(graf, liczba_wierzcholkow))
        {
            cout << "TAK";
        }
        else
        {
            cout << "NIE";
        }
        return 0;
    }
}