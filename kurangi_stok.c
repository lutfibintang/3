#include <stdio.h>
#include <string.h>
#include "header.h"

void kurangi_stok(struct Barang daftarBarang[], int jumlah_barang) {
    char nama[50];
    int i, minus;

    printf("Masukkan nama barang: ");
    scanf("%s", nama);
    printf("Masukkan jumlah stok yang ingin dikurangi: ");
    scanf("%d", &minus);

    for (i = 0; i < jumlah_barang; i++) {
        if (strcmp(daftarBarang[i].nama, nama) == 0) {
            if (daftarBarang[i].stok < minus) {
                printf("Stok tidak cukup.\n");
                return;
            }
            daftarBarang[i].stok -= minus;
            tulis_barang(daftarBarang, jumlah_barang);  // Menyimpan perubahan ke file
            printf("\n====== Stok berhasil dikurangi. ======\n\n");
            return;
        }
    }
    printf("\n====== Barang dengan nama %s tidak ditemukan. ======\n\n", nama);
}
