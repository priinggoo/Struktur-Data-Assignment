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
> ![Screenshot 2024-04-03 013924](https://private-user-images.githubusercontent.com/162521019/319109927-85fc22c2-6ea1-45e7-bff5-7b1ca4100b12.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQyODYsIm5iZiI6MTcxMjEzMzk4NiwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTA5OTI3LTg1ZmMyMmMyLTZlYTEtNDVlNy1iZmY1LTdiMWNhNDEwMGIxMi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODQ2MjZaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1lMmI0OGNmNDVkOWU1NjNlZGI2ODc2OWE0MmI0YmU4NDUxOTAyZWFmZDM5ODg1MjQ3YjBhZGFmYzRlNjJmOWRhJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.jU-0wBF5TWqv0uWqGBRw8ysKPsdSClXBeBqCpJYQfUQ) /


#### Tampilan Operasi Tambah
> ![Screenshot 2024-04-03 154951](https://private-user-images.githubusercontent.com/162521019/319111914-8b7f6fdb-7993-4b35-93cd-0211a8ac86bb.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ1NTMsIm5iZiI6MTcxMjEzNDI1MywicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTExOTE0LThiN2Y2ZmRiLTc5OTMtNGIzNS05M2NkLTAyMTFhOGFjODZiYi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODUwNTNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1jMDljNDRmYjdjODBkNmUwZWNjN2ZjYTU0YzY2YmUwYWNmOThiYjNlZDQwZDkwMDQxZWRjZDc2OTRkYWY4N2MzJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.xModppGNIB12L3A1jYw2azMvBjI_rjPudaimDxulUgo)

> ![Screenshot 2024-04-03 014033](https://private-user-images.githubusercontent.com/162521019/319112584-589ab62f-d6a8-49d3-b52c-ff1ba7f7e669.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ2MTAsIm5iZiI6MTcxMjEzNDMxMCwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTEyNTg0LTU4OWFiNjJmLWQ2YTgtNDlkMy1iNTJjLWZmMWJhN2Y3ZTY2OS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODUxNTBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0zZTM1MjdhOTFhMjMyNTdmMGVkZGZmNzM0OGZkNGFjMzg1YmRmZjU2MzI0MmUzZGY4NjVjYjkwNTI1OTIwYTY0JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.kszPc5IRPu5lOmWbhsDDohkXYJerwuWyZnSFhc6q9ig)



#### Tampilan Operasi Hapus
> ![Screenshot 2024-04-03 014130](https://private-user-images.githubusercontent.com/162521019/319113116-04377531-ce15-439f-ba1d-799c858fcf1e.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ2NzQsIm5iZiI6MTcxMjEzNDM3NCwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTEzMTE2LTA0Mzc3NTMxLWNlMTUtNDM5Zi1iYTFkLTc5OWM4NThmY2YxZS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODUyNTRaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1jODNhNDU5NmU5YzU3MjdiYmJiZjZkZmFjMzBiODNiMWQzMjE1ZjkxZGM3ZDE4NDM3ZWI1Njg4NjBiZDFlMDNjJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.Fx7ctEujr-O__sdJfeVd1CubBqe7pYUuS6Oa9bkQyLk)

> ![Screenshot 2024-04-03 014143](https://private-user-images.githubusercontent.com/162521019/319113397-ad5803ff-e27c-4b16-9115-ab71f4ba0340.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ3MDUsIm5iZiI6MTcxMjEzNDQwNSwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTEzMzk3LWFkNTgwM2ZmLWUyN2MtNGIxNi05MTE1LWFiNzFmNGJhMDM0MC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODUzMjVaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1kZmU3NDhlOTc2YmMwYzY2NTRlYTFjZjEwNTFmYzU3OTIzYmJiNTUzNDY1YTBjNTk0M2Y2NGZkOTdiZTM4YmM3JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.fwkLQayYmVhMkQM0iXcOFZgN3DxD-mZ2yCtMcKpd1uk)



#### Tampilan Operasi Ubah
> ![Screenshot 2024-04-03 014217](https://private-user-images.githubusercontent.com/162521019/319113724-df5a7d6d-08f9-4893-b76e-dbd683aa5660.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ3NTQsIm5iZiI6MTcxMjEzNDQ1NCwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTEzNzI0LWRmNWE3ZDZkLTA4ZjktNDg5My1iNzZlLWRiZDY4M2FhNTY2MC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODU0MTRaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0yMzE4MjhmODEyZTVmM2U3ODg4MjVmYzM5M2FlYTA3NjhkYWQxYTNlNzc3MDA1NGE1ZjkzOTgxOTA3YmYyZGY2JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.EENOmycCugYhcbuJT15O7bGrl_fYR8RLTivd8om8myg)

> ![Screenshot 2024-04-03 014244](https://private-user-images.githubusercontent.com/162521019/319114123-655b1b96-de68-4947-a4c7-0cac6a4fa221.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ4MDMsIm5iZiI6MTcxMjEzNDUwMywicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTE0MTIzLTY1NWIxYjk2LWRlNjgtNDk0Ny1hNGM3LTBjYWM2YTRmYTIyMS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODU1MDNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hYjgyNjNhODAxNjNlY2I3NTNjNDEyOGQyZTYyYTkxODU1OThlMGM4MzNlNjA2NmY4MmE1NDQ4ZjU3ZTg0N2ZhJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.NJBMh4Gq0Erxc5hrKrXjXoQ-2FeC7vSfFhKRz6PgnxE)



#### Tampilan Operasi Tampil Data
> ![Screenshot 2024-04-03 015455](https://private-user-images.githubusercontent.com/162521019/319114371-b4783ca2-f94a-40af-9525-30a273183bf1.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ4NDMsIm5iZiI6MTcxMjEzNDU0MywicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTE0MzcxLWI0NzgzY2EyLWY5NGEtNDBhZi05NTI1LTMwYTI3MzE4M2JmMS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODU1NDNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04OGZiYTU5YWY5M2JhMjU4ODI0ZDE4ZTJmMzhhNGU3MDM2MThjN2RjZmFmMmUzMTkxNWZlMzcwYzY5MmMzZmFlJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.XxUUp0z4CJs_iCxUKggOi05QbqjMXjnBOfvKQAl26XQ)




### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)
> ![Screenshot 2024-04-03 131916](https://private-user-images.githubusercontent.com/162521019/319114803-98bc2cfb-1110-49b4-884a-239d46448fbe.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ5MTMsIm5iZiI6MTcxMjEzNDYxMywicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTE0ODAzLTk4YmMyY2ZiLTExMTAtNDliNC04ODRhLTIzOWQ0NjQ0OGZiZS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODU2NTNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1lMzI1Y2M4YjNkMWM5NzQyNDdlYmU1NWZiYzViOTVhMDY2NjM3M2U0YTAyZTRhNGRmOTQxOTliNjQ0YWFlMzZmJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.Hmlk7fUKdK6HIdnkidjl4Qa77cwof6x2FEHnQdzu-w0)


### 3. Lakukan perintah berikut:

#### a) Tambah data Wati 2330004 diantara Farrel dan Denis
> ![Screenshot 2024-04-03 132302](https://private-user-images.githubusercontent.com/162521019/319115293-be400275-a4d0-498f-b0f1-18b283ecd45c.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzQ5OTgsIm5iZiI6MTcxMjEzNDY5OCwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTE1MjkzLWJlNDAwMjc1LWE0ZDAtNDk4Zi1iMGYxLTE4YjI4M2VjZDQ1Yy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODU4MThaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xZDFhOGM2YWViOTg3OWMwY2U2OTEyZTFmMDE3ODYxNzhkMTMzMGZkZmIxZDk5NmQ1Mzc3ZjFmMjNhYTE4NjgyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.pM3v84SaJ-fx2w1iVeOIRhWjSlVfKkV3MMdc1StSbh0)



#### b) Hapus data Denis
> ![Screenshot 2024-04-03 132337](https://private-user-images.githubusercontent.com/162521019/319115564-7db3a237-05f5-4e30-8880-0dc404aa2e87.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzUwNDMsIm5iZiI6MTcxMjEzNDc0MywicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTE1NTY0LTdkYjNhMjM3LTA1ZjUtNGUzMC04ODgwLTBkYzQwNGFhMmU4Ny5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODU5MDNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mNzc3MjRjNTczNWMyZTEwM2YxODk1NDQyYzJmNmZhNGRiMTc1ZmFiM2JhNzRjMGUxNjNlNzllNTc4ZjVjMjY1JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.WWV4bMf5TdwZQA5HnVstbYXjl3Yy1ku7Bxe4qKBTd2A)



#### c) Tambahkan data berikut di awal: Owi 2330000
> ![Screenshot 2024-04-03 132543](https://private-user-images.githubusercontent.com/162521019/319115801-045b49d6-2f34-449d-805d-9fbee85627e0.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzUwODEsIm5iZiI6MTcxMjEzNDc4MSwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTE1ODAxLTA0NWI0OWQ2LTJmMzQtNDQ5ZC04MDVkLTlmYmVlODU2MjdlMC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwODU5NDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT02MThlNzU3Yjc5NTM4YjNlNWQ5YzE5YjRjY2MxZmEzMzkwOGJjOThhOTZmMDIzYzY3YmYyYjY1NTM3YTM3ZTFhJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.0YRZRTzcNmD5bTrpvb6z7qD_0FNcSki38ICSNupzeds)



#### d) Tambahkan data berikut di akhir: David 2330010
> ![Screenshot 2024-04-03 132640](https://private-user-images.githubusercontent.com/162521019/319118323-5c4bcc2a-c084-4120-a287-2852f5bdf197.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzU1NjUsIm5iZiI6MTcxMjEzNTI2NSwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTE4MzIzLTVjNGJjYzJhLWMwODQtNDEyMC1hMjg3LTI4NTJmNWJkZjE5Ny5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwOTA3NDVaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0zOWY4YzViOTExZjU4ZTJlMDYyY2NlOTQzNDE2MTlhYmVlMzQ1MDg0Mzc0N2RjZTYwYzZjZWZhZGJhMTk2OTBkJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.X-zZd_2p2gvMudSBGg-oD4T3_4No756nqryBs4j18J0)



#### e) Ubah data Udin menjadi data berikut: Idin 23300045
> ![Screenshot 2024-04-03 133040](https://private-user-images.githubusercontent.com/162521019/319119843-f718b488-0c6c-4e0e-8241-5d7c594e0b7f.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzU4MjQsIm5iZiI6MTcxMjEzNTUyNCwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTE5ODQzLWY3MThiNDg4LTBjNmMtNGUwZS04MjQxLTVkN2M1OTRlMGI3Zi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwOTEyMDRaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xNjZhMmNjYTYwZDMxNDljODQ4MmM4N2VlMWVmNmEzNDg3NGFlM2U2MWM1OTQ2OGQ0MGRhODkxODRhZWMxNDg3JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.ODFFqneQxOWpdMK44MEfHAmbuNJ2GfGN2ITQln5ZpvE)



#### f) Ubah data terkahir menjadi berikut: Lucy 23300101
> ![Screenshot 2024-04-03 133128](https://private-user-images.githubusercontent.com/162521019/319120298-3c810699-6530-40d1-b701-a2d017a7a161.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzU4OTEsIm5iZiI6MTcxMjEzNTU5MSwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTIwMjk4LTNjODEwNjk5LTY1MzAtNDBkMS1iNzAxLWEyZDAxN2E3YTE2MS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwOTEzMTFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1hM2FjOWY3NWJlNzlhMDFmNTUzZmVhZmYzY2ZhODNkZTkyNTgwYjQzZDk4ZjczYmVhYTI1Y2JlNjAzNmVhMjA0JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.wIRt1rHkFyrzL0SAKwQq4ufPEmfLtlPG73oiT2ZsfRM)



#### g) Hapus data awal
> ![Screenshot 2024-04-03 133151](https://private-user-images.githubusercontent.com/162521019/319120693-11877074-8f45-4502-b776-2fd1c1a17969.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzU5NTQsIm5iZiI6MTcxMjEzNTY1NCwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTIwNjkzLTExODc3MDc0LThmNDUtNDUwMi1iNzc2LTJmZDFjMWExNzk2OS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwOTE0MTRaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0yODllNTBiMmYyMWQwNDMyNTI4MDM3YWU0YmNhMGJkOTM3YmFiNzhkZThjNzEzZGVjMjUwNGU4OWE0YjI5YTQ2JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.4t85l9-fdMkoiQB-wkPhA3NeeIirvxqn_kjwwSRnWac)



#### h) Ubah data awal menjadi berikut: Bagas 2330002
> ![Screenshot 2024-04-03 133228](https://private-user-images.githubusercontent.com/162521019/319120928-06fc27ae-053e-4b93-afa4-f685217c4cb4.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzU5OTQsIm5iZiI6MTcxMjEzNTY5NCwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTIwOTI4LTA2ZmMyN2FlLTA1M2UtNGI5My1hZmE0LWY2ODUyMTdjNGNiNC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwOTE0NTRaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0xZTUxZjljZDAzYTgzY2VlYTMxMDQyZGUyYzczMDhjYjZlODJmOGMwZDcwZjJkYWUyOGMwZWNkMzlkMzhmYzgzJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.aHuKx2OFmWee8p0FLLHZrKweDzaNdgSZ5z0oUPpO57w)



#### i) Hapus data akhir
> ![Screenshot 2024-04-03 133250](https://private-user-images.githubusercontent.com/162521019/319121256-ba7216b2-d4ec-41eb-bd91-78e6ed334f18.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzYwMzYsIm5iZiI6MTcxMjEzNTczNiwicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTIxMjU2LWJhNzIxNmIyLWQ0ZWMtNDFlYi1iZDkxLTc4ZTZlZDMzNGYxOC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwOTE1MzZaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1lNmUyNGMwMDMxZTQ4OGMxNTE5ZjMxMDBmMWYyZWQ2ZTJhZjcxNzZjZDI2OGQzMzVkZTVlMjhjMTMxZTU2YzEyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.2NlTUC4WjaWXst7fGQWR33pDpHMaiupo_KUSJbB51fc)



#### j) Tampilkan seluruh data
> ![Screenshot 2024-04-03 133336](https://private-user-images.githubusercontent.com/162521019/319121476-6b9df1a2-e97c-4e12-b078-04dfc61a423d.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTIxMzYwNjcsIm5iZiI6MTcxMjEzNTc2NywicGF0aCI6Ii8xNjI1MjEwMTkvMzE5MTIxNDc2LTZiOWRmMWEyLWU5N2MtNGUxMi1iMDc4LTA0ZGZjNjFhNDIzZC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDAzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQwM1QwOTE2MDdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0wZmE0NjhhZjZmOWM5YmU5NzcxMjM5NDMxNDA5M2RjMTI4MjFhOThlOWQwMTUxZDNmOTBmYmEwMGI0MmNiNDMzJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.ot5G34L49Oxgw-guixBy-sCfr9cqwhsBabcFRd80YB8)



Dalam program ini, terdapat struktur data Student yang memiliki atribut name dan id, serta pointer next yang menunjuk ke node berikutnya. Kelas CircularLinkedList memiliki method-method untuk melakukan operasi-operasi pada linked list, seperti penambahan data mahasiswa di depan, belakang, atau tengah, modifikasi data mahasiswa, serta penghapusan data mahasiswa.

Fungsi main bertanggung jawab untuk menampilkan menu kepada pengguna dan memanggil method-method dari kelas CircularLinkedList sesuai dengan pilihan pengguna. Pengguna dapat memilih untuk menambahkan, mengubah, menghapus, atau menampilkan data mahasiswa, serta keluar dari program.

Dengan demikian, program ini menyediakan kerangka kerja untuk manajemen data mahasiswa menggunakan circular linked list dan interaksi dengan pengguna melalui menu yang disediakan.

## Kesimpulan
Linked list circular adalah salah satu struktur data yang fleksibel dan serbaguna dalam pemrograman. Dibandingkan dengan struktur data lainnya, linked list circular memiliki ciri khusus di mana elemen terakhir dalam daftar menunjuk kembali ke elemen pertama, membentuk siklus tertutup. Ini memungkinkan iterasi tak terbatas melalui elemen-elemen daftar. Meskipun memiliki keuntungan seperti kemampuan untuk menyisipkan dan menghapus elemen dengan efisien tanpa alokasi memori besar, linked list circular juga memiliki kekurangan, termasuk kompleksitas dalam mengakses elemen secara acak. Implementasi linked list circular memerlukan manajemen memori yang cermat, termasuk penghapusan elemen yang tidak lagi digunakan untuk mencegah kebocoran memori. Meskipun demikian, linked list circular tetap relevan dan digunakan dalam berbagai aplikasi, seperti implementasi antrian sirkular dalam sistem manajemen proses dan pemodelan struktur jaringan dalam pemrograman komputer. Dalam pengembangan perangkat lunak, pemahaman tentang cara menangani masalah khusus terkait dengan linked list circular menjadi penting, termasuk memastikan bahwa iterasi melalui daftar tidak menyebabkan pengulangan tak terbatas.


## Referensi
[1] Wikipedia - Circular linked list: https://en.wikipedia.org/wiki/Circular_linked_list
[2] GeeksForGeeks - Circular Linked List: https://www.geeksforgeeks.org/circular-linked-list/
[3]Programiz - Circular Linked List: https://www.programiz.com/dsa/circular-linked-list

