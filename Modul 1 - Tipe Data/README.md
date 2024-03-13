# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Karika Pringgo Hutomo</p>

## Dasar Teori


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




Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.
