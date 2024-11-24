#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi utama program
void menu_user() {
    int pilihan;
    struct Barang daftarBarang[100];  // Array untuk menyimpan barang yang dibaca
    int jumlah_barang;

    jumlah_barang = baca_barang(daftarBarang);
    // Setelah login berhasil, program akan masuk ke menu utama
    do {
        printf("===== Menu Pengguna =====\n");
        printf("1. Lihat Barang\n");
        printf("2. Pembayaran\n");
        printf("0. Home\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                kategori_barang(daftarBarang, jumlah_barang);
                break;
            case 2:
                kasir();
                break;
            case 0:
                main();
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
        }
    } while (pilihan != 0);

    exit(0);  // Keluar dari aplikasi setelah selesai
}