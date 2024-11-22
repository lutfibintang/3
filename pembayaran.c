#include <stdio.h>
#include <stdlib.h>

void pembayaran(float totalHarga) {
    float jumlahUang, kembalian;
    
    // Menampilkan total harga yang harus dibayar
    printf("Total harga yang harus dibayar: %.2f\n", totalHarga);
    
    // Meminta input jumlah uang yang diberikan oleh pelanggan
    printf("Masukkan jumlah uang yang dibayarkan: ");
    scanf("%f", &jumlahUang);
    
    // Mengecek apakah jumlah uang yang diberikan lebih besar atau sama dengan total harga
    if (jumlahUang >= totalHarga) {
        // Menghitung kembalian
        kembalian = jumlahUang - totalHarga;
        
        // Menampilkan kembalian
        printf("Pembayaran berhasil. Kembalian: %.2f\n", kembalian);
    } else {
        // Jika uang yang diberikan kurang
        printf("Uang yang dibayarkan kurang! Pembayaran gagal.\n");
    }
}

float hitungTotalHarga(FILE *file) {
    char namaBarang[100];
    float harga, totalHarga = 0.0;
    
    // Membaca setiap baris file
    while (fscanf(file, "%s %f", namaBarang, &harga) != EOF) {
        printf("Barang: %s, Harga: %.2f\n", namaBarang, harga);
        totalHarga += harga;  // Menambahkan harga barang ke total harga
    }
    
    return totalHarga;
}

int main() {
    FILE *file;
    float totalHarga;

    // Membuka file barang.txt
    file = fopen("barang.txt", "r");
    
    // Mengecek apakah file berhasil dibuka
    if (file == NULL) {
        printf("File tidak ditemukan!\n");
        return 1;
    }
    
    // Menghitung total harga dari file
    totalHarga = hitungTotalHarga(file);
    
    // Menutup file setelah selesai
    fclose(file);
    
    // Memanggil fungsi pembayaran untuk memproses pembayaran
    pembayaran(totalHarga);
    
    return 0;
}
