//KARTIKAPRINNGGOHUTOMO
//2311102196

#include <iostream>

using namespace std;

struct Student {
  string name;
  string studentID;
};

struct Node {
  Student data;
  Node* next;
};

Node* front = NULL;
Node* back = NULL;

bool isEmpty() {
  return front == NULL;
}

void enqueueQueue(Student data) {
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
  cout << "Student queue data: " << endl;
  Node* current = front;
  int i = 1;
  while (current != NULL) {
    cout << i << ". Name: " << current->data.name << ", Student ID: " << current->data.studentID << endl;
    current = current->next;
    i++;
  }
}

int main() {
  Student student1 = {"Pringgo", "2311102196"};
  Student student2 = {"Andika", "2311102197"};
  enqueueQueue(student1);
  enqueueQueue(student2);
  viewQueue();
  cout << "Number of queues = " << countQueue() << endl;
  dequeueQueue();
  viewQueue();
  cout << "Number of queues = " << countQueue() << endl;
  clearQueue();
  viewQueue();
  cout << "Number of queues = " << countQueue() << endl;
  return 0;
}
