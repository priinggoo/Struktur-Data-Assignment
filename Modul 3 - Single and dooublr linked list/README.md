# <h1 align="center">Laporan Praktikum SINGLE AND DOUBLE LINKED LIST</h1>
<p align="center">Karika Pringgo Hutomo</p>


# Dasar Teori
 Linked list adalah sejumlah node yang dihubungkan secara sekuensial, saling bersambungan, dinamis. Senarai berkait adalah struktur data yang paling dasar dan memiliki beberapa kelebihan terhadap array/larik, seperti lebih efisien dalam melaksanakan penyisipan-penyisipan dan penghapusan-penghapusan, menggunakan alokasi penyimpanan secara dinamis, dan memiliki ukuran yang dinamis yang tidak diketahui pada saat kompilasi.
Single linked list adalah jenis linked list yang hanya memiliki satu pointer yang menghubungkan setiap node, sedangkan double linked list memiliki dua pointer, yaitu pointer next dan pointer prev, yang memungkinkan penyisipan-penyisipan dan penghapusan-penghapusan lebih efisien.
Single linked list dapat dibuat dengan menggunakan sebuah variabel pointer yang menunjuk ke node pertama, serta fungsi-fungsi untuk menambahkan node di awal, akhir, dan tengah linked list. Double linked list dibuat dengan menggunakan dua pointer, yaitu pointer next dan pointer prev, serta fungsi-fungsi untuk menambahkan node di awal, akhir, dan tengah linked list, serta menghapus node dari linked list.

# Guided
```C++
1. Program Input Single Linked List
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}

```
Program di atas merupakan implementasi dari single linked list non-circular dalam bahasa pemrograman C++. Ini adalah struktur data dinamis yang terdiri dari sejumlah node, di mana setiap node memiliki data dan pointer yang menunjuk ke node berikutnya. 

Program ini menyediakan fungsi-fungsi dasar untuk mengelola linked list, termasuk penambahan dan penghapusan elemen di depan, belakang, atau di posisi tertentu, pengubahan nilai elemen, serta tampilan isi linked list. 

Dengan menggunakan manipulasi pointer `head` dan `tail`, program ini mengatur aliran data dalam linked list. Hal ini memungkinkan penggunaannya sebagai dasar untuk pengembangan aplikasi yang memerlukan penyimpanan data dinamis dengan struktur linked list.
Guided
``` C++
2. Program Mencari Nilai Maksimal pada Array
#include <iostream>
using namespace std;

// Node structure
struct Node {
    string nama;
    int usia;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert data at the front of the list
    void insertFront(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert data at the end of the list
    void insertEnd(string nama, int usia) {
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to insert data after a specific node
    void insertAfter(string namaAfter, string nama, int usia) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != namaAfter) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with nama " << namaAfter << " not found!" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node by name
    void deleteNode(string nama) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with nama " << nama << " not found!" << endl;
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }

    // Function to display the linked list
    void displayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }

    // Function to update data by name
    void updateData(string oldNama, string newNama, int newUsia) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != oldNama) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node with nama " << oldNama << " not found!" << endl;
            return;
        }
        temp->nama = newNama;
        temp->usia = newUsia;
    }
};

int main() {
    LinkedList list;

    // Menambahkan data awal
    list.insertFront("tiko", 23); // Ganti Nama_anda dan Usia_anda sesuai dengan nama dan usia Anda

    // Menambahkan data sesuai permintaan
    list.insertEnd("John", 19);
    list.insertEnd("Jane", 20);
    list.insertEnd("Michael", 18);
    list.insertEnd("Yusuke", 19);
    list.insertEnd("Akechi", 20);
    list.insertEnd("Hoshino", 18);
    list.insertEnd("Karin", 18);

    // a. Menambahkan data sesuai urutan
    list.insertAfter("John", "Futaba", 18);

    // b. Menghapus data Akechi
    list.deleteNode("Akechi");

    // c. Menambahkan data di awal
    list.insertFront("Igor", 20);

    // e. Mengubah data Michael menjadi Reyn
    list.updateData("Michael", "Reyn", 18);

    // f. Menampilkan seluruh data
    cout << "Seluruh data:" << endl;
    list.displayList();

    return 0;
}
```
Program di atas adalah implementasi dari struktur data linked list dalam bahasa pemrograman C++. Linked list digunakan untuk menyimpan data dalam bentuk node-node yang terhubung. Setiap node memiliki dua bagian: data (nama dan usia dalam program ini) dan pointer yang menunjuk ke node berikutnya.

Kelas `LinkedList` menyediakan beberapa fungsi dasar untuk mengelola linked list, seperti penambahan dan penghapusan data, serta pembaruan dan penampilan isi linked list.

Dalam `main()` function, operasi-operasi dasar dilakukan, termasuk penambahan data di depan dan belakang linked list, penambahan data setelah node tertentu, penghapusan data, pembaruan data, dan penampilan isi linked list.

Program ini memberikan contoh penggunaan linked list dalam menyimpan dan memanipulasi data dengan operasi dasar, seperti penambahan, penghapusan, dan pembaruan data.


Unguided
1. [Soal]
``` C++
///Kartika Pringgo Hutomo
///2311102196

#include <iostream>
#include <string>

using namespace std;

// Node Structure
struct Node {
    string name;
    int age;
    Node* next;
};

// Linked List Class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert data at the end of the list
    void insert(string name, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display all data in the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " " << temp->age << endl;
            temp = temp->next;
        }
    }

    // Function to delete a node based on name
    void deleteNode(string name) {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->name == name) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Function to insert a node after a specific node
    void insertAfter(string prevName, string name, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;

        Node* temp = head;
        while (temp != nullptr && temp->name != prevName) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << prevName << " not found in the list." << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(string name, int age) {
        Node* newNode = new Node;
        newNode->name = name;
        newNode->age = age;

        newNode->next = head;
        head = newNode;
    }

    // Function to update data based on name
    void update(string name, string newName, int newAge) {
        Node* temp = head;
        while (temp != nullptr && temp->name != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << name << " not found in the list." << endl;
            return;
        }

        temp->name = newName;
        temp->age = newAge;
    }
};

int main() {
    LinkedList list;

    // Inserting data
    list.insert("Pringgo", 20);
    list.insert("John", 19);
    list.insert("Jane", 20);
    list.insert("Michael", 18);
    list.insert("Yusuke", 19);
    list.insert("Akechi", 20);
    list.insert("Hoshino", 18);
    list.insert("Karin", 18);

    char choice;
    string name, newName;
    int age, newAge;

    do {
        cout << "Menu:" << endl;
        cout << "a. Display all data" << endl;
        cout << "b. Delete Akechi's data" << endl;
        cout << "c. Add data between John and Jane" << endl;
        cout << "d. Add data at the beginning" << endl;
        cout << "e. Update Michael's data" << endl;
        cout << "f. Exit" << endl;
        cout << "Choose a menu: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                break;
            case 'b':
                list.deleteNode("Akechi");
                cout << "Akechi's data has been deleted." << endl;
                break;
            case 'c':
                cout << "Enter name and age to be added: ";
                cin >> name >> age;
                list.insertAfter("John", name, age);
                break;
            case 'd':
                cout << "Enter name and age to be added at the beginning: ";
                cin >> name >> age;
                list.insertAtBeginning(name, age);
                break;
            case 'e':
                cout << "Enter new name and age for Michael: ";
                cin >> newName >> newAge;
                list.update("Michael", newName, newAge);
                break;
            case 'f':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }

        // Displaying data after each operation
        cout << "Student data:" << endl;
        list.display();
        cout << endl;

    } while (choice != 'f');

    return 0;
}


```

Output: 
> ![Screenshot 2024-03-27 150305](https://private-user-images.githubusercontent.com/162521019/317205715-57517cab-ddb3-4d16-a692-66358ccefae8.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTE1MzE5ODEsIm5iZiI6MTcxMTUzMTY4MSwicGF0aCI6Ii8xNjI1MjEwMTkvMzE3MjA1NzE1LTU3NTE3Y2FiLWRkYjMtNGQxNi1hNjkyLTY2MzU4Y2NlZmFlOC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwMzI3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDMyN1QwOTI4MDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT03NTA0Y2NjY2NkZWYzZWViZjM0NGMxYTRhNmRlNWMzNjA1NjczZmFkMGY4NmE3ODgxMTg0ZDU4NjQ1MWQyOGU5JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.BPglIB3p5E2whVFws2RarZPZ3odSihMcWPw45TO_i4s)

Program di atas merupakan implementasi dari struktur data linked list dalam bahasa pemrograman C++. Linked list adalah struktur data linear di mana elemen-elemennya tidak disimpan dalam lokasi memori yang berurutan; sebaliknya, setiap elemen (node) menunjuk ke elemen berikutnya dalam urutan.

Dalam program ini, linked list direpresentasikan menggunakan kelas bernama `LinkedList`, dan setiap node dari linked list direpresentasikan oleh struktur `Node`. Setiap node berisi dua bidang: `nama` dan `usia`, yang menyimpan nama dan usia seseorang, secara berurutan. Selain itu, setiap node memiliki pointer `next`, yang menunjukkan ke node berikutnya dalam linked list.

Kelas `LinkedList` menyediakan beberapa fungsi anggota untuk memanipulasi linked list:

1. `insert(string name, int age)`: Menyisipkan node baru dengan nama dan usia yang diberikan di akhir linked list.
2. `display()`: Menampilkan semua node dalam linked list, mencetak nama dan usia setiap orang.
3. `deleteNode(string name)`: Menghapus node dengan nama yang ditentukan dari linked list.
4. `insertAfter(string prevName, string name, int age)`: Menyisipkan node baru dengan nama dan usia yang diberikan setelah node dengan nama sebelumnya yang ditentukan.
5. `insertAtBeginning(string name, int age)`: Menyisipkan node baru dengan nama dan usia yang diberikan di awal linked list.
6. `update(string name, string newName, int newAge)`: Memperbarui nama dan usia node dengan nama yang ditentukan.

Pada fungsi `main()`, program menunjukkan penggunaan fungsi anggota ini dengan melakukan berbagai operasi pada linked list berdasarkan input pengguna. Pengguna diberi menu untuk memilih opsi seperti menampilkan semua data, menghapus node tertentu, menambahkan data antara node, menambahkan data di awal, memperbarui data, dan keluar dari program. Setelah setiap operasi, linked list yang diperbarui ditampilkan untuk mencerminkan perubahan yang telah dilakukan. Program ini memberikan contoh praktis tentang bagaimana linked list dapat digunakan untuk mengelola dan memanipulasi data secara dinamis.

2. [Soal]
``` C++
///KartikaPringgoHutomo
///2311102196

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string productName;
    double price;
    Node* prev;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addData(string name, double price) {
        Node* newNode = new Node;
        newNode->productName = name;
        newNode->price = price;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteData(string name) {
        Node* current = head;
        while (current != nullptr) {
            if (current->productName == name) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Product not found!" << endl;
    }

    void updateData(string name, string newName, double newPrice) {
        Node* current = head;
        while (current != nullptr) {
            if (current->productName == name) {
                current->productName = newName;
                current->price = newPrice;
                return;
            }
            current = current->next;
        }
        cout << "Product not found!" << endl;
    }

    void addDataAfter(string name, double price, string after) {
        Node* current = head;
        while (current != nullptr) {
            if (current->productName == after) {
                Node* newNode = new Node;
                newNode->productName = name;
                newNode->price = price;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Product after not found!" << endl;
    }

    void deleteDataAfter(string name) {
        Node* current = head;
        while (current != nullptr) {
            if (current->productName == name) {
                if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Product not found!" << endl;
    }

    void deleteAllData() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    void displayData() {
        Node* current = head;
        
        cout << "Product Name  ||\t Price " << endl;
      
        while (current != nullptr) {
            cout << current->productName << "\t" << current->price << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList productList;
    productList.addData("Originote", 60000);
    productList.addData("Somethinc", 150000);
    productList.addData("Skintific", 100000);
    productList.addData("Wardah", 50000);
    productList.addData("Hanasui", 30000);

    int choice;
    string name, newName, after;
    double price, newPrice;

    do {
       
        cout << "  Purwokerto Skincare Store || " << endl;
       

        cout << "1. Add Data" << endl;
        cout << "2. Delete Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Add Data After Specific Product" << endl;
        cout << "5. Delete Data After Specific Product" << endl;
        cout << "6. Delete All Data" << endl;
        cout << "7. Display Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Product Name: ";
                cin >> name;
                cout << "Price: ";
                cin >> price;
                productList.addData(name, price);
                productList.displayData();
                break;
            case 2:
                cout << "Product Name to delete: ";
                cin >> name;
                productList.deleteData(name);
                productList.displayData();
                break;
            case 3:
                cout << "Product Name to update: ";
                cin >> name;
                cout << "New Product Name: ";
                cin >> newName;
                cout << "New Price: ";
                cin >> newPrice;
                productList.updateData(name, newName, newPrice);
                productList.displayData();
                break;
            case 4:
                cout << "Product Name: ";
                cin >> name;
                cout << "Price: ";
                cin >> price;
                cout << "After Product: ";
                cin >> after;
                productList.addDataAfter(name, price, after);
                productList.displayData();
                break;
            case 5:
                cout << "Product Name to delete after: ";
                cin >> name;
                productList.deleteDataAfter(name);
                productList.displayData();
                break;
            case 6:
                productList.deleteAllData();
                cout << "All data has been deleted." << endl;
                break;
            case 7:
                productList.displayData();
                break;
            case 8:
                cout << "Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
    } 
```
Output:
> ![Screenshot 2024-03-27 161930](https://private-user-images.githubusercontent.com/162521019/317206238-dcdb48bf-8c69-48e7-a98b-364286e76f2d.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTE1MzIwNjcsIm5iZiI6MTcxMTUzMTc2NywicGF0aCI6Ii8xNjI1MjEwMTkvMzE3MjA2MjM4LWRjZGI0OGJmLThjNjktNDhlNy1hOThiLTM2NDI4NmU3NmYyZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwMzI3JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDMyN1QwOTI5MjdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1jMjZjMjAxMWYyOGJkZmYyMDVkM2NjY2MzZTJhNzVhNjQxNTFkZTk2YTMwNmExMDQzMmZmODQzNGQ3ZWEwODdhJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.prWZTXuj2EHQvtINa3PIx5TxWmjTNHmba-FZGOPlWhw)


Program di atas adalah sebuah aplikasi sederhana untuk mengelola daftar produk dalam sebuah toko skincare. Berikut adalah penjelasan singkat mengenai program tersebut:

1. **Struktur Data Node**: Terdapat struktur data `Node` yang digunakan untuk merepresentasikan setiap elemen dalam linked list. Setiap `Node` memiliki dua atribut yaitu `productName` untuk menyimpan nama produk dan `price` untuk menyimpan harga produk. Selain itu, terdapat dua pointer yaitu `prev` untuk menunjuk ke node sebelumnya dan `next` untuk menunjuk ke node selanjutnya.

2. **Class LinkedList**: Kelas `LinkedList` merupakan implementasi dari linked list yang memiliki beberapa metode untuk melakukan operasi seperti menambah data, menghapus data, mengupdate data, dan menampilkan data.

   - Metode `addData(string name, double price)`: Digunakan untuk menambahkan data produk baru ke dalam linked list.
   - Metode `deleteData(string name)`: Digunakan untuk menghapus data produk berdasarkan nama produk.
   - Metode `updateData(string name, string newName, double newPrice)`: Digunakan untuk mengupdate data produk berdasarkan nama produk.
   - Metode `addDataAfter(string name, double price, string after)`: Digunakan untuk menambahkan data produk baru setelah produk tertentu.
   - Metode `deleteDataAfter(string name)`: Digunakan untuk menghapus data produk setelah produk tertentu.
   - Metode `deleteAllData()`: Digunakan untuk menghapus semua data produk dari linked list.
   - Metode `displayData()`: Digunakan untuk menampilkan semua data produk yang ada dalam linked list.

3. **Fungsi `main()`**: Di dalam fungsi `main()`, program menginisialisasi objek `LinkedList` bernama `productList` dan menambahkan beberapa data produk awal. Kemudian, program memberikan pilihan menu kepada pengguna untuk melakukan operasi seperti menambah data, menghapus data, mengupdate data, menampilkan data, dan lainnya. Program akan terus berjalan hingga pengguna memilih opsi keluar.

Dengan menggunakan linked list, program ini dapat mengelola daftar produk dengan efisien, memungkinkan penambahan, penghapusan, dan pengubahan data dengan mudah.

# Kesimpulan

Kesimpulan dari materi single dan double linked list adalah bahwa linked list adalah sebuah struktur data yang dinamis dan efisien untuk menyimpan dan mengelola data. Single linked list hanya memiliki pointer next, sedangkan double linked list memiliki pointer next dan pointer prev, yang memungkinkan lebih banyak operasi, seperti menambahkan dan menghapus node dari list. Double linked list juga dapat digunakan untuk mengurutkan data secara efisien.


# Referensi
[1] https://www.geeksforgeeks.org/difference-between-singly-linked-list-and-doubly-linked-list/
