#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi utama program
void menu_user(){
    int pilihan;
    // Setelah login berhasil, program akan masuk ke menu utama
    do {
        printf("===== Menu Pengguna =====\n");
        printf("1. Lihat Barang\n");  // Bisa ditambahkan fungsionalitas lihat barang
        printf("0. Keluar\n");
        printf("Masukkan pilihan (1/0): ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                printf("Pengguna melihat barang.\n");
                // Implementasi untuk melihat barang
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
                break;
            }
    } while (pilihan != 0);
    exit(0);
}