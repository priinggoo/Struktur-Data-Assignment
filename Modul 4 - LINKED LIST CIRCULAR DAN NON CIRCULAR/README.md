# <h1 align="center">Laporan Praktikum Modul 4 - Linked list Circular</h1>
<p align="center">Kartika Pringgo Hutomo - 2311102196</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Linked List Circular
Linked List Circular adalah variasi dari struktur data Linked List linier di mana node terakhir menunjuk kembali ke node pertama, membentuk suatu lingkaran tertutup. Setiap node terdiri dari data dan pointer yang menunjuk ke node berikutnya. Ada dua jenis, yaitu Singly Linked List Circular dan Doubly Linked List Circular.

### Linked List Non Circular

Linked List Non Circular adalah struktur data yang terdiri dari kumpulan node yang terhubung secara linear. Setiap node terdiri dari dua bagian: data dan pointer. Data adalah informasi yang disimpan dalam node, sedangkan pointer adalah alamat memori dari node berikutnya.
   
## Guided 

### 1. Linked List Non Circular

```C++
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;
Node *tail;

// inialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}

// pengecekan
bool isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// tambah depan
void insertDepan(int nilai)
{
    // buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
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

// tambah belakang
void insertBelakang(int nilai)
{
    // buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty())
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

// hitung jumlah list
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

// tambah tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan di tengah" << endl;
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

// hapus depan
void hapusDepan()
{
    Node *hapus;

    if (!isEmpty())
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
        cout << "List Kosong!" << endl;
    }
}

// hapus belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;

    if (!isEmpty())
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
        cout << "List Kosong!" << endl;
    }
}

// hapsu tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;

    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan di tengah" << endl;
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

// ubah depan
void ubahDepan(int data)
{
    if (!isEmpty())
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// ubah tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;

    if (!isEmpty())
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan di tengah" << endl;
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
        cout << "List masih kosong" << endl;
    }
}

// ubah belakang
void ubahBelakang(int data)
{
    if (!isEmpty())
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong" << endl;
    }
}

// hapus list
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

// tampilkan list
void tampil()
{
    Node *bantu;
    bantu = head;

    if (!isEmpty())
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

Program ini memiliki fungsi-fungsi dasar untuk operasi pada linked list, seperti penambahan, penghapusan, dan pengubahan elemen. Fungsi-fungsi tersebut mencakup pengecekan apakah linked list kosong, penambahan elemen di depan, di belakang, atau di tengah linked list, penghapusan elemen di depan, di belakang, atau di tengah linked list, pengubahan nilai elemen di depan, di belakang, atau di tengah linked list, penghapusan seluruh isi linked list, dan menampilkan isi linked list

### 2. Linked List Circular

```C++

#include <iostream>

using namespace std;


// program single linked list circular

// deklarasi struct node
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// pengecekan
bool isEmpty()
{
    if (head == NULL)
    {
        return 1; // true
    }
    else
    {
        return 0; // false
    }
}

// buat node baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// hitung list
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// tambah depan
void insertDepan(string data)
{
    // buat node baru
    buatNode(data);

    if (isEmpty())
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// tambah belakan
void insertBelakang(string data)
{
    // buat node baru
    buatNode(data);

    if (isEmpty())
    {
        head = baru;
        tail = head;
        tail->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
        tail = baru;
    }
}

// tambah tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty())
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// hapus depan
void hapusDepan()
{
    if (!isEmpty())
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus belakang
void hapusBelakang()
{
    if (!isEmpty())
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }

            while (tail->next != hapus)
            {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus tengah
void hapusTengah(int posisi)
{
    if (!isEmpty())
    {
        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// hapus list
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

// tampilkan list
void tampil()
{
    if (!isEmpty())
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

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
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```
Dalam program ini, digunakan struct Node yang memiliki dua bagian: data dan pointer ke Node berikutnya. Terdapat fungsi-fungsi untuk melakukan operasi-operasi dasar pada linked list, seperti pengecekan apakah linked list kosong, penambahan elemen di depan, di belakang, atau di tengah linked list, penghapusan elemen di depan, di belakang, atau di tengah linked list, penghapusan seluruh isi linked list, dan menampilkan isi linked list



## Unguided 

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1:

```C++
//Kartika Pringgo Hutomo
//2311102106

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string id;
    Student* next;
};

class CircularLinkedList {
private:
    Student* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Add a student to the front
    void addFront(string name, string id) {
        Student* newStudent = new Student;
        newStudent->name = name;
        newStudent->id = id;

        if (head == nullptr) {
            head = newStudent;
            newStudent->next = head;
        } else {
            Student* last = head;
            while (last->next != head) {
                last = last->next;
            }
            newStudent->next = head;
            last->next = newStudent;
            head = newStudent;
        }
        cout << "Student successfully added to the front." << endl;
    }

    // Add a student to the back
    void addBack(string name, string id) {
        Student* newStudent = new Student;
        newStudent->name = name;
        newStudent->id = id;

        if (head == nullptr) {
            head = newStudent;
            newStudent->next = head;
        } else {
            Student* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newStudent;
            newStudent->next = head;
        }
        cout << "Student successfully added to the back." << endl;
    }

    // Add a student in the middle
    void addMiddle(string name, string id, int position) {
        if (position <= 0) {
            cout << "Position must be greater than 0." << endl;
            return;
        }
        Student* newStudent = new Student;
        newStudent->name = name;
        newStudent->id = id;

        if (head == nullptr) {
            head = newStudent;
            newStudent->next = head;
            cout << "Student successfully added in the middle." << endl;
            return;
        }

        Student* temp = head;
        int count = 1;
        while (count < position - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (count < position - 1) {
            cout << "Position is too large." << endl;
            return;
        }

        newStudent->next = temp->next;
        temp->next = newStudent;
        cout << "Student successfully added in the middle." << endl;
    }

    // Modify data of the first student
    void modifyFront(string name, string id) {
        if (head == nullptr) {
            cout << "Empty Linked List." << endl;
            return;
        }
        head->name = name;
        head->id = id;
        cout << "Data of the first student successfully modified." << endl;
    }

    // Modify data of the last student
    void modifyBack(string name, string id) {
        if (head == nullptr) {
            cout << "Empty Linked List." << endl;
            return;
        }
        Student* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->name = name;
        temp->id = id;
        cout << "Data of the last student successfully modified." << endl;
    }

    // Modify data of a student in the middle
    void modifyMiddle(string name, string id, int position) {
        if (head == nullptr) {
            cout << "Empty Linked List." << endl;
            return;
        }
        Student* temp = head;
        int count = 1;
        while (count < position && temp->next != head) {
            temp = temp->next;
            count++;
        }
        if (count != position) {
            cout << "Position is too large." << endl;
            return;
        }
        temp->name = name;
        temp->id = id;
        cout << "Data of student at position " << position << " successfully modified." << endl;
    }

    // Delete data of the first student
    void deleteFront() {
        if (head == nullptr) {
            cout << "Empty Linked List." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Student* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Student* del = head;
            head = head->next;
            temp->next = head;
            delete del;
        }
        cout << "Data of the first student successfully deleted." << endl;
    }

    // Delete data of the last student
    void deleteBack() {
        if (head == nullptr) {
            cout << "Empty Linked List." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Student* temp = head;
            Student* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
        cout << "Data of the last student successfully deleted." << endl;
    }

    // Delete data of a student in the middle
    void deleteMiddle(int position) {
        if (head == nullptr) {
            cout << "Empty Linked List." << endl;
            return;
        }
        if (position <= 0) {
            cout << "Position must be greater than 0." << endl;
            return;
        }
        Student* temp = head;
        Student* prev = nullptr;
        int count = 1;
        while (count < position && temp->next != head) {
            prev = temp;
            temp = temp->next;
            count++;
        }
        if (count != position) {
            cout << "Position is too large." << endl;
            return;
        }
        if (temp == head) {
            deleteFront();
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Data of student at position " << position << " successfully deleted." << endl;
    }

    // Delete all student data
    void deleteList() {
        if (head == nullptr) {
            cout << "Empty Linked List" << endl;
            return;
        }
        Student* current = head;
        Student* next = nullptr;
        while (current->next != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete current;
        head = nullptr;
        cout << "All student data successfully deleted." << endl;
    }

    // Display list of students
    void display() {
        if (head == nullptr) {
            cout << "Empty Linked List." << endl;
            return;
        }
        Student* temp = head;
        do {
            cout << "Name: " << temp->name << ", ID: " << temp->id << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    CircularLinkedList list;
    int choice;
    string name, id;
    int position;

    do {
        cout << "\nLIST OF STUDENT DATA||\n";
        cout << "Menu :\n";
        cout << "1. Add to Front\n";
        cout << "2. Add to Back\n";
        cout << "3. Add to Middle\n";
        cout << "4. Modify Front\n";
        cout << "5. Modify Back\n";
        cout << "6. Modify Middle\n";
        cout << "7. Delete Front\n";
        cout << "8. Delete Back\n";
        cout << "9. Delete Middle\n";
        cout << "10. Delete List\n";
        cout << "11. Display Data\n";
        cout << "0. Exit\n";
        cout << "Choose Operation: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                list.addFront(name, id);
                break;
            case 2:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                list.addBack(name, id);
                break;
            case 3:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Position: ";
                cin >> position;
                list.addMiddle(name, id, position);
                break;
            case 4:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                list.modifyFront(name, id);
                break;
            case 5:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                list.modifyBack(name, id);
                break;
            case 6:
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Position: ";
                cin >> position;
                list.modifyMiddle(name, id, position);
                break;
            case 7:
                list.deleteFront();
                break;
            case 8:
                list.deleteBack();
                break;
            case 9:
                cout << "Enter Position: ";
                cin >> position;
                list.deleteMiddle(position);
                break;
            case 10:
                list.deleteList();
                break;
            case 11:
                list.display();
                break;
            case 0:
                cout << "Thank you:)" << endl;
                break;
            default:
                cout << "Sorry, invalid choice." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

```

#### Output:

#### Tampilan Awal

#### Tampilan Operasi Tambah

#### Tampilan Operasi Hapus



#### Tampilan Operasi Ubah

#### Tampilan Operasi Tampil Data


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)

### 3. Lakukan perintah berikut:

#### a) Tambah data Wati 2330004 diantara Farrel dan Denis

#### b) Hapus data Denis

#### c) Tambahkan data berikut di awal: Owi 2330000

#### d) Tambahkan data berikut di akhir: David 2330010

#### e) Ubah data Udin menjadi data berikut: Idin 23300045

#### f) Ubah data terkahir menjadi berikut: Lucy 23300101

#### g) Hapus data awal

#### h) Ubah data awal menjadi berikut: Bagas 2330002

#### i) Hapus data akhir

#### j) Tampilkan seluruh data

Dalam program ini, terdapat struktur data Student yang memiliki atribut name dan id, serta pointer next yang menunjuk ke node berikutnya. Kelas CircularLinkedList memiliki method-method untuk melakukan operasi-operasi pada linked list, seperti penambahan data mahasiswa di depan, belakang, atau tengah, modifikasi data mahasiswa, serta penghapusan data mahasiswa.

Fungsi main bertanggung jawab untuk menampilkan menu kepada pengguna dan memanggil method-method dari kelas CircularLinkedList sesuai dengan pilihan pengguna. Pengguna dapat memilih untuk menambahkan, mengubah, menghapus, atau menampilkan data mahasiswa, serta keluar dari program.

Dengan demikian, program ini menyediakan kerangka kerja untuk manajemen data mahasiswa menggunakan circular linked list dan interaksi dengan pengguna melalui menu yang disediakan.

## Kesimpulan

## Referensi
[1] 
[2] 
