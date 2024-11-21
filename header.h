#define HEADER_H

struct Barang {
    char id[10];
    char nama[50];
    float harga;
    int stok;
};

typedef struct {
    char id[10];
    char nama[50];
    float harga;
    int stok;
} barang;

barang brg[100];
int jumlah_barang = 0;
