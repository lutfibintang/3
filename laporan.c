#include <stdio.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menulis laporan ke dalam file
void tulis_laporan(char *nama_member, char *nama_barang, int jumlah_beli, float harga_total, int poin) {
    FILE *file = fopen("laporan.txt", "a");
    if (file != NULL) {
        fprintf(file, "Nama Member: %s\n", nama_member);
        fprintf(file, "Barang: %s, Jumlah: %d, Total Harga: %.2f, Poin: %d\n\n", nama_barang, jumlah_beli, harga_total, poin);
        fclose(file);
    } else {
        printf("Gagal membuka laporan.txt\n");
    }
}
