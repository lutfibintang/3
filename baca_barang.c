#include <stdio.h>
#include <string.h>
#include "header.h"

int baca_barang(struct Barang daftarBarang[]) {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file barang.txt.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(file, "%s %s %d %f %f", daftarBarang[i].id, daftarBarang[i].nama, &daftarBarang[i].stok, &daftarBarang[i].harga, &daftarBarang[i].diskon) != EOF) {
        i++;
    }
    fclose(file);
    return i;
}