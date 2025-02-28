#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Metoda Havla-Hakimiego ze zlozonoscia O(n²)
bool havlaHakimi(vector<int> stopnie)
{
    cout << "\nMetoda Havla-Hakimiego - KROKI:\n";
    while (true)
    {
        // Sortujemy malejaco
        sort(stopnie.rbegin(), stopnie.rend());
        cout << "Posortowany ciag: ";
        for (int s : stopnie)
        {
            cout << s << " ";
        }
        cout << endl;

        // Jesli wszystkie sa 0 to graf istnieje
        if (stopnie[0] == 0)
        {
            cout << "Wszystkie stopnie sa rowne 0 - graf istnieje\n";
            return true;
        }
        int najwyzszy = stopnie[0];
        // Usuwanie najwiekszego elementu
        stopnie.erase(stopnie.begin());
        cout << "Usuniety najwiekszy stopien: " << najwyzszy << endl;
        // Przypadek gdy stopien jest za duzy
        if (najwyzszy > stopnie.size())
        {
            cout << "Najwiekszy stopien " << najwyzszy << " wiekszy niz liczba pozostalych wierzcholkow - graf nie istnieje\n";
            return false;
        }
        for (int i = 0; i < najwyzszy; i++)
        {
            stopnie[i]--;
            if (stopnie[i] < 0)
            {
                cout << "Stopien wierzcholka nr " << i + 1 << " spadl ponizej 0 - graf nie istnieje\n";
                return false;
            }
        }
        cout << "Zaktualizowany ciag po odjeciu: ";
        for (int s : stopnie)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}

// Metoda Erdosa-Gallai ze zlozonoscia O(n)
bool erdosGallai(vector<int> stopnie)
{
    cout << "\nMetoda Erdosa-Gallai - KROKI:\n";
    // Sortujemy malejaco
    sort(stopnie.rbegin(), stopnie.rend());
    cout << "Posortowany ciag: ";
    for (int s : stopnie)
    {
        cout << s << " ";
    }
    cout << endl;
    int suma_stopni = accumulate(stopnie.begin(), stopnie.end(), 0);
    cout << "Suma stopni: " << suma_stopni << endl;
    // Suma stopni musi byc parzysta
    if (suma_stopni % 2 != 0)
    {
        cout << "Suma stopni jest nieparzysta - graf nie istnieje\n";
        return false;
    }
    int suma_lewa = 0;
    int suma_prawa = 0;
    int n = stopnie.size();
    for (int k = 1; k <= n; k++)
    {
        suma_lewa = suma_lewa + stopnie[k - 1];
        suma_prawa = k * (k - 1);
        for (int i = k; i < n; i++)
        {
            suma_prawa = suma_prawa + min(k, stopnie[i]);
        }
        cout << "Dla k=" << k << ": Suma_lewa = " << suma_lewa << ", Suma_prawa = " << suma_prawa << endl;
        // Jesli nie bedzie spelnialo warunku
        if (suma_lewa > suma_prawa)
        {
            cout << "Warunek sumowy nie jest spelniony - graf nie istnieje\n";
            return false;
        }
    }
    cout << "Warunki spelnione - graf istnieje\n";
    return true;
}

int main()
{
    vector<int> stopnie;
    int liczba_wierzcholkow;
    int stopien;
    cout << "Podaj liczbe wierzcholkow: ";
    cin >> liczba_wierzcholkow;
    cout << "Podaj stopnie wierzcholkow:\n";
    for (int i = 0; i < liczba_wierzcholkow; i++)
    {
        cin >> stopien;
        stopnie.push_back(stopien);
    }
    cout << (havlaHakimi(stopnie) ? "CIAG JEST GRAFICZNY" : "CIAG NIE JEST GRAFICZNY") << endl;
    cout << (erdosGallai(stopnie) ? "CIAG JEST GRAFICZNY" : "CIAG NIE JEST GRAFICZNY") << endl;
    return 0;
}
