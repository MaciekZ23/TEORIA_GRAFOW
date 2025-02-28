package JAVA;
import java.util.*;

public class Ciagi_graficzne
{
    //Metoda Havla-Hakimiego ze zlozonoscia O(n²)
    public static boolean havlaHakimi(List<Integer> stopnie)
    {
        while(true)
        {
            //Sortujemy malejaco
            Collections.sort(stopnie, Collections.reverseOrder());
            //Jesli wszystkie stopnie sa rowne 0 to graf istnieje
            if(stopnie.get(0) == 0)
            {
                return true;
            }
            int najwyzszy = stopnie.get(0);
            stopnie.remove(0);
            //Warunek gdy stopien jest za duzy
            if(najwyzszy > stopnie.size())
            {
                return false;
            }
            //Zmniejszanie stopni wierzcholkow
            for(int i = 0; i < najwyzszy; i++)
            {
                stopnie.set(i, stopnie.get(i) - 1);
                if(stopnie.get(i) < 0)
                {
                    return false;
                }
            }
        }
    }

    //Metoda Erdosa-Gallai ze zlozonoscia O(n)
    public static boolean erdosGallai(List<Integer> stopnie)
    {
        //Sortujemy malejaco
        Collections.sort(stopnie, Collections.reverseOrder());
        int suma_stopni = stopnie.stream().mapToInt(Integer::intValue).sum();
        //Suma stopni musi byc parzysta
        if(suma_stopni % 2 != 0)
        {
            return false;
        }
        int sumaLewa = 0;
        int sumaPrawa;
        int n = stopnie.size();
        for(int k = 1; k <= n; k++)
        {
            sumaLewa = sumaLewa + stopnie.get(k - 1);
            sumaPrawa = k * (k - 1);
            for(int i = k; i < n; i++)
            {
                sumaPrawa = sumaPrawa + Math.min(k, stopnie.get(i));
            }
            if(sumaLewa > sumaPrawa)
            {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Podaj liczbe wierzcholkow: ");
        int liczbaWierzcholkow = scanner.nextInt();
        List<Integer> stopnie = new ArrayList<>();
        for(int i = 0; i < liczbaWierzcholkow; i++)
        {
            stopnie.add(scanner.nextInt());
        }
        System.out.println("\nWynik metody Havla-Hakimiego: " + (havlaHakimi(new ArrayList<>(stopnie)) ? "CIAG JEST GRAFICZNY" : "CIAG NIE JEST GRAFICZNY"));
        System.out.println("Wynik metody Erdosa-Gallai: " + (erdosGallai(new ArrayList<>(stopnie)) ? "CIAG JEST GRAFICZNY" : "CIAG NIE JEST GRAFICZNY"));
        scanner.close();
    }
}