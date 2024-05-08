# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Kartika Pringgo Hutomo - 2311102196</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian Stack
Stack adalah struktur data yang mengikuti prinsip operasi Last In, First Out (LIFO), di mana elemen yang disisipkan terakhir akan menjadi elemen yang pertama diambil atau dikeluarkan. Stack dapat digunakan untuk menyimpan sejumlah objek atau variabel dan mempermudah pengguna dalam mengorganisasi data.
### Jenis - jenis Stack
Stack Statik: Stack statik memiliki ukuran yang tetap dan tidak dapat diubah. Implementasi stack statik biasanya menggunakan array, di mana elemen disimpan dalam array dengan akses ke data yang terakhir dimasukkan ke stack.
Stack Dinamis: Stack dinamis dapat menambah atau mengurangi elemen dalam stack tanpa terbatas oleh ukuran. Implementasi stack dinamis biasanya menggunakan linked list, di mana elemen disimpan dalam node dan dapat ditambahkan atau dihapus secara dinamis.
Double-Ended Stack: Double-ended stack dapat melakukan operasi push dan pop pada kedua ujung depan dan belakang stack. Keuntungan dari stack ini adalah memungkinkan akses data dari kedua ujung stack, sehingga menjadi lebih fleksibel.
Circular Stack: Circular stack berbentuk sirkuler dan umumnya diimplementasikan dengan menggunakan array. Keuntungan dari stack ini adalah memori yang tidak boros dan lebih efisien.
Dynamic Stack: Dynamic stack dapat disesuaikan ukurannya selama program berjalan. Implementasi stack ini biasanya menggunakan linked list, di mana elemen disimpan dalam node dan dapat ditambahkan atau dihapus secara dinamis.
Undo-Redo Stack: Undo-redo stack adalah stack yang dipakai untuk melakukan operasi undo dan redo pada sebuah aplikasi. Implementasinya menggunakan linked list, di mana elemen disimpan dalam node dan dapat ditambahkan atau dihapus secara dinamis.
Register Stack: Register stack adalah stack yang hanya mampu menangani sejumlah kecil data dan umumnya digunakan dalam unit memori. Keuntungan dari stack ini adalah memori yang tidak boros dan lebih efisien.
Memory Stack: Memory stack dapat menangani sejumlah besar data memori dengan ketinggian stack yang fleksibel. Keuntungan dari stack ini adalah memungkinkan akses data dari kedua ujung stack, sehingga menjadi lebih fleksibel.
### Fungsi dan Kegunaan Stack
Mengelola Data: Stack digunakan untuk mengelola data berdasarkan prinsip operasi LIFO.
Mengatur Fungsi: Stack digunakan untuk mengatur fungsi yang dipanggil, di mana variabel lokal disimpan dalam stack.
Mengontrol Memori: Stack digunakan untuk mengontrol bagaimana memori dialokasikan dan tidak dialokasikan.

### Operasi pada Stack
Push: Operasi push digunakan untuk menambahkan elemen baru ke dalam stack. Elemen yang ditambahkan ini akan menjadi elemen terakhir yang disimpan dalam stack, sehingga stack akan memiliki elemen yang lebih banyak. Kegunaan push adalah untuk menambahkan data ke dalam stack, seperti dalam kasus penggunaan stack sebagai tumpukan data yang harus diolah secara berurutan.
Pop: Operasi pop digunakan untuk menghapus elemen terakhir yang disimpan dalam stack. Elemen yang dihapus ini adalah elemen yang paling baru ditambahkan ke dalam stack. Kegunaan pop adalah untuk menghapus data yang tidak lagi dibutuhkan dari stack, seperti dalam kasus penggunaan stack sebagai tumpukan data yang harus diolah secara berurutan.
Top: Operasi top digunakan untuk menampilkan elemen terakhir yang disimpan dalam stack. Kegunaan top adalah untuk menampilkan data yang paling baru ditambahkan ke dalam stack, seperti dalam kasus penggunaan stack sebagai tumpukan data yang harus diolah secara berurutan.
IsEmpty: Operasi isempty digunakan untuk memeriksa apakah stack dalam keadaan kosong. Kegunaan isempty adalah untuk memastikan bahwa stack tidak kosong sebelum melakukan operasi pop, sehingga menghindari error yang timbul dari operasi pop pada stack kosong.
IsFull: Operasi isfull digunakan untuk memeriksa apakah stack telah penuh. Kegunaan isfull adalah untuk memastikan bahwa stack tidak penuh sebelum melakukan operasi push, sehingga menghindari error yang timbul dari operasi push pada stack penuh.


   
## Guided 

### Guided 1

```C++
//Kartika Pringgo Hutomo
//2311102198

#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull(){
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku (string data) {
    if (isFull ()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak da data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = " ";
        top --;
    }
}

void peekArrayBuku (int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << "adalah" << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku (int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi dta yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = " ";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout <<  arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " <<isFull() << endl;
    cout << "Apakah data stack kosong? " <<isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "'\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}

```

#### Output :
> ![Screenshot 2024-05-08 204453](https://private-user-images.githubusercontent.com/162521019/328927667-a8d55c09-198e-435b-aadc-3bd075a8d590.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTUxNzg5NTAsIm5iZiI6MTcxNTE3ODY1MCwicGF0aCI6Ii8xNjI1MjEwMTkvMzI4OTI3NjY3LWE4ZDU1YzA5LTE5OGUtNDM1Yi1hYWRjLTNiZDA3NWE4ZDU5MC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTA4JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUwOFQxNDMwNTBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hMzdjYzk4Nzc3M2E3OTBlMDZjNjdlNDM5NTFmOTFmM2U5MWMxYmQ3NzkzNWE1ZDY4OTYwODRkZTQ0MDgyMTUxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.QKftM1gBocQosXmp3R14pfAG9z6PW-YKWtua73prY0A)



Program C++ di atas adalah implementasi sederhana dari struktur data stack menggunakan array untuk mengelola daftar buku. Program memungkinkan pengguna untuk menambah, menghapus, melihat, mengubah, dan menghitung jumlah buku dalam tumpukan.

Dalam program ini, fungsi-fungsi dasar seperti `pushArrayBuku()`, `popArrayBuku()`, dan `peekArrayBuku()` digunakan untuk operasi dasar pada tumpukan. Fungsi `isFull()` dan `isEmpty()` memeriksa apakah tumpukan penuh atau kosong.

Di dalam fungsi `main()`, beberapa buku ditambahkan ke tumpukan menggunakan `pushArrayBuku()` dan kemudian dicetak menggunakan `cetakArrayBuku()`. Program juga memeriksa status tumpukan, menghapus, mengubah, dan menghitung jumlah buku di dalamnya.

Terakhir, program mengosongkan tumpukan menggunakan `destroyArrayBuku()` dan mencetak jumlah buku setelah dihapus. Dengan demikian, program ini memberikan fungsionalitas praktis dalam mengelola daftar buku menggunakan struktur data stack.


## Unguided 

### Unguided 1
### Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
//Kartika Pringgo Hutomo
//2311102196

#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to remove non-alphabetic characters from the sentence
string removeNonAlphabeticCharacters(string str) {
    string result = "";
    for (char c : str) {
        if (isalpha(c)) {
            result += tolower(c);
        }
    }
    return result;
}

// Function to check whether a sentence is a palindrome or not
bool Palindrome(string str) {
    stack<char> characterStack;
    int length = str.length();

    // Pushing the first half of characters into the stack
    for (int i = 0; i < length / 2; i++) {
        characterStack.push(str[i]);
    }

    // Checking the second half of characters with the characters pushed into the stack
    for (int i = length / 2 + (length % 2); i < length; i++) {
        if (str[i] != characterStack.top()) {
            return false;
        }
        characterStack.pop();
    }

    return true;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Removing non-alphabetic characters from the sentence
    string cleanSentence = removeNonAlphabeticCharacters(sentence);

    if (Palindrome(cleanSentence)) {
        cout << "The sentence is a PALINDROME." << endl;
    } else {
        cout << "The sentence is NOT A PALINDROME." << endl;
    }

    return 0;
}


```

#### Output:
> ![Screenshot 2024-05-08 210623](https://private-user-images.githubusercontent.com/162521019/328927878-f4dc4465-e27d-478c-af21-e60c28f66d3e.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTUxNzg5ODYsIm5iZiI6MTcxNTE3ODY4NiwicGF0aCI6Ii8xNjI1MjEwMTkvMzI4OTI3ODc4LWY0ZGM0NDY1LWUyN2QtNDc4Yy1hZjIxLWU2MGMyOGY2NmQzZS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTA4JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUwOFQxNDMxMjZaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04Zjg4OTRlMDk2N2U0YWI4ZDZkYTQ2YzEwZWFiODE3NGM5MWNhYjEzOWZhOGQzMDRiMmQ3YmQyZWVjYjQxOGNkJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.WJJ1YzWHtmFQdJQoKuCmLaq8qCvzfoxDZEgAAwllL9U)



Program di atas merupakan program sederhana dalam bahasa C++ yang bertujuan untuk mengecek apakah sebuah kalimat yang dimasukkan oleh pengguna merupakan palindrom atau tidak. Setelah meminta masukan kalimat dari pengguna, program menghapus karakter non-alfabet dari kalimat tersebut dan mengonversi semua karakter menjadi huruf kecil. 

Selanjutnya, program menggunakan pendekatan tumpukan (stack) untuk membandingkan setengah karakter pertama dengan setengah karakter terakhir dari kalimat. Jika kedua setengah kalimat tersebut sama, maka kalimat dianggap sebagai palindrom.

Akhirnya, program mencetak hasil dari pemeriksaan tersebut, yaitu apakah kalimat tersebut merupakan palindrom atau tidak.


## Unguided 2
### Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
//Kartika Pringgo Hutomo
//2311102196

#include <iostream>
#include <string>

using namespace std;

string arrayData[50];
int maximum = 50, top = 0;

bool isFull() {
    return (top == maximum);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayData(string sentence) {
    if (isFull()) {
        cout << "Data is full" << endl;
    }
    else {
        arrayData[top] = sentence;
        top++;
    }
}

void popArrayData() {
    if (isEmpty()) {
        cout << "No data to remove" << endl;
    }
    else {
        arrayData[top - 1] = "";
        top--;
    }
}


void reverseSentence(string sentence) {
    for (char &c : sentence) {
        pushArrayData(string(1, c)); // Pushing each character into the stack
    }

    string reversedString = "";
    while (!isEmpty()) {
        reversedString += arrayData[top - 1]; // Retrieving characters from the stack to form the reversed sentence
        popArrayData();
    }

    cout << "Result\t: " << reversedString << endl;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "Sentence: " << sentence << endl;
    reverseSentence(sentence);

    return 0;
}

```

#### Output:
> ![Screenshot 2024-05-08 211622](https://private-user-images.githubusercontent.com/162521019/328928254-a3afd9eb-ae5f-471b-b661-b866e775227b.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTUxNzkwNTAsIm5iZiI6MTcxNTE3ODc1MCwicGF0aCI6Ii8xNjI1MjEwMTkvMzI4OTI4MjU0LWEzYWZkOWViLWFlNWYtNDcxYi1iNjYxLWI4NjZlNzc1MjI3Yi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTA4JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUwOFQxNDMyMzBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0wMTgxMGZmMjIwNTkyMDYyMDIwNGI4MmU0Y2NkZWUyNTQ2OWVmMDIzNDA0ZmI4NGZjMjJhZmVmYmI0MjMyNmFiJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.FtL4akoKEczJ5ln0Opt74grd7KEb27jkk4WJeL5Wu-g)



Program C++ ini digunakan untuk membalikkan sebuah kalimat yang dimasukkan oleh pengguna. Program menggunakan array untuk menyimpan karakter-karakter kalimat dan mengubah urutannya menjadi terbalik. Fungsi `reverseSentence()` bertanggung jawab untuk melakukan proses pembalikan kalimat dengan memanfaatkan array sebagai tumpukan. Setelah menerima masukan kalimat dari pengguna, program mencetak kalimat asli dan hasil pembalikan kalimat tersebut.
## Kesimpulan
Kesimpulan dari stack adalah bahwa stack adalah suatu struktur data yang mengikuti prinsip Last In First Out (LIFO), di mana elemen yang terakhir disisipkan akan menjadi elemen pertama yang keluar. Stack digunakan dalam evaluasi dan konversi ekspresi matematika, serta dalam pengelolaan fungsi yang efisien dan kontrol atas memori. Stack juga memiliki kelebihan seperti manajemen data yang efisien, manajemen fungsi yang efisien, kontrol atas memori, manajemen memori cerdas, tidak mudah rusak, dan tidak mengizinkan pengubahan ukuran variabel. Dengan demikian, stack sangat berguna dalam berbagai aplikasi, seperti dalam pengembangan program, analisis data, dan lain-lain.


## Referensi
[1] https://aditajulian05.blogspot.com/2017/04/makalah-struktur-data-stack.html?m=1

[2] https://ids.ac.id/struktur-data-stack-pengertian-jenis-dan-contoh/
