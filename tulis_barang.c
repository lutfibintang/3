#include <stdio.h>
#include <string.h>
#include "header.h"

void tulis_barang(struct Barang daftarBarang[], int jumlah_barang) {
    FILE *file = fopen("barang.txt", "w");
    if (file == NULL) {
        printf("Gagal membuka file untuk menulis\n");
        return;
    }

    // Tulis Semua Item ke dalam file.
    for (int i = 0; i < jumlah_barang; i++) {
        fprintf(file, "%s %s %d %.2f %.0f\n", daftarBarang[i].id, daftarBarang[i].nama, daftarBarang[i].stok, daftarBarang[i].harga, daftarBarang[i].diskon);
    }
    fclose(file);
}