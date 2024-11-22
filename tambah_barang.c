#include <stdio.h>
#include <string.h>
#include "header.h"

void tambah_barang() {
    struct Barang barang;

    // Input ID Barang
    printf("ID Barang\t: ");
    if (scanf("%[^\n]", barang.id) != 1) {
        printf("Gagal membaca input ID Barang.\n");
        return;
    }
    getchar(); 

    // Input Nama Barang
    printf("Nama Barang\t: ");
    if (fgets(barang.nama, sizeof(barang.nama), stdin) == NULL) {
        printf("Gagal membaca input Nama Barang.\n");
        return;
    }
    barang.nama[strcspn(barang.nama, "\n")] = '\0';

    // Input Jumlah Stok
    printf("Masukan Jumlah Stok\t: ");
    if (scanf("%d", &barang.stok) != 1) {
        printf("Gagal membaca input Jumlah Stok.\n");
        return;
    }
    getchar();

    // Input Harga Barang
    printf("Masukan Harga Barang\t: ");
    if (scanf("%f", &barang.harga) != 1) {
        printf("Gagal membaca input Harga Barang.\n");
        return;
    }
    
    FILE *file = fopen("barang.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file untuk menambahkan barang.\n");
        return;
    }

    // Tulis Data kedalam FIle
    fprintf(file, "%s,%s,%d,%.2f\n", barang.id, barang.nama, barang.stok, barang.harga);

    fclose(file);

    printf("Barang berhasil ditambahkan.\n");
}
