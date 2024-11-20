#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void simpan_akun(struct Akun akun) {
    FILE *file = fopen("akun.txt", "a"); // Mode append untuk menambah data
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Menyimpan data akun (username dan password) ke dalam file
    fprintf(file, "%s,%s\n", akun.username, akun.password);

    fclose(file);
    printf("Akun berhasil disimpan.\n");
}

// Fungsi untuk memverifikasi akun saat login
int login(char *role) {
    char username[20], password[20];
    struct Akun akun;
    FILE *file = fopen("akun.txt", "r");

    if (file == NULL) {
        printf("Gagal membuka file akun.\n");
        return 0;
    }

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Membaca data akun dari file dan memverifikasi login
    while (fscanf(file, "%[^,],%s\n", akun.username, akun.password) != EOF) {
        // Pengecekan login sesuai dengan role yang diminta (admin atau pengguna biasa)
        if (strcmp(username, akun.username) == 0 && strcmp(password, akun.password) == 0) {
            fclose(file);
            if (strcmp(username, "admin") == 0) {
                strcpy(role, "admin");
            } else {
                strcpy(role, "user");
            }
            return 1;
        }
    }

    fclose(file);
    printf("Username atau password salah.\n");
    return 0;
}

// Fungsi untuk mendaftar akun baru
void daftar_akun() {
    struct Akun akun;

    printf("Daftar Akun Baru\n");

    // Input username dan password
    printf("Masukkan Username: ");
    scanf("%s", akun.username);
    printf("Masukkan Password: ");
    scanf("%s", akun.password);

    // Menyimpan akun baru ke file
    simpan_akun(akun);
}

// Fungsi untuk login atau mendaftar
// void login_atau_daftar() {
//     int pilihan;
//     char role[10];

//     while (1) {
//         printf("===== Sistem Login =====\n");
//         printf("1. Login\n");
//         printf("2. Daftar Akun Baru\n");
//         printf("Masukkan pilihan (1/2): ");
//         scanf("%d", &pilihan);

//         if (pilihan == 1) {
//             if (login(role)) {
//                 if (strcmp(role, "admin") == 0) {
//                     printf("Selamat datang, Admin!\n");
//                 } else {
//                     printf("Selamat datang, Pengguna!\n");
//                 }

//                 // Arahkan ke file berdasarkan role
//                 buka_file_berdasarkan_role(role);
//             } else {
//                 printf("Gagal login. Silakan coba lagi.\n");
//             }
//         } else if (pilihan == 2) {
//             daftar_akun();
//         } else {
//             printf("Pilihan tidak valid.\n");
//         }
//     }
// }
