package JAVA;
import java.io.*;
import java.util.*;

public class Reprezentacja_grafu
{
    private int liczbaWierzcholkow;
    private int liczbaKrawedzi;
    private int[][] macierzSasiedztwa;
    private List<List<Integer>> listaSasiedztwa;
    private List<int[]> listaKrawedzi;
    private int[][] macierzIncydencji;

    public Reprezentacja_grafu(String nazwaPliku) 
    {
        try(BufferedReader br = new BufferedReader(new FileReader(nazwaPliku))) 
        {
            String[] pierwszaLinia = br.readLine().split(" ");
            liczbaWierzcholkow = Integer.parseInt(pierwszaLinia[0]);
            liczbaKrawedzi = Integer.parseInt(pierwszaLinia[1]);

            //Inicjalizacja struktur danych
            macierzSasiedztwa = new int[liczbaWierzcholkow][liczbaWierzcholkow];
            listaSasiedztwa = new ArrayList<>();
            listaKrawedzi = new ArrayList<>();
            macierzIncydencji = new int[liczbaWierzcholkow][liczbaKrawedzi];

            for(int i = 0; i < liczbaWierzcholkow; i++) 
            {
                listaSasiedztwa.add(new ArrayList<>());
            }

            //Wczytywanie krawedzi z pliku
            for(int i = 0; i < liczbaKrawedzi; i++) 
            {
                String[] linia = br.readLine().split(" ");
                int v = Integer.parseInt(linia[0]) - 1;
                int w = Integer.parseInt(linia[1]) - 1;

                listaKrawedzi.add(new int[]{v, w});
                macierzSasiedztwa[v][w] = 1;
                listaSasiedztwa.get(v).add(w);
                macierzIncydencji[v][i] = -1;
                macierzIncydencji[w][i] = 1;
            }

        } 
        catch(IOException e) 
        {
            System.err.println("Blad: Nie mozna otworzyc pliku " + nazwaPliku);
            System.exit(1);
        }
    }

    public void wypiszMacierzSasiedztwa() 
    {
        System.out.println("Macierz sasiedztwa:");
        for(int[] wiersz : macierzSasiedztwa) 
        {
            for(int wartosc : wiersz) 
            {
                System.out.print(wartosc + " ");
            }
            System.out.println();
        }
    }

    public void wypiszListeSasiedztwa() 
    {
        System.out.println("\nLista sasiedztwa:");
        for(int i = 0; i < liczbaWierzcholkow; i++) 
        {
            System.out.print((i + 1) + ": ");
            for(int sasiad : listaSasiedztwa.get(i)) 
            {
                System.out.print((sasiad + 1) + " ");
            }
            System.out.println();
        }
    }

    public void wypiszListeKrawedzi() 
    {
        System.out.println("\nLista krawedzi:");
        for(int[] krawedz : listaKrawedzi) 
        {
            System.out.println("(" + (krawedz[0] + 1) + ", " + (krawedz[1] + 1) + ")");
        }
    }

    public void wypiszMacierzIncydencji() 
    {
        System.out.println("\nMacierz incydencji:");
        for(int[] wiersz : macierzIncydencji) 
        {
            for(int wartosc : wiersz) 
            {
                System.out.print(wartosc + "\t");
            }
            System.out.println();
        }
    }

    public void wypiszReprezentacje() 
    {
        wypiszMacierzSasiedztwa();
        wypiszListeSasiedztwa();
        wypiszListeKrawedzi();
        wypiszMacierzIncydencji();
    }

    public static void main(String[] args) 
    {
        String nazwaPliku = "dane.txt";
        Reprezentacja_grafu graf = new Reprezentacja_grafu(nazwaPliku);
        graf.wypiszReprezentacje();
    }
}
