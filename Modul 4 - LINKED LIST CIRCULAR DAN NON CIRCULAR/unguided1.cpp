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
