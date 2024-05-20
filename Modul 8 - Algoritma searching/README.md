# <h1 align="center">Laporan Praktikum Algoritma searching</h1>
<p align="center">Karika Pringgo Hutomo</p>


# Dasar Teori
Dasar Teori Algoritma Searching:

Algoritma searching adalah suatu teknik yang digunakan dalam Artificial Intelligence (AI) untuk mencari suatu solusi melalui langkah sistematis dengan mendefinisikan ruang masalah, aturan produksi, dan metode pencarian yang tepat. Dalam pemrograman, algoritma searching digunakan untuk mencari data dalam suatu aplikasi dengan menggunakan query yang spesifik. Terdapat beberapa jenis algoritma searching, seperti algoritma linear search dan binary search, yang memiliki kelebihan dan kekurangan masing-masing.

### 1. Algoritma Sequential Search

Algoritma Sequential Search adalah suatu metode pencarian data yang membandingkan setiap elemen dalam array secara berurutan, mulai dari elemen pertama, hingga elemen yang dicari ditemukan atau hingga elemen terakhir array. Kelebihan algoritma ini adalah kemampuan untuk melakukan pencarian secara terurut dan efisiensi dalam penggunaan sumber daya komputasi. Namun, kekurangannya adalah waktu pencarian yang relatif lebih lama jika data dalam jumlah besar. Algoritma ini digunakan dalam berbagai aplikasi, seperti pengarsipan data, pencarian data mahasiswa, dan penggunaan dalam sistem pembelajaran.

### 2. Algoritma Binary Search

Algoritma binary search adalah tipe algoritma yang digunakan untuk mencari suatu data dalam suatu array yang telah disortir. Proses ini dilakukan dengan cara membagi array menjadi dua bagian yang sama besar, kemudian membandingkan data yang dicari dengan elemen tengah. Jika data yang dicari lebih kecil dari elemen tengah, maka proses dilanjutkan pada bagian kiri, dan jika lebih besar, maka dilanjutkan pada bagian kanan. Kelebihan algoritma binary search adalah untuk data dalam jumlah besar, waktu searching lebih cepat dan beban komputasi lebih kecil. Namun, kekurangannya adalah data harus sudah disortir lebih dulu, sehingga tidak dapat digunakan untuk data yang tidak disortir.

### 3. Kelebihan dan Kekurangan

Kelebihan algoritma searching adalah dapat digunakan untuk mencari data dalam suatu aplikasi dengan menggunakan query yang spesifik. Namun, kekurangannya adalah dapat memerlukan waktu yang relatif lama untuk mencari data dalam jumlah besar, serta dapat memerlukan sumber daya komputasi yang lebih besar.

### 4. Contoh Penerapan

Contoh penerapan algoritma searching dapat ditemukan dalam berbagai aplikasi, seperti verifikasi password ketika ingin masuk ke akun tertentu, mencari angka terbesar, mengepel lantai, menulis pesan, dan login Facebook. Dalam kehidupan sehari-hari, algoritma searching digunakan untuk menemukan solusi melalui langkah sistematis dengan mendefinisikan ruang masalah, aturan produksi, dan metode pencarian yang tepat.

Dalam sintesis, dasar teori algoritma searching meliputi penggunaan algoritma linear search dan binary search untuk mencari data dalam suatu aplikasi, serta kelebihan dan kekurangan masing-masing. Algoritma searching digunakan dalam berbagai aplikasi dan memiliki implikasi yang signifikan dalam kehidupan sehari-hari.


# Guided 1
```C++

```
     
Guided 2
``` C++

```


Unguided
1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang
sudah di input dengan menggunakan Binary Search!
``` C++
//KARTIKA PRINGGO HUTOMO
//2311102196

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi untuk melakukan binary search
bool binarySearch(const string& sorted_str, char target) {
    int left = 0;
    int right = sorted_str.length() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (sorted_str[middle] == target) {
            return true;
        }

        if (sorted_str[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return false;
}

int main() {
    string kalimat;
    char target;

    // Memasukkan kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Memasukkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    // Menghapus spasi dan mengurutkan kalimat
    kalimat.erase(remove(kalimat.begin(), kalimat.end(), ' '), kalimat.end());
    sort(kalimat.begin(), kalimat.end());

    // Menampilkan kalimat yang sudah diurutkan
    cout << "Kalimat setelah diurutkan: " << kalimat << endl;

    // Mencari huruf menggunakan binary search
    if (binarySearch(kalimat, target)) {
        cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}

```

Output> 
> ![Screenshot 2024-05-21 023853](https://private-user-images.githubusercontent.com/162521019/332181978-2fca75f4-3678-42e9-98fb-ee2c1313cec1.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTYyMzQ0NzEsIm5iZiI6MTcxNjIzNDE3MSwicGF0aCI6Ii8xNjI1MjEwMTkvMzMyMTgxOTc4LTJmY2E3NWY0LTM2NzgtNDJlOS05OGZiLWVlMmMxMzEzY2VjMS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTIwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyMFQxOTQyNTFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0zZGIwNTJkOGNkYWNmMjhlNjE0OTQyZGQwMDVmNmVmNTEzZTIxMTYwZDkxMThmOTkzOTQzNjUxYmI1M2JkY2NjJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.VW6OpI5XRMnAWMRYqI7Fi-Mz2EBC_cCs63pFP7pNYK0)



Program ini ditulis dalam bahasa C++ untuk mencari sebuah huruf dalam kalimat yang diurutkan menggunakan algoritma binary search. Program dimulai dengan mendefinisikan fungsi `binarySearch` yang menerima string terurut dan karakter target, lalu mengembalikan `true` jika karakter ditemukan dan `false` jika tidak. Dalam fungsi `main`, program meminta pengguna untuk memasukkan sebuah kalimat dan karakter yang ingin dicari. Kalimat yang dimasukkan oleh pengguna kemudian dihapus dari spasi menggunakan `erase` dan `remove`, setelah itu diurutkan dengan fungsi `sort`. Kalimat yang sudah diurutkan ditampilkan ke layar. Selanjutnya, program menggunakan fungsi `binarySearch` untuk mencari karakter target dalam kalimat yang sudah diurutkan. Jika karakter ditemukan, program menampilkan pesan bahwa karakter tersebut ditemukan dalam kalimat. Jika tidak, program menampilkan pesan bahwa karakter tersebut tidak ditemukan. Program diakhiri dengan `return 0`, menandakan bahwa eksekusi telah selesai dengan sukses.


2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam
sebuah kalimat!
``` C++
//KARTIKA PRINGGO
//2311102196

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk memeriksa apakah sebuah karakter adalah huruf vokal
bool isVowel(char c) {
    // Mengubah karakter menjadi huruf kecil untuk pemeriksaan
    c = tolower(c);
    // Memeriksa apakah karakter termasuk dalam huruf vokal
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string kalimat;
    int vowelCount = 0;

    // Memasukkan kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghitung jumlah huruf vokal dalam kalimat
    for (char c : kalimat) {
        if (isVowel(c)) {
            vowelCount++;
        }
    }

    // Menampilkan jumlah huruf vokal
    cout << "Jumlah huruf vokal dalam kalimat: " << vowelCount << endl;

    return 0;
}

```
Output:
> ![Screenshot 2024-05-21 024001](https://private-user-images.githubusercontent.com/162521019/332182131-5626ee36-614a-48ee-90e1-2dd87f5c80d5.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTYyMzQ1MDgsIm5iZiI6MTcxNjIzNDIwOCwicGF0aCI6Ii8xNjI1MjEwMTkvMzMyMTgyMTMxLTU2MjZlZTM2LTYxNGEtNDhlZS05MGUxLTJkZDg3ZjVjODBkNS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTIwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyMFQxOTQzMjhaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hMzAyZTY0MWIxNGY1ZjBjODc2ZGEwYjcxNDU5NmM4OGZjZjRhMzVjMjJlNDU3Y2I4NWJmYjg0NGRmZTU5ZDE3JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.O43Hq5KbjWkuCUMNwO78V2ylM9TZliNo4hfvvJm9D-E)



Program ini ditulis dalam bahasa C++ untuk menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna. Program dimulai dengan mendefinisikan fungsi `isVowel` yang menerima satu karakter sebagai argumen dan mengembalikan nilai `true` jika karakter tersebut adalah huruf vokal (a, e, i, o, u), baik huruf kecil maupun besar. Dalam fungsi utama `main`, program mendeklarasikan variabel string `kalimat` untuk menyimpan kalimat yang dimasukkan oleh pengguna dan variabel `vowelCount` untuk menghitung jumlah huruf vokal. Program kemudian meminta pengguna untuk memasukkan sebuah kalimat menggunakan `getline(cin, kalimat)` agar seluruh kalimat dapat diterima termasuk spasi. Setelah kalimat dimasukkan, program menggunakan loop `for` untuk iterasi setiap karakter dalam kalimat dan memeriksa apakah karakter tersebut adalah huruf vokal dengan memanggil fungsi `isVowel`. Jika karakter adalah huruf vokal, `vowelCount` akan ditambah satu. Akhirnya, program menampilkan jumlah huruf vokal yang ditemukan dalam kalimat menggunakan `cout` dan mengakhiri eksekusi dengan `return 0`, menandakan bahwa program telah berjalan dengan sukses.

3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4
dengan menggunakan algoritma Sequential Search!
``` C++
//KARTIKA PRINGGO HUTOMO
//2311102196

#include <iostream>
using namespace std;

int main() {
    // Inisialisasi array data
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen dalam array
    int target = 4; // Angka yang dicari
    int count = 0; // Variabel untuk menghitung jumlah angka target

    // Menggunakan Sequential Search untuk menghitung jumlah angka 4
    for (int i = 0; i < n; ++i) {
        if (data[i] == target) {
            count++;
        }
    }

    // Menampilkan jumlah angka 4 dalam array
    cout << "Jumlah angka " << target << " dalam array adalah: " << count << endl;

    return 0;
}

```

Output:
> ![Screenshot 2024-05-21 024052](https://private-user-images.githubusercontent.com/162521019/332182274-aba5a764-e7ab-4e63-8730-aed7a09c88cd.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTYyMzQ1NDcsIm5iZiI6MTcxNjIzNDI0NywicGF0aCI6Ii8xNjI1MjEwMTkvMzMyMTgyMjc0LWFiYTVhNzY0LWU3YWItNGU2My04NzMwLWFlZDdhMDljODhjZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTIwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyMFQxOTQ0MDdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1jYzZjYjA3Yzk3N2QyOGFhNTNmODliODU4YmM0ZWJlZDkzMGIwNGNlNzZhZmQ3ZjhmN2MxYzJlY2RkMTVjNDBlJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.AgwydZF371C0x6n6Gg-pUa2Ua7gmndh7oQvKeb-hoKs)




Program ini ditulis dalam bahasa C++ untuk menghitung berapa kali angka `4` muncul dalam sebuah array menggunakan metode Sequential Search. Program dimulai dengan mendefinisikan array `data` yang berisi sepuluh elemen integer. Kemudian, variabel `n` dihitung untuk mendapatkan jumlah elemen dalam array tersebut. Angka yang dicari, yaitu `4`, disimpan dalam variabel `target`, dan variabel `count` diinisialisasi dengan nilai `0` untuk menghitung jumlah kemunculan angka `4`. Program menggunakan loop `for` untuk melakukan iterasi dari awal hingga akhir array. Setiap elemen array dibandingkan dengan `target`, dan jika elemen tersebut sama dengan `target`, maka `count` ditambah satu. Setelah loop selesai, program menampilkan jumlah kemunculan angka `4` dalam array. Akhirnya, program selesai dengan mengembalikan nilai `0`, menandakan bahwa eksekusi program telah berhasil.

# Kesimpulan

Algoritma searching adalah suatu teknik yang digunakan untuk mencari suatu solusi melalui langkah sistematis dengan mendefinisikan ruang masalah, aturan produksi, dan metode pencarian yang tepat. Dalam praktiknya, terdapat dua jenis algoritma searching yang umum digunakan: linear search dan binary search. Algoritma linear search relatif lebih cepat dan efisien untuk data yang terbatas, namun kurang cepat untuk data dalam jumlah besar. Sebaliknya, algoritma binary search lebih cepat dan efisien untuk data dalam jumlah besar, namun memerlukan data yang telah disortir.

Kelebihan algoritma searching adalah dapat digunakan untuk mencari data dalam suatu aplikasi dengan menggunakan query yang spesifik. Namun, kekurangannya adalah dapat memerlukan waktu yang relatif lama untuk mencari data dalam jumlah besar, serta dapat memerlukan sumber daya komputasi yang lebih besar. Algoritma searching digunakan dalam berbagai aplikasi, seperti verifikasi password, mencari angka terbesar, dan login Facebook. Dalam sintesis, algoritma searching adalah suatu teknik yang efektif untuk mencari solusi melalui langkah sistematis, namun memerlukan perhatian pada kelebihan dan kekurangannya.


# Referensi
[1] https://www.niagahoster.co.id/blog/algoritma-pemrograman/
[2] https://www.slideshare.net/slideshow/02-teknik-dasar-ai-searchingpdf/257325100
