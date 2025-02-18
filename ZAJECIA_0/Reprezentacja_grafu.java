package ZAJECIA_0;
import java.util.*;

class Graf 
{
    private int wierzcholki;
    private int[][] macierzSasiedztwa;
    private List<List<Integer>> listaSasiedztwa;
    private List<int[]> listaKrawedzi;

    public Graf(int wierzcholki, int[][] krawedzie) 
    {
        this.wierzcholki = wierzcholki;
        this.macierzSasiedztwa = new int[wierzcholki][wierzcholki];
        this.listaSasiedztwa = new ArrayList<>();
        this.listaKrawedzi = new ArrayList<>();

        for(int i = 0; i < wierzcholki; i++) 
        {
            listaSasiedztwa.add(new ArrayList<>());
        }

        konwertuj(krawedzie);
    }

    private void konwertuj(int[][] krawedzie)
    {
        for(int[] krawedz : krawedzie) 
        {
            int u = krawedz[0] - 1;
            int v = krawedz[1] - 1;

            macierzSasiedztwa[u][v] = 1;
            macierzSasiedztwa[v][u] = 1;

            listaSasiedztwa.get(u).add(v + 1);
            listaSasiedztwa.get(v).add(u + 1);

            listaKrawedzi.add(new int[]{u + 1, v + 1});
        }
    }

    public void wypiszMacierzSasiedztwa() 
    {
        System.out.println("Macierz sasiedztwa:");
        for(int[] row : macierzSasiedztwa) 
        {
            for(int val : row) 
            {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public void wypiszListeSasiedztwa() 
    {
        System.out.println("Lista sasiedztwa:");
        for(int i = 0; i < wierzcholki; i++) 
        {
            System.out.println((i + 1) + ": " + listaSasiedztwa.get(i));
        }
    }

    public void wypiszListeKrawedzi() 
    {
        System.out.println("Lista krawedzi:");
        for(int[] krawedz : listaKrawedzi) 
        {
            System.out.println("(" + krawedz[0] + ", " + krawedz[1] + ")");
        }
    }
}

public class Reprezentacja_grafu 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Podaj liczbe wierzcholkow i krawedzi: ");
        int wierzcholki = scanner.nextInt();
        int liczbaKrawedzi = scanner.nextInt();

        int[][] krawedzie = new int[liczbaKrawedzi][2];

        System.out.println("Podaj krawedzie (u v):");
        for(int i = 0; i < liczbaKrawedzi; i++) 
        {
            krawedzie[i][0] = scanner.nextInt();
            krawedzie[i][1] = scanner.nextInt();
        }
        scanner.close();

        Graf graf = new Graf(wierzcholki, krawedzie);
        graf.wypiszMacierzSasiedztwa();
        graf.wypiszListeSasiedztwa();
        graf.wypiszListeKrawedzi();
    }
}
