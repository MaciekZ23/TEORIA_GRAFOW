import numpy as np

class Graf:
    def __init__(self, nazwa_pliku):
        try:
            with open(nazwa_pliku, "r") as plik:
                linie = plik.readlines()
        except FileNotFoundError:
            print(f"Blad: Plik {nazwa_pliku} nie istnieje")
            exit(1)

        #Wczytanie liczby wierzcholkow i krawedzi
        self.liczba_wierzcholkow, self.liczba_krawedzi = map(int, linie[0].split())

        #Inicjalizacja reprezentacji grafu
        self.macierz_sasiedztwa = np.zeros((self.liczba_wierzcholkow, self.liczba_wierzcholkow), dtype=int)
        self.lista_sasiedztwa = [[] for _ in range(self.liczba_wierzcholkow)]
        self.lista_krawedzi = []
        self.macierz_incydencji = np.zeros((self.liczba_wierzcholkow, self.liczba_krawedzi), dtype=int)

        #Wczytanie krawedzi
        for i, linia in enumerate(linie[1:], start=0):
            v, w = map(int, linia.split())
            v -= 1 
            w -= 1
            self.lista_krawedzi.append((v, w))
            self.macierz_sasiedztwa[v][w] = 1  #Graf skierowany (v -> w)
            self.lista_sasiedztwa[v].append(w)
            self.macierz_incydencji[v][i] = -1  #Wierzcholek poczatkowy (-1)
            self.macierz_incydencji[w][i] = 1   #Wierzcholek koncowy (1)

    def wypisz_macierz_sasiedztwa(self):
        print("Macierz sasiedztwa:")
        print(self.macierz_sasiedztwa)

    def wypisz_liste_sasiedztwa(self):
        print("\nLista sasiedztwa:")
        for i, sasiedzi in enumerate(self.lista_sasiedztwa):
            print(f"{i + 1}: {', '.join(str(s+1) for s in sasiedzi)}")

    def wypisz_liste_krawedzi(self):
        print("\nLista krawedzi:")
        for (v, w) in self.lista_krawedzi:
            print(f"({v + 1}, {w + 1})")

    def wypisz_macierz_incydencji(self):
        print("\nMacierz incydencji:")
        print(self.macierz_incydencji)

    def wypisz_reprezentacje(self):
        self.wypisz_macierz_sasiedztwa()
        self.wypisz_liste_sasiedztwa()
        self.wypisz_liste_krawedzi()
        self.wypisz_macierz_incydencji()

if __name__ == "__main__":
    nazwa_pliku = r"D:\Maciek\PRZEDMIOTY SZKOLNE\TEORIA GRAFÓW\IMPLEMENTACJE ALGORYTMÓW\ZAJECIA_1\ZAD9_10\dane.txt"
    graf = Graf(nazwa_pliku)
    graf.wypisz_reprezentacje()
