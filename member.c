#include <stdio.h>
#include <string.h>
#include "header.h"  // Pastikan header.h sudah di-include di sini

// Fungsi untuk menambah member
void tambah_member() {
    struct user newMember;  // Menggunakan struct user langsung tanpa typedef
    
    // Input ID Member
    printf("Masukkan ID Member: ");
    fgets(newMember.id, sizeof(newMember.id), stdin);
    newMember.id[strcspn(newMember.id, "\n")] = '\0';  // Menghapus newline
    
    // Input Nama Member
    printf("Masukkan Nama Member: ");
    fgets(newMember.nama, sizeof(newMember.nama), stdin);
    newMember.nama[strcspn(newMember.nama, "\n")] = '\0'; // Menghapus newline

    // Menyimpan data member ke dalam file member.txt
    FILE *file = fopen("member.txt", "a"); // Mode "a" untuk menambah ke akhir file
    if (file == NULL) {
        printf("Gagal membuka file member.txt.\n");
        return;
    }

    newMember.poin = 0;

    fprintf(file, "%s,%s,%d\n", newMember.nama, newMember.id, newMember.poin); // Menyimpan ID dan Nama Member
    fclose(file);
    
    printf("\n====== Member baru berhasil ditambahkan. ======\n");
}

// Fungsi untuk menampilkan semua member dari file member.txt
void tampilkan_member() {
    FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file member.txt.\n");
        return;
    }

    struct user member;
    printf("\nDaftar Member:\n");
    printf("%-50s %-20s %-10s\n", "Nama", "ID Member", "Poin");

    // Membaca file baris per baris
    while (fscanf(file, "%49[^,],%49[^,],%d\n", member.nama, member.id, &member.poin) == 3) {
        // Menampilkan data member
        printf("%-50s %-20s %-10d\n", member.nama, member.id, member.poin);
    }
    printf("\n");

    fclose(file);
}

// Fungsi untuk menghitung poin berdasarkan total pembelian
int hitung_poin(float total) {
    return total / 1000;  // 1 poin per 1000 pembelian
}

int cek_member(char *nama_member) {
    FILE *file = fopen("member.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file member.txt\n");
        return 0;
    }

    char line[100];  // Buffer untuk membaca baris dari file
    char nama[50];   // Nama yang akan dicocokkan dengan input
    char id[50];     // ID yang akan diabaikan
    while (fgets(line, sizeof(line), file)) {
        // Pisahkan nama dan ID berdasarkan koma
        if (sscanf(line, "%49[^,],%10s", nama, id) == 2) {
            // Menghapus newline jika ada pada nama
            nama[strcspn(nama, "\n")] = '\0';
            // Cek jika nama dalam file cocok dengan nama yang dimasukkan
            if (strcmp(nama_member, nama) == 0) {
                fclose(file);
                return 1;  // Member ditemukan
            }
        }
    }

    fclose(file);
    return 0;  // Member tidak ditemukan
}

void update_member(const char *nama, int poin_tambah) {
    FILE *file = fopen("member.txt", "r+");
    if (file == NULL) {
        printf("Gagal membuka file member.txt\n");
        return;
    }

    char lines[1000] = "";  // Buffer untuk menyimpan data file sementara
    char line[100];
    int found = 0;
    long pos;

    // Membaca file baris per baris dan memodifikasi data member yang cocok
    while (fgets(line, sizeof(line), file)) {
        pos = ftell(file);  // Menyimpan posisi file
        char nama_member[50], id_member[50];
        int poin;

        // Membaca data dalam format nama, id, poin
        if (sscanf(line, "%49[^,],%49[^,],%d", nama_member, id_member, &poin) == 3) {
            if (strcmp(nama_member, nama) == 0) {  // Mencocokkan nama member
                // Member ditemukan, update poinnya
                poin += poin_tambah;  // Menambahkan poin dari pembelanjaan
                sprintf(line, "%s,%s,%d\n", nama_member, id_member, poin); // Format baru
                found = 1;
            }
        }

        // Menambahkan baris ke buffer sementara
        strcat(lines, line);
    }

    if (!found) {
        printf("\n====== Member dengan nama '%s' tidak ditemukan. ======\n\n", nama);
    } else {
        // Menulis seluruh data kembali ke file
        file = freopen("member.txt", "w", file);  // Membuka file kembali untuk menulis ulang
        if (file == NULL) {
            printf("Gagal membuka file member.txt untuk menulis\n");
            return;
        }

        // Menulis seluruh data yang telah diperbarui ke dalam file
        fputs(lines, file);
    }

    fclose(file);
}