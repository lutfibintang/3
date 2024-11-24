#ifndef HEADER_H
#define HEADER_H

// Definisi struct untuk data akun
struct Akun {
    char username[20];
    char password[20];
}; 

struct Barang{
    char id[10];
    char nama[50];
    int stok;
    float harga;
    float diskon;
};

typedef struct{
    char id[10];
    char nama[50];
    int stok;
    float harga;
    float diskon;
} barang;

// user karyawan struct
struct user{
    char nama[32];
    char id[10];
    int poin;
};

void tambah_barang();
void simpan_akun(struct Akun akun);
void daftar_akun();
int login_user();
void login_atau_daftar();
void buka_file_berdasarkan_role();
void menu_user();
void menu_admin();
int login_admin();
int baca_barang(struct Barang daftarBarang[]);
void tulis_barang(struct Barang daftarBarang[], int jumlah_barang);
void kurangi_stok(struct Barang daftarBarang[], int jumlah_barang);
void tambah_stok(struct Barang daftarBarang[], int jumlah_barang);
int cek_id(const char *id);
void kategori_barang(struct Barang daftarBarang[], int jumlah_barang);
int main();
void hapus_barang();
void kasir();
float hitung_total(struct Barang barang, int jumlah_beli);
void tulis_laporan(char *nama_member, char *nama_barang, int jumlah_beli, float harga_total, int poin);
void tambah_member();
void tampilkan_member();
float hitung_diskon(struct Barang barang, int jumlah_beli);
int hitung_poin(float total);
int cek_member(char *nama_member);
void update_member(const char *nama, int poin_tambah);

#endif