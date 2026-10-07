# 📚 Mini Aplikasi Kasir Penjualan Buku

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:1e293b,100:2563eb&height=200&section=header&text=Toko%20Buku%20Wisdom&fontSize=45&fontColor=ffffff&animation=fadeIn&fontAlignY=35" alt="Toko Buku Wisdom"/>
</p>

<p align="center">
  <b>Mini Aplikasi kasir sederhana berbasis C++ untuk mengelola buku, stok, transaksi penjualan, dan mencetak struk.</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-11-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++11"/>
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-16A34A?style=for-the-badge" alt="Platform"/>
  <img src="https://img.shields.io/badge/Type-Console%20Application-7C3AED?style=for-the-badge" alt="Console Application"/>
  <img src="https://img.shields.io/badge/Status-Completed-22C55E?style=for-the-badge" alt="Completed"/>
</p>

---

## 🧾 Tentang Project

**Mini Aplikasi Kasir Penjualan Buku** adalah aplikasi berbasis **C++ console** yang mensimulasikan sistem kasir sederhana pada sebuah toko buku bernama **Toko Buku Wisdom**.

Aplikasi ini memungkinkan pengguna untuk mengelola data buku, menambahkan stok, melakukan transaksi dengan beberapa buku sekaligus, menghitung total pembelian, serta menghasilkan struk transaksi secara otomatis.

Project ini dibuat sebagai media pembelajaran untuk menerapkan konsep dasar hingga menengah dalam bahasa pemrograman C++ ke dalam sebuah aplikasi yang memiliki alur kerja nyata.

---

## ✨ Fitur Utama

| Fitur | Deskripsi |
|---|---|
| 📕 Tambah Buku | Menambahkan buku baru beserta judul, penulis, harga, dan stok |
| 📦 Tambah Stok | Menambah jumlah stok dari buku yang sudah terdaftar |
| 📋 Daftar Buku | Menampilkan seluruh buku beserta harga dan stok |
| 🛒 Keranjang | Memungkinkan pembelian lebih dari satu buku dalam satu transaksi |
| 💰 Perhitungan Total | Menghitung subtotal dan total transaksi secara otomatis |
| 📉 Pengurangan Stok | Stok berkurang setelah transaksi berhasil |
| 🧾 Struk Pembelian | Menampilkan detail transaksi dalam format struk |
| 📄 File Struk | Menyimpan struk transaksi ke file `.txt` |
| 🛡️ Validasi Input | Mencegah input angka, stok, dan jumlah pembelian yang tidak valid |
| ⏳ Loading Animation | Memberikan animasi sederhana saat proses berlangsung |

---

## 🖥️ Preview Menu

Ketika program dijalankan, pengguna akan menemukan menu utama seperti berikut:

```text
========================================
  Selamat Datang di Toko Buku Wisdom
========================================

Menu Utama:
1. Tambah Buku Baru
2. Tambah Stok Buku
3. Daftar Buku
4. Penjualan
5. Keluar
```

---

## 🔄 Alur Sistem

Secara sederhana, alur aplikasi dapat digambarkan seperti berikut:

```text
                ┌──────────────┐
                │  Start App   │
                └──────┬───────┘
                       │
                       ▼
              ┌─────────────────┐
              │ Data Buku Awal  │
              └────────┬────────┘
                       │
                       ▼
               ┌───────────────┐
               │  Menu Utama   │
               └───────┬───────┘
                       │
       ┌───────────────┼────────────────┐
       │               │                │
       ▼               ▼                ▼
  Tambah Buku      Tambah Stok      Daftar Buku
       │               │                │
       └───────────────┼────────────────┘
                       │
                       ▼
                ┌───────────────┐
                │   Penjualan   │
                └───────┬───────┘
                        │
                        ▼
                  ┌───────────┐
                  │ Keranjang │
                  └─────┬─────┘
                        │
                        ▼
                 Hitung Subtotal
                        │
                        ▼
                   Hitung Total
                        │
                        ▼
                  Cetak Struk
                    /       \
                   /         \
                  ▼           ▼
             Console      File .txt
                  │
                  ▼
              Update Stok
                  │
                  ▼
              Menu Utama
```

---

## 📚 Data Buku Awal

Program sudah menyediakan beberapa data buku saat pertama kali dijalankan:

| No | Judul | Penulis | Harga | Stok |
|---:|---|---|---:|---:|
| 1 | Pancasila | Taufiqurrahman | Rp50.000 | 1 |
| 2 | Dasar-Dasar C++ | Fatih Fitra | Rp100.000 | 5 |
| 3 | Belajar Linux Dari Nol | Ali Murtadlo | Rp90.000 | 8 |

Data tersebut dapat dikembangkan dengan menambahkan buku baru melalui menu program.

---

## 🛒 Sistem Penjualan

Pada menu **Penjualan**, pengguna dapat memilih beberapa buku untuk dimasukkan ke keranjang.

Program akan melakukan proses berikut:

```text
Pilih Buku
    ↓
Masukkan Jumlah
    ↓
Validasi Nomor Buku
    ↓
Validasi Jumlah
    ↓
Cek Ketersediaan Stok
    ↓
Masukkan ke Keranjang
    ↓
Tambah Buku Lain?
    ↓
Hitung Total
    ↓
Cetak Struk
    ↓
Kurangi Stok
```

Program juga menangani kondisi ketika **buku yang sama dimasukkan ke keranjang beberapa kali**, sehingga jumlah pembelian tidak dapat melebihi stok yang tersedia.

---

## 🧾 Contoh Struk

Contoh hasil transaksi:

```text
========== STRUK PEMBELIAN ==========
Toko Buku Wisdom
------------------------------------
Dasar-Dasar C++ x2 @Rp100000 = Rp200000
Pancasila x1 @Rp50000 = Rp50000
------------------------------------
TOTAL: Rp250000
Terima kasih telah berbelanja di sini!
```

Selain ditampilkan pada terminal, struk juga disimpan secara otomatis ke:

```text
struk pembelian.txt
```

---

## 🛡️ Input Validation

Salah satu bagian penting dari aplikasi ini adalah **validasi input**.

Program menggunakan template function:

```cpp
template <typename T>
T bacaAngka(const string& prompt)
```

Fungsi tersebut memastikan input angka benar-benar berupa nilai numerik.

Contoh:

```text
Pilih menu: abc
Input harus berupa angka!
Pilih menu:
```

Validasi juga diterapkan pada:

- Nomor buku
- Jumlah stok
- Jumlah pembelian
- Harga buku
- Judul buku
- Ketersediaan stok

Tujuannya adalah mencegah program menerima data yang tidak sesuai dan menjaga agar stok tidak menjadi negatif.

---

## 🧠 Konsep C++ yang Digunakan

Project ini menerapkan berbagai konsep fundamental C++:

### Data Structure

```cpp
struct buku
struct tokoBuku
vector<buku>
vector<Pembelian>
```

### Programming Concepts

- `struct`
- Constructor
- Function
- Template Function
- Reference
- `const`
- `vector`
- `string`
- Conditional Statement
- Looping
- `switch-case`
- Range-based `for`
- Lambda Function

### Standard Library

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <limits>
#include <thread>
#include <chrono>
#include <cstdlib>
```

Library tersebut digunakan untuk menangani input/output, penyimpanan data, formatting terminal, file handling, validasi input, serta animasi sederhana.

---

## 🏗️ Struktur Program

```text
Mini-Aplikasi-Kasir-Penjualan-Buku/
│
├── 📄 Mini-Aplikasi-Kasir-Penjualan-Buku.cpp
│   └── Source code utama aplikasi
│
└── 📖 README.md
    └── Dokumentasi project
```

File hasil transaksi:

```text
struk pembelian.txt
```

akan dibuat ketika transaksi berhasil dan **bukan merupakan source file utama project**.

---

## ⚙️ Cara Menjalankan

### 1. Clone Repository

```bash
git clone https://github.com/herdiansyahdp/Mini-Aplikasi-Kasir-Penjualan-Buku.git
```

### 2. Masuk ke Folder

```bash
cd Mini-Aplikasi-Kasir-Penjualan-Buku
```

### 3. Compile

Pastikan compiler **g++** sudah terpasang.

```bash
g++ -std=c++11 Mini-Aplikasi-Kasir-Penjualan-Buku.cpp -o toko_buku
```

### 4. Jalankan

**Windows:**

```powershell
.\toko_buku.exe
```

**Linux / macOS:**

```bash
./toko_buku
```

> Project menggunakan fitur standar **C++11** dan tidak bergantung pada `windows.h`, sehingga pendekatan program dibuat agar dapat dikompilasi pada berbagai sistem operasi yang memiliki compiler C++ yang kompatibel.

---

## 🧩 Struktur OOP / Program

Walaupun project ini belum menggunakan class secara penuh, program sudah mulai memisahkan tanggung jawab melalui beberapa struktur.

### `struct buku`

Menyimpan informasi buku:

```cpp
struct buku {
    string judul;
    string penulis;
    double harga;
    int stokBuku;
};
```

### `struct tokoBuku`

Menangani aktivitas utama toko:

```cpp
struct tokoBuku {
    vector<buku> stok;

    void tambahBuku(...);
    void tambahStok();
    void tampilanBuku();
    void jualBuku();
    void loading(...);
};
```

Pendekatan ini membuat fungsi-fungsi program lebih terorganisasi dan mudah dikembangkan.

---

## 🎯 Tujuan Pembelajaran

Project ini dibuat untuk memahami bagaimana konsep dasar C++ dapat digunakan untuk membangun sebuah aplikasi sederhana yang memiliki alur bisnis.

```text
Data
  ↓
Validation
  ↓
Processing
  ↓
Transaction
  ↓
Calculation
  ↓
Output
  ↓
File Handling
```

Dari project ini, konsep yang dipelajari tidak hanya mengenai syntax C++, tetapi juga bagaimana menyusun **logic program** agar sebuah aplikasi dapat berjalan secara terstruktur.

---

## 🚀 Pengembangan Selanjutnya

Project ini masih dapat dikembangkan menjadi aplikasi kasir yang lebih lengkap.

Beberapa pengembangan yang dapat dilakukan:

```text
🔹 Edit / hapus data buku
🔹 Pencarian buku
🔹 Penyimpanan database
🔹 Riwayat transaksi
🔹 Login admin / kasir
🔹 Diskon dan pajak
🔹 Perhitungan uang pembayaran & kembalian
🔹 Laporan penjualan
🔹 GUI Desktop
🔹 Sistem inventory yang lebih lengkap
```

---

## 📌 Status Project

```text
████████████████████████████████████████ 100%
```

**Status:** ✅ Completed

Project saat ini berfungsi sebagai aplikasi kasir sederhana berbasis terminal dan sebagai dokumentasi pembelajaran C++.

---

## 👨‍💻 Author

<p align="center">
  <b>Herdiansyah</b><br>
  Teknik Informatika
</p>

<p align="center">
  <a href="https://github.com/herdiansyahdp">
    <img src="https://img.shields.io/badge/GitHub-herdiansyahdp-181717?style=for-the-badge&logo=github" alt="GitHub"/>
  </a>
</p>

---

## ⭐ Support

Project ini dibuat untuk **pembelajaran dan dokumentasi perkembangan programming**.

Kalau project ini bermanfaat, jangan lupa kasih ⭐ pada repository.

<p align="center">
  <i>Built with C++, logic, and a lot of debugging. ☕💻</i>
</p>

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:2563eb,100:1e293b&height=100&section=footer" alt="Footer"/>
</p>
