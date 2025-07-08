#include <iostream>
using namespace std;

// Deklarasi menu toko buah dari file LinkedList
void menuTokoBuah();

int main() {
    string nama = "Muhammad Enuh";
    string nim = "24010019";
    string kelas = "A2024";

    int pilih;

    do {
        cout << "\n==============================\n";
        cout << "NIM   : " << nim << "\n";
        cout << "Nama  : " << nama << "\n";
        cout << "Kelas : " << kelas << "\n";
        cout << "==============================\n";
        cout << "MENU UAS:\n";
        cout << "1. Linked List (Toko Buah)\n";
        cout << "2. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                menuTokoBuah();
                break;
            case 2:
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 2);

    return 0;
}
