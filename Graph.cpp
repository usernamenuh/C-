#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Struktur Graph (menggunakan adjacency list)
map<string, vector<string>> graph;

// Tambah node (pelanggan)
void tambahPelanggan(string nama) {
    if (graph.count(nama)) {
        cout << "Pelanggan '" << nama << "' sudah ada.\n";
    } else {
        graph[nama] = {};
        cout << "Pelanggan '" << nama << "' berhasil ditambahkan.\n";
    }
}

// Tambah relasi (edge) antar pelanggan
void tambahRelasi(string dari, string ke) {
    if (!graph.count(dari) || !graph.count(ke)) {
        cout << "Salah satu pelanggan tidak ditemukan.\n";
    } else {
        graph[dari].push_back(ke);
        cout << "Relasi dari '" << dari << "' ke '" << ke << "' berhasil ditambahkan.\n";
    }
}

// Tampilkan semua relasi
void tampilkanGraph() {
    cout << "\n=== RELASI PELANGGAN ===\n";
    for (auto& pair : graph) {
        cout << "- " << pair.first << " terhubung ke: ";
        if (pair.second.empty()) {
            cout << "(tidak ada)";
        } else {
            for (auto& tetangga : pair.second) {
                cout << tetangga << " ";
            }
        }
        cout << "\n";
    }
}

// Menu utama graph
void menuGraph() {
    int pilih;
    string nama1, nama2;

    do {
        cout << "\n=== MENU RELASI PELANGGAN (GRAPH) ===\n";
        cout << "1. Tambah Pelanggan (Node)\n";
        cout << "2. Tambah Relasi Antar Pelanggan (Edge)\n";
        cout << "3. Tampilkan Relasi Pelanggan\n";
        cout << "4. Kembali ke Menu Utama\n";
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
                cout << "Masukkan nama pelanggan asal: ";
                getline(cin, nama1);
                cout << "Masukkan nama pelanggan tujuan: ";
                getline(cin, nama2);
                tambahRelasi(nama1, nama2);
                break;
            case 3:
                tampilkanGraph();
                break;
            case 4:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 4);
}
