def czy_identyczne_grafy(graf1, graf2):
    if(len(graf1) != len(graf2)):
        return False
    
    for wierzcholek in range(len(graf1)):
        if(len(graf1[wierzcholek]) != len(graf2[wierzcholek])):
            return False
        licznik = {}
        for sasiad in graf1[wierzcholek]:
            licznik[sasiad] = licznik.get(sasiad, 0) + 1
        for sasiad in graf2[wierzcholek]:
            if(licznik.get(sasiad, 0) == 0):
                return False
            licznik[sasiad] -= 1
    return True

graf1 = [[1, 2], [0, 2], [0, 1, 3], [2]]
graf2 = [[1, 2], [0, 2], [0, 1, 3], [2]]

if(czy_identyczne_grafy(graf1, graf2)):
    print("Grafy sa identyczne")
else:
    print("Grafy nie sa identyczne")