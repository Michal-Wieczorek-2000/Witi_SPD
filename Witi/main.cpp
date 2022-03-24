#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

struct zadanie{
    int p=0;
    int w = 0;
    int d = 0;
    int nr_procesu;
};

/**************************************************************** Wczytanie *****************************************************/
int wczytaj(std::vector < zadanie > &zad, int &N, string str) {
    ifstream infile;
    int num = 0; // num must start at 0
    infile.open(str);// file containing numbers in 3 columns 
    if (infile.fail()) // checks to see if file opended 
    {
        std::cout << "error" << endl;
        return 1; // no point continuing if the file didn't open...
    }
    zadanie temp;
    infile >> N;

    //cout << "Do wykonania jest " << N1 << " zadan."<<endl;
    while (!infile.eof()) // reads file to end of *file*, not line
    {

        infile >> temp.p;
        infile >> temp.w;
        infile >> temp.d;

        ++num; // go to the next number
        temp.nr_procesu = num;

        zad.push_back(temp);

    }
    //zad.pop_back();
    infile.close();
    //cout << "Num" << num << endl;
    //cout << "N" << N << endl;

    return 0;
}

/*int C(string ciag_bitowy, std::vector < zadanie > zad) {
    int sum = 0;
    for(int i=0; i<ciag_bitowy.length(); i++)
    {
        if(ciag_bitowy[i] == '1')
        {
            sum += zad[ciag_bitowy.length() - i-1].p;
            std::cout << "Suma " << sum << endl;
        }
    }
    return sum;
}*/
/*
int Kara(int indeks, int C, std::vector < zadanie > zad) {
    if(C <= zad[indeks].d)
    {
        return 0;
    }
    else
    {
        return (C - zad[indeks].d)*zad[indeks].w;
    }
}
*/
/*string Inkrementuj_bitowe(string ciag_bitowy) {
    int i = 0;
    while(ciag_bitowy[ciag_bitowy.length() - i - 1]=='1')
    {
        ciag_bitowy[ciag_bitowy.length() - i - 1] = '0';
        i++;
    }
    
    ciag_bitowy[ciag_bitowy.length() - i -1] = '1';
    return ciag_bitowy;
}*/

/*int Bit_to_ind(string ciag_bitowy) {
    int index = 0;

    for (int i = 0; i < ciag_bitowy.length(); i++) { 
        if(ciag_bitowy[ciag_bitowy.length() - i - 1] == '1') index = index + pow(2, i);
        std::cout << index << endl;
    }
    return index;
}*/

/*int F(std::vector < zadanie > zad, std::vector < int >& F_tab) {
    string warunek;
    int liczba_wystapien=0;
    string ciag_bitowy;
    string stary_ciag;
    string nowy_ciag;

    for (int i = 0; i < zad.size(); i++) {
        ciag_bitowy += "0";
    }


    for (int i = 0; i < 2 ^ zad.size(); i++) {

        // Sprawdzamy liczbe wystepien 1
        for (int j = 0; j < ciag_bitowy.length(); j++)
        {
            if (ciag_bitowy[j] == '1')
            {
                liczba_wystapien++;
            }
        }

        int temp;
        // Glowna czesc funkcji
        if (i == 0)
        {
            F_tab.push_back(0);
            ciag_bitowy = Inkrementuj_bitowe(ciag_bitowy);
        }
        else
        {   
            for (int k = 0; k < liczba_wystapien; k++) {
                // Szukamy minimum z Funckji f
                // Trzeba do³o¿yc konwersje ciagu do inta
                // 
                if(liczba_wystapien == 1)
                {
                    temp = 0 + Kara(Bit_to_ind(ciag_bitowy), C(ciag_bitowy, zad), zad);   // F[0] zawsze 0
                }
                else
                {   
                    stary_ciag = ciag_bitowy;
                    int index = 0;
                    if (k == 0) {
                        // licz dla f o indkesie poiwstalym z pierwszej skreslonej
                        
                        while (stary_ciag[stary_ciag.length() - index - 1] == '1')
                        {
                            stary_ciag[stary_ciag.length() - index - 1] = '0';
                            index++;
                        }
                    }
                    else
                    {   
                        nowy_ciag = ciag_bitowy;
                        while (nowy_ciag[nowy_ciag.length() - index - 1] == '1')
                        {
                            nowy_ciag[nowy_ciag.length() - index - 1] = '0';
                            index++;
                        }
                        temp = min(F_tab[Bit_to_ind(nowy_ciag)] + Kara(index+1, C(ciag_bitowy, zad), zad), F_tab[Bit_to_ind(stary_ciag)] + Kara(Bit_to_ind(ciag_bitowy), C(ciag_bitowy, zad), zad));
                        stary_ciag = nowy_ciag;
                        // Zamien miejscami tego 1 i 0
                    }
                }
            }
            F_tab.push_back(temp);
            ciag_bitowy = Inkrementuj_bitowe(ciag_bitowy);
        }

    }
}*/
int F_func(std::vector < zadanie >zad)
{   
    int* F = new int[pow(2, zad.size()) ];
    F[0] = 0;
    for(int id = 1; id < pow(2, zad.size()) ; id++)
    {
        int c = 0;
        for(int i = 0,mask=1; i<zad.size(); i++, mask *= 2)
        {
            if (id & mask) {
                c += zad[i].p;
            }
        }

        F[id] = 9999;
        for (int i = 0, mask = 1; i < zad.size(); i++, mask *= 2)
        {   
            if (id & mask) {
                    F[id] = min( F[id], F[id - mask] + max(0, c - zad[i].d) * zad[i].w );
            }
        }
        //cout << "C = " << c << endl;
        //cout << F[id] << endl;
    }
 
    return F[ int( pow(2, zad.size()) ) - 1];
}


int main() {
        
        std::vector < zadanie > zadania0;
        std::vector < zadanie > zadania1;
        std::vector < zadanie > zadania2;
        std::vector < zadanie > zadania3;
        std::vector < zadanie > zadania4;
        std::vector < zadanie > zadania5;
        std::vector < zadanie > zadania6;
        std::vector < zadanie > zadania7;
        std::vector < zadanie > zadania8;
        std::vector < zadanie > zadania9;
        std::vector < zadanie > zadania10;
        std::vector < zadanie > zadania11;
        
        int N0 = 0;int N1 = 0;int N2 = 0;int N3 = 0;int N4 = 0;int N5 = 0;int N6 = 0;int N7 = 0;int N8 = 0;int N9 = 0;int N10 = 0; int N11 = 0;        

        string str = "witi0.txt";
        wczytaj(zadania0, N0, str);

        str = "witi1.txt";
        wczytaj(zadania1, N1, str);
        str = "witi2.txt";
        wczytaj(zadania2, N2, str);
        str = "witi3.txt";
        wczytaj(zadania3, N3, str);
        str = "witi4.txt";
        wczytaj(zadania4, N4, str);
        str = "witi5.txt";
        wczytaj(zadania5, N5, str);
        str = "witi6.txt";
        wczytaj(zadania6, N6, str);
        str = "witi7.txt";
        wczytaj(zadania7, N7, str);
        str = "witi8.txt";
        wczytaj(zadania8, N8, str);
        str = "witi9.txt";
        wczytaj(zadania9, N9, str);
        str = "witi10.txt";
        wczytaj(zadania10, N10, str);
        str = "witi11.txt";
        wczytaj(zadania11, N11, str);
        
        /*for (int i = 0; i < N0; i++) // reads file to end of *file*, not line
        {
            std::cout << zadania0[i].p << " "; // read first column number
            std::cout << zadania0[i].w << " "; // read first column number
            std::cout << zadania0[i].d << " "; // read first column number
            std::cout << endl;
        }*/

        cout << "Dla data.10 opt=" << F_func(zadania1) << endl;
        cout << "Dla data.11 opt=" << F_func(zadania2) << endl;
        cout << "Dla data.12 opt=" << F_func(zadania3) << endl;
        cout << "Dla data.13 opt=" << F_func(zadania4) << endl;
        cout << "Dla data.14 opt=" << F_func(zadania5) << endl;
        cout << "Dla data.15 opt=" << F_func(zadania6) << endl;
        cout << "Dla data.16 opt=" << F_func(zadania7) << endl;
        cout << "Dla data.17 opt=" << F_func(zadania8) << endl;
        cout << "Dla data.18 opt=" << F_func(zadania9) << endl;
        cout << "Dla data.19 opt=" << F_func(zadania10) << endl;
        cout << "Dla data.20 opt=" << F_func(zadania11) << endl;

        //std::cout << "Indeks przed inkrem" << Bit_to_ind(ciag_bitowy)<<endl;
        //std::cout<< (ciag_bitowy = "0101") << endl;
        //std::cout << "Indeks po inkrem" << Bit_to_ind(ciag_bitowy)<<endl;

	//std::cout << "Hello world!" << std::endl;
}