#include <stdio.h>
#include <string.h>
#include "header.h"

int baca_barang(struct Barang daftarBarang[]) {
    FILE *file = fopen("daftar_barang", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%[^|]|%[^|]|%d|%d\n", daftarBarang[i].id, daftarBarang[i].nama, &daftarBarang[i].harga, &daftarBarang[i].stok) == 4) {
        i++;
    }

    fclose(file);
    return i; // Mengembalikan jumlah barang yang berhasil dibaca
}
