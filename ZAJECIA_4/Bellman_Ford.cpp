#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

using namespace std;

const int INF = numeric_limits<int>::max();
const int N = 6; // liczba wierzcholkow (s, a, b, c, d, x)

unordered_map<char, int> name = {{'s', 0}, {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'x', 5}};
char revName[N] = {'s', 'a', 'b', 'c', 'd', 'x'};

vector<pair<int, int>> graph[N]; // graf jako lista krawedzi

void bellman(char startChar)
{
    int start = name[startChar];
    vector<int> d(N, INF);
    vector<int> f(N, -1);
    vector<bool> inQueue(N, false);
    deque<int> q;
    d[start] = 0;
    q.push_back(start);
    inQueue[start] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        inQueue[u] = false;
        for (auto [v, w] : graph[u])
        {
            if (d[u] != INF && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                f[v] = u;
                if (!inQueue[v])
                {
                    if (!q.empty() && d[v] < d[q.front()])
                    {
                        q.push_front(v);
                    }
                    else
                    {
                        q.push_back(v);
                    }
                    inQueue[v] = true;
                }
            }
        }
    }

    cout << "Odleglosci od zrodla (" << startChar << "):\n";
    for (int i = 0; i < N; i++)
    {
        cout << revName[i] << ": ";
        if (d[i] == INF)
        {
            cout << "∞";
        }
        else
        {
            cout << d[i];
        }
        cout << endl;
    }

    cout << "\nOjcowie (skad przyszlismy):\n";
    for (int i = 0; i < N; i++)
    {
        cout << revName[i] << ": ";
        if (f[i] == -1)
        {
            cout << "-";
        }
        else
        {
            cout << revName[f[i]];
        }
        cout << endl;
    }

    char endChar = 'c';
    int end = name[endChar];

    cout << "\nNajkrotsza sciezka z " << startChar << " do " << endChar << ": ";
    if (d[end] == INF)
    {
        cout << "Brak sciezki" << endl;
    }
    else
    {
        vector<char> path;
        int v = end;
        vector<bool> visited(N, false);

        while (v != -1)
        {
            if (visited[v])
            {
                cout << "\nBlad: wykryto cykl podczas odtwarzania sciezki" << endl;
                return;
            }

            visited[v] = true;
            path.push_back(revName[v]);
            v = f[v];
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
        cout << "Koszt sciezki: " << d[end] << endl;
    }
}

int main()
{
    // s -> a (4), s -> x (5)
    graph[name['s']].push_back({name['a'], 4});
    graph[name['s']].push_back({name['x'], 5});

    // a -> b (5)
    graph[name['a']].push_back({name['b'], 5});

    // b -> c (6)
    graph[name['b']].push_back({name['c'], 6});

    // x -> a (-3), x -> d (7)
    graph[name['x']].push_back({name['a'], -3});
    graph[name['x']].push_back({name['d'], 7});

    // b -> d (2)
    graph[name['b']].push_back({name['d'], 2});

    bellman('s');
    return 0;
}