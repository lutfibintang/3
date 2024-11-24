#include <stdio.h>
#include <string.h>
#include "header.h"

void kategori_barang(struct Barang daftarBarang[], int jumlah_barang) {
    // Mengurutkan barang berdasarkan ID
    for (int i = 0; i < jumlah_barang - 1; i++) {
        for (int j = i + 1; j < jumlah_barang; j++) {
            if (strcmp(daftarBarang[i].id, daftarBarang[j].id) > 0) {
                // Tukar barang[i] dan barang[j] jika ID lebih besar
                struct Barang temp = daftarBarang[i];
                daftarBarang[i] = daftarBarang[j];
                daftarBarang[j] = temp;
            }
        }
    }

    // Tampilkan barang berdasarkan kategori
    printf("\n====== Daftar Barang yang sudah dikategorikan: ======\n");
    char kategori = '\0';  // Variabel untuk kategori berdasarkan huruf pertama ID

    for (int i = 0; i < jumlah_barang; i++) {
        // Cek kategori berdasarkan huruf pertama ID
        if (kategori != daftarBarang[i].id[0]) {
            kategori = daftarBarang[i].id[0];
            printf("\n----- Kategori: %c -----\n", kategori);  // Tampilkan kategori baru
            // Menampilkan header kolom
            printf("%-13s %-21s %-11s %-16s %-10s\n", "ID", "Nama", "Stok", "Harga", "Diskon(dalam persen '%')");
        }
        
        // Tampilkan data barang dengan format yang rapi
        printf("> %-12s> %-20s> %-10d> Rp%-14.2f> %-10.0f\n", daftarBarang[i].id, daftarBarang[i].nama, daftarBarang[i].stok, daftarBarang[i].harga, daftarBarang[i].diskon);
    }
    printf("\n");
}
