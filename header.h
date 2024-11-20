#ifndef HEADER_H
#define HEADER_H

// Mendeklarasikan variabel
struct Barang {
    char id[10];
    char nama[50];
    float harga;
    int stok;
};

// Definisi struct untuk data akun
struct Akun {
    char username[20];
    char password[20];
    int role; // 1 untuk admin, 2 untuk user
}; 

typedef struct {
    char id[10];
    char nama[50];
    float harga;
    int stok;
} barang;

// user karyawan struct
typedef struct {
    char username[32];
    char id[10];
    unsigned int no_barang;
} user;

void tambah_barang();
void simpan_akun(struct Akun akun);
void daftar_akun();
int login();
void login_atau_daftar();
void buka_file_berdasarkan_role();
void menu_user();
void menu_admin();

#endif