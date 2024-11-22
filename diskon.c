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

float bacaDiskon(FILE *file) {
    char jenisDiskon[20];
    float persenDiskon = 0.0;
    
    // Membaca jenis diskon dan persentase diskon dari file
    if (fscanf(file, "%s %f", jenisDiskon, &persenDiskon) != EOF) {
        printf("Diskon yang diberikan: %.2f%%\n", persenDiskon);
    }
    
    return persenDiskon;
}

int main() {
    FILE *fileBarang, *fileDiskon;
    float totalHarga, diskon, hargaSetelahDiskon;
    
    // Membuka file barang.txt
    fileBarang = fopen("barang.txt", "r");
    if (fileBarang == NULL) {
        printf("File barang tidak ditemukan!\n");
        return 1;
    }
    
    // Membuka file diskon.txt
    fileDiskon = fopen("diskon.txt", "r");
    if (fileDiskon == NULL) {
        printf("File diskon tidak ditemukan!\n");
        fclose(fileBarang);
        return 1;
    }
    
    // Menghitung total harga dari file barang
    totalHarga = hitungTotalHarga(fileBarang);
    
    // Membaca diskon dari file diskon
    diskon = bacaDiskon(fileDiskon);
    
    // Menutup file setelah selesai digunakan
    fclose(fileBarang);
    fclose(fileDiskon);
    
    // Menghitung harga setelah diskon
    hargaSetelahDiskon = totalHarga - (totalHarga * (diskon / 100));
    
    printf("Harga setelah diskon: %.2f\n", hargaSetelahDiskon);
    
    // Memanggil fungsi pembayaran untuk memproses pembayaran
    pembayaran(hargaSetelahDiskon);
    
    return 0;
}
