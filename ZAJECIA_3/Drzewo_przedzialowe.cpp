#include <iostream>
#include <vector>

using namespace std;

class DrzewoPrzedzialowe
{
private:
    vector<int> drzewo;
    int rozmiar;

public:
    DrzewoPrzedzialowe(int n)
    {
        rozmiar = n;
        drzewo.resize(2 * n, 0);
    }

    void buduj(const vector<int> &dane)
    {
        for (int i = 0; i < rozmiar; i++)
        {
            drzewo[rozmiar + i] = dane[i];
        }
        for (int i = rozmiar - 1; i > 0; i--)
        {
            drzewo[i] = drzewo[2 * i] + drzewo[2 * i + 1];
        }
    }

    void aktualizuj(int pozycja, int wartosc)
    {
        int indeks = rozmiar + pozycja;
        drzewo[indeks] = wartosc;
        while (indeks > 1)
        {
            indeks /= 2;
            drzewo[indeks] = drzewo[2 * indeks] + drzewo[2 * indeks + 1];
        }
    }

    int sumaPrzedzialu(int a, int b)
    {
        int suma = 0;
        int va = rozmiar + a;
        int vb = rozmiar + b;
        suma += drzewo[va];
        if (va != vb)
        {
            suma += drzewo[vb];
        }
        while (va / 2 != vb / 2)
        {
            if (va % 2 == 0)
            {
                suma += drzewo[va + 1];
            }
            if (vb % 2 == 1)
            {
                suma += drzewo[vb - 1];
            }
            va /= 2;
            vb /= 2;
        }
        return suma;
    }
};

int main()
{
    int M, k;
    cout << "Podaj liczbe elementow i liczbe zapytan: ";
    cin >> M >> k;
    vector<int> dane(M);
    cout << "Podaj " << M << " liczb: ";
    for (int i = 0; i < M; i++)
    {
        cin >> dane[i];
    }
    DrzewoPrzedzialowe drzewo(M);
    drzewo.buduj(dane);
    cout << "Podaj " << k << " zapytan o przedzial (a, b): " << endl;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << "Suma na przedziale [" << a << ", " << b << "] = " << drzewo.sumaPrzedzialu(a, b) << endl;
    }
    return 0;
}