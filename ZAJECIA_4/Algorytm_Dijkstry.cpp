#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int N = 9;

// Graf jako lista sasiedztwa
vector<pair<int, int>> graph[N];

void dijkstra(int start)
{
    vector<int> d(N, INF); // odleglosc od zrodla
    vector<int> f(N, 0);   // ojcowie
    vector<bool> visited(N, false);

    d[start] = 0;

    for (int krok = 1; krok <= 8; krok++)
    {
        int v = -1;
        for (int i = 1; i <= 8; i++)
        {
            if (!visited[i] && (v == -1 || d[i] < d[v]))
            {
                v = i;
            }
        }
        if (d[v] == INF)
        {
            break;
        }
        visited[v] = true;

        for (auto [u, w] : graph[v])
        {
            if (!visited[u] && d[u] > d[v] + w)
            {
                d[u] = d[v] + w;
                f[u] = v;
            }
        }

        cout << "Krok " << krok << ": " << endl;
        cout << "Odleglosc od zrodla:" << endl;
        for (int i = 1; i <= 8; i++)
        {
            if (d[i] == INF)
            {
                cout << "∞ ";
            }
            else
            {
                cout << d[i] << " ";
            }
        }
        cout << endl;
        cout << "Ojcowie - skad przyszlismy:" << endl;
        for (int i = 1; i <= 8; i++)
        {
            cout << f[i] << " ";
        }
        cout << "\n\n";
    }

    int cel = 5;
    if (d[cel] == INF)
    {
        cout << "Brak sciezki z " << start << " do " << cel << endl;
    }
    else
    {
        cout << "Najkrotsza sciezka z " << start << " do " << cel << ": ";
        vector<int> path;
        for (int v = cel; v != 0; v = f[v])
        {
            path.push_back(v);
        }
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i];
            if (i > 0)
            {
                cout << " -> ";
            }
        }
        cout << endl;
        cout << "Koszt sciezki: " << d[cel] << endl;
    }
}

int main()
{
    graph[2].push_back({1, 2});
    graph[1].push_back({2, 2});

    graph[1].push_back({3, 3});
    graph[3].push_back({1, 3});

    graph[1].push_back({4, 4});
    graph[4].push_back({1, 4});

    graph[1].push_back({6, 5});
    graph[6].push_back({1, 5});

    graph[3].push_back({7, 5});
    graph[7].push_back({3, 5});

    graph[3].push_back({5, 7});
    graph[5].push_back({3, 7});

    graph[4].push_back({5, 6});
    graph[5].push_back({4, 6});

    graph[4].push_back({8, 1});
    graph[8].push_back({4, 1});

    graph[4].push_back({6, 2});
    graph[6].push_back({4, 2});

    graph[5].push_back({7, 3});
    graph[7].push_back({5, 3});

    graph[5].push_back({8, 2});
    graph[8].push_back({5, 2});

    dijkstra(2);
    return 0;
}