#include <stdio.h>
#include <string.h>
#include "header.h"

void tambah_stok(struct Barang daftarBarang[], int jumlah_barang) {
    char id[10];
    int i, jumlah;

    printf("Masukkan ID barang: ");
    scanf("%s", id);
    printf("Masukkan jumlah stok yang ingin ditambah: ");
    scanf("%d", &jumlah);

    // Search for the item by ID
    for (i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftarBarang[i].id, id) == 0) {
            daftarBarang[i].stok += jumlah;  // Add stock
            tulis_barang(daftarBarang, jumlah_barang);  // Save changes to file
            printf("\n====== Stok berhasil ditambahkan. ======\n\n");
            return;
        }
    }
    printf("\nBarang dengan ID %s tidak ditemukan.\n\n", id);
}