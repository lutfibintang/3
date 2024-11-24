#include <stdlib.h>
#include "header.h"
#include <stdio.h>
#include <string.h>

// Fungsi login atau daftar
// Fungsi login atau daftar
void login_atau_daftar(char *role) {  // Passing role ke fungsi ini
    int pilihan;

    // Loop utama login/daftar
    while (1) {
        printf("\n===== Sistem Login =====\n");
        printf("1. Login Admin\n");
        printf("2. Login User\n");
        printf("3. Daftar Akun Baru\n");
        printf("0. Keluar\n"); 
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);
        getchar();  // Untuk membersihkan buffer input

        if (pilihan == 1) {
            if (login_admin(role)) {
                break;  // Keluar dari loop jika login berhasil sebagai admin
            }
        } else if (pilihan == 2) {
            if (login_user(role)) {
                break;  // Keluar dari loop jika login berhasil sebagai user
            }
        } else if (pilihan == 3) {
            daftar_akun();  // Daftar akun baru
        } else if (pilihan == 0) {
            printf("\n===== Keluar Dari Program. =====");
            exit(0);  // Keluar
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
