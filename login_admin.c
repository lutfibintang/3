#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk login sebagai admin (menggunakan admin.txt)
int login_admin(char *role) {
    char username[20], password[20];
    struct Akun akun;
    FILE *file = fopen("admin.txt", "r");

    if (file == NULL) {
        printf("Gagal membuka file admin.\n");
        return 0;
    }

    printf("\n====== SISTEM LOGIN ADMIN ======\n");
    printf("Masukkan Username: ");
    scanf("%s", username);
    printf("Masukkan Password: ");
    scanf("%s", password);

    while (fscanf(file, "%[^,],%s\n", akun.username, akun.password) != EOF) {
        if (strcmp(username, akun.username) == 0 && strcmp(password, akun.password) == 0) {
            fclose(file);
            strcpy(role, "admin");  // Set role sebagai admin
            printf("\n====== Login berhasil sebagai Admin. ======\n\n");
            return 1;
        }
    }

    fclose(file);
    printf("\n\n===== Username atau password salah. =====\n");
    return 0;
}