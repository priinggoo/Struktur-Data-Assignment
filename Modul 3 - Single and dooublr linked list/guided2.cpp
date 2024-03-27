//Kartika Pringgo Hutomo
//2311102196

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