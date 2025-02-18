#include <iostream>
#include <vector>

using namespace std;

class Graf 
{
private:
    int wierzcholki;
    vector<vector<int>> macierzSasiedztwa;
    vector<vector<int>> listaSasiedztwa;
    vector<pair<int, int>> listaKrawedzi;

public:
    Graf(int w, vector<pair<int, int>> krawedzie) 
    {
        wierzcholki = w;
        macierzSasiedztwa = vector<vector<int>>(w, vector<int>(w, 0));
        listaSasiedztwa = vector<vector<int>>(w);
        
        for(auto &krawedz : krawedzie) 
        {
            int u = krawedz.first - 1;
            int v = krawedz.second - 1;
            
            macierzSasiedztwa[u][v] = 1;
            macierzSasiedztwa[v][u] = 1;

            listaSasiedztwa[u].push_back(v + 1);
            listaSasiedztwa[v].push_back(u + 1);

            listaKrawedzi.push_back({u + 1, v + 1});
        }
    }

    void wypiszMacierzSasiedztwa() 
    {
        cout << "\nMacierz sasiedztwa:\n";
        for(const auto &row : macierzSasiedztwa) 
        {
            for(int val : row) 
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void wypiszListeSasiedztwa() 
    {
        cout << "\nLista sasiedztwa:\n";
        for(int i = 0; i < wierzcholki; i++) 
        {
            cout << (i + 1) << ": ";
            for(int sasiad : listaSasiedztwa[i]) 
            {
                cout << sasiad << " ";
            }
            cout << endl;
        }
    }

    void wypiszListeKrawedzi() 
    {
        cout << "\nLista krawedzi:\n";
        for(const auto &krawedz : listaKrawedzi) 
        {
            cout << "(" << krawedz.first << ", " << krawedz.second << ")\n";
        }
    }
};

int main() 
{
    int wierzcholki, liczbaKrawedzi;
    cout << "Podaj liczbe wierzcholkow i krawedzi: ";
    cin >> wierzcholki >> liczbaKrawedzi;

    vector<pair<int, int>> krawedzie;
    cout << "Podaj krawedzie (u v):\n";
    for(int i = 0; i < liczbaKrawedzi; i++) 
    {
        int u, v;
        cin >> u >> v;
        krawedzie.push_back({u, v});
    }

    Graf graf(wierzcholki, krawedzie);

    graf.wypiszMacierzSasiedztwa();
    graf.wypiszListeSasiedztwa();
    graf.wypiszListeKrawedzi();

    return 0;
}
