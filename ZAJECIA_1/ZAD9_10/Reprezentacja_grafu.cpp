#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Graf
{
private:
    int liczba_wierzcholkow;
    int liczba_krawedzi;
    vector<vector<int>> macierz_sasiedztwa;
    vector<vector<int>> lista_sasiedztwa;
    vector<pair<int, int>> lista_krawedzi;
    vector<vector<int>> macierz_incydencji;

public:
    Graf(string nazwa_pliku)
    {
        ifstream plik(nazwa_pliku);
        if (!plik)
        {
            cerr << "Blad: Nie mozna otworzyc pliku " << nazwa_pliku << endl;
            exit(1);
        }

        // Wczytanie liczby wierzcholkow i krawedzi
        plik >> liczba_wierzcholkow >> liczba_krawedzi;

        // Inicjalizacja macierzy sasiedztwa i listy sasiedztwa
        macierz_sasiedztwa.resize(liczba_wierzcholkow, vector<int>(liczba_wierzcholkow, 0));
        lista_sasiedztwa.resize(liczba_wierzcholkow);
        macierz_incydencji.resize(liczba_wierzcholkow, vector<int>(liczba_krawedzi, 0));

        int v;
        int w;
        for (int i = 0; i < liczba_krawedzi; i++)
        {
            plik >> v >> w;
            v--;
            w--;
            lista_krawedzi.push_back({v, w});
            macierz_sasiedztwa[v][w] = 1;
            lista_sasiedztwa[v].push_back(w);
            macierz_incydencji[v][i] = -1;
            macierz_incydencji[w][i] = 1;
        }
        plik.close();
    }

    // Wypisanie macierzy sasiedztwa
    void wypiszMacierzSasiedztwa()
    {
        cout << "\nMacierz sasiedztwa:\n";
        for (const auto &wiersz : macierz_sasiedztwa)
        {
            for (int wartosc : wiersz)
            {
                cout << wartosc << " ";
            }
            cout << endl;
        }
    }

    // Wypisanie listy sasiedztwa
    void wypiszListeSasiedztwa()
    {
        cout << "\nLista sasiedztwa:\n";
        for (int i = 0; i < liczba_wierzcholkow; i++)
        {
            cout << i + 1 << ": ";
            for (int sasiad : lista_sasiedztwa[i])
            {
                cout << sasiad + 1 << " ";
            }
            cout << endl;
        }
    }

    // Wypisanie listy krawedzi
    void wypiszListeKrawedzi()
    {
        cout << "\nLista krawedzi:\n";
        for (auto krawedz : lista_krawedzi)
        {
            cout << "(" << krawedz.first + 1 << ", " << krawedz.second + 1 << ")" << endl;
        }
    }

    // Wypisanie macierzy incydencji
    void wypiszMacierzIncydencji()
    {
        cout << "\nMacierz incydencji:\n";
        for (const auto &wiersz : macierz_incydencji)
        {
            for (int wartosc : wiersz)
            {
                cout << wartosc << "\t";
            }
            cout << endl;
        }
    }

    // Wywolanie wszystkich metod wypisujacych
    void wypiszReprezentacje()
    {
        wypiszMacierzSasiedztwa();
        wypiszListeSasiedztwa();
        wypiszListeKrawedzi();
        wypiszMacierzIncydencji();
    }
};

int main()
{
    string nazwa_pliku = "dane.txt";
    Graf graf(nazwa_pliku);
    graf.wypiszReprezentacje();
    return 0;
}