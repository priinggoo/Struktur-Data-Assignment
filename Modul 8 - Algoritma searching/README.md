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
//KARTIKA PRINGGO HUTOMO
//2311102196

#include <iostream>

using namespace std;

int main() {
  // Jumlah data
  int n = 10;

  // Data yang akan dicari
  int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
  int cari = 10;
  int i;
  // Variabel untuk menandakan apakah data ditemukan
  bool ditemukan = false;

  // Algoritma Sequential Search
  for (i = 0; i < n; i++) {
    if (data[i] == cari) {
      ditemukan = true;
      break;
    }
  }

  // Menampilkan hasil pencarian
  cout << "\t Program Sequential Search Sederhana\n" << endl;
  cout << "Data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

  if (ditemukan) {
    cout << "\nAngka " << cari << " ditemukan pada indeks ke-" << i << endl;
  } else {
    cout << cari << " tidak dapat ditemukan pada data." << endl;
  }

  return 0;
}
```
> ![Screenshot 2024-05-21 144939](https://private-user-images.githubusercontent.com/162521019/332336675-23c282f2-7283-495f-ac8e-53b09d3e68c1.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTYyNzg4MjEsIm5iZiI6MTcxNjI3ODUyMSwicGF0aCI6Ii8xNjI1MjEwMTkvMzMyMzM2Njc1LTIzYzI4MmYyLTcyODMtNDk1Zi1hYzhlLTUzYjA5ZDNlNjhjMS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTIxJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyMVQwODAyMDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1kODE5ZmU2N2NjZDQwNjMxMDc5ZjQwMGE3OTNmNzY2YWRiMjk4YWMwZDBkNDNiNTMyMjU1YWYzNzFhNDRhYWYzJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.ABia8DSO6YZZG-fUh9RoFzSh8nhr-YzsI_yz9m5_YNA)



Program di atas adalah implementasi dari algoritma sequential search dalam bahasa C++. Program ini dimulai dengan mendeklarasikan variabel `n` yang berisi jumlah elemen dalam array, yaitu 10. Array `data` berisi sepuluh bilangan bulat, dan variabel `cari` berisi nilai 10 yang akan dicari dalam array. Variabel `ditemukan` digunakan sebagai penanda apakah nilai yang dicari ditemukan dalam array atau tidak. Algoritma sequential search dilakukan dengan melakukan iterasi melalui setiap elemen dalam array `data` dan memeriksa apakah elemen tersebut sama dengan nilai yang dicari. Jika nilai ditemukan, variabel `ditemukan` diatur menjadi `true` dan loop berhenti. Setelah pencarian selesai, program menampilkan pesan hasil pencarian. Jika nilai ditemukan, program mencetak indeks di mana nilai tersebut ditemukan. Jika tidak, program mencetak pesan bahwa nilai tidak ditemukan dalam data. Program ini menunjukkan cara sederhana untuk mencari nilai dalam array menggunakan algoritma sequential search.

     
Guided 2
``` C++
//KARTIKA ORINGGO HUTOMO 
//2311102196

#include <iostream>
#include <iomanip>

using namespace std;

// Deklarasi array dan variabel untuk pencarian
int arrayData[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

// Fungsi selection sort untuk mengurutkan array
void selectionSort(int arr[], int n) {
    int temp, minIndex;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Fungsi binary search untuk mencari data dalam array yang telah diurutkan
void binarySearch(int arr[], int n, int target) {
    int start = 0, end = n - 1, middle, found = 0;

    while (start <= end && found == 0) {
        middle = (start + end) / 2;

        if (arr[middle] == target) {
            found = 1;
        } else if (arr[middle] < target) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }

    if (found == 1) {
        cout << "\nData ditemukan pada indeks ke-" << middle << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH" << endl;

    cout << "\nData awal: ";
    // Menampilkan data awal
    for (int i = 0; i < 7; i++) {
        cout << setw(3) << arrayData[i];
    }
    cout << endl;

    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;

    // Mengurutkan data dengan selection sort
    selectionSort(arrayData, 7);

    cout << "\nData diurutkan: ";
    // Menampilkan data setelah diurutkan
    for (int i = 0; i < 7; i++) {
        cout << setw(3) << arrayData[i];
    }
    cout << endl;

    // Melakukan binary search
    binarySearch(arrayData, 7, cari);

  return 0;
}

```
> ![Screenshot 2024-05-21 145546](https://private-user-images.githubusercontent.com/162521019/332336980-5312d5b2-d9d1-4644-b472-74689198f26c.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTYyNzg4NjgsIm5iZiI6MTcxNjI3ODU2OCwicGF0aCI6Ii8xNjI1MjEwMTkvMzMyMzM2OTgwLTUzMTJkNWIyLWQ5ZDEtNDY0NC1iNDcyLTc0Njg5MTk4ZjI2Yy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTIxJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyMVQwODAyNDhaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05ZTVmODJlZjVmMjg0MjBmM2U4YzMyYTVmNDdiYjhiM2JlZmI4NTdlM2RhNThhMzFkNWFkYTU5MTJmZWY1NzNiJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.vodJShJeiDjNi7KbuNhEwM2vuNKUyr5iev-FWs5jV10)



Program ini mengimplementasikan algoritma selection sort dan binary search dalam bahasa C++. Pertama, program mendeklarasikan sebuah array berisi tujuh bilangan bulat dan sebuah variabel untuk menyimpan nilai yang akan dicari oleh pengguna. Fungsi `selectionSort` mengurutkan array dengan mencari elemen terkecil dalam bagian yang belum terurut dan menukarnya dengan elemen pertama dari bagian tersebut, berulang hingga seluruh array terurut. Setelah itu, fungsi `binarySearch` mencari nilai dalam array yang telah diurutkan dengan memeriksa elemen tengah dan menyesuaikan jangkauan pencarian hingga nilai ditemukan atau jangkauan habis. Pada fungsi `main`, program menampilkan array awal, meminta pengguna memasukkan nilai yang dicari, mengurutkan array menggunakan `selectionSort`, menampilkan array yang sudah diurutkan, lalu mencari nilai tersebut menggunakan `binarySearch` dan menampilkan hasil pencarian. Program ini menunjukkan cara mengurutkan dan mencari nilai dalam array menggunakan algoritma dasar selection sort dan binary search.

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
