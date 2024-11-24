#include <stdio.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menghapus barang berdasarkan ID
void hapus_barang() {
    char id[10];
    struct Barang daftarBarang[100];  // Array untuk menyimpan barang yang dibaca
    int jumlah_barang, i, index_hapus = -1;

    // Baca daftar barang dari file
    jumlah_barang = baca_barang(daftarBarang);

    // Input ID Barang yang akan dihapus
    printf("Masukkan ID Barang yang ingin dihapus: ");
    scanf("%s", id);

    // Mencari barang berdasarkan ID
    for (i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftarBarang[i].id, id) == 0) {
            index_hapus = i;
            break;
        }
    }

    // Jika barang ditemukan
    if (index_hapus != -1) {
        // Menggeser semua barang setelah barang yang dihapus ke kiri
        for (i = index_hapus; i < jumlah_barang - 1; i++) {
            daftarBarang[i] = daftarBarang[i + 1];
        }
        jumlah_barang--;  // Kurangi jumlah barang

        // Menulis kembali data barang yang telah diubah ke dalam file
        tulis_barang(daftarBarang, jumlah_barang);
        printf("\n======Barang dengan ID %s berhasil dihapus. ======\n\n", id);
    } else {
        printf("Barang dengan ID %s tidak ditemukan.\n", id);
    }
}
