#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi utama program
void menu_admin(){
    int pilihan;
    // Setelah login berhasil, program akan masuk ke menu utama
    do {
        printf("===== Menu Admin =====\n");
            printf("1. Tambah Barang\n");
            printf("0. Keluar\n");
            printf("Masukkan pilihan (1/0): ");
            scanf("%d", &pilihan);
            getchar();

            switch (pilihan) {
                case 1:
                    tambah_barang();  // Panggil fungsi untuk menambah barang
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