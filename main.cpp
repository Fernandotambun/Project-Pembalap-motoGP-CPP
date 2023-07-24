#include <iostream>
#include <string>
#include <fstream>

#include "function.h"
#include "menu.h"
using namespace std;


//kamus
int pilihan;
Pembalap pembalap ;

int main()
{

    do
    {

        tampilMenu();

        cout << "Masukkan pilihan (1-5): ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");
            cout << "=======================================" << endl;
            cout << "           Tambah Pembalap             " << endl;
            cout << "=======================================" << endl;
            pembalap.tambahPembalap();
            break;
        case 2:
            system("cls");
            cout << "=======================================" << endl;
            cout << "           Lihat Hasil Balapan       " << endl;
            cout << "=======================================" << endl;
            pembalap.lihatHasilBalapan();
            break;
        case 3:
            system("cls");
            cout << "=======================================" << endl;
            cout << "           Lihat Juara Dunia            " << endl;
            cout << "=======================================" << endl;
            pembalap.lihatJuaraDunia();
            break;
        case 4:
            system("cls");
            cout << "=======================================" << endl;
            cout << "              Edit Pembalap            " << endl;
            cout << "=======================================" << endl;
            pembalap.editPembalap();
            break;
        case 5:
            system("cls");
            cout << "=======================================" << endl;
            cout << "       Hapus Pembalap       " << endl;
            cout << "=======================================" << endl;
            pembalap.hapusPembalap();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

        cout << endl;
        cout << "Tekan enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");

    }
    while (pilihan != 0);

    return 0;
}

