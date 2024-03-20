# <h1 align="center">Laporan Praktikum ARRAY</h1>
<p align="center">Karika Pringgo Hutomo</p>


# Dasar Teori

Array adalah struktur data yang terdiri dari kumpulan elemen yang memiliki jenis data yang sama, yang disusun dalam urutan tertentu dan diidentifikasi oleh indeks atau nomor posisi. Dasar-dasar teori array meliputi konsep deklarasi, inisialisasi, akses elemen, ukuran array, operasi pada array, serta penggunaan indeks negatif dan multidimensi. Saat dideklarasikan, array memerlukan spesifikasi tipe data elemen dan ukuran array. Elemen-elemen array dapat diinisialisasi dengan nilai awal dan diakses menggunakan indeksnya, dimulai dari 0 hingga (jumlah_elemen - 1). Array mendukung berbagai operasi seperti penambahan, pengurangan, pencarian, penyisipan, dan penghapusan. Beberapa bahasa pemrograman mendukung indeks negatif untuk mengakses elemen dari akhir array, dan array multidimensi juga digunakan untuk menyimpan data dalam struktur yang lebih kompleks. Dengan pemahaman yang kuat tentang dasar-dasar teorinya, array menjadi alat yang sangat berguna dalam pengembangan perangkat lunak untuk menyimpan, mengelola, dan memanipulasi data secara efisien.

# Guided
```C++
1. Program Input Array Tiga Dimensi
#include <iostream>

using namespace std;

int main()
{
// Deklarasi array
int arr[2][3][3];
// Input elemen 

for (int x = 0; x < 2; x++)
{
    for (int y = 0; y < 3; y++)
    {
        for (int z = 0; z < 3; z++)
        {
             cout << "Input Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            cin >> arr[x][y][z];
        }
    }

    cout << endl;

}

// Output Array
for (int x = 0; x << 2; x++)
{
    for (int y = 0; y < 3; y++)
    {
        for (int z = 0; z < 3; z++)
        { 
            cout << arr[x][y][z] << ends;
        }

        cout << endl;
    }
    cout << endl;
}
}
```
      Program tersebut merupakan contoh penggunaan array multidimensi dalam bahasa C++. Array tiga dimensi `arr` dengan ukuran 2x3x3 digunakan untuk menyimpan data. Melalui loop, program mengisi array dengan input dari pengguna dan kemudian menampilkannya. Loop pertama untuk mengatur lapisan utama, loop kedua untuk baris, dan loop ketiga untuk kolom. Setelah array terisi, program menampilkan isi array tanpa permintaan input lagi. Dengan demikian, program memungkinkan pengguna untuk menginputkan dan melihat data dalam array multidimensi secara efisien.

Guided
``` C++
2. Program Mencari Nilai Maksimal pada Array
#include <iostream>

using namespace std

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukan Panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke -" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks + array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```

Program di atas adalah contoh program sederhana dalam bahasa C++ yang bertujuan untuk menemukan nilai maksimum dalam sebuah array yang diisi oleh pengguna. 

Pertama-tama, program meminta pengguna untuk memasukkan panjang array yang diinginkan, kemudian mendeklarasikan array dengan ukuran sesuai dengan input pengguna. Selanjutnya, program meminta pengguna untuk memasukkan angka-angka yang akan disimpan dalam array.

Setelah array terisi, program menggunakan loop `for` untuk mencari nilai maksimum dalam array tersebut. Saat mencari nilai maksimum, setiap elemen array dibandingkan dengan nilai maksimum yang tersimpan. Jika ditemukan elemen array yang lebih besar dari nilai maksimum yang tersimpan, nilai maksimum diperbarui dengan nilai tersebut.

Terakhir, program menampilkan nilai maksimum yang ditemukan beserta lokasi indeksnya. Namun, perlu diperhatikan bahwa terdapat kesalahan kecil dalam program, yaitu pada baris yang mencari nilai maksimum, harusnya `maks = array[i]` bukan `maks + array[i]` untuk mengganti nilai maksimum ketika ditemukan elemen array yang lebih besar.

Unguided
1. [Soal]
#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah angka: ";
    cin >> n;

    int numbers[n];
    int evenNumbers[n];
    int oddNumbers[n];
    int evenCount = 0;
    int oddCount = 0;

    // Meminta pengguna untuk memasukkan angka ke dalam array
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Memisahkan angka genap dan ganjil
    for (int i = 0; i < n; ++i) {
        if (numbers[i] % 2 == 0) {
            evenNumbers[evenCount++] = numbers[i];
        } else {
            oddNumbers[oddCount++] = numbers[i];
        }
    }

    // Menampilkan data array
    cout << "\nData Array: ";
    for (int i = 0; i < n; ++i) {
        cout << numbers[i];
        if (i < n - 1) {
            cout << " ";
        }
    }

    // Menampilkan angka genap
    cout << "\nNomor Genap: ";
    for (int i = 0; i < evenCount; ++i) {
        cout << evenNumbers[i];
        if (i < evenCount - 1) {
            cout << ", ";
        }
    }

    // Menampilkan angka ganjil
    cout << "\nNomor Ganjil: ";
    for (int i = 0; i < oddCount; ++i) {
        cout << oddNumbers[i];
        if (i < oddCount - 1) {
            cout << ", ";
        }
    }

    return 0;
}

Output> 
"C:\Users\MSI GF63\Pictures\Screenshots\Screenshot 2024-03-20 113032.png"
image

Program tersebut meminta pengguna untuk memasukkan sejumlah angka dan menyimpannya dalam sebuah array. Selanjutnya, program memisahkan angka-angka genap dan ganjil ke dalam dua array terpisah, `evenNumbers` dan `oddNumbers`. Setelah pemisahan, program menampilkan seluruh data array, angka-angka genap, dan ganjil kepada pengguna. Ini dilakukan dengan loop `for` untuk setiap array, serta penambahan tanda koma dan spasi sesuai kebutuhan. Program kemudian mengakhiri eksekusi.

2. [Soal]
#include <iostream>

using namespace std;

int main() {
    int size1, size2, size3;

    // Meminta pengguna untuk memasukkan ukuran elemen array
    cout << "Masukkan ukuran elemen array tiga dimensi:\n";
    cout << "Ukuran dimensi 1: ";
    cin >> size1;
    cout << "Ukuran dimensi 2: ";
    cin >> size2;
    cout << "Ukuran dimensi 3: ";
    cin >> size3;

    // Deklarasi array
    int arr[size1][size2][size3];

    // Input elemen array
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output elemen array
    cout << "Data Array:\n";
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    // Tampilan array
    cout << "\nArray:\n";
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

Output:
image
Program tersebut meminta pengguna untuk memasukkan ukuran elemen dari array tiga dimensi, lalu mendeklarasikan array sesuai dengan ukuran yang dimasukkan. Selanjutnya, program meminta pengguna untuk mengisi array dengan elemen-elemennya. Setelah array terisi, program menampilkan seluruh elemen array beserta indeksnya, dan kemudian menampilkan array secara visual. Terakhir, program mengakhiri eksekusi setelah menampilkan array. Ini memberikan kontrol penuh kepada pengguna untuk menentukan ukuran dan isi array tiga dimensi.

3. [Soal]
#include <iostream>

using namespace std;

int main() {
    int size;
    
    // Meminta pengguna untuk memasukkan ukuran elemen array
    cout << "Masukkan jumlah elemen array: ";
    cin >> size;

    // Meminta pengguna untuk memasukkan elemen array
    int arr[size];
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;
    cout << "\nPilih operasi yang ingin dilakukan:\n";
    cout << "1. Mencari nilai maksimum\n";
    cout << "2. Mencari nilai minimum\n";
    cout << "3. Mencari nilai rata-rata\n";
    cout << "Pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            // Mencari nilai maksimum
            int maxIndex = 0;
            for (int i = 1; i < size; ++i) {
                if (arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }
            cout << "Nilai maksimum dari array adalah: " << arr[maxIndex] << " pada indeks " << maxIndex << endl;
            break;
        }
        case 2: {
            // Mencari nilai minimum
            int minIndex = 0;
            for (int i = 1; i < size; ++i) {
                if (arr[i] < arr[minIndex]) {
                    minIndex = i;
                }
            }
            cout << "Nilai minimum dari array adalah: " << arr[minIndex] << " pada indeks " << minIndex << endl;
            break;
        }
        case 3: {
            // Mencari nilai rata-rata
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                sum += arr[i];
            }
            double average = sum / size;
            cout << "Nilai rata-rata dari array adalah: " << average << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid.\n";
    }

    return 0;
}


Output:
image

Program tersebut meminta pengguna untuk memasukkan jumlah elemen array dan elemen-elemennya. Setelah itu, program meminta pengguna untuk memilih operasi yang ingin dilakukan: mencari nilai maksimum, minimum, atau rata-rata dari elemen-elemen array. Program menggunakan struktur kontrol switch untuk menentukan operasi yang akan dilakukan sesuai dengan pilihan pengguna, dan kemudian menampilkan hasilnya ke layar. Program mengakhiri eksekusi setelah selesai melakukan operasi sesuai dengan pilihan pengguna.

Kesimpulan
Tipe data primitif, abstrak, dan koleksi adalah konsep fundamental dalam pemrograman komputer. Tipe data primitif, seperti integer, float, char, dan boolean, menyediakan representasi dasar untuk nilai-nilai seperti angka, karakter, dan logika. Mereka memiliki ukuran dan perilaku yang telah ditentukan oleh bahasa pemrograman yang digunakan. Di sisi lain, tipe data abstrak, seperti list, stack, queue, dan tree, adalah konsep yang mengabstraksi representasi data dari implementasi fisiknya. Mereka memungkinkan pemrogram untuk berinteraksi dengan data secara konseptual, tanpa perlu memperhatikan detail teknis bagaimana data tersebut disimpan. Sedangkan, koleksi adalah struktur data yang digunakan untuk menyimpan kumpulan nilai atau objek. Mereka bisa berupa tipe data primitif atau tipe data abstrak lainnya, dan menyediakan cara yang efisien untuk mengelola dan memanipulasi data dalam program. Pemahaman konsep-konsep ini penting dalam pengembangan perangkat lunak, karena membantu dalam pemilihan struktur data yang tepat dan penggunaan yang efisien untuk menyelesaikan berbagai masalah komputasi.

Referensi
[1] Muhammad taufik dwi putra, Deden predeka, dan Ana rahma yuniarti, Belajar Dasar Pemrograman dengan C++.Bandung:WIDANA,2022.
