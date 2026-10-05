# 📚 Toko Buku Wisdom

Program **Toko Buku Wisdom** adalah aplikasi sederhana berbasis **C++** untuk mengelola data buku dan melakukan transaksi penjualan.

Project ini dibuat sebagai dokumentasi pembelajaran pemrograman C++, khususnya penerapan **struct, vector, function, loop, conditional statement, file handling, input validation, dan lambda function**.

## ✨ Fitur

* ➕ Menambahkan buku baru
* 📦 Menambahkan stok buku
* 📖 Menampilkan daftar buku
* 🛒 Melakukan transaksi penjualan
* 🧺 Menggunakan keranjang pembelian
* 💰 Menghitung subtotal dan total pembayaran
* 🧾 Mencetak struk pembelian
* 📄 Menyimpan struk ke file `.txt`
* ✅ Validasi input angka
* ✅ Validasi jumlah stok dan pembelian
* ⏳ Animasi loading sederhana

## 🧠 Konsep C++ yang Digunakan

Project ini menggunakan beberapa konsep dasar C++, antara lain:

* `struct`
* `vector`
* `string`
* Function
* Constructor
* Reference (`const &`)
* Template function
* Range-based `for`
* Lambda function
* Conditional statement
* Looping
* Input validation
* File handling dengan `ofstream`
* `thread` dan `chrono`
* Manipulasi output dengan `iomanip`

## 📋 Menu Program

Saat program dijalankan, tersedia menu utama:

```text
Menu Utama:
1. Tambah Buku Baru
2. Tambah Stok Buku
3. Daftar Buku
4. Penjualan
5. Keluar
```

### 1. Tambah Buku Baru

User dapat memasukkan:

* Judul buku
* Nama penulis
* Harga buku
* Jumlah stok

### 2. Tambah Stok Buku

User memilih buku berdasarkan nomor kemudian menentukan jumlah stok tambahan.

### 3. Daftar Buku

Menampilkan seluruh buku yang tersedia beserta:

```text
No | Judul | Penulis | Harga | Stok
```

### 4. Penjualan

User dapat memilih beberapa buku dan memasukkannya ke dalam keranjang.

Program akan:

1. Memvalidasi nomor buku.
2. Memvalidasi jumlah pembelian.
3. Mengecek ketersediaan stok.
4. Menghitung subtotal.
5. Menghitung total transaksi.
6. Mengurangi stok setelah transaksi berhasil.
7. Mencetak struk ke layar.
8. Menyimpan struk ke file teks.

### 5. Keluar

Mengakhiri program.

## 🛡️ Validasi Input

Program memiliki fungsi `bacaAngka()` untuk memastikan input numerik valid. Jika user memasukkan huruf ketika program meminta angka, input akan ditolak dan program meminta input kembali.

Program juga melakukan validasi terhadap:

* Nomor buku
* Jumlah stok
* Jumlah pembelian
* Harga buku
* Judul buku
* Stok yang tersedia

Program juga memperhitungkan buku yang sudah masuk ke keranjang agar stok tidak menjadi negatif ketika buku yang sama dipilih beberapa kali dalam satu transaksi.

## 🧾 Contoh Data Awal

Program memiliki beberapa data buku awal:

| Buku                   | Penulis        |     Harga | Stok |
| ---------------------- | -------------- | --------: | ---: |
| Pancasila              | Taufiqurrahman |  Rp50.000 |    1 |
| Dasar-Dasar C++        | Fatih Fitra    | Rp100.000 |    5 |
| Belajar Linux Dari Nol | Ali Murtadlo   |  Rp90.000 |    8 |

## 📁 File Output

Setelah transaksi berhasil, program akan membuat file:

```text
struk pembelian.txt
```

Contoh isi:

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

## ⚙️ Cara Menjalankan

### 1. Clone repository

```bash
git clone https://github.com/USERNAME/NAMA-REPOSITORY.git
```

### 2. Masuk ke folder project

```bash
cd Toko-Buku-Wisdom
```

### 3. Compile

Dengan `g++`:

```bash
g++ -std=c++11 toko_buku.cpp -o toko_buku
```

### 4. Jalankan

Windows:

```powershell
.\toko_buku.exe
```

Linux/macOS:

```bash
./toko_buku
```

## 🗂️ Struktur Project

```text
Toko-Buku-Wisdom/
│
├── toko_buku.cpp
├── README.md
└── .gitignore
```

File `struk pembelian.txt` merupakan file hasil output program dan sebaiknya tidak dimasukkan ke repository sebagai file permanen.

## 🎯 Tujuan Project

Project ini dibuat sebagai media pembelajaran untuk memahami bagaimana konsep dasar C++ dapat digabungkan menjadi sebuah aplikasi sederhana yang memiliki:

**Manajemen data → Validasi input → Keranjang → Transaksi → Perhitungan → Output → File handling**

## 👨‍💻 Author

**Herdiansyah**

Mahasiswa Teknik Informatika

---

⭐ Project ini dibuat untuk keperluan pembelajaran dan dokumentasi perkembangan pemrograman C++.