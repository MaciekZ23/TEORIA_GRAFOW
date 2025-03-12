#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool czyIdentyczneGrafy(int liczba_wierzcholkow, vector<vector<int>> &graf1, vector<vector<int>> &graf2)
{
    if(graf1.size() != graf2.size())
    {
        return false;
    }
    for(int wierzcholek = 0; wierzcholek < liczba_wierzcholkow; wierzcholek++)
    {
        if(graf1[wierzcholek].size() != graf2[wierzcholek].size())
        {
            return false;
        }
        unordered_map<int, int> licznik;
        for(int sasiad : graf1[wierzcholek])
        {
            licznik[sasiad]++;
        }
        for(int sasiad : graf2[wierzcholek])
        {
            if(licznik[sasiad] == 0)
            {
                return false;
            }
            licznik[sasiad]--;
        }
    }
    return true;
}

int main()
{
    int liczba_wierzcholkow = 4;
    vector<vector<int>> graf1 = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    vector<vector<int>> graf2 = {{5, 2}, {0, 2}, {0, 1, 3}, {2}};
    cout << (czyIdentyczneGrafy(liczba_wierzcholkow, graf1, graf2) ? "Grafy sa identyczne" : "Grafy nie sa identyczne") << endl;
    return 0;
}