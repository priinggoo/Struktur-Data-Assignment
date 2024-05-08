//Kartika Pringgo Hutomo
//2311102196

#include <iostream>
#include <string>

using namespace std;

string arrayData[50];
int maximum = 50, top = 0;

bool isFull() {
    return (top == maximum);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayData(string sentence) {
    if (isFull()) {
        cout << "Data is full" << endl;
    }
    else {
        arrayData[top] = sentence;
        top++;
    }
}

void popArrayData() {
    if (isEmpty()) {
        cout << "No data to remove" << endl;
    }
    else {
        arrayData[top - 1] = "";
        top--;
    }
}


void reverseSentence(string sentence) {
    for (char &c : sentence) {
        pushArrayData(string(1, c)); // Pushing each character into the stack
    }

    string reversedString = "";
    while (!isEmpty()) {
        reversedString += arrayData[top - 1]; // Retrieving characters from the stack to form the reversed sentence
        popArrayData();
    }

    cout << "Result\t: " << reversedString << endl;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    cout << "Sentence: " << sentence << endl;
    reverseSentence(sentence);

    return 0;
}
