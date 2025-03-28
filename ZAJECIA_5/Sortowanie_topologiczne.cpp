#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sortowanie_topologiczne(int n, vector<vector<int>> &graf)
{
    vector<int> stopien_wejsciowy(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int sasiad : graf[i])
        {
            stopien_wejsciowy[sasiad]++;
        }
    }
    cout << "Stopnie wejsciowe:" << endl;
    for (int i = 0; i < stopien_wejsciowy.size(); i++)
    {
        cout << stopien_wejsciowy[i] << " ";
    }
    cout << endl;
    queue<int> kolejka;
    for (int i = 0; i < n; i++)
    {
        if (stopien_wejsciowy[i] == 0)
        {
            kolejka.push(i);
        }
    }
    vector<int> wynik;
    while (!kolejka.empty())
    {
        int v = kolejka.front();
        kolejka.pop();
        wynik.push_back(v);

        for (int sasiad : graf[v])
        {
            stopien_wejsciowy[sasiad]--;
            if (stopien_wejsciowy[sasiad] == 0)
            {
                kolejka.push(sasiad);
            }
        }
    }
    cout << "Sortowanie topologiczne:" << endl;
    for (int v : wynik)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{
    int n = 7;
    // Przyklad z wykladu wziety
    vector<vector<int>> graf = {{4, 2}, {0, 4}, {}, {1}, {2}, {1, 4}, {2}};
    sortowanie_topologiczne(n, graf);
    return 0;
}
