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
        cout << "1. Tampilkan semua data" << endl;
        cout << "2. Hapus data Akechi" << endl;
        cout << "3. Masukkan data antara John dan Jane" << endl;
        cout << "4. Insert data at the beginning" << endl;
        cout << "5. Perbarui data Michael" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 'a':
                break;
            case 'b':
                list.deleteNode("Akechi");
                cout << "Akechi's data has been deleted." << endl;
                break;
            case 'c':
                cout << "Enter name and age to be inserted: ";
                cin >> name >> age;
                list.insertAfter("John", name, age);
                break;
            case 'd':
                cout << "Enter name and age to be inserted at the beginning: ";
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
