#include <iostream>
#include <limits>
#include "TokoBuah.h"
using namespace std;

void menuTokoBuah();
void menuTree();
void menuGraph();

// Fungsi untuk membersihkan layar
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk menampilkan header program
void tampilkanHeader(const string& nama, const string& nim, const string& kelas) {
    cout << "\n==================================\n";
    cout << "         SISTEM TOKO BUAH          \n";
    cout << "==================================\n";
    cout << "NIM   : " << nim << "\n";
    cout << "Nama  : " << nama << "\n";
    cout << "Kelas : " << kelas << "\n";
    cout << "----------------------------------\n";
}

int main() {
    const string nama  = "Muhammad Enuh";
    const string nim   = "24010019";
    const string kelas = "A2024";
    int pilih;

    do {
        clearScreen();
        tampilkanHeader(nama, nim, kelas);
        
        cout << "\nMENU UTAMA:\n";
        cout << "1. Toko Buah (Linked List)\n";
        cout << "2. Hierarki Pelanggan (Tree)\n";
        cout << "3. Relasi Pelanggan (Graph)\n";
        cout << "4. Exit\n";
        cout << "\nPilih menu [1-4]: ";
        
        // Validasi input
        while (!(cin >> pilih)) {
            cout << "Input tidak valid! Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilih) {
            case 1:
                clearScreen();
                tampilkanHeader(nama, nim, kelas);
                menuTokoBuah();
                break;
            
            case 2:
                clearScreen();
                tampilkanHeader(nama, nim, kelas);
                menuTree();
                break;
            
            case 3:
                clearScreen();
                tampilkanHeader(nama, nim, kelas);
                menuGraph();
                break;
            
            case 4:
                cout << "\nTerima kasih telah menggunakan program ini!\n";
                cout << "Program selesai.\n\n";
                break;
            
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                cout << "Tekan Enter untuk melanjutkan...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
        }

    } while (pilih != 4);

    return 0;
}