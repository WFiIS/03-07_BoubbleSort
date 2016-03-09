#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

void Fill(double *&tabela, long *rozmiar, double zakres);
void Print(double *tabela, long rozmiar);
long Search(double *tabela, long rozmiar, double liczba, long *operacji);
long BinSearch(double *tabela, long rozmiar, double liczba, long *operacji);
void Boubblesort(double *tabela, long rozmiar, long *operacji);

void F1();

int main() {
    srand(100);

    F1();

    return 0;
}

void Fill(double *&tabela, long *rozmiar, double zakres) {
    tabela = new double[*rozmiar];
    for (long i = 0; i < *rozmiar; i++) {
        double a = zakres * rand() / RAND_MAX;
        *(tabela + i) = a;
    }
}

void Print(double *tabela, long rozmiar) {
    for (long i = 0; i < rozmiar; i++) {
        cout << *(tabela + i) << endl;
    }
}

long Search(double *tabela, long rozmiar, double liczba, long *operacji) {
    long index = 0;

    for (long i = 1; i < rozmiar; i++) {
        if (abs(*(tabela + i) - liczba) < abs(*(tabela + index) - liczba)) {
            index = i;
        }

        *operacji += 1;
    }

    return index;
}

void Boubblesort(double *tabela, long rozmiar, long *operacji) {
    *operacji = 0;

    for (long i = 0; i < rozmiar - 1; i++) {
        for (long j = 0; j < rozmiar - i - 1; j++) {
            if (*(tabela + j) < *(tabela + j + 1)) {
                double a = *(tabela + j + 1);
                *(tabela + j + 1) = *(tabela + j);
                *(tabela + j) = a;
            }

            *operacji += 1;
        }
    }
}

long BinSearch(double *tabela, long rozmiar, double liczba, long *operacji) {
    *operacji = 0;
    long index = 0;
    long indexMin = 0;
    long indexMax = rozmiar;

    while (indexMax - indexMin > 1) {
        index = (indexMin + indexMax) / 2;
        if (liczba <= tabela[index]) {
            indexMin = index;
        } else {
            indexMax = index;
        }

        *operacji += 1;
    }

    index = fabs(tabela[indexMin] - liczba) < fabs(tabela[indexMax] - liczba) ? indexMin : indexMax;

    *operacji += 1;

    return index;
}

void F1() {
    double *tab;
    long rozmiar0 = 10;
    long *rozmiar = &rozmiar0;

    long liczbaPorownan0 = 0;
    long *liczbaPorownan = &liczbaPorownan0;

    Fill(tab, rozmiar, 20.0);

    cout << "Rozmiar wygenerowanej tabeli: " << rozmiar0 << endl;
    cout << "Element najblizszy 7.5: " << tab[Search(tab, rozmiar0, 7.5, liczbaPorownan)] << endl;
    cout << "Liczba porownan: " << *liczbaPorownan << endl;
    cout << endl << endl;

    cout << "Tablica po sortowaninu: " << endl;
    Boubblesort(tab, rozmiar0, liczbaPorownan);
    Print(tab, rozmiar0);
    cout << "Liczba porownan: " << *liczbaPorownan << endl;
    cout << endl << endl;

    cout << "Element najblizszy (binarnie) 7.5: " << tab[BinSearch(tab, rozmiar0, 7.5, liczbaPorownan)] << endl;
    cout << "Liczba porownan: " << *liczbaPorownan << endl;
    cout << endl << endl;
}
