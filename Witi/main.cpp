#include <iostream>
#include <fstream>
#include <vector>

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
        cout << "error" << endl;
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
    cout << "Num" << num << endl;
   cout << "N" << N << endl;

    return 0;
}

int ALG(std::vector < zadanie > zad, int N ) {
    int *tab_pom = new int[N * N];
    return 0;
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
        
        int N0 = 0;int N1 = 0;int N2 = 0;int N3 = 0;int N4 = 0;int N5 = 0;int N6 = 0;int N7 = 0;int N8 = 0;int N9 = 0;int N10 = 0;

        string str = "witi1.txt";
        wczytaj(zadania0, N0, str);
        str = "witi2.txt";
        wczytaj(zadania1, N1, str);
        str = "witi3.txt";
        wczytaj(zadania2, N2, str);
        str = "witi4.txt";
        wczytaj(zadania3, N3, str);
        str = "witi5.txt";
        wczytaj(zadania4, N4, str);
        str = "witi6.txt";
        wczytaj(zadania5, N5, str);
        str = "witi7.txt";
        wczytaj(zadania6, N6, str);
        str = "witi8.txt";
        wczytaj(zadania7, N7, str);
        str = "witi9.txt";
        wczytaj(zadania8, N8, str);
        str = "witi10.txt";
        wczytaj(zadania9, N9, str);
        str = "witi11.txt";
        wczytaj(zadania10, N10, str);

        /*for (int i = 0; i < N0; i++) // reads file to end of *file*, not line
        {
            cout << zadania0[i].p << " "; // read first column number
            cout << zadania0[i].w << " "; // read first column number
            cout << zadania0[i].d << " "; // read first column number
            cout << endl;

        }*/
        /*int* X;

        int czasMax = 0;
        X = new int[N1];
        czasMax += min(ALG1(N1, zadania1, X), min(ALG2(N1, zadania1, X), ALG3(N1, zadania1, X)));
        delete X;

        X = new int[N2];
        czasMax += min(ALG1(N2, zadania2, X), min(ALG2(N2, zadania2, X), ALG3(N2, zadania2, X)));
        delete X;

        X = new int[N3];
        czasMax += min(ALG1(N3, zadania3, X), min(ALG2(N3, zadania3, X), ALG3(N3, zadania3, X)));
        delete X;

        X = new int[N4];
        czasMax += min(ALG1(N4, zadania4, X), min(ALG2(N4, zadania4, X), ALG3(N4, zadania4, X)));
        delete X;
        cout << "Cmax" << czasMax << endl;

        return 0;
    }
    */


	//std::cout << "Hello world!" << std::endl;
}