#include <stdio.h>
#include <string.h>
#include "header.h"

int cek_id(const char *id) {
    FILE *file = fopen("barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file barang.txt untuk memeriksa ID.\n");
        return 0; // Return false if the file can't be opened
    }

    struct Barang barang;
    while (fscanf(file, "%s %s %d %f %f", barang.id, barang.nama, &barang.stok, &barang.harga, &barang.diskon) != EOF) {
        if (strcmp(barang.id, id) == 0) {
            fclose(file);
            return 1; // ID exists in the file
        }
    }

    fclose(file);
    return 0; // ID does not exist
}


void tambah_barang() {
    struct Barang barang;

    // Input ID Barang
    printf("ID Barang\t\t: ");
    if (scanf("%[^\n]", barang.id) != 1) {
        printf("Gagal membaca input ID Barang.\n");
        return;
    }
    getchar(); 

    // Input Nama Barang
    printf("Nama Barang\t\t: ");
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
    
    //input diskon
    printf("Masukan Diskon Barang\t: ");
    if (scanf("%f", &barang.diskon) != 1) {
        printf("Gagal membaca input Diskon Barang.\n");
        return;
    }
    
    FILE *file = fopen("barang.txt", "a");
    if (file == NULL) {
        printf("Gagal membuka file untuk menambahkan barang.\n");
        return;
    }

    // Tulis Data kedalam FIle
    fprintf(file, "%s %s %d %.2f %.0f\n", barang.id, barang.nama, barang.stok, barang.harga, barang.diskon);

    fclose(file);

    printf("\n====== Barang berhasil ditambahkan. =======\n\n");
}
