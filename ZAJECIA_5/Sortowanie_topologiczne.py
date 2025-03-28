from collections import deque

def sortowanie_topologiczne(n, graf):
    stopien_wejsciowy = [0] * n
    for sasiady in graf:
        for sasiad in sasiady:
            stopien_wejsciowy[sasiad] += 1
    
    kolejka = deque([i for i in range(n) if stopien_wejsciowy[i] == 0])
    wynik = []
    while kolejka:
        v = kolejka.popleft()
        wynik.append(v)
        for sasiad in graf[v]:
            stopien_wejsciowy[sasiad] -= 1
            if(stopien_wejsciowy[sasiad] == 0):
                kolejka.append(sasiad)
    
    print(" ".join(map(str, wynik)))

n = 7
graf = [[4, 2], [0, 4], [], [1], [2], [1, 4], [2]]
sortowanie_topologiczne(n, graf)
