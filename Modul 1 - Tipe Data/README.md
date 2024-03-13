# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Karika Pringgo Hutomo</p>

## Dasar Teori

Tipe data dalam pemrograman adalah konsep yang mendefinisikan jenis nilai yang dapat disimpan dan diolah oleh program komputer. Tipe data menentukan cara data direpresentasikan dalam memori dan jenis operasi yang dapat dilakukan pada data tersebut. Ada dua jenis utama tipe data:

Tipe Data Primitif: Tipe data primitif adalah tipe data dasar yang disediakan oleh bahasa pemrograman untuk merepresentasikan nilai-nilai sederhana seperti angka, karakter, dan boolean. Contoh tipe data primitif termasuk integer, floating-point, character, dan boolean.

Tipe Data Abstrak: Tipe data abstrak adalah konsep yang mengabstraksi representasi data dari implementasi fisiknya. Ini memungkinkan pemrogram untuk berinteraksi dengan data secara konseptual, tanpa perlu memperhatikan detail teknis bagaimana data tersebut disimpan. Contoh tipe data abstrak termasuk list, stack, queue, dan tree

Tipe Data Koleksi: Tipe data koleksi adalah jenis lain dari tipe data yang digunakan dalam pemrograman untuk menyimpan dan mengelola kumpulan nilai atau objek. Tipe data koleksi memungkinkan manipulasi dan akses efisien terhadap sejumlah besar data. Beberapa contoh tipe data koleksi termasuk:
## Guided 

### 1. Tipe Data Primitif 

```C++
#include <iostream>
using namespace std;
// Main program 
int main()
{
    char op;
    float num1, num2;
    cin >> op;
    cin >> num1 >> num2;
    switch (op)
    {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*': 
            cout << num1 * num2;
            break;
        case '/':
            cout << num1 / num2;
            break;
        default:
            cout << "Eror! operator is not correct";

    }
    return 0;
}
```
 Program di atas adalah sebuah program sederhana dalam bahasa pemrograman C++. Program ini bertujuan untuk menerima input berupa sebuah operator (+, -, *, /) dan dua bilangan, lalu melakukan operasi aritmatika yang sesuai dengan operator yang diberikan. Pertama-tama, program mendeklarasikan variabel `op` untuk menyimpan operator dan variabel `num1` dan `num2` untuk menyimpan dua bilangan. Kemudian, program meminta input operator dan dua bilangan tersebut dari pengguna menggunakan fungsi `cin`. Setelah itu, program menggunakan struktur kontrol `switch` untuk memeriksa nilai dari variabel `op`. Jika operator yang diberikan adalah '+', program akan melakukan penambahan `num1` dan `num2` dan menampilkan hasilnya dengan menggunakan `cout`. Begitu juga untuk operator '-', '*', dan '/'. Jika operator yang diberikan tidak sesuai dengan yang diharapkan, program akan menampilkan pesan kesalahan "Error! Operator is not correct". Program kemudian mengembalikan nilai 0 untuk menandakan bahwa program telah selesai dijalankan dengan sukses. Program ini tidak menangani kasus di mana format input tidak sesuai dengan yang diharapkan, seperti jika tidak ada operator atau tidak ada dua bilangan yang diberikan.

## Guided 

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

// struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    // menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Name : %s\n", mhs1.name);
    printf("Address : %s\n", mhs1.address);
    printf("Age : %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Name : %s\n", mhs2.name);
    printf("Address : %s\n", mhs2.address);
    printf("Age : %d\n", mhs2.age);
    return 0;
}
```
Program di atas adalah contoh penggunaan struktur (struct) dalam bahasa pemrograman C untuk menyimpan informasi tentang mahasiswa. Struktur `Mahasiswa` didefinisikan dengan tiga anggota: `name` untuk menyimpan nama mahasiswa, `address` untuk alamatnya, dan `age` untuk usianya. Di dalam fungsi `main()`, dua variabel `mhs1` dan `mhs2` dideklarasikan sebagai objek dari struktur `Mahasiswa`.

Selanjutnya, nilai-nilai untuk setiap anggota struktur dari masing-masing mahasiswa diisi menggunakan operator penugasan. Setelah mengisi data, informasi tentang masing-masing mahasiswa dicetak ke layar menggunakan fungsi `printf()` dengan format yang sesuai. Setiap nilai dari `name`, `address`, dan `age` dicetak dengan menggunakan spesifikasi konversi yang sesuai, yaitu `%s` untuk string dan `%d` untuk integer.

Program ini menunjukkan cara menggunakan struktur untuk mengorganisir dan menyimpan data terkait dalam satu kesatuan yang koheren. Dengan struktur, kita dapat mengelola informasi yang kompleks dan mempermudah pengolahan data dalam program. Program tersebut kemudian mengembalikan nilai `0` untuk menandakan bahwa program telah berjalan dengan sukses.

## Guided 

### 3. Tipe Data Koleksi

```C++
#include <iostream>

using namespace std;

int main()
{
    // deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    // menncetak array
    cout << "Isi array pertama : " << nilai[0] << endl;
    cout << "Isi array kedua :  " << nilai[1] << endl;
    cout << "Isi array ketiga : " << nilai[2] << endl;
    cout << "Isi array keempat : " << nilai[3] << endl;
    cout << "Isi array kelima : " << nilai[4] << endl;
    return 0;
}
```
 Program yang diberikan merupakan contoh sederhana penggunaan array dalam bahasa pemrograman C++. Pertama-tama, sebuah array bernama `nilai` yang memiliki panjang 5 elemen dideklarasikan dan diinisialisasi dengan beberapa nilai. Kemudian, nilai-nilai dalam array tersebut dicetak ke layar menggunakan objek `cout` dari namespace `std`.

Dalam program ini, array `nilai` digunakan untuk menyimpan beberapa nilai bilangan bulat. Setiap elemen array diakses menggunakan indeksnya masing-masing, yang dimulai dari 0 hingga panjang array dikurangi 1. Misalnya, `nilai[0]` merujuk pada elemen pertama array, `nilai[1]` pada elemen kedua, dan seterusnya.

Setelah nilai-nilai array dicetak ke layar menggunakan perintah `cout`, program mengembalikan nilai `0` yang menandakan bahwa program telah berjalan dengan sukses.

Program ini memberikan contoh dasar tentang bagaimana array digunakan dalam pemrograman C++. Array memungkinkan penyimpanan dan pengaksesan sejumlah nilai data yang serupa secara terstruktur dalam satu variabel. Dalam kasus ini, program hanya mencetak nilai-nilai array, namun dalam aplikasi yang lebih kompleks, nilai-nilai dalam array dapat digunakan untuk berbagai macam tujuan seperti perhitungan matematika, pengolahan data, dan banyak lagi.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>

using namespace std;

// Fungsi untuk menghitung luas persegi
float hitungLuasPersegi(float sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung rata-rata sejumlah bilangan
float hitungRataRata(float *bilangan, int jumlahBilangan) {
    float total = 0;
    for (int i = 0; i < jumlahBilangan; ++i) {
        total += bilangan[i];
    }
    return total / jumlahBilangan;
}

// Fungsi untuk menghitung luas lingkaran
float hitungLuasLingkaran(float jariJari) {
    return 3.14 * jariJari * jariJari;
}

int main() {
    // Contoh pemanggilan fungsi hitungLuasPersegi
    float sisiPersegi = 5.5;
    float luasPersegi = hitungLuasPersegi(sisiPersegi);
    cout << "Luas persegi dengan sisi " << sisiPersegi << " adalah: " << luasPersegi << endl;

    // Contoh pemanggilan fungsi hitungRataRata
    float bilangan[] = {10.5, 20.75, 15.25, 12.0, 8.75};
    int jumlahBilangan = sizeof(bilangan) / sizeof(bilangan[0]); // Menghitung jumlah elemen dalam array
    float rataRata = hitungRataRata(bilangan, jumlahBilangan);
    cout << "Rata-rata dari bilangan yang diberikan adalah: " << rataRata << endl;

    // Contoh pemanggilan fungsi hitungLuasLingkaran
    float jariJari = 3.0;
    float luasLingkaran = hitungLuasLingkaran(jariJari);
    cout << "Luas lingkaran dengan jari-jari " << jariJari << " adalah: " << luasLingkaran << endl;

    return 0;
}
```
#### Output:
> ![image](https://private-user-images.githubusercontent.com/162521019/312352754-b0ff6023-5c9f-4241-8cbf-f84a961d0c1d.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTAzMTU4NjAsIm5iZiI6MTcxMDMxNTU2MCwicGF0aCI6Ii8xNjI1MjEwMTkvMzEyMzUyNzU0LWIwZmY2MDIzLTVjOWYtNDI0MS04Y2JmLWY4NGE5NjFkMGMxZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwMzEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDMxM1QwNzM5MjBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0yM2Y1NjFhOGYwOWU0NTFiNTBlNWY0YTczYzRkODZmMjgzMGVhMjczZjNhNDZhYzJlNzRhNDZkZjg3OGM5ODJhJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.NyzLF97i7ax0UjTolBaOkiSa2LTSwLRdQNxyXHhZI7g)



Program yang telah dibuat merupakan sebuah program sederhana dalam bahasa pemrograman C++ yang memiliki tiga fungsi berbeda. Pertama, fungsi hitungLuasPersegi digunakan untuk menghitung luas persegi berdasarkan panjang sisi yang diberikan. Kedua, fungsi hitungRataRata bertujuan untuk menghitung rata-rata dari sejumlah bilangan yang diberikan. Terakhir, fungsi hitungLuasLingkaran digunakan untuk menghitung luas lingkaran berdasarkan jari-jari yang diberikan. Program ini menggunakan tipe data primitif double untuk menyimpan nilai desimal dalam perhitungan. Dalam fungsi main, ketiga fungsi tersebut dipanggil dengan memberikan argumen sesuai dengan kebutuhan masing-masing fungsi. Dengan penggabungan ketiga fungsi tersebut dalam satu program, program menjadi lebih modular dan mudah dipahami. Penggunaan tipe data primitif dalam program ini memungkinkan untuk melakukan operasi matematika dengan akurat dan efisien.


kesimpulan 
Tipe data primitif adalah tipe data yang disediakan oleh bahasa pemrograman secara bawaan untuk merepresentasikan nilai dasar seperti angka, karakter, dan boolean. Mereka merupakan komponen dasar dari bahasa pemrograman dan digunakan untuk menyimpan nilai tunggal. Tipe data primitif umumnya memiliki ukuran dan representasi yang tetap, dan mereka memiliki operasi yang dapat dilakukan secara langsung pada nilai-nilai tersebut. Contoh tipe data primitif termasuk `int`, `float`, `char`, `bool`, dan sebagainya. Mereka sering digunakan untuk menyimpan data sederhana dan melakukan operasi matematika atau logika dasar. Kesimpulannya, tipe data primitif adalah fondasi dari representasi nilai dalam pemrograman, dan mereka penting dalam pembangunan hampir semua jenis aplikasi dan program.


### 2. [Soal]

```C++
#include <iostream>
#include <string>
using namespace std;

// Deklarasi struct untuk representasi kendaraan
struct KendaraanStruct {
    string jenis;
    string merk;
    int tahunProduksi;
    double harga;
};

// Deklarasi class untuk representasi kendaraan
class KendaraanClass {
public:
    // Atribut dari class
    string jenis;
    string merk;
    int tahunProduksi;
    double harga;

    // Metode untuk menampilkan informasi kendaraan
    void displayInfo() {
        cout << "Jenis: " << jenis << endl;
        cout << "Merk: " << merk << endl;
        cout << "Tahun Produksi: " << tahunProduksi << endl;
        cout << "Harga: " << harga << endl;
    }
};

int main() {
    // Menggunakan struct
    KendaraanStruct mobil1;
    mobil1.jenis = "Mobil";
    mobil1.merk = "Toyota";
    mobil1.tahunProduksi = 2020;
    mobil1.harga = 250000000;

    cout << "Informasi Kendaraan Menggunakan Struct:" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Jenis: " << mobil1.jenis << endl;
    cout << "Merk: " << mobil1.merk << endl;
    cout << "Tahun Produksi: " << mobil1.tahunProduksi << endl;
    cout << "Harga: " << mobil1.harga << endl << endl;

    // Menggunakan class
    KendaraanClass mobil2;
    mobil2.jenis = "Mobil";
    mobil2.merk = "Honda";
    mobil2.tahunProduksi = 2018;
    mobil2.harga = 200000000;

    cout << "Informasi Kendaraan Menggunakan Class:" << endl;
    cout << "-------------------------------------" << endl;
    mobil2.displayInfo();

    return 0;
}

```
#### Output:
> ![image](https://private-user-images.githubusercontent.com/162521019/312354609-279f060e-c851-48f3-bfd3-69e23a4df4f8.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTAzMTYyMTQsIm5iZiI6MTcxMDMxNTkxNCwicGF0aCI6Ii8xNjI1MjEwMTkvMzEyMzU0NjA5LTI3OWYwNjBlLWM4NTEtNDhmMy1iZmQzLTY5ZTIzYTRkZjRmOC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwMzEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDMxM1QwNzQ1MTRaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mYTdkZDJhZTczNGExMDllY2UxNjk2Yjc5MzhiYjdhYzJmYjE3MzkwYWU1NDFkZTAyMjMwODg1MzM4YTA2ZmE4JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.VXpXfYpsLIcEJQssqkC3tra-ChrC7JULVj7rTHYDJKc)


`Class` dan `struct` adalah dua konsep penting dalam bahasa pemrograman C++ untuk membuat tipe data baru dengan struktur yang disesuaikan. `Class` memungkinkan definisi tipe baru dengan atribut dan metode, mendukung fitur-fitur seperti inheritance, encapsulation, dan access specifiers. Di sisi lain, `struct` digunakan untuk tipe data dengan atribut, tanpa metode, dan semua anggotanya secara default bersifat `public`. Perbedaan utama antara keduanya adalah dalam hak akses, penggunaan default, dan fitur-fitur seperti inheritance dan encapsulation. Dalam pengembangan aplikasi modern, `class` lebih umum digunakan karena fleksibilitasnya, sementara `struct` berguna untuk kasus sederhana. Pemilihan antara keduanya didasarkan pada kebutuhan dan kompleksitas program, serta gaya dan konvensi pengkodean yang digunakan.

### 3. [Soal]

```C++
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Mendefinisikan map untuk menyimpan nama dan umur
    map<string, int> dataOrang;

    // Meminta pengguna untuk memasukkan data nama dan umur
    int jumlahOrang;
    cout << "Masukkan jumlah orang: ";
    cin >> jumlahOrang;

    for (int i = 0; i < jumlahOrang; ++i) {
        string nama;
        int umur;
        
        cout << "Masukkan nama orang ke-" << i+1 << ": ";
        cin >> nama;
        cout << "Masukkan umur orang ke-" << i+1 << ": ";
        cin >> umur;

        // Menyimpan data nama dan umur ke dalam map
        dataOrang[nama] = umur;
    }

    // Menampilkan daftar nama dan umur yang telah dimasukkan
    cout << "\nData Orang:\n";
    for (const auto& data : dataOrang) {
        cout << "Nama: " << data.first << ", Umur: " << data.second << endl;
    }

    return 0;
}

```
#### Output:
> ![image](https://private-user-images.githubusercontent.com/162521019/312355438-c12b65a4-b489-44fd-8aad-4841e13e989b.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTAzMTYzNzAsIm5iZiI6MTcxMDMxNjA3MCwicGF0aCI6Ii8xNjI1MjEwMTkvMzEyMzU1NDM4LWMxMmI2NWE0LWI0ODktNDRmZC04YWFkLTQ4NDFlMTNlOTg5Yi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwMzEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDMxM1QwNzQ3NTBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05Y2UxMTZlYTBkM2I4YzZjZmVkZWRhNWQ4YzcyZDhhZjkxY2VhMTc0ZjVkZGM1NTQxMTE5ZmQwYjdmOGQxOWRlJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.FEUaW81bWEzLeuGj5nUkIR9ZwSiWyESM3dNNTw1ojRM)


Array adalah kumpulan elemen yang disimpan dalam urutan linier di dalam memori, diakses menggunakan indeks numerik, sementara map adalah struktur data yang memetakan kunci ke nilai, memungkinkan akses ke nilai dengan menggunakan kunci yang unik. Perbedaan utama terletak pada cara penyimpanan dan pengaksesan data, dengan array menyimpan data secara berurutan dengan indeks numerik dan map menyimpan data sebagai pasangan kunci-nilai yang tidak berurutan. Selain itu, array memiliki ukuran tetap, sementara map biasanya memiliki ukuran dinamis yang dapat berubah saat program berjalan. Pemilihan antara keduanya tergantung pada kebutuhan spesifik program, termasuk jenis data yang akan disimpan, kecepatan akses, dan fleksibilitas ukuran data.




## Kesimpulan
Tipe data primitif, abstrak, dan koleksi adalah konsep fundamental dalam pemrograman komputer. Tipe data primitif, seperti integer, float, char, dan boolean, menyediakan representasi dasar untuk nilai-nilai seperti angka, karakter, dan logika. Mereka memiliki ukuran dan perilaku yang telah ditentukan oleh bahasa pemrograman yang digunakan. Di sisi lain, tipe data abstrak, seperti list, stack, queue, dan tree, adalah konsep yang mengabstraksi representasi data dari implementasi fisiknya. Mereka memungkinkan pemrogram untuk berinteraksi dengan data secara konseptual, tanpa perlu memperhatikan detail teknis bagaimana data tersebut disimpan. Sedangkan, koleksi adalah struktur data yang digunakan untuk menyimpan kumpulan nilai atau objek. Mereka bisa berupa tipe data primitif atau tipe data abstrak lainnya, dan menyediakan cara yang efisien untuk mengelola dan memanipulasi data dalam program. Pemahaman konsep-konsep ini penting dalam pengembangan perangkat lunak, karena membantu dalam pemilihan struktur data yang tepat dan penggunaan yang efisien untuk menyelesaikan berbagai masalah komputasi.

## Referensi
[1] Muhammad taufik dwi putra, Deden predeka, dan Ana rahma yuniarti, Belajar Dasar Pemrograman dengan C++.Bandung:WIDANA,2022. 
