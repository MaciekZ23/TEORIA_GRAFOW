"""Metoda Havla-Hakimiego ze zlozonoscia O(n²)"""
def havla_hakimi(stopnie):
    while True:
        #Sortowanie malejaco
        stopnie.sort(reverse=True)
        #Jesli wszystkie stopnie sa rowne 0, to graf istnieje
        if(stopnie[0] == 0):
            return True
        #Pobieramy najwiekszy stopien
        najwyzszy = stopnie.pop(0)
        #Warunek czy stopien nie jest zbytnio duzy
        if(najwyzszy > len(stopnie)):
            return False
        #Odejmujemy 1 od kolejnych elementow
        for i in range(najwyzszy):
            stopnie[i] = stopnie[i] - 1
            if(stopnie[i] < 0):
                return False

"""Metoda Erdosa-Gallai ze zlozonoscia O(n)"""
def erdos_gallai(stopnie):
    #Sortujemy malejaco
    stopnie.sort(reverse=True)
    suma_stopni = sum(stopnie)
    #Sprawdzenie parzystosci
    if(suma_stopni % 2 != 0):
        return False
    suma_lewa = 0
    n = len(stopnie)

    for k in range(1, n + 1):
        suma_lewa = suma_lewa + stopnie[k - 1]
        suma_prawa = k * (k - 1)
        for i in range(k, n):
            suma_prawa = suma_prawa + min(k, stopnie[i])

        #Jesli warunek nie zachodzi
        if(suma_lewa > suma_prawa):
            return False
    return True
    
liczba_wierzcholkow = int(input("Podaj liczbe wierzcholkow: "))
stopnie = list(map(int, input("Podaj stopnie wierzcholkow: ").split()))

print("\nWynik metody Havla-Hakimiego:", "CIAG JEST GRAFICZNY" if havla_hakimi(stopnie[:]) else "CIAG NIE JEST GRAFICZNY")
print("Wynik metody Erdosa-Gallai:", "CIAG JEST GRAFICZNY" if erdos_gallai(stopnie[:]) else "CIAG NIE JEST GRAFICZNY")