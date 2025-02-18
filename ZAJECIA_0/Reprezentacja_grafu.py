class Graf:
    def __init__(self, wierzcholki, krawedzie):
        self.wierzcholki = wierzcholki
        self.krawedzie = krawedzie
        self.macierz_sasiedztwa = [[0] * wierzcholki for _ in range(wierzcholki)]
        self.lista_sasiedztwa = [[] for _ in range(wierzcholki)]
        self.lista_krawedzi = []
        self._konwertuj()

    def _konwertuj(self):
        for u, v in self.krawedzie:
            self.macierz_sasiedztwa[u - 1][v - 1] = 1
            self.macierz_sasiedztwa[v - 1][u - 1] = 1 
            
            self.lista_sasiedztwa[u - 1].append(v)
            self.lista_sasiedztwa[v - 1].append(u)
            
            self.lista_krawedzi.append((u, v))

    def wypisz_macierz_sasiedztwa(self):
        print("\nMacierz sąsiedztwa:")
        for wiersz in self.macierz_sasiedztwa:
            print(" ".join(map(str, wiersz)))

    def wypisz_liste_sasiedztwa(self):
        print("\nLista sąsiedztwa:")
        for i in range(self.wierzcholki):
            print(f"{i + 1}: {', '.join(map(str, self.lista_sasiedztwa[i]))}")

    def wypisz_liste_krawedzi(self):
        print("\nLista krawędzi:")
        for u, v in self.lista_krawedzi:
            print(f"({u}, {v})")


def main():
    wierzcholki, liczba_krawedzi = map(int, input("Podaj liczbę wierzchołków i krawędzi: ").split())
    krawedzie = []
    print("Podaj krawędzie (u v):")
    for _ in range(liczba_krawedzi):
        u, v = map(int, input().split())
        krawedzie.append((u, v))

    graf = Graf(wierzcholki, krawedzie)
    graf.wypisz_macierz_sasiedztwa()
    graf.wypisz_liste_sasiedztwa()
    graf.wypisz_liste_krawedzi()

if __name__ == "__main__":
    main()
