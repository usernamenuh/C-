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
// Tambahkan fungsi-fungsi baru ini di bagian deklarasi fungsi
void tambahDepan(int kode, string nama, int stok);
void tambahBelakang(int kode, string nama, int stok); // ini sama dengan tambahBuah yang sudah ada
void tambahTengah(int kode, string nama, int stok, int posisi);

// Tambahkan deklarasi fungsi baru
void tampilkanBuahDenganNull();
void tampilkanBuahTabel();

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

// Modifikasi fungsi tampilkanBuah() untuk menampilkan menu pilihan tampilan
void tampilkanBuah() {
    if (!head) {
        cout << "Data buah kosong.\n";
        return;
    }

    int pilihan;
    cout << "\nPilih jenis tampilan:\n";
    cout << "1. Tampilan dengan NULL\n";
    cout << "2. Tampilan Tabel\n";
    cout << "Pilih (1/2): ";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            tampilkanBuahDenganNull();
            break;
        case 2:
            tampilkanBuahTabel();
            break;
        default:
            cout << "Pilihan tidak valid.\n";
    }
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
	int posisi;

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
⣿⣿⣿⣯⣉⣻⠿⠶⠤⠤⣤⣤⣤⣤⣴⣶⣿⣿⣿⣿⣿⡿⠿⠿⠟⣋⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣶⣤⣭⣭⣤⣤⣤⣴⣶⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠀
        )" << "\n";

		cout << "=== MENU TOKO BUAH ===\n";
		cout << "1. Tambah Buah di Depan\n";
		cout << "2. Tambah Buah di Tengah\n";
		cout << "3. Tambah Buah di Belakang\n";
        cout << "4. Tampilkan Semua Buah\n";
        cout << "5. Hapus Buah\n";
        cout << "6. Cari Buah\n";
        cout << "7. Kembali ke Menu Utama\n";
        cout << "Pilih: ";

        while (!(cin >> pilih)) {
            cout << "Input tidak valid! Masukkan angka: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilih) {
    case 1: // Tambah Depan
        cout << "Masukkan kode buah  : ";
        while (!(cin >> kode)) {
            cout << "Input harus angka. Masukkan ulang kode buah: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Masukkan nama buah  : ";
        cin.ignore();
        getline(cin, nama);

        cout << "Masukkan stok buah  : ";
        while (!(cin >> stok)) {
            cout << "Input harus angka. Masukkan ulang stok buah: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        tambahDepan(kode, nama, stok);
        break;

    case 2: // Tambah Tengah
        cout << "Masukkan kode buah  : ";
        while (!(cin >> kode)) {
            cout << "Input harus angka. Masukkan ulang kode buah: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Masukkan nama buah  : ";
        cin.ignore();
        getline(cin, nama);

        cout << "Masukkan stok buah  : ";
        while (!(cin >> stok)) {
            cout << "Input harus angka. Masukkan ulang stok buah: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int posisi;
        cout << "Masukkan posisi (1 untuk depan): ";
        while (!(cin >> posisi) || posisi <= 0) {
            cout << "Input tidak valid. Masukkan posisi yang valid: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        tambahTengah(kode, nama, stok, posisi);
        break;

    case 3: // Tambah Belakang (fungsi yang sudah ada)
        // ... kode yang sama seperti sebelumnya ...
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

                tambahBelakang(kode, nama, stok);
                break;

            case 4:
                tampilkanBuah();
                break;

            case 5:
                cout << "Masukkan kode buah yang ingin dihapus: ";
                while (!(cin >> kode)) {
                    cout << "Input harus angka. Masukkan ulang kode buah: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                hapusBuah(kode);
                break;

            case 6:
                cout << "Masukkan kode buah yang ingin dicari: ";
                while (!(cin >> kode)) {
                    cout << "Input harus angka. Masukkan ulang kode buah: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cariBuah(kode);
                break;

            case 7:
                cout << "Kembali ke menu utama...\n";
                break;

            default:
                cout << "Pilihan tidak valid. Silakan ulangi.\n";
        }

    } while (pilih != 7);
}

// Fungsi untuk menambah di depan
void tambahDepan(int kode, string nama, int stok) {
    Node* baru = new Node{kode, nama, stok, nullptr};
    
    if (!head) {
        head = baru;
    } else {
        baru->next = head;
        head = baru;
    }
    
    cout << "Buah '" << nama << "' berhasil ditambahkan di depan.\n";
}

// Fungsi untuk menambah di tengah berdasarkan posisi
void tambahTengah(int kode, string nama, int stok, int posisi) {
    if (posisi <= 0) {
        cout << "Posisi harus lebih besar dari 0\n";
        return;
    }
    
    // Jika posisi 1, sama dengan tambah depan
    if (posisi == 1) {
        tambahDepan(kode, nama, stok);
        return;
    }
    
    Node* baru = new Node{kode, nama, stok, nullptr};
    Node* temp = head;
    int counter = 1;
    
    // Cari posisi yang diinginkan
    while (temp && counter < posisi - 1) {
        temp = temp->next;
        counter++;
    }
    
    // Jika posisi melebihi panjang list
    if (!temp) {
        cout << "Posisi melebihi panjang list. Data akan ditambahkan di akhir.\n";
        tambahBelakang(kode, nama, stok);
        return;
    }
    
    // Sisipkan node baru
    baru->next = temp->next;
    temp->next = baru;
    
    cout << "Buah '" << nama << "' berhasil ditambahkan di posisi " << posisi << ".\n";
}

// Rename fungsi tambahBuah yang sudah ada menjadi tambahBelakang
// (opsional, untuk konsistensi penamaan)
void tambahBelakang(int kode, string nama, int stok) {
    Node* baru = new Node{kode, nama, stok, nullptr};

    if (!head) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = baru;
    }

    cout << "Buah '" << nama << "' berhasil ditambahkan di belakang.\n";
}

// Fungsi untuk menampilkan dengan format NULL
void tampilkanBuahDenganNull() {
    Node* temp = head;
    
    cout << "\nFormat Linked List dengan NULL:\n";
    while (temp) {
        cout << "[Kode: " << temp->kode << ", Nama: " << temp->nama 
             << ", Stok: " << temp->stok << "]";
        if (temp->next) {
            cout << " -> ";
        } else {
            cout << " -> NULL";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi untuk menampilkan dengan format tabel
void tampilkanBuahTabel() {
    Node* temp = head;
    
    cout << "\n+------+-----------------+-------+----------+\n";
    cout << "| Kode | Nama Buah       | Stok  | Next     |\n";
    cout << "+------+-----------------+-------+----------+\n";

    while (temp) {
        cout << "| " << temp->kode << string(6 - to_string(temp->kode).length(), ' ')
             << "| " << temp->nama << string(17 - temp->nama.length(), ' ')
             << "| " << temp->stok << string(7 - to_string(temp->stok).length(), ' ')
             << "| " << (temp->next ? to_string(temp->next->kode) : "NULL") 
             << string(10 - (temp->next ? to_string(temp->next->kode).length() : 4), ' ')
             << "|\n";
        temp = temp->next;
    }
    
    cout << "+------+-----------------+-------+----------+\n";
}