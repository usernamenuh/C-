#ifndef TOKO_BUAH_H
#define TOKO_BUAH_H

#include <string>

struct Node {
    int kode;
    std::string nama;
    int stok;
    Node* next;
};

// Deklarasi fungsi-fungsi yang dibutuhkan oleh kedua program
extern Node* head;
bool cekStokBuah(int kode, int jumlah);
void kurangiStokBuah(int kode, int jumlah);
std::string getNamaBuah(int kode);

#endif