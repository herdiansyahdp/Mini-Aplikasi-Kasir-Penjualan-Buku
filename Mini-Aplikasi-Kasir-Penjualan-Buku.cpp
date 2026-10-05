#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

// Pengganti Sleep() dari windows.h supaya bisa jalan di OS apa pun
void tunda(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// Baca angka dengan validasi: kalau user ngetik huruf, diulang terus sampai valid
template <typename T>
T bacaAngka(const string& prompt) {
    T nilai;
    while (true) {
        cout << prompt;
        if (cin >> nilai) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // buang sisa baris
            return nilai;
        }
        if (cin.eof()) exit(0); // input sudah habis, hindari loop tak berujung
        cout << "Input harus berupa angka!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Baca satu baris, ambil karakter pertama (aman kalau user ngetik "yes", "ya", dll)
char bacaYN(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    return s.empty() ? 'n' : s[0];
}

struct buku {
    string judul;
    string penulis;
    double harga;
    int stokBuku;

    buku(string j, string p, double h, int s) : judul(j), penulis(p), harga(h), stokBuku(s) {}
};

struct tokoBuku {
    vector<buku> stok;

    // Parameter diganti nama jadi "b" supaya tidak bentrok dengan nama struct "buku"
    void tambahBuku(const buku& b) {
        stok.push_back(b);
    }

    void tambahStok() {
        if (stok.empty()) {
            cout << "Belum ada buku yang terdaftar\n";
            return;
        }
        tampilanBuku();

        int noBuku = bacaAngka<int>("Masukkan nomor buku yang ingin ditambah stoknya: ");
        if (noBuku < 1 || noBuku > (int)stok.size()) {
            cout << "Nomor buku tidak valid!\n";
            return;
        }

        int jumlah = bacaAngka<int>("Masukkan jumlah stok yang ingin ditambahkan: ");
        if (jumlah <= 0) {
            cout << "Jumlah stok harus lebih dari 0!\n";
            return;
        }

        stok[noBuku - 1].stokBuku += jumlah;
        loading("Menambah stok buku");
        cout << "Stok buku \"" << stok[noBuku - 1].judul << "\" berhasil ditambah!\n";
    }

    void tampilanBuku() {
        cout << "========== DAFTAR BUKU ==========\n";
        cout << left << setw(3) << "No" << setw(25) << "Judul" << setw(15) << "Penulis" << setw(12) << "Harga" << "Stok\n";
        cout << "------------------------------------------------------------\n";

        for (size_t i = 0; i < stok.size(); ++i) {
            cout << left << setw(3) << i + 1 << setw(25) << stok[i].judul << setw(15) << stok[i].penulis
                 << "Rp" << setw(10) << fixed << setprecision(0) << stok[i].harga << stok[i].stokBuku << endl;
        }
        cout << endl;
    }

    void jualBuku() {
        struct Pembelian {
            int index;
            int jumlah;
        };

        vector<Pembelian> keranjang;
        char tambah = 'y'; // WAJIB diinisialisasi, karena "continue" di do-while lompat ke pengecekan kondisi
        double total = 0.0;

        do {
            tampilanBuku();

            int noBuku = bacaAngka<int>("Masukkan nomor buku yang ingin dibeli (0 untuk selesai): ");
            if (noBuku == 0) break;
            if (noBuku < 1 || noBuku > (int)stok.size()) {
                cout << "Nomor buku tidak ada!\n";
                continue;
            }
            int idx = noBuku - 1;

            int jumlah = bacaAngka<int>("Masukkan jumlah yang ingin dibeli: ");
            if (jumlah <= 0) {
                cout << "Jumlah harus lebih dari 0!\n";
                continue;
            }

            // Hitung buku yang sama yang sudah ada di keranjang, supaya stok tidak jebol
            int sudahDiKeranjang = 0;
            for (const auto& item : keranjang) {
                if (item.index == idx) sudahDiKeranjang += item.jumlah;
            }

            if (jumlah + sudahDiKeranjang > stok[idx].stokBuku) {
                cout << "Stok buku tidak cukup! Sisa yang bisa dibeli: "
                     << stok[idx].stokBuku - sudahDiKeranjang << "\n";
                continue;
            }

            keranjang.push_back({idx, jumlah});
            total += stok[idx].harga * jumlah;

            tambah = bacaYN("Tambahkan buku lain? (y/n): ");

        } while (tambah == 'y' || tambah == 'Y');

        // Cek keranjang kosong DULU, sebelum mencetak header struk
        if (keranjang.empty()) {
            cout << "Tidak ada pembelian.\n";
            return;
        }

        loading("Mencetak struk");

        // Satu fungsi cetak untuk layar dan file, urutannya sama persis
        auto cetakStruk = [&](ostream& out) {
            out << fixed << setprecision(0); // set eksplisit, supaya angka besar tidak jadi 1.5e+06
            out << "\n========== STRUK PEMBELIAN ==========\n";
            out << "Toko Buku Wisdom\n";
            out << "------------------------------------\n";
            for (const auto& item : keranjang) {
                double subtotal = stok[item.index].harga * item.jumlah;
                out << stok[item.index].judul << " x" << item.jumlah
                    << " @Rp" << stok[item.index].harga << " = Rp" << subtotal << "\n";
            }
            out << "------------------------------------\n";
            out << "TOTAL: Rp" << total << "\n";
            out << "Terima kasih telah berbelanja di sini!\n";
        };

        cetakStruk(cout);

        ofstream file("struk pembelian.txt");
        if (file) {
            cetakStruk(file);
        } else {
            // Transaksi tetap lanjut, jangan di-return sebelum stok dikurangi
            cerr << "Peringatan: gagal membuat file struk, struk hanya tampil di layar.\n";
        }

        for (const auto& item : keranjang) {
            stok[item.index].stokBuku -= item.jumlah;
        }
    }

    void loading(const string& message) {
        cout << "\n" << message << "...\n";
        for (int i = 0; i < 30; ++i) {
            cout << "=";
            tunda(50);
        }
        cout << "\nSelesai!\n";
    }
};

void tampilanWelcome() {
    cout << "Sedang Memuat...\n";
    for (int i = 0; i < 30; ++i) {
        cout << "=";
        tunda(50);
    }
    cout << "\n========================================\n";
    cout << "  Selamat Datang di Toko Buku Wisdom\n";
    cout << "========================================\n";
}

int main() {
    tokoBuku toko;
    int pilih;

    toko.tambahBuku(buku("Pancasila", "Taufiqurrahman", 50000, 1));
    toko.tambahBuku(buku("Dasar-Dasar C++", "Fatih Fitra", 100000, 5));
    toko.tambahBuku(buku("Belajar Linux Dari Nol", "Ali Murtadlo", 90000, 8));

    tampilanWelcome();

    do {
        cout << "\nMenu Utama:\n";
        cout << "1. Tambah Buku Baru\n";
        cout << "2. Tambah Stok Buku\n";
        cout << "3. Daftar Buku\n";
        cout << "4. Penjualan\n";
        cout << "5. Keluar\n";
        pilih = bacaAngka<int>("Pilih menu: ");

        switch (pilih) {
            case 1: {
                string judul, penulis;

                // Tidak perlu cin.ignore() lagi, newline sudah dibuang oleh bacaAngka
                cout << "Masukkan judul buku: ";
                getline(cin, judul);
                cout << "Masukkan nama penulis: ";
                getline(cin, penulis);
                double harga = bacaAngka<double>("Masukkan harga buku: Rp ");
                int stokBuku = bacaAngka<int>("Masukkan jumlah stok buku: ");

                if (judul.empty() || harga <= 0 || stokBuku < 0) {
                    cout << "Data buku tidak valid! (judul kosong, harga <= 0, atau stok negatif)\n";
                    break;
                }

                toko.tambahBuku(buku(judul, penulis, harga, stokBuku));
                toko.loading("Menambahkan buku");
                cout << "Buku berhasil ditambahkan!\n";
                break;
            }
            case 2:
                toko.tambahStok();
                break;
            case 3:
                toko.loading("Memuat daftar buku");
                toko.tampilanBuku();
                break;
            case 4:
                toko.loading("Memproses penjualan");
                toko.jualBuku();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan aplikasi Toko Buku Wisdom!\n";
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilih != 5);

    return 0;
}