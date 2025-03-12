package JAVA;
import java.util.*;

public class IdentyczneGrafy 
{
    public static boolean czyIdentyczneGrafy(List<List<Integer>> graf1, List<List<Integer>> graf2) 
    {
        if(graf1.size() != graf2.size()) 
        {
            return false;
        }

        for(int wierzcholek = 0; wierzcholek < graf1.size(); wierzcholek++) 
        {
            if (graf1.get(wierzcholek).size() != graf2.get(wierzcholek).size()) 
            {
                return false;
            }

            Map<Integer, Integer> licznik = new HashMap<>();
            for(int sasiad : graf1.get(wierzcholek)) 
            {
                licznik.put(sasiad, licznik.getOrDefault(sasiad, 0) + 1);
            }
            for(int sasiad : graf2.get(wierzcholek)) 
            {
                if(!licznik.containsKey(sasiad) || licznik.get(sasiad) == 0) 
                {
                    return false;
                }
                licznik.put(sasiad, licznik.get(sasiad) - 1);
            }
        }
        return true;
    }

    public static void main(String[] args) 
    {
        List<List<Integer>> graf1 = Arrays.asList(
            Arrays.asList(1, 2), Arrays.asList(0, 2), Arrays.asList(0, 1, 3), Arrays.asList(2)
        );
        List<List<Integer>> graf2 = Arrays.asList(
            Arrays.asList(1, 2), Arrays.asList(0, 2), Arrays.asList(0, 1, 3), Arrays.asList(2)
        );

        System.out.println(czyIdentyczneGrafy(graf1, graf2) ? "Grafy sa identyczne" : "Grafy nie sa identyczne");
    }
}
