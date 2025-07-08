#include <iostream>
using namespace std;

// Deklarasi menu dari file terpisah
void menuTokoBuah();    // Dari tugas 1 - Linked List
void menuTree();
void menuGraph();

int main() {
    // Identitas mahasiswa
    string nama  = "Muhammad Enuh";
    string nim   = "24010019";
    string kelas = "A2024";

    int pilih;

    do {
        // Tampilan menu utama
        cout << "\n==================================\n";
        cout << "             MENU UAS            \n";
        cout << "==================================\n";
        cout << "NIM   : " << nim << "\n";
        cout << "Nama  : " << nama << "\n";
        cout << "Kelas : " << kelas << "\n";
        cout << "----------------------------------\n";
        cout << "1. Toko Buah (Linked List)\n";
        cout << "2. Data Pelanggan (Tree)\n";
        cout << "3. Graph (Relasi Pelanggan)\n";
        cout << "4. Exit\n";
        cout << "Pilih menu [1-3]: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                menuTokoBuah();
                break;
            case 2:
                menuTree();
                break;
            case 3:
                menuGraph();
                break;
            case 4:
                cout << "\nProgram selesai. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilih != 3);

    return 0;
}
