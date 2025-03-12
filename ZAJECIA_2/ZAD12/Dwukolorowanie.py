import sys
from collections import deque

def czy_dwukolorowy(graf, liczba_wierzcholkow):
    kolor = [-1] * liczba_wierzcholkow  
    
    for poczatek in range(liczba_wierzcholkow):
        #Jesli wierzcholek nie jest jeszcze pokolorowany
        if(kolor[poczatek] == -1):  
            kolejka = deque([poczatek])
            #Kolorujemy pierwszym kolorem
            kolor[poczatek] = 0  
            
            while kolejka:
                wierzcholek = kolejka.popleft()
                for sasiad in graf[wierzcholek]:
                    #Jeszcze nie pokolorowany
                    if(kolor[sasiad]) == -1:  
                        #Kolor przeciwny
                        kolor[sasiad] = 1 - kolor[wierzcholek]  
                        kolejka.append(sasiad)
                    #Konflikt kolorow
                    elif(kolor[sasiad] == kolor[wierzcholek]):  
                        return False
    return True

def main():
    liczba_wierzcholkow = int(sys.stdin.readline().strip())
    liczba_krawedzi = int(sys.stdin.readline().strip())

    graf = [[] for _ in range(liczba_wierzcholkow)]

    for _ in range(liczba_krawedzi):
        u, v = map(int, sys.stdin.readline().split())
        graf[u].append(v)
        graf[v].append(u) 

    if(czy_dwukolorowy(graf, liczba_wierzcholkow)):
        print("TAK")
    else:
        print("NIE")

if __name__ == "__main__":
    main()
