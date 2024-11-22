#include <stdlib.h>
#include "header.h"
#include <stdio.h>
#include <string.h>

// Fungsi login atau daftar
void login_atau_daftar(char *role) { // Menambahkan role sebagai parameter
    int pilihan;

    // Loop utama login/daftar
    while (1) {
        printf("===== Sistem Login =====\n");
        printf("1. Login\n");
        printf("2. Daftar Akun Baru\n");
        printf("Masukkan pilihan (1/2): ");
        scanf("%d", &pilihan);
        getchar();

        if (pilihan == 1) {
            if (login(role)) { // Memastikan role diubah di sini
                // Setelah login berhasil, tampilkan pesan selamat datang dan arahkan ke menu utama
                if (strcmp(role, "admin") == 0) {
                    printf("Selamat datang, Admin!\n");
                } else {
                    printf("Selamat datang, Pengguna!\n");
                }
                
                // Keluar dari login_atau_daftar() dan menuju menu utama
                return; // Menghentikan eksekusi fungsi login_atau_daftar dan melanjutkan ke menu utama
            } else {
                printf("Gagal login. Silakan coba lagi.\n");
            }
        } else if (pilihan == 2) {
            daftar_akun(); // Mendaftar akun baru
        } else {
            printf("Pilihan tidak valid.\n");
        }
    }
}

// Fungsi utama program
int main() {
    char role[10]; // Menyimpan role (admin atau user)
    int pilihan;
    // Memulai login atau daftar dan passing role sebagai parameter
    login_atau_daftar(role);  // Passing 'role' ke fungsi login_atau_daftar()
    // Setelah login berhasil, program akan masuk ke menu utama
    do {
        if (strcmp(role, "admin") == 0) {
            // Menu Admin
            menu_admin();
        } else if (strcmp(role, "user") == 0) {
            // Menu Pengguna
            menu_user();
        }
    } while (pilihan != 0);

    return 0;
}
