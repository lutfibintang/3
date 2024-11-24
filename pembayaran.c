#include <stdio.h>
#include <string.h>
#include "header.h"

float hitung_total(struct Barang barang, int jumlah_beli) {
    return barang.harga * jumlah_beli;
}

void kasir() {
    struct Barang daftarBarang[100];
    struct user member;  // Menambahkan struct untuk member
    int jumlah_barang = baca_barang(daftarBarang);  // Membaca data barang dari file

    if (jumlah_barang == 0) {
        printf("Tidak ada barang yang tersedia.\n");
        return;
    }

    // Menampilkan daftar barang yang tersedia
    kategori_barang(daftarBarang, jumlah_barang);

    char input_id[10];  // Menggunakan ID barang untuk pencarian
    int jumlah_beli;
    float total_bayar = 0;
    char continue_beli = 'y'; // Variabel untuk melanjutkan pembelian

    // Meminta apakah pembeli member
    char is_member;
    printf("Apakah Anda member? (y/n): ");
    scanf(" %c", &is_member);
    while(getchar() != '\n');  // Menghapus sisa input

    if (is_member == 'y' || is_member == 'Y') {
        // Input nama member
        printf("Masukkan Nama Member: ");
        fgets(member.nama, sizeof(member.nama), stdin);
        member.nama[strcspn(member.nama, "\n")] = '\0';  // Menghapus newline dari nama
        
        // Mengecek apakah member terdaftar
        if (cek_member(member.nama)) {
            printf("Selamat datang %s, member terdaftar!\n", member.nama);
            member.poin = 0; // Inisialisasi poin member
        } else {
            printf("Nama member tidak terdaftar.\n");
            strcpy(member.nama, "Non-Member");  // Jika bukan member
            member.poin = 0;
        }
    } else {
        strcpy(member.nama, "Non-Member");  // Jika bukan member
        member.poin = 0;
    }

    while (continue_beli == 'y' || continue_beli == 'Y') {
        // Input ID barang yang ingin dibeli
        printf("\nMasukkan ID Barang: ");
        fgets(input_id, sizeof(input_id), stdin);
        input_id[strcspn(input_id, "\n")] = '\0';  // Menghapus newline dari input_id

        if (strcmp(input_id, "-") == 0) {
            printf("Proses pembelian dibatalkan.\n");
            return;  // Jika user mengetik '-', batal transaksi
        }

        int found = 0;
        for (int i = 0; i < jumlah_barang; i++) {
            if (strcmp(daftarBarang[i].id, input_id) == 0) {  // Mencari berdasarkan ID
                found = 1;
                // Input jumlah barang yang ingin dibeli
                printf("Masukkan jumlah beli: ");
                if (scanf("%d", &jumlah_beli) != 1 || jumlah_beli <= 0) {
                    printf("Input jumlah beli tidak valid. Harap masukkan angka yang valid.\n");
                    while(getchar() != '\n');  // Clear buffer jika scanf gagal
                    return;
                }

                // Validasi jumlah beli
                if (jumlah_beli > daftarBarang[i].stok) {
                    printf("Stok tidak cukup untuk barang %s. Stok tersisa: %d.\n", daftarBarang[i].nama, daftarBarang[i].stok);
                    return;
                }

                // Menghitung total harga barang setelah diskon
                float harga_total = hitung_diskon(daftarBarang[i], jumlah_beli);
                total_bayar += harga_total;

                // Mengurangi stok barang yang dibeli
                daftarBarang[i].stok -= jumlah_beli;
                printf("Total untuk %s (setelah diskon): %.2f\n", daftarBarang[i].nama, harga_total);

                member.poin += hitung_poin(harga_total);
                
                // Menulis laporan pembelian ke dalam file
                tulis_laporan(member.nama, daftarBarang[i].nama, jumlah_beli, harga_total, member.poin);

                // Menyimpan perubahan stok barang ke dalam file
                tulis_barang(daftarBarang, jumlah_barang);

                break;
            }
        }

        if (!found) {
            printf("Barang dengan ID %s tidak ditemukan.\n", input_id);
        } else {
            
            // Tanya apakah ingin membeli barang lain
            printf("\nApakah Anda ingin membeli barang lain? (y/n): ");
            while (getchar() != '\n'); // Menghapus sisa input sebelumnya
            scanf("%c", &continue_beli);  // Menerima input y/n
            getchar();
        }
    }

    // Menampilkan total pembelian dan poin
    printf("\n====== Total Pembayaran Akhir: %.2f ======\n", total_bayar);
    printf("====== Nama Member: %s, Poin: %d ======\n\n ", member.nama, member.poin);
    update_member(member.nama, member.poin);
}