# Sorting Program

## Deskripsi
Program ini merupakan implementasi dari tiga algoritma pengurutan: Bubble Sort, Selection Sort, dan Insertion Sort. Program ini juga melakukan pengukuran waktu eksekusi untuk setiap algoritma pada berbagai jumlah bilangan.

## Identitas Mahasiswa
- **Nama:** Muhammad Mahathir
- **NPM:** 2208107010056
- **Mata Kuliah:** Struktur Data dan Algoritma B

## Cara Menjalankan Kode Program

1. **Kompilasi Program**
   - Pastikan Anda memiliki kompiler C seperti GCC terinstal di sistem Anda.
   - Buka terminal dan arahkan ke direktori tempat file `sorting.c` berada.
   - Jalankan perintah berikut untuk mengkompilasi program:
     ```bash
     gcc sorting.c -o sorting
     ```

2. **Menjalankan Program**
   - Setelah berhasil dikompilasi, jalankan program dengan perintah:
     ```bash
     ./sorting
     ```

3. **Hasil Eksekusi**
   - Program akan menghasilkan file output dalam folder `output` yang berisi bilangan yang sudah diurutkan berdasarkan jenis algoritma dan jumlah bilangan.

## Fungsi-fungsi dalam Kode Program

### 1. `saveToFile`
   - Fungsi untuk menyimpan array ke dalam file teks.
   - Parameter:
     - `arr`: Array bilangan integer yang akan disimpan.
     - `n`: Jumlah elemen dalam array.
     - `filename`: Nama file tujuan.

### 2. `bubbleSort`
   - Fungsi untuk melakukan Bubble Sort pada array.
   - Parameter:
     - `arr`: Array bilangan integer yang akan diurutkan.
     - `n`: Jumlah elemen dalam array.
     - `filename`: Nama file untuk menyimpan hasil pengurutan.

### 3. `selectionSort`
   - Fungsi untuk melakukan Selection Sort pada array.
   - Parameter:
     - `arr`: Array bilangan integer yang akan diurutkan.
     - `n`: Jumlah elemen dalam array.
     - `filename`: Nama file untuk menyimpan hasil pengurutan.

### 4. `insertionSort`
   - Fungsi untuk melakukan Insertion Sort pada array.
   - Parameter:
     - `arr`: Array bilangan integer yang akan diurutkan.
     - `n`: Jumlah elemen dalam array.
     - `filename`: Nama file untuk menyimpan hasil pengurutan.

### 5. `printTableBorder`
   - Fungsi untuk mencetak garis tepi tabel pada output.

### 6. `main`
   - Fungsi utama yang menginisialisasi variabel, menghasilkan bilangan acak, menyimpan ke file input, melakukan pengurutan, dan mencetak hasil waktu eksekusi pada tabel.

## Link Penjelasan Program
Untuk penjelasan lebih lanjut tentang program ini, Anda dapat melihat [video penjelasan di sini](https://youtu.be/Fl0qhpmN37I).

## Catatan
- Program ini menggunakan alokasi dinamis untuk mengelola memori.
- Pengukuran waktu eksekusi dilakukan dengan bantuan fungsi `clock()` dari library `time.h`.
