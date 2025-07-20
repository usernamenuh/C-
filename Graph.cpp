#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Struktur untuk menyimpan detail transaksi
struct Transaksi {
    int kodeBuah;
    int jumlah;
    string tanggal;
};

// Modifikasi struktur Graph untuk menyimpan transaksi
map<string, vector<pair<string, Transaksi>>> graph;
map<string, vector<Transaksi>> riwayatPembelian;

// Tambah node (pelanggan)
void tambahPelanggan(string nama) {
    if (graph.count(nama)) {
        cout << "Pelanggan '" << nama << "' sudah ada.\n";
    } else {
        graph[nama] = {};
        riwayatPembelian[nama] = {};
        cout << "Pelanggan '" << nama << "' berhasil ditambahkan.\n";
    }
}

// Tambah transaksi pembelian
void tambahTransaksi(string nama, int kodeBuah, int jumlah, string tanggal) {
    if (!graph.count(nama)) {
        cout << "Pelanggan tidak ditemukan.\n";
        return;
    }
    
    // Cek apakah buah tersedia (perlu akses ke linked list buah)
    // TODO: Tambahkan pengecekan stok buah
    
    Transaksi baru = {kodeBuah, jumlah, tanggal};
    riwayatPembelian[nama].push_back(baru);
    cout << "Transaksi berhasil dicatat.\n";
}

// Tambah relasi berdasarkan rekomendasi
void tambahRelasi(string dari, string ke, Transaksi transaksi) {
    if (!graph.count(dari) || !graph.count(ke)) {
        cout << "Salah satu pelanggan tidak ditemukan.\n";
    } else {
        graph[dari].push_back({ke, transaksi});
        cout << "Relasi dan rekomendasi dari '" << dari << "' ke '" << ke << "' berhasil ditambahkan.\n";
    }
}

// Tampilkan semua relasi dengan detail transaksi
void tampilkanGraph() {
    cout << "\n=== RELASI DAN REKOMENDASI PELANGGAN ===\n";
    for (const auto& pair : graph) {
        cout << "Pelanggan: " << pair.first << "\n";
        cout << "Riwayat Pembelian:\n";
        if (riwayatPembelian[pair.first].empty()) {
            cout << "  Belum ada pembelian\n";
        } else {
            for (const auto& transaksi : riwayatPembelian[pair.first]) {
                cout << "  Kode Buah: " << transaksi.kodeBuah 
                     << ", Jumlah: " << transaksi.jumlah 
                     << ", Tanggal: " << transaksi.tanggal << "\n";
            }
        }
        
        cout << "Terhubung dengan:\n";
        if (pair.second.empty()) {
            cout << "  Tidak ada relasi\n";
        } else {
            for (const auto& relasi : pair.second) {
                cout << "  - " << relasi.first << " (Rekomendasi: Buah "
                     << relasi.second.kodeBuah << ", Jumlah: "
                     << relasi.second.jumlah << ")\n";
            }
        }
        cout << "\n";
    }
}

// Menu utama graph
void menuGraph() {
    int pilih;
    string nama1, nama2, tanggal;
    int kodeBuah, jumlah;

    do {
        cout << "\n=== MENU RELASI PELANGGAN (GRAPH) ===\n";
        cout << "1. Tambah Pelanggan\n";
        cout << "2. Catat Pembelian Buah\n";
        cout << "3. Tambah Rekomendasi Antar Pelanggan\n";
        cout << "4. Tampilkan Relasi dan Riwayat\n";
        cout << "5. Kembali ke Menu Utama\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                cout << "Masukkan nama pelanggan: ";
                getline(cin, nama1);
                tambahPelanggan(nama1);
                break;
            
            case 2:
                cout << "Masukkan nama pelanggan: ";
                getline(cin, nama1);
                cout << "Masukkan kode buah: ";
                cin >> kodeBuah;
                cout << "Masukkan jumlah: ";
                cin >> jumlah;
                cin.ignore();
                cout << "Masukkan tanggal (DD/MM/YYYY): ";
                getline(cin, tanggal);
                tambahTransaksi(nama1, kodeBuah, jumlah, tanggal);
                break;
            
            case 3:
                cout << "Masukkan nama pelanggan pemberi rekomendasi: ";
                getline(cin, nama1);
                cout << "Masukkan nama pelanggan penerima rekomendasi: ";
                getline(cin, nama2);
                cout << "Masukkan kode buah yang direkomendasikan: ";
                cin >> kodeBuah;
                cout << "Masukkan jumlah yang direkomendasikan: ";
                cin >> jumlah;
                cin.ignore();
                cout << "Masukkan tanggal rekomendasi: ";
                getline(cin, tanggal);
                tambahRelasi(nama1, nama2, {kodeBuah, jumlah, tanggal});
                break;
            
            case 4:
                tampilkanGraph();
                break;
            
            case 5:
                cout << "Kembali ke menu utama...\n";
                break;
            
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 5);
}