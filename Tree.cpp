#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
using namespace std;

// Struktur node untuk pelanggan dengan informasi pembelian
struct TreeNode {
    string nama;
    vector<TreeNode*> children;
    vector<pair<int, int>> pembelian; // pair<kodeBuah, jumlah>
    int totalPembelian;
    string level; // Bronze, Silver, Gold
};

// Fungsi untuk menentukan level pelanggan berdasarkan total pembelian
string tentukanLevel(int total) {
    if (total >= 1000000) return "Gold";
    if (total >= 500000) return "Silver";
    return "Bronze";
}

// Fungsi untuk membuat node pelanggan baru
TreeNode* buatPelanggan(string nama) {
    TreeNode* node = new TreeNode;
    node->nama = nama;
    node->totalPembelian = 0;
    node->level = "Bronze";
    return node;
}

// Menambahkan anak (pelanggan cabang dari pelanggan utama)
void tambahAnak(TreeNode* parent, string namaAnak) {
    TreeNode* anak = buatPelanggan(namaAnak);
    parent->children.push_back(anak);
    cout << "Pelanggan '" << namaAnak << "' berhasil ditambahkan di bawah '" << parent->nama << "'.\n";
}

// Menambahkan pembelian untuk pelanggan
void tambahPembelian(TreeNode* pelanggan, int kodeBuah, int jumlah, int harga) {
    pelanggan->pembelian.push_back({kodeBuah, jumlah});
    pelanggan->totalPembelian += (jumlah * harga);
    pelanggan->level = tentukanLevel(pelanggan->totalPembelian);
}

// Menampilkan data pelanggan dalam bentuk tree dengan detail
void tampilkanTree(TreeNode* root, int level = 0) {
    if (!root) return;
    
    // Tampilkan informasi pelanggan
    cout << string(level * 2, ' ') << "└─ " << root->nama << " [" << root->level << "]\n";
    
    // Tampilkan riwayat pembelian
    if (!root->pembelian.empty()) {
        cout << string((level + 1) * 2, ' ') << "Riwayat Pembelian:\n";
        for (const auto& beli : root->pembelian) {
            cout << string((level + 2) * 2, ' ') 
                 << "Buah #" << beli.first 
                 << " - Jumlah: " << beli.second << "\n";
        }
        cout << string((level + 2) * 2, ' ') 
             << "Total Pembelian: Rp " << root->totalPembelian << "\n";
    }

    // Tampilkan anak-anak
    for (TreeNode* anak : root->children) {
        tampilkanTree(anak, level + 1);
    }
}

// Mencari pelanggan berdasarkan nama
TreeNode* cariPelanggan(TreeNode* root, const string& target) {
    if (!root) return nullptr;
    if (root->nama == target) return root;

    for (TreeNode* anak : root->children) {
        TreeNode* hasil = cariPelanggan(anak, target);
        if (hasil) return hasil;
    }
    return nullptr;
}

// Menampilkan statistik pelanggan
void tampilkanStatistik(TreeNode* root) {
    if (!root) return;
    
    int totalGold = 0, totalSilver = 0, totalBronze = 0;
    vector<TreeNode*> pelangganTerbaik;
    
    // Fungsi helper untuk menghitung statistik
    function<void(TreeNode*)> hitungStatistik = [&](TreeNode* node) {
        if (!node) return;
        
        if (node->level == "Gold") totalGold++;
        else if (node->level == "Silver") totalSilver++;
        else totalBronze++;
        
        if (node->totalPembelian > 0) {
            pelangganTerbaik.push_back(node);
        }
        
        for (auto anak : node->children) {
            hitungStatistik(anak);
        }
    };
    
    hitungStatistik(root);
    
    // Sortir pelanggan berdasarkan total pembelian
    sort(pelangganTerbaik.begin(), pelangganTerbaik.end(),
         [](TreeNode* a, TreeNode* b) {
             return a->totalPembelian > b->totalPembelian;
         });
    
    cout << "\n=== STATISTIK PELANGGAN ===\n";
    cout << "Total Pelanggan Gold   : " << totalGold << "\n";
    cout << "Total Pelanggan Silver : " << totalSilver << "\n";
    cout << "Total Pelanggan Bronze : " << totalBronze << "\n";
    
    cout << "\nTop 5 Pelanggan:\n";
    for (int i = 0; i < min(5, (int)pelangganTerbaik.size()); i++) {
        cout << i+1 << ". " << pelangganTerbaik[i]->nama 
             << " (Rp " << pelangganTerbaik[i]->totalPembelian 
             << " - " << pelangganTerbaik[i]->level << ")\n";
    }
}

// Menu untuk mengelola data pelanggan (tree)
void menuTree() {
    TreeNode* root = nullptr;
    int pilih;
    string nama, parent;

    do {
        cout << "\n=== MENU HIERARKI PELANGGAN (TREE) ===\n";
        cout << "1. Tambah Pelanggan Utama (Root)\n";
        cout << "2. Tambah Pelanggan Cabang (Anak)\n";
        cout << "3. Catat Pembelian Pelanggan\n";
        cout << "4. Tampilkan Struktur Pelanggan\n";
        cout << "5. Tampilkan Statistik Pelanggan\n";
        cout << "6. Cari Pelanggan\n";
        cout << "7. Kembali ke Menu Utama\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                if (root) {
                    cout << "Pelanggan utama (root) sudah ada.\n";
                } else {
                    cout << "Masukkan nama pelanggan utama: ";
                    getline(cin, nama);
                    root = buatPelanggan(nama);
                    cout << "Pelanggan '" << nama << "' berhasil ditambahkan sebagai root.\n";
                }
                break;

            case 2:
                if (!root) {
                    cout << "Pelanggan utama belum dibuat.\n";
                } else {
                    cout << "Masukkan nama pelanggan induk: ";
                    getline(cin, nama);
                    TreeNode* parentNode = cariPelanggan(root, nama);
                    if (parentNode) {
                        cout << "Masukkan nama pelanggan cabang: ";
                        getline(cin, nama);
                        tambahAnak(parentNode, nama);
                    } else {
                        cout << "Pelanggan induk tidak ditemukan.\n";
                    }
                }
                break;

            case 3:
                if (!root) {
                    cout << "Belum ada data pelanggan.\n";
                } else {
                    cout << "Masukkan nama pelanggan: ";
                    getline(cin, nama);
                    TreeNode* pelanggan = cariPelanggan(root, nama);
                    if (pelanggan) {
                        int kodeBuah, jumlah, harga;
                        cout << "Masukkan kode buah: ";
                        cin >> kodeBuah;
                        cout << "Masukkan jumlah: ";
                        cin >> jumlah;
                        cout << "Masukkan harga per unit: ";
                        cin >> harga;
                        tambahPembelian(pelanggan, kodeBuah, jumlah, harga);
                        cout << "Pembelian berhasil dicatat.\n";
                    } else {
                        cout << "Pelanggan tidak ditemukan.\n";
                    }
                }
                break;

            case 4:
                if (!root) {
                    cout << "Belum ada data pelanggan.\n";
                } else {
                    cout << "\nStruktur Hierarki Pelanggan:\n";
                    tampilkanTree(root);
                }
                break;

            case 5:
                if (!root) {
                    cout << "Belum ada data pelanggan.\n";
                } else {
                    tampilkanStatistik(root);
                }
                break;

            case 6:
                if (!root) {
                    cout << "Belum ada data pelanggan.\n";
                } else {
                    cout << "Masukkan nama pelanggan yang ingin dicari: ";
                    getline(cin, nama);
                    TreeNode* hasil = cariPelanggan(root, nama);
                    if (hasil) {
                        cout << "Pelanggan ditemukan:\n";
                        cout << "Nama: " << hasil->nama << "\n";
                        cout << "Level: " << hasil->level << "\n";
                        cout << "Total Pembelian: Rp " << hasil->totalPembelian << "\n";
                    } else {
                        cout << "Pelanggan tidak ditemukan.\n";
                    }
                }
                break;

            case 7:
                cout << "Kembali ke menu utama...\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 7);
}