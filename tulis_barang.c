#include <stdio.h>
#include <string.h>
#include "header.h"

void tulis_barang(struct Barang daftarBarang[], int jumlah_barang) {
    FILE *file = fopen("daftar_barang", "w");
    if (file == NULL) {
        printf("Tidak dapat membuka file untuk menulis.\n");
        return;
    }
	int i;
    for (i = 0; i < jumlah_barang; i++) {
        fprintf(file, "%s|%s|%d|%d\n", daftarBarang[i].id, daftarBarang[i].nama, daftarBarang[i].harga, daftarBarang[i].stok);
    }

    fclose(file);
}
