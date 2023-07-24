#ifndef menu_h
#define menu_h

#include <iostream>
#include <string>
#include <fstream>
#include "function.h"
using namespace std;
void menuSirkuit()
{
    cout << "==================== Menu Sirkuit ===========================\n";
    cout << "|              1. Losail                                    |" << endl; //Qatar
    cout << "|              2. Twin Ring Motegi                          |" << endl; //Jepang
    cout << "|              3. Sepang                                    |" << endl; //Malaysia
    cout << "|              4. Mandalika                                 |" << endl; //Indonesia
    cout << "|              5. Valencia                                  |" << endl; //Spanyol
    cout << "|              6. Philip Island                             |" << endl; //Australia
    cout << "|              7. San Misano                                |" << endl; //Italia
    cout << "|              8. TT Assen                                  |" << endl; //Belanda
    cout << "|              9. Silverstone                               |" << endl; //Inggris
    cout << "|              10. Sachsenring                              |" << endl; //Jerman
    cout << "==============================================================\n";
}
// fungsi untuk menampilkan menu utama
void tampilMenu()
{
    cout << "==================== Menu Pembalap ===========================\n";
    cout << "|              1. Tambah Data Pembalap                       |" << endl;
    cout << "|              2. Tampilkan Hasil Balapan                    |" << endl;
    cout << "|              3. Lihat juara Dunia                          |" << endl;
    cout << "|              4. Edit Data Pembalap                         |" << endl;
    cout << "|              5. Hapus Data Pembalap                        |" << endl;
    cout << "|              0. Keluar                                     |" << endl;
    cout << "==============================================================\n";
}


#endif


