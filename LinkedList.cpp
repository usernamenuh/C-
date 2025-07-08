#include <iostream>
#include <string>
#include <limits> // untuk numeric_limits
using namespace std;

// === Struct untuk Node Buah ===
struct Node {
    int kode;
    string nama;
    int stok;
    Node* next;
};

// Deklarasi fungsi
void tambahBuah(int kode, string nama, int stok);
void tampilkanBuah();
void hapusBuah(int kode);
void cariBuah(int kode);
void menuTokoBuah();

// Pointer head (linked list)
Node* head = nullptr;

// Fungsi tambah buah ke linked list
void tambahBuah(int kode, string nama, int stok) {
    Node* baru = new Node{kode, nama, stok, nullptr};

    if (!head) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = baru;
    }

    cout << "Buah '" << nama << "' berhasil ditambahkan.\n";
}

// Fungsi menampilkan semua buah
void tampilkanBuah() {
    if (!head) {
        cout << "Data buah kosong.\n";
        return;
    }

    Node* temp = head;

    cout << "\n+------+-----------------+-------+\n";
    cout << "| Kode | Nama Buah       | Stok  |\n";
    cout << "+------+-----------------+-------+\n";

    while (temp) {
        cout << "| " << temp->kode << "    | "
             << temp->nama << string(17 - temp->nama.length(), ' ')
             << "| " << temp->stok << "\n";
        temp = temp->next;
    }

    cout << "+------+-----------------+-------+\n";
}

// Fungsi menghapus buah berdasarkan kode
void hapusBuah(int kode) {
    if (!head) {
        cout << "Data buah kosong.\n";
        return;
    }

    if (head->kode == kode) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Buah dengan kode " << kode << " berhasil dihapus.\n";
        return;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr && curr->kode != kode) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) {
        cout << "Buah tidak ditemukan.\n";
    } else {
        prev->next = curr->next;
        delete curr;
        cout << "Buah berhasil dihapus.\n";
    }
}

// Fungsi mencari buah berdasarkan kode
void cariBuah(int kode) {
    Node* temp = head;
    while (temp) {
        if (temp->kode == kode) {
            cout << "Buah ditemukan:\n";
            cout << "Kode : " << temp->kode << "\n";
            cout << "Nama : " << temp->nama << "\n";
            cout << "Stok : " << temp->stok << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Buah tidak ditemukan.\n";
}

// Fungsi menu utama toko buah
void menuTokoBuah() {
    int pilih;
    int kode, stok;
    string nama;

    do {
        // Tambahkan dekorasi ASCII art di sini
        cout << R"(

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠛⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⣠⣶⣆⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣺⣿⣿⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠘⢿⣿⣿⣶⠄⠈⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠘⠿⠟⢁⣴⣿⣷⣤⣀⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⢠⣶⣿⣿⣿⣿⣿⣿⣷⣄⠈⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⠻⣿⣿⣷⣶⢌⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠉⠉⠉⠻⣿⣿⣿⣿⠀⣸⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣦⡈⠹⢿⣿⣿⣿⣿⣿⣿⣿⣎⢿⣿⣿⡿⢿⣋⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡿⠛⠉⢀⣀⣀⣀⠈⠙⠛⠿⢿⠏⠀⣴⣿⣦⠀⢸⣿⣿⣿⠀⣿⣿⣿⣿⣈⢿⣿⣿⣿⣌⠻⣿⣿⣦⡀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⡿⠋⢀⣤⣾⣿⣿⣿⣿⣿⣷⣶⣤⡀⠀⣴⣿⣿⠋⠀⣸⣿⣿⣿⠀⢹⣿⣿⣿⣿⣆⢻⣿⣿⣿⣷⣌⠻⣿⣿⣦⡀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⡟⠁⢠⣾⡿⢋⣽⣿⣿⣿⣿⣿⣿⣿⣷⡈⠻⠿⠋⠀⠐⢿⣿⣿⣿⡄⠘⣿⣿⣿⣿⣿⣧⡙⢿⣿⣿⣿⣷⣌⠻⣿⣿⣦⡀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⡿⠀⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⣾⣶⣜⢿⣦⣄⠈⠻⣿⡇⠀⣿⣿⣿⣿⣿⣿⣷⡈⢻⣿⣿⣿⣿⡧⠀⢿⣿⣿⣦⡀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⠁⠀⣈⡛⠛⠛⠛⠛⢋⠉⣿⣿⣿⣿⡿⢁⣼⣿⣿⣿⣦⠹⣿⣷⣄⠘⢿⡀⠹⣿⣿⣿⣿⣿⣿⣿⣧⣿⣿⣿⣿⢅⠀⢸⣯⡻⣿⣿⣶⡀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡇⠀⢸⣿⠟⣠⠿⣿⣿⣿⡇⠹⣿⣿⣿⢁⣾⣿⣿⣿⣿⣿⣧⠸⣿⣿⡄⠘⣧⠀⢹⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⡿⠊⣼⣿⣿⣿⣮⡻⣿⣿⣧⡀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡇⠀⣿⣿⡀⠿⠃⠘⠻⣿⣿⡀⠻⣿⣿⣾⣿⠿⠉⢿⣿⣿⣿⡇⢹⣿⡇⠀⣿⣆⠀⢻⣿⣿⣿⣿⣧⠀⢀⣾⣏⣤⣾⣿⣿⣿⣿⣿⣿⣦⡙⢿⣿⣦⡀⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿
⡇⠀⣿⡏⢠⣄⠀⠀⠀⣿⣿⣿⣦⣈⣉⣉⣀⣴⣦⠘⢿⣿⣿⣷⢸⣿⠇⢀⣿⣿⣆⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣦⡙⢿⣿⣦⡀⠹⢿⣿⣿⣿⣿⣿⣿
⡇⠀⣿⣷⣤⣭⣤⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡈⠻⣿⣿⣼⠇⠀⣸⣿⣿⣿⣦⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣙⠻⣿⣿⣿⣿⣿⣿⣦⡙⣿⣿⣦⡈⠻⣿⣿⣿⣿⣿
⡇⠀⢸⣿⣿⣿⣿⣿⣿⣏⠉⠛⠿⢿⡟⠁⠀⠉⣿⣿⣿⣄⠙⠻⡟⠀⣴⣿⣿⣿⣿⣿⣷⡀⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠈⠻⣿⣿⣿
⣿⡀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣷⠀⣀⠀⣿⣿⣿⣿⠏⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣦⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠈⠻⢿
⣿⣷⠀⠈⢻⣿⣿⣿⣿⣿⣿⡿⠟⣿⡿⣄⣙⣁⣿⣿⠟⠁⠀⣠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢀⣤⠈
⣿⣿⣷⡄⠀⠙⢿⣿⣿⡏⢠⣶⡀⠛⠃⣿⣿⠟⠋⠁⢀⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣸⠟⠀
⣿⣿⣿⣿⣷⣀⠀⠉⠙⠳⠜⠋⠀⠛⠀⠁⠀⢀⣠⣶⣿⣿⣿⣿⣦⣍⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣀⠈⠙⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠛⠉⠀⣀⣠⣼
⣿⣿⣿⣯⣉⣻⠿⠶⠤⠤⣤⣤⣤⣤⣴⣶⣿⣿⣿⣿⣿⡿⠿⠿⠟⣋⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣬⣍⣙⣛⣻⣿⣿⣷⣶⣤⣤⣀⣀⣀⣀⣀⣀⣀⣀⣤⣤⣶⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣶⣤⣭⣭⣤⣤⣤⣴⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠀
        )" << "\n";

        cout << "=== MENU TOKO BUAH ===\n";
        cout << "1. Tambah Buah\n";
        cout << "2. Tampilkan Semua Buah\n";
        cout << "3. Hapus Buah\n";
        cout << "4. Cari Buah\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilih: ";

        while (!(cin >> pilih)) {
            cout << "Input tidak valid! Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilih) {
            case 1:
                cout << "Masukkan kode buah  : ";
                while (!(cin >> kode)) {
                    cout << "Input harus angka. Masukkan ulang kode buah: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                cout << "Masukkan nama buah  : ";
                cin.ignore(); // bersihkan newline
                getline(cin, nama);

                cout << "Masukkan stok buah  : ";
                while (!(cin >> stok)) {
                    cout << "Input harus angka. Masukkan ulang stok buah: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                tambahBuah(kode, nama, stok);
                break;

            case 2:
                tampilkanBuah();
                break;

            case 3:
                cout << "Masukkan kode buah yang ingin dihapus: ";
                while (!(cin >> kode)) {
                    cout << "Input harus angka. Masukkan ulang kode buah: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                hapusBuah(kode);
                break;

            case 4:
                cout << "Masukkan kode buah yang ingin dicari: ";
                while (!(cin >> kode)) {
                    cout << "Input harus angka. Masukkan ulang kode buah: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cariBuah(kode);
                break;

            case 5:
                cout << "Kembali ke menu utama...\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan ulangi.\n";
        }

    } while (pilih != 5);
}
