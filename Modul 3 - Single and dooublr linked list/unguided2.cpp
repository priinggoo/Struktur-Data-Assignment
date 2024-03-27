///KartikaPringgoHutomo
///KartikaPringgoHutomo

#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    string nama;
    int harga;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void insertData(string nama, int harga) {
    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->harga = harga;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteData(string nama) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->nama == nama) {
            if (temp == head) {
                head = temp->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else if (temp == tail) {
                tail = temp->prev;
                tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
    cout << "Data " << nama << " tidak ditemukan" << endl;
}

void updateData(string nama, string namaBaru, int hargaBaru) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->nama == nama) {
            temp->nama = namaBaru;
            temp->harga = hargaBaru;
            return;
        }
        temp = temp->next;
    }
    cout << "Data " << nama << " tidak ditemukan" << endl;
}

void insertBetween(string nama1, string nama2, string namaBaru, int hargaBaru) {
    Node* newNode = new Node;
    newNode->nama = namaBaru;
    newNode->harga = hargaBaru;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->nama == nama1) {
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data " << nama1 << " tidak ditemukan" << endl;
        return;
    }

    Node* temp2 = temp->next;
    while (temp2 != NULL) {
        if (temp2->nama == nama2) {
            break;
        }
        temp2 = temp2->next;
    }

    if (temp2 == NULL) {
        cout << "Data " << nama2 << " tidak ditemukan" << endl;
        return;
    }

    newNode->next = temp2;
    newNode->prev = temp;
    temp->next = newNode;
    temp2->prev = newNode;
}

void deleteDataBetween(string nama1, string nama2) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->nama == nama1) {
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data " << nama1 << " tidak ditemukan" << endl;
        return;
    }

    Node* temp2 = temp->next;
    while (temp2 != NULL) {
        if (temp2->nama == nama2) {
            break;
        }
        temp2 = temp2->next;
    }

    if (temp2 == NULL) {
        cout << "Data " << nama2 << " tidak ditemukan" << endl;
        return;
    }

    Node* temp3 = temp->next;
    while (temp3 != temp2) {
        Node* tempNode = temp3;
        temp3 = temp3->next;
        delete tempNode;
    }

    temp->next = temp2;
    temp2->prev = temp;
}

void deleteAllData() {
    Node* temp = head;
    while (temp != NULL) {
        Node* tempNode = temp;
        temp = temp->next;
        delete tempNode;
    }
    head = NULL;
    tail = NULL;
}

void displayData() {
    Node* temp = head;
    cout << "Nama Produk\tHarga" << endl;
    while (temp != NULL) {
        cout << temp->nama << "\t\t" << temp->harga << endl;
        temp = temp->next;
    }
}

int main() {
    insertData("Originote", 60000);
    insertData("Somethinc", 150000);
    insertData("Skintific", 100000);
    insertData("Wardah", 50000);
    insertData("Hanasui", 30000);

    insertBetween("Somethinc", "Skintific", "Azarine", 65000);
    deleteData("Wardah");
    updateData("Hanasui", "Cleora", 55000);

    int choice;
    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        string nama, namaBaru;
        int harga, hargaBaru;
        string nama1, nama2;

        switch (choice) {
            case 1:
                cout << "Masukkan nama produk: ";
                cin >> nama;
                cout << "Masukkan harga produk: ";
                cin >> harga;
                insertData(nama, harga);
                break;
            case 2:
                cout << "Masukkan nama produk yang akan dihapus: ";
                cin >> nama;
                deleteData(nama);
                break;
            case 3:
                cout << "Masukkan nama produk yang akan diupdate: ";
                cin >> nama;
                cout << "Masukkan nama baru: ";
                cin >> namaBaru;
                cout << "Masukkan harga baru: ";
                cin >> hargaBaru;
                updateData(nama, namaBaru, hargaBaru);
                break;
            case 4:
                cout << "Masukkan nama produk sebelum posisi yang diinginkan: ";
                cin >> nama1;
                cout << "Masukkan nama produk setelah posisi yang diinginkan: ";
                cin >> nama2;
                cout << "Masukkan nama produk baru: ";
                cin >> namaBaru;
                cout << "Masukkan harga produk baru: ";
                cin >> hargaBaru;
                insertBetween(nama1, nama2, namaBaru, hargaBaru);
                break;
            case 5:
                cout << "Masukkan nama produk sebelum data yang akan dihapus: ";
                cin >> nama1;
                cout << "Masukkan nama produk setelah data yang akan dihapus: ";
                cin >> nama2;
                deleteDataBetween(nama1, nama2);
                break;
            case 6:
                deleteAllData();
                cout << "Semua data telah dihapus" << endl;
                break;
            case 7:
                displayData();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 8);

    return 0;
}