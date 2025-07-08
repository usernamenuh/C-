#include <iostream>
#include <functional>

#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

    void menuLinkedList() {
        cout << "\n[LINKED LIST]\n";
    struct Node {
        int data;
        Node* next;
    };

    Node* head = nullptr;

    auto tambahData = [&](int value) {
        Node* newNode = new Node{value, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Data " << value << " berhasil ditambahkan.\n";
    };

    auto tampilkanData = [&]() {
        if (head == nullptr) {
            cout << "Linked List kosong.\n";
            return;
        }
        cout << "Isi Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    };

    auto hapusData = [&](int value) {
        if (head == nullptr) {
            cout << "Linked List kosong.\n";
            return;
        }

        if (head->data == value) {
            Node* hapus = head;
            head = head->next;
            delete hapus;
            cout << "Data " << value << " berhasil dihapus.\n";
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Data " << value << " tidak ditemukan.\n";
        } else {
            prev->next = curr->next;
            delete curr;
            cout << "Data " << value << " berhasil dihapus.\n";
        }
    };

    // Menu linked list
    int pilihan, nilai;
    do {
        cout << "\n=== MENU LINKED LIST ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Hapus Data\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahData(nilai);
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusData(nilai);
                break;
            case 4:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    // Hapus semua node sebelum keluar dari fungsi
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}



void menuTree() {
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root = nullptr;

    // Fungsi rekursif untuk menambahkan node ke BST
    function<TreeNode*(TreeNode*, int)> tambahNode = [&](TreeNode* node, int value) -> TreeNode* {
        if (node == nullptr) {
            node = new TreeNode{value, nullptr, nullptr};
            cout << "Data " << value << " berhasil ditambahkan ke tree.\n";
        } else if (value < node->data) {
            node->left = tambahNode(node->left, value);
        } else if (value > node->data) {
            node->right = tambahNode(node->right, value);
        } else {
            cout << "Data sudah ada di tree.\n";
        }
        return node;
    };

    // Fungsi inorder traversal
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    };

    // Fungsi mencari data di tree
    function<bool(TreeNode*, int)> cariNode = [&](TreeNode* node, int value) -> bool {
        if (node == nullptr) return false;
        if (value == node->data) return true;
        else if (value < node->data) return cariNode(node->left, value);
        else return cariNode(node->right, value);
    };

    // Menu tree
    int pilihan, nilai;
    do {
        cout << "\n=== MENU TREE ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Inorder\n";
        cout << "3. Cari Data\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                root = tambahNode(root, nilai);
                break;
            case 2:
                if (root == nullptr)
                    cout << "Tree kosong.\n";
                else {
                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;
                }
                break;
            case 3:
                cout << "Masukkan nilai yang dicari: ";
                cin >> nilai;
                if (cariNode(root, nilai))
                    cout << "Data ditemukan di tree.\n";
                else
                    cout << "Data tidak ditemukan.\n";
                break;
            case 4:
                cout << "Kembali ke menu utama...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 4);

    // Fungsi untuk menghapus tree (menghindari memory leak)
    function<void(TreeNode*)> hapusTree = [&](TreeNode* node) {
        if (node != nullptr) {
            hapusTree(node->left);
            hapusTree(node->right);
            delete node;
        }
    };

    hapusTree(root);
}


void menuGraph() {

    using namespace std;

    map<string, vector<string>> graph;

    auto tambahSimpul = [&](const string& node) {
        if (graph.count(node)) {
            cout << "Simpul '" << node << "' sudah ada.\n";
        } else {
            graph[node] = {};
            cout << "Simpul '" << node << "' berhasil ditambahkan.\n";
        }
    };

    auto tambahEdge = [&](const string& dari, const string& ke) {
        if (!graph.count(dari) || !graph.count(ke)) {
            cout << "Salah satu atau kedua simpul tidak ditemukan.\n";
            return;
        }
        graph[dari].push_back(ke);
        graph[ke].push_back(dari);
        cout << "Edge antara '" << dari << "' dan '" << ke << "' berhasil ditambahkan.\n";
    };

    auto tampilkanGraph = [&]() {
        cout << "\n=== ADJACENCY LIST ===\n";
        for (const auto& [node, tetangga] : graph) {
            cout << node << " -> ";
            for (const string& t : tetangga) {
                cout << t << " ";
            }
            cout << endl;
        }
    };

    // Menu
    int pilihan;
    string simpul1, simpul2;
    do {
        cout << "\n=== MENU GRAPH ===\n";
        cout << "1. Tambah Simpul (Node)\n";
        cout << "2. Tambah Edge (Sisi)\n";
        cout << "3. Tampilkan Graph\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama simpul (misal: A): ";
                cin >> simpul1;
                tambahSimpul(simpul1);
                break;
            case 2:
                cout << "Masukkan simpul asal: ";
                cin >> simpul1;
                cout << "Masukkan simpul tujuan: ";
                cin >> simpul2;
                tambahEdge(simpul1, simpul2);
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

    } while (pilihan != 4);
}


int main() {
    string nim = "24010019";
    string nama = "Muhammad Enuh";
    string kelas = "A2024";


    cout << "===============================\n";
    cout << "NIM   : " << nim << endl;
    cout << "Nama  : " << nama << endl;
    cout << "Kelas : " << kelas << endl;
    cout << "===============================\n";

    int pilihan;
    do {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Linked List\n";
        cout << "2. Tree\n";
        cout << "3. Graph\n";
        cout << "4. Exit\n";
        cout << "Pilih menu [1-4]: ";
        cin >> pilihan;

        // Proses pilihan
        switch (pilihan) {
            case 1:
                menuLinkedList();
                break;
            case 2:
                menuTree();
                break;
            case 3:
                menuGraph();
                break;
            case 4:
                cout << "Terima kasih! Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 4);

    return 0;
}
