//KARTIKAPRINGGOHUTOMO
//2311102196

#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = NULL;
Node* back = NULL;

bool isEmpty() {
    return front == NULL;
}

void enqueueQueue(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        front = back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

void dequeueQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == NULL) {
            back = NULL;
        }
    }
}

int countQueue() {
    int count = 0;
    Node* current = front;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void clearQueue() {
    while (front != NULL) {
        dequeueQueue();
    }
}

void viewQueue() {
    cout << "Queue data at teller: " << endl;
    Node* current = front;
    int i = 1;
    while (current != NULL) {
        cout << i << ". " << current->data << endl;
        current = current->next;
        i++;
    }
}

int main() {
    enqueueQueue("Andi");
    enqueueQueue("Maya");
    viewQueue();
    cout << "Number of queue = " << countQueue() << endl;
    dequeueQueue();
    viewQueue();
    cout << "Number of queue = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Number of queue = " << countQueue() << endl;
    return 0;
}
