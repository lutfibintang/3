#include <stdio.h>
#include <string.h>
#include "header.h"

float hitung_diskon(struct Barang barang, int jumlah_beli) {
    float total = hitung_total(barang, jumlah_beli);
    // Menghitung harga setelah diskon
    return total - (total * barang.diskon / 100);
}
