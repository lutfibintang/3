#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi utama program
void menu_admin(){
    int pilihan;
    struct Barang daftarBarang[100]; // Misalnya ada 100 barang, sesuaikan dengan kebutuhan Anda
    int jumlah_barang = baca_barang(daftarBarang); // Membaca barang dari file

    jumlah_barang = baca_barang(daftarBarang);
    // Setelah login berhasil, program akan masuk ke menu utama
    do {
        printf("===== Menu Admin =====\n");
            printf("1. Tambah Barang\n");
            printf("2. Tambah Stok\n");
            printf("3. Hapus Barang\n");
            printf("4. Kurangi Stok\n");
            printf("5. Tambah Member\n");
            printf("6. Lihat Member\n");
            printf("9. Lihat Barang\n");
            printf("0. Home\n");
            printf("Masukkan pilihan: ");
            scanf("%d", &pilihan);
            getchar();

            switch (pilihan) {
                case 1:
                    tambah_barang();  // Panggil fungsi untuk menambah barang
                    break;
                case 2:
                    tambah_stok(daftarBarang, jumlah_barang);  // Panggil fungsi untuk menambah barang
                    break;
                case 3:
                    hapus_barang();  // Panggil fungsi untuk menambah barang
                    break;
                case 4:
                    kurangi_stok(daftarBarang, jumlah_barang);  // Panggil fungsi untuk menambah barang
                    break;
                case 5:
                    tambah_member();  // Panggil fungsi untuk menambah barang
                    break;
                case 6:
                    tampilkan_member();  // Panggil fungsi untuk menambah barang
                    break;
                case 9:
                    kategori_barang(daftarBarang, jumlah_barang);  // Panggil fungsi untuk menambah barang
                    break;
                case 0:
                    main();
                    break;
                default:
                    printf("Pilihan tidak valid.\n");
                    break;
            }
    } while (pilihan != 0);
    exit(0);
}