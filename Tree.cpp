#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Struktur node untuk pelanggan
struct TreeNode {
    string nama;
    vector<TreeNode*> children;
};

// Fungsi untuk membuat node pelanggan baru
TreeNode* buatPelanggan(string nama) {
    TreeNode* node = new TreeNode;
    node->nama = nama;
    return node;
}

// Menambahkan anak (pelanggan cabang dari pelanggan utama)
void tambahAnak(TreeNode* parent, string namaAnak) {
    TreeNode* anak = buatPelanggan(namaAnak);
    parent->children.push_back(anak);
    cout << "Pelanggan '" << namaAnak << "' berhasil ditambahkan di bawah '" << parent->nama << "'.\n";
}

// Menampilkan data pelanggan dalam bentuk tree (indentasi = level)
void tampilkanTree(TreeNode* root, int level = 0) {
    if (!root) return;
    cout << string(level * 2, ' ') << "- " << root->nama << "\n";
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

// Menu untuk mengelola data pelanggan (tree)
void menuTree() {
    TreeNode* root = nullptr;
    int pilih;
    string nama, parent;

    do {
        cout << "\n=== MENU DATA PELANGGAN (TREE) ===\n";
        cout << "1. Tambah Pelanggan Utama (Root)\n";
        cout << "2. Tambah Pelanggan Cabang (Anak)\n";
        cout << "3. Tampilkan Struktur Pelanggan\n";
        cout << "4. Cari Pelanggan\n";
        cout << "5. Kembali ke Menu Utama\n";
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
                    getline(cin, parent);
                    TreeNode* parentNode = cariPelanggan(root, parent);
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
                    cout << "\nStruktur Pelanggan:\n";
                    tampilkanTree(root);
                }
                break;
            case 4:
                if (!root) {
                    cout << "Belum ada data pelanggan.\n";
                } else {
                    cout << "Masukkan nama pelanggan yang ingin dicari: ";
                    getline(cin, nama);
                    TreeNode* hasil = cariPelanggan(root, nama);
                    if (hasil)
                        cout << "Pelanggan '" << nama << "' ditemukan.\n";
                    else
                        cout << "Pelanggan tidak ditemukan.\n";
                }
                break;
            case 5:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 5);
}
