# <h1 align="center">Laporan Praktikum Modul 5 - Hash Table</h1>
<p align="center">Kartika Pringgo Hutomo - 2311102196</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Hash Table

Hash Table adalah struktur data yang digunakan untuk menyimpan dan mengelola data dengan cepat dan efisien. Ini beroperasi dengan prinsip kunci-nilai, di mana setiap elemen data memiliki kunci yang unik yang digunakan untuk mengakses atau memanipulasinya. Hash Table (Tabel Hash) adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai. Ini menggunakan fungsi hash untuk mengonversi kunci menjadi indeks dalam array. Dengan cara ini, akses ke data menjadi sangat cepat karena kita dapat langsung menghitung indeks tempat data disimpan. Ini cocok untuk pencarian, penyisipan, penghapusan, dan pembaruan data dalam waktu konstan, asalkan tidak ada konflik dalam fungsi hash (collision)[1].

### Kegunaan Struktur Data Hash Table 

- Pencarian Cepat: Dapat digunakan untuk mencari data dengan cepat berdasarkan key. Ini sangat berguna dalam aplikasi seperti basis data, kamus, dan cache.
- Penyimpanan Data: Hash table dapat digunakan untuk menyimpan data dengan efisien. Data dapat diambil dan dimasukkan ke dalam tabel dengan waktu konstan, 
  asalkan tidak ada collision yang signifikan.
- Implementasi Struktur Data Lain: Hash table dapat digunakan untuk mengimplementasikan struktur data lain, seperti set dan map[1].

### Operasi dalam Struktur Data Hash Table

- Pencarian (Search)
- Penyisipan (Insertion)
- Penghapusan (Deletion)
- Update
- Collision Handling
- Resize
- Iterasi[1].

### Cara kerja Struktur Data Hash Table

1. *Inisialisasi*,
Hash Table awalnya dibuat dengan ukuran tertentu, yang biasanya merupakan bilangan prima. Ukuran ini dapat disesuaikan sesuai kebutuhan.

2. *Fungsi Hash*,
Hash Table menggunakan fungsi hash untuk memetakan nilai yang diberikan dengan kunci tertentu ke indeks dalam array. Fungsi hash ini harus menghasilkan nilai yang unik untuk setiap kunci yang berbeda, sehingga elemen-elemen dapat disimpan dengan benar.

3. *Pemetaan Nilai*,
Ketika sebuah elemen baru ditambahkan ke Hash Table, fungsi hash digunakan untuk menentukan indeks tempat elemen tersebut akan disimpan dalam array. Ini memungkinkan akses cepat ke elemen berdasarkan kunci.

4. *Penanganan Bentrokan*,
Dalam beberapa kasus, dua kunci yang berbeda dapat menghasilkan nilai hash yang sama. Ini disebut bentrokan. Hash Table harus memiliki mekanisme untuk menangani bentrokan ini. Beberapa metode yang umum digunakan adalah chaining (menggunakan linked list untuk menyimpan elemen dengan nilai hash yang sama) dan linear probing (mencari slot kosong berikutnya dalam array jika terjadi bentrokan).

5. *Operasi Utama*,
Operasi utama yang digunakan dalam Hash Table adalah pencarian (untuk mencari elemen berdasarkan kunci), penambahan (untuk menambahkan elemen baru), dan penghapusan (untuk menghapus elemen). Fungsi hash digunakan dalam operasi ini untuk menentukan indeks elemen yang akan diakses atau dimodifikasi.

6. *Efisiensi*,
Efisiensi Hash Table tergantung pada efisiensi fungsi hash yang digunakan. Fungsi hash yang baik harus menghasilkan distribusi nilai hash yang merata untuk menghindari bentrokan yang berlebihan[1].


   
## Guided 

### Guided 1

```C++
#include <iostream>;+

using namespace std;

const int MAX_SIZE = 10;

// fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// class hash table
class HashTable
{
private:
    Node **table;

public:
    // konstruktor
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }

    // destruktor
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];

            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }

        delete[] table;
    }

    // insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }

            current = current->next;
        }

        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }

            current = current->next;
        }

        return -1;
    }

    // deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }

                delete current;
                return;
            }

            prev = current;
            current = current->next;
        }
    }

    // traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];

            while (current != nullptr)
            {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;

    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);
    
    // Traversal
    ht.traverse();
    return 0;
}
```

Program tersebut merupakan implementasi sederhana dari hash table dalam C++. Hash table digunakan untuk menyimpan pasangan kunci-nilai. Setiap elemen hash table direpresentasikan oleh struktur data `Node` yang memiliki atribut kunci (`key`) dan nilai (`value`). Fungsi hash sederhana (`hash_func`) digunakan untuk mengonversi kunci menjadi indeks hash. Kelas `HashTable` menyediakan operasi-insert, pencarian, penghapusan, dan penelusuran.

Di dalam `main` function, objek `HashTable` dibuat, dan beberapa operasi dasar seperti operasi-insert, pencarian, penghapusan, dan penelusuran dilakukan untuk mengilustrasikan fungsionalitas hash table. Dengan menggunakan hash table, program ini memungkinkan penyimpanan data yang efisien dengan kompleksitas waktu konstan untuk operasi-operasi dasar.


### Guided 2

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode
{
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    // Hash function
    int hashFunc(string key)
    {
        int hash_val = 0;

        for (char c : key)
        {
            hash_val += c;
        }

        return hash_val % TABLE_SIZE;
    }

    // Insertion
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }

        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Deletion
    void remove(string name)
    {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Searching
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }

        return "";
    }

    // Transversing
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";

            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }

            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : "
         << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : "
         << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : "
         << employee_map.searchByName("Mistah") << endl
         << endl;

    cout << "Hash Table : " << endl;
    employee_map.print();
    return 0;
}
```

Program di atas adalah implementasi sederhana dari hash map dalam C++. Hash map digunakan untuk memetakan nama ke nomor telepon. Berikut adalah penjelasan singkat tentang bagaimana program tersebut berfungsi:

Program mendefinisikan dua kelas utama: `HashNode` untuk merepresentasikan node dalam hash map, dan `HashMap` yang menyediakan fungsionalitas hash map.

Kelas `HashNode` memiliki atribut `name` dan `phone_number` untuk menyimpan pasangan kunci-nilai.

Kelas `HashMap` menggunakan vektor untuk menyimpan data. Fungsi hash sederhana digunakan untuk mengonversi nama menjadi indeks dalam vektor. Metode chaining digunakan untuk menangani kolisi.

Program menyediakan operasi-insert, pencarian, penghapusan, dan pencetakan untuk mengelola data dalam hash map.

Di dalam fungsi `main`, operasi-operasi dasar seperti operasi-insert, pencarian, penghapusan, dan pencetakan dilakukan untuk menunjukkan fungsionalitas hash map. Dengan menggunakan hash map, program ini memungkinkan penyimpanan dan pencarian data yang efisien berdasarkan nama.







## Unguided 

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
### a. Setiap mahasiswa memiliki NIM dan nilai.
### b. Program memiliki tampilan pilihan menu berisi poin C.
### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
//KARTIKA PRINGGO HUTOMO
//2311102196
//IF-11-E

#include <iostream>
#include <string>
#include <list>
using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    int nilai;
    Mahasiswa(string nim, string nama, int nilai) {
        this->nim = nim;
        this->nama = nama;
        this->nilai = nilai;
    }
};

// Hash table menggunakan list untuk menangani kolisi
list<Mahasiswa> hash_table[100];

// Fungsi hash sederhana
int hashFunction(string nim) {
    int sum = 0;
    for (char c : nim) {
        sum += c;
    }
    return sum % 100;
}

// Fungsi untuk menambahkan data baru
void tambahData(string nim, string nama, int nilai) {
    int index = hashFunction(nim);
    hash_table[index].push_back(Mahasiswa(nim, nama, nilai));
    cout << "Data mahasiswa dengan NIM " << nim << ", Nama: " << nama << ", dan nilai " << nilai << " berhasil ditambahkan." << endl;
}

// Fungsi untuk menghapus data
void hapusData(string nim) {
    int index = hashFunction(nim);
    for (list<Mahasiswa>::iterator it = hash_table[index].begin(); it != hash_table[index].end(); it++) {
        if (it->nim == nim) {
            hash_table[index].erase(it);
            cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
            return;
        }
    }
    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
}

// Fungsi untuk mencari data berdasarkan NIM
void cariDataNIM(string nim) {
    int index = hashFunction(nim);
    for (Mahasiswa mahasiswa : hash_table[index]) {
        if (mahasiswa.nim == nim) {
            cout << "Data mahasiswa dengan NIM " << nim << " ditemukan dengan nilai " << mahasiswa.nilai << "." << endl;
            return;
        }
    }
    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
}

// Fungsi untuk mencari data berdasarkan rentang nilai
void cariDataNilai(int nilai_bawah, int nilai_atas) {
    cout << "Data mahasiswa dengan nilai antara " << nilai_bawah << " dan " << nilai_atas << ":" << endl;
    for (int i = 0; i < 100; i++) {
        for (Mahasiswa mahasiswa : hash_table[i]) {
            if (mahasiswa.nilai >= nilai_bawah && mahasiswa.nilai <= nilai_atas) {
                cout << "NIM: " << mahasiswa.nim << ", Nama: " << mahasiswa.nama << ", Nilai: " << mahasiswa.nilai << endl;
            }
        }
    }
}

// Fungsi untuk menampilkan semua data
void tampilkanData() {
    cout << "Daftar Mahasiswa:" << endl;
    for (int i = 0; i < 100; i++) {
        if (!hash_table[i].empty()) {
            cout << "Indeks Hash " << i << ":" << endl;
            for (Mahasiswa mahasiswa : hash_table[i]) {
                cout << "NIM: " << mahasiswa.nim << ", Nama: " << mahasiswa.nama << ", Nilai: " << mahasiswa.nilai << endl;
            }
            cout << endl;
        }
    }
}

int main() {
    int pilihan;
    string nim;
    string nama;
    int nilai;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Cari Data Berdasarkan NIM" << endl;
        cout << "4. Cari Data Berdasarkan Rentang Nilai (80-90)" << endl;
        cout << "5. Tampilkan Semua Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahData(nim, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM: ";
                cin >> nim;
                hapusData(nim);
                break;
            case 3:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cariDataNIM(nim);
                break;
            case 4:
                int nilai_bawah, nilai_atas;
                cout << "Masukkan nilai bawah: ";
                cin >> nilai_bawah;
                cout << "Masukkan nilai atas: ";
                cin >> nilai_atas;
                cariDataNilai(nilai_bawah, nilai_atas);
                break;
            case 5:
                tampilkanData();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}


```

#### Output:
### Tambah Data
> ![Screenshot 2024-04-17 135729](https://private-user-images.githubusercontent.com/162521019/323119493-5396bc45-bc3b-44b8-a6f3-f8690b98c804.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTMzMzg3NjUsIm5iZiI6MTcxMzMzODQ2NSwicGF0aCI6Ii8xNjI1MjEwMTkvMzIzMTE5NDkzLTUzOTZiYzQ1LWJjM2ItNDRiOC1hNmYzLWY4NjkwYjk4YzgwNC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDE3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQxN1QwNzIxMDVaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hNWQyNTI2ZTU1YzU0MGI1M2IxNDU1NDg0MDViYjczM2I3YmQ1N2Y2ZWM4MzMzYzZjNzdjODdkNGZhOWRlNzgxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.V-mu1WgVGvwPJPcJm7R8c4VJvCU4KL5g1frETAwwhHw)


### Tampilan Awal
> ![Screenshot 2024-04-17 135913](https://private-user-images.githubusercontent.com/162521019/323119792-6c714535-9a48-4a2e-89b9-1b6eb353ae44.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTMzMzg4MDEsIm5iZiI6MTcxMzMzODUwMSwicGF0aCI6Ii8xNjI1MjEwMTkvMzIzMTE5NzkyLTZjNzE0NTM1LTlhNDgtNGEyZS04OWI5LTFiNmViMzUzYWU0NC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDE3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQxN1QwNzIxNDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04YWUzNTQwNTc0ZjhiYzA1ZjRjYjU3MDdlODNjNWEzOWI2MzkyMzIxMDAzZGUwMzAyNDU3YjJhNzJkNDY5ODg3JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.XnXE0DEkYIrY_kyGB3lwm8cTeSFFHZ-63Yp0cLh-wOQ)


### Hapus Data
> ![Screenshot 2024-04-17 135949](https://private-user-images.githubusercontent.com/162521019/323120007-77a20d45-80b4-4b1e-8199-161ffb7053d7.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTMzMzg4NDEsIm5iZiI6MTcxMzMzODU0MSwicGF0aCI6Ii8xNjI1MjEwMTkvMzIzMTIwMDA3LTc3YTIwZDQ1LTgwYjQtNGIxZS04MTk5LTE2MWZmYjcwNTNkNy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDE3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQxN1QwNzIyMjFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0yZjYwMWM2YWE1YzdjNDA3YWM0OTVjYmM1MWZjMjA3YWI0ZGNlNzdlODdiZjNkMTkxYjM5ZmI1YjQxNTFhMGIxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.rMhsRtMZpDsBiQCkxxYob0E73AAnkf5n4fOj6pUNPWE)

### Setelah Hapus Data
> ![Screenshot 2024-04-17 140042](https://private-user-images.githubusercontent.com/162521019/323121208-050fe197-e069-43d0-91d8-21528d5cc92c.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTMzMzkwODMsIm5iZiI6MTcxMzMzODc4MywicGF0aCI6Ii8xNjI1MjEwMTkvMzIzMTIxMjA4LTA1MGZlMTk3LWUwNjktNDNkMC05MWQ4LTIxNTI4ZDVjYzkyYy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDE3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQxN1QwNzI2MjNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT01MmY2ZjE4MDE2NTI1ZjkxZWE4ZDI0MTc2OWUxMWMwYzcyOTZkZGNkMzczOWI2Y2FmOTY0MjgzY2RmNzhhYWU3JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.d3UY744GQGR6kWQpIl8J_Ym9WgNefxdF2AKr1TnuB_0)


### Mencari Data Berdasarkan Nim Mahasiswa
> ![Screenshot 2024-04-17 140015](https://private-user-images.githubusercontent.com/162521019/323120756-d39d2a56-0fbb-47ed-a68c-dd3a6b5c1c82.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTMzMzg5ODcsIm5iZiI6MTcxMzMzODY4NywicGF0aCI6Ii8xNjI1MjEwMTkvMzIzMTIwNzU2LWQzOWQyYTU2LTBmYmItNDdlZC1hNjhjLWRkM2E2YjVjMWM4Mi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDE3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQxN1QwNzI0NDdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0zNGE5MDVhNDBlYTQ1YWI3MzBlOWE5MDkyMzJlNzUyYzEwNzk1M2QwYzA5YmMzMzFhZTllM2E2NDAyY2JhMDFjJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.Pwd5ja84PH5-_J9vep8JYU-pZivytYBjICxHwdJ4J2M)

### Mencari Data Mahasiswa Berdasarkan Nilai
> ![Screenshot 2024-04-17 140023](https://private-user-images.githubusercontent.com/162521019/323121003-f1ca8921-45fc-40fe-ac99-936a493f8e58.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTMzMzkwMzcsIm5iZiI6MTcxMzMzODczNywicGF0aCI6Ii8xNjI1MjEwMTkvMzIzMTIxMDAzLWYxY2E4OTIxLTQ1ZmMtNDBmZS1hYzk5LTkzNmE0OTNmOGU1OC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDE3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQxN1QwNzI1MzdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT00MmQ4MzYzOWVhMWY5OGUwNWYzMjEyMDEyOTkyNzU0MDkwMWIwOGMyYWMwOGYzNzM1NWRkZDY2YjU4ZWY0NTYxJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.8PhW-C9j7axOtjmwwJyqVAgkRYOgRrEnjF_uF0DG_hw)





Program tersebut merupakan implementasi sederhana dari hash table untuk menyimpan data mahasiswa. Struktur `Mahasiswa` memiliki NIM, nama, dan nilai. Hash table diimplementasikan sebagai array dari list. Fungsi hash mengonversi NIM menjadi indeks hash. Terdapat fungsi untuk menambah, menghapus, mencari data berdasarkan NIM, mencari data dalam rentang nilai, dan menampilkan semua data. Dalam loop utama, pengguna diberikan pilihan untuk melakukan operasi tertentu hingga keluar dari program.


## Kesimpulan
Kesimpulan dari dasar teori hash table adalah bahwa hash table adalah sebuah struktur data yang digunakan untuk mengorganisir dan mengelola data dengan cepat dan efisien. Hash table menggunakan fungsi hash untuk memetakan kunci-kunci ke dalam range kecil bilangan indeks, yang memungkinkan akses ke data menjadi sangat cepat. Fungsi hash yang digunakan untuk memetakan kunci menjadi indeks dalam array, dan beberapa teknik yang dapat digunakan untuk mengatasi kendala collision, seperti Hash Matrix, Chaining, Re-hashing, Linear Probing, Quadratic Probing, dan Double Hashing. Hash table sering digunakan di berbagai perangkat lunak komputer, terutama untuk larik-larik asosiatif, indeks basis data, caches, dan sets.

## Referensi
[1] https://fikti.umsu.ac.id/struktur-data-hash-table-pengertian-cara-kerja-dan-operasi-hash-table/

[2] https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/#:~:text=A%20hash%20table%20is%20a,function%2C%20hashing%20can%20work%20well.
