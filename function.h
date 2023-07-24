#ifndef function_h
#define function_h

#include <iostream>
#include <fstream> // untuk file handling
#include <string> // untuk fungsi-fungsi string
#include <iomanip> // untuk fungsi setw
#include <algorithm> // untuk mengurutkan data pembalap
#include <vector>
#include "menu.h"
using namespace std;

// Konstanta untuk nama file
const string namaFile[10] =
{
    "Losail.txt",       // Losail, Qatar
    "TwinRingMotegi.txt", // Twin Ring Motegi, Jepang
    "Sepang.txt",       // Sepang, Malaysia
    "Mandalika.txt",    // Mandalika, Indonesia
    "Valencia.txt",     // Valencia, Spanyol
    "PhilipIsland.txt", // Philip Island, Australia
    "SanMisano.txt",    // San Misano, Italia
    "TTAssen.txt",      // TT Assen, Belanda
    "Silverstone.txt",  // Silverstone, Inggris
    "Sachsenring.txt"   // Sachsenring, Jerman
};
const int lap = 20;
const int panjangSirkuit[10] = {5, 5, 5, 4, 4,6,7,8,9,4};
const int point[10] = {25, 20, 16, 13, 11, 10, 9, 8, 7, 6};

// Membaca data pembalap dari file dan menyimpannya ke array
const int MAX = 1000;

class Motor
{
private:
    string merek;
    string warna;
    //blm tau apa lagi

};

class Balapan
{
public:
    string tanggal;
    int lap;


};

class Sirkuit
{
private:
    string namaSirkuit;
    string lokasi;
    int panjangSirkuit;
    int point;

};


class Pembalap
{
public :
    int nomorUrut; // Menambahkan variabel untuk nomor urut
    string namaPembalap;
    string namaTim;
    string negara;
    int nomorPembalap;
    int jam,menit,detik;
    int point;
    int sPoint;


    // Fungsi untuk menghitung point berdasarkan posisi finish
    void hitungPoint(int posisi)
    {
        if (posisi <= 10)
        {
            point = ::point[posisi - 1];
        }
        else
        {
            point = 0;
        }
    }
    void tambahPembalap()
    {
        int nomor = 1;

        // Membaca nomor terakhir dari semua file sirkuit
        for (int i = 0; i < 10; i++)
        {
            ifstream fin;
            fin.open(namaFile[i]);

            string line;
            while (getline(fin, line))
            {
                nomor++;
            }

            fin.close();
        }

        // Menggunakan variabel nomor sebagai nomor urut auto increment
        nomorUrut = nomor;
ulang:
        cout << "Masukkan nama pembalap: ";
        cin.ignore();
        getline(cin, namaPembalap);
        cout << "Masukkan nama tim: ";
        getline(cin, namaTim);
        cout << "Masukkan negara: ";
        getline(cin, negara);
        cout << "Masukkan nomor pembalap: ";
        cin >> nomorPembalap;
        cout << "Masukkan jam: ";
        cin >> jam;
        if (jam > 23 || jam < 0)
        {
            cout << "Inputan tidak valid" << endl;
            goto ulang;
        }
        cout << "Masukkan menit: ";
        cin >> menit;
        if (menit > 59 || menit < 0)
        {
            cout << "Inputan tidak valid" << endl;
            goto ulang;
        }
        cout << "Masukkan detik: ";
        cin >> detik;
        if (detik > 59 || detik < 0)
        {
            cout << "Inputan tidak valid" << endl;
            goto ulang;
        }

        menuSirkuit();
        int pilihan;
        cin >> pilihan;
// Mengecek apakah pilihan sirkuit valid atau tidak
        if (pilihan < 1 || pilihan > 10)
        {
            cout << "Pilihan tidak valid\n";
            return; // Keluar dari fungsi
        }

        // Membuka file dengan nama yang sesuai berdasarkan pilihan sirkuit
        ofstream file(namaFile[pilihan - 1], ios::app);

        // Menulis data pembalap ke file dengan menambahkan nomor urut
        file << "|" << nomorUrut << "|" << namaPembalap << "|" << namaTim << "|" << negara << "|" << nomorPembalap << "|" << jam << ":" << menit << ":" << detik << "|" << "\n";

        file.close();

        cout << "Data berhasil ditambahkan." << endl;
    }

// Fungsi untuk menghitung total waktu dalam detik
    int totalWaktu()
    {
        return jam * 3600 + menit * 60 + detik;
    }

// Fungsi untuk menampilkan data pembalap dengan format tertentu
    void tampilData()
    {
        cout << "|" // Menampilkan nomor urut sebagai nomor pertama
             << setw(5) << nomorUrut << "|"
             // Menampilkan nomor pembalap sebagai nomor kedua
             << setw(5) << nomorPembalap << "|" << setw(20) << namaPembalap << "|" << setw(15) << namaTim << "|" << setw(10) << negara << "|" << setw(10) << jam << ":" << menit << ":" << detik << "|"
             "\n";
    }

// Fungsi untuk menampilkan data pembalap dengan format tertentu dan gap waktu dengan pembalap pertama
    void tampilDataGap(int gap)
    {
        cout << "|" // Menampilkan nomor urut sebagai nomor pertama
             << setw(5) << nomorUrut << "|"
             // Menampilkan nomor pembalap sebagai nomor kedua
             << setw(5) << nomorPembalap << "|" << setw(20) << namaPembalap << "|" << setw(15) << namaTim << "|" << setw(10) << negara << "|" << setw(10) << jam << ":" << menit << ":" << detik << "|"
             // Menampilkan gap waktu dengan format +mm:ss
             // Jika gap lebih dari 60 detik, maka tambahkan menit
             // Jika gap kurang dari 10 detik, maka tambahkan 0 di depan
             // Jika gap sama dengan 0, maka tampilkan kosong
             << setw(10) << (gap > 0 ? "+" : "") << (gap >= 60 ? to_string(gap / 60) + ":" : "") << (gap % 60 < 10 && gap >= 60 ? "0" : "") << (gap > 0 ? to_string(gap % 60) : "") << "|"
             "\n";
    }

// Fungsi untuk menampilkan info pembalap dengan data tambahan seperti konsumsi bensin dan waktu balapan
    void tampilInfo()
    {
        cout << "Nama pembalap: " << namaPembalap << "\n";
        cout << "Nama tim: " << namaTim << "\n";
        cout << "Negara: " << negara << "\n";
        cout << "Nomor pembalap: " << nomorPembalap << "\n";
        cout << "Waktu balapan: " << jam << ":" << menit << ":" << detik << "\n";
        // Menghitung konsumsi bensin dengan asumsi rata-rata 5 liter per lap
        // dan panjang sirkuit sesuai dengan pilihan sirkuit
        double konsumsi = 5.0 * lap / (panjangSirkuit[nomorUrut - 1] * 0.001);
        cout << "Konsumsi bensin: " << fixed << setprecision(2) << konsumsi << " liter/100 km\n";
    }

    void lihatHasilBalapan()
    {
        menuSirkuit();
        int pilihan;
        cin >> pilihan;

        // Mengecek apakah pilihan sirkuit valid atau tidak
        if (pilihan < 1 || pilihan > 10)
        {
            cout << "Pilihan tidak valid\n";
            return; // Keluar dari fungsi
        }

        // Membuka file dengan nama yang sesuai berdasarkan pilihan sirkuit
        ifstream file(namaFile[pilihan - 1]);

        // Membuat array untuk menyimpan data pembalap
        Pembalap data[MAX];
        int n = 0;

        // Membaca setiap baris dari file dan memasukkan data ke array
        string line;
        while (getline(file, line))
        {
            // Membuat objek pembalap baru
            Pembalap p;

            // Menggunakan metode yang Anda berikan untuk memisahkan data berdasarkan karakter '|'
            int pos;
            line.erase(0, 1); // Membuang karakter '|' pertama

            // Membaca nomor urut dan menyimpannya ke objek
            pos = line.find('|');
            p.nomorUrut = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            // Membaca nama pembalap dan menyimpannya ke objek
            pos = line.find('|');
            p.namaPembalap = line.substr(0, pos);
            line.erase(0, pos + 1);

            // Membaca nama tim dan menyimpannya ke objek
            pos = line.find('|');
            p.namaTim = line.substr(0, pos);
            line.erase(0, pos + 1);

            // Membaca negara dan menyimpannya ke objek
            pos = line.find('|');
            p.negara = line.substr(0, pos);
            line.erase(0, pos + 1);

            // Membaca nomor pembalap dan menyimpannya ke objek
            pos = line.find('|');
            p.nomorPembalap = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            // Membaca waktu balapan dan menyimpannya ke objek
            pos = line.find('|');
            // Menggunakan stringstream lagi untuk memisahkan waktu berdasarkan karakter ':'
            stringstream st(line.substr(0, pos));
            string waktu;
            getline(st, waktu, ':');
            p.jam = stoi(waktu);
            getline(st, waktu, ':');
            p.menit = stoi(waktu);
            getline(st, waktu, ':');
            p.detik = stoi(waktu);

            // Menambahkan fungsi untuk menghitung point berdasarkan posisi finish
            p.hitungPoint(p.nomorUrut);

            bool found = false;
        for (int j = 0; j < n; j++) {
            if (data[j].nomorPembalap == p.nomorPembalap) {
                data[j].point += p.point;
                found = true;
                break;
            }
        }

        if (!found) {
            data[n] = p;
            n++;
        }
        }

        file.close();

        // Mengurutkan data pembalap berdasarkan total waktu menggunakan bubble sort
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (data[j].totalWaktu() > data[j + 1].totalWaktu())
                {
                    // Menukar data pembalap yang tidak terurut
                    Pembalap temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }

        // Menampilkan nama sirkuit, tanggal, lap, dan point
        cout << "Nama sirkuit: " << namaFile[pilihan - 1].substr(0, namaFile[pilihan - 1].length() - 4) << "\n"; // Menghapus ekstensi .txt dari nama file
        cout << "Tanggal: 01/01/2021\n"; // Asumsi tanggal sama untuk semua sirkuit
        cout << "Lap: " << lap << "\n";

        // Menampilkan data pembalap dengan format tabel dan gap waktu
        cout << "-----------------------------------------------------------------------\n";
        cout << "| No. | No.P | Nama Pembalap | Nama Tim | Negara | Waktu | Gap | Point |\n";
        cout << "-----------------------------------------------------------------------\n";
        for (int i = 0; i < n; i++) {
        if (i == 0) {
            data[i].tampilDataGap(0);
            cout << setw(10) << data[i].point << "|\n";
        } else {
            int gap = data[i].totalWaktu() - data[0].totalWaktu();
            data[i].tampilDataGap(gap);
            cout << setw(10) << data[i].point << "|\n";
        }
    }
        cout << "-----------------------------------------------------------------------\n";

        // Menanyakan apakah ingin kembali ke menu atau melihat info pembalap
        cout << "Apakah Anda ingin kembali ke menu atau melihat info pembalap?\n";
        cout << "1. Kembali ke menu\n";
        cout << "2. Lihat info pembalap\n";
        int pilihan2;
        cin >> pilihan2;

        if (pilihan2 == 1)
        {
            return; // Keluar dari fungsi
        }
        else if (pilihan2 == 2)
        {
            // Menanyakan nomor pembalap yang ingin dilihat info nya
            cout << "Masukkan nomor pembalap yang ingin dilihat info nya: ";
            int nomor;
            cin >> nomor;

            // Mencari pembalap dengan nomor yang sesuai di array data
            Pembalap p;
            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (data[i].nomorPembalap == nomor)
                {
                    p = data[i]; // Menyimpan pembalap yang ditemukan ke variabel p
                    found = true;
                    break;
                }
            }

            if (found)
            {
                // Menampilkan info pembalap dengan data tambahan
                p.tampilInfo();
            }
            else
            {
                // Jika tidak ada pembalap dengan nomor yang sesuai, maka tampilkan pesan error
                cout << "Pembalap dengan nomor " << nomor << " tidak ada di sirkuit ini.\n";
            }
        }
        else
        {
            cout << "Pilihan tidak valid\n";
        }
    }

// Fungsi untuk menampilkan juara dunia berdasarkan total point dari semua sirkuit
    void lihatJuaraDunia()
    {
        // Membuat array untuk menyimpan data pembalap dari semua sirkuit
        Pembalap data[MAX];
        int n = 0;

        // Melakukan loop untuk setiap file sirkuit
        for (int k = 0; k < 10; k++)
        {
            // Membuka file dengan nama yang sesuai
            ifstream file(namaFile[k]);

            // Membaca setiap baris dari file dan memasukkan data ke array
            string line;
            while (getline(file, line))
            {
                // Membuat objek pembalap baru
                Pembalap p;

                // Menggunakan metode yang Anda berikan untuk memisahkan data berdasarkan karakter '|'
                int pos;
                line.erase(0, 1); // Membuang karakter '|' pertama

                // Membaca nomor urut dan menyimpannya ke objek
                pos = line.find('|');
                p.nomorUrut = stoi(line.substr(0, pos));
                line.erase(0, pos + 1);

                // Membaca nama pembalap dan menyimpannya ke objek
                pos = line.find('|');
                p.namaPembalap = line.substr(0, pos);
                line.erase(0, pos + 1);

                // Membaca nama tim dan menyimpannya ke objek
                pos = line.find('|');
                p.namaTim = line.substr(0, pos);
                line.erase(0, pos + 1);

                // Membaca negara dan menyimpannya ke objek
                pos = line.find('|');
                p.negara = line.substr(0, pos);
                line.erase(0, pos + 1);

                // Membaca nomor pembalap dan menyimpannya ke objek
                pos = line.find('|');
                p.nomorPembalap = stoi(line.substr(0, pos));
                line.erase(0, pos + 1);

                // Membaca waktu balapan dan menyimpannya ke objek
                pos = line.find('|');
                // Menggunakan stringstream lagi untuk memisahkan waktu berdasarkan karakter ':'
                stringstream st(line.substr(0, pos));
                string waktu;
                getline(st, waktu, ':');
                p.jam = stoi(waktu);
                getline(st, waktu, ':');
                p.menit = stoi(waktu);
                getline(st, waktu, ':');
                p.detik = stoi(waktu);

                // Menambahkan fungsi untuk menghitung point berdasarkan posisi finish
                p.hitungPoint(p.nomorUrut);

                // Mengecek apakah pembalap sudah ada di array data atau belum
                bool found = false;
                for (int i = 0; i < n; i++)
                {
                    if (data[i].nomorPembalap == p.nomorPembalap)
                    {
                        // Jika pembalap sudah ada, maka tambahkan point nya dengan point dari sirkuit ini
                        data[i].point += p.point;
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    // Jika pembalap belum ada, maka tambahkan pembalap ke array data
                    data[n] = p;
                    n++;
                }
            }

            file.close();
        }

        // Mengurutkan data pembalap berdasarkan total point menggunakan bubble sort
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (data[j].point < data[j + 1].point)
                {
                    // Menukar data pembalap yang tidak terurut
                    Pembalap temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }

        // Menampilkan juara dunia dengan format tabel
        cout << "-----------------------------------------------------------------------\n";
        cout << "| No. | No.P | Nama Pembalap | Nama Tim | Negara | Point |\n";
        cout << "-----------------------------------------------------------------------\n";
        for (int i = 0; i < n; i++)
        {
            cout << "|" << setw(5) << i + 1 // Menampilkan nomor urut berdasarkan peringkat point
                 << "|" << setw(5) << data[i].nomorPembalap << "|" << setw(20) << data[i].namaPembalap << "|" << setw(15) << data[i].namaTim << "|" << setw(10) << data[i].negara << "|" << setw(10) << data[i].point << "|\n";
        }
        cout << "-----------------------------------------------------------------------\n";
    }

    void editPembalap()
{
    // Memanggil fungsi menuSirkuit untuk menampilkan daftar sirkuit
    menuSirkuit();

    int pilihanSirkuit;
    cin >> pilihanSirkuit;

    // Mengecek apakah pilihan sirkuit valid atau tidak
    if (pilihanSirkuit < 1 || pilihanSirkuit > 10)
    {
        cout << "Pilihan sirkuit tidak valid\n";
        return; // Keluar dari fungsi jika pilihan tidak valid
    }

    ifstream file;
    ofstream tempFile;
    bool found = false;

    cout << "Masukkan nama pembalap yang ingin diedit: ";
    cin.ignore();
    string targetNama;
    getline(cin, targetNama);

    // Mencari data pembalap yang akan diedit berdasarkan nama pembalap
    file.open(namaFile[pilihanSirkuit - 1]);
    tempFile.open("temp.txt");

    string line;
    while (getline(file, line))
    {
        int pos = line.find('|');
        string namaPembalap = line.substr(pos + 1, line.find('|', pos + 1) - pos - 1);

        // Jika nama pembalap cocok dengan target, tampilkan data pembalap
        if (namaPembalap == targetNama)
        {
            cout << "Data pembalap yang akan diedit:\n";
            cout << line << endl;
            found = true;

            // Minta input baru untuk data yang ingin diedit
            cout << "Masukkan nama pembalap baru: ";
            getline(cin, namaPembalap);
            cout << "Masukkan nama tim baru: ";
            getline(cin, namaTim);
            cout << "Masukkan negara baru: ";
            getline(cin, negara);
            cout << "Masukkan nomor pembalap baru: ";
            cin >> nomorPembalap;
            cout << "Masukkan jam baru: ";
            cin >> jam;
            cout << "Masukkan menit baru: ";
            cin >> menit;
            cout << "Masukkan detik baru: ";
            cin >> detik;

            // Update data pembalap dengan data baru
            line = "|" + to_string(nomorUrut) + "|" + namaPembalap + "|" + namaTim + "|" + negara + "|" + to_string(nomorPembalap) + "|" + to_string(jam) + ":" + to_string(menit) + ":" + to_string(detik) + "|";
        }

        tempFile << line << endl;
    }

    file.close();
    tempFile.close();

    // Hapus file asli dan ganti dengan file sementara yang telah diedit
    if (found)
    {
        remove(namaFile[pilihanSirkuit - 1].c_str());
        rename("temp.txt", namaFile[pilihanSirkuit - 1].c_str());
        cout << "Data pembalap berhasil diedit." << endl;
    }
    else
    {
        cout << "Data pembalap dengan nama " << targetNama << " tidak ditemukan di sirkuit ini." << endl;
    }
}

void hapusPembalap()
{
    // Memanggil fungsi menuSirkuit untuk menampilkan daftar sirkuit
    menuSirkuit();

    int pilihanSirkuit;
    cin >> pilihanSirkuit;

    // Mengecek apakah pilihan sirkuit valid atau tidak
    if (pilihanSirkuit < 1 || pilihanSirkuit > 10)
    {
        cout << "Pilihan sirkuit tidak valid\n";
        return; // Keluar dari fungsi jika pilihan tidak valid
    }

    ifstream file;
    ofstream tempFile;
    bool found = false;

    cout << "Masukkan nama pembalap yang ingin dihapus: ";
    cin.ignore();
    string targetNama;
    getline(cin, targetNama);

    // Mencari data pembalap yang akan dihapus berdasarkan nama pembalap
    file.open(namaFile[pilihanSirkuit - 1]);
    tempFile.open("temp.txt");

    string line;
    while (getline(file, line))
    {
        int pos = line.find('|');
        string namaPembalap = line.substr(pos + 1, line.find('|', pos + 1) - pos - 1);

        // Jika nama pembalap cocok dengan target, tampilkan data pembalap
        if (namaPembalap == targetNama)
        {
            cout << "Data pembalap yang akan dihapus:\n";
            cout << line << endl;
            found = true;
        }
        else
        {
            // Jika nama pembalap tidak cocok dengan target, salin data pembalap ke file sementara
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    // Hapus file asli dan ganti dengan file sementara yang tidak berisi data pembalap yang dihapus
    if (found)
    {
        remove(namaFile[pilihanSirkuit - 1].c_str());
        rename("temp.txt", namaFile[pilihanSirkuit - 1].c_str());
        cout << "Data pembalap berhasil dihapus." << endl;
    }
    else
    {
        cout << "Data pembalap dengan nama " << targetNama << " tidak ditemukan di sirkuit ini." << endl;
    }
}


};
#endif
