# <h1 align="center">Laporan Praktikum Modul 7 - Queue</h1>
<p align="center">Kartika Pringgo Hutomo - 2311102196</p>
<p align="center">IF - 11 - E</p>

## Dasar Teori

### Pengertian Queue
Queue, dalam bahasa Indonesia disebut sebagai antrian, adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah "First In, First Out" (FIFO), yang berarti elemen data yang pertama dimasukkan ke dalam antrian akan menjadi yang pertama pula untuk dikeluarkan[1][2][3][4].

### Jenis - jenis Queue
Jenis-jenis Queue dapat diklasifikasikan berdasarkan cara implementasinya, maupun berdasarkan penggunaannya. Di antara jenis-jenis tersebut adalah:
Berdasarkan Implementasinya
Linear/Simple Queue: Elemen-elemen data disusun dalam barisan linear dan penambahan serta penghapusan elemen hanya terjadi pada dua ujung barisan.
Circular Queue: Mirip dengan jenis linear, tetapi ujung-ujung barisan terhubung satu sama lain, menciptakan struktur antrean yang berputar.
Berdasarkan Penggunaan
Priority Queue: Setiap elemen memiliki prioritas tertentu. Elemen dengan prioritas tertinggi akan diambil terlebih dahulu.
Double-ended Queue (Dequeue): Elemen dapat ditambahkan atau dihapus dari kedua ujung antrean
### Fungsi dan Kegunaan Queue
Queue memiliki berbagai fungsi dan kegunaan dalam berbagai aplikasi dan algoritma. Salah satu fungsi utamanya adalah mengatur dan mengelola antrean tugas atau operasi secara efisien. Dalam sistem komputasi, queue digunakan untuk menangani tugas-tugas seperti penjadwalan proses, antrean pesan, dan manajemen sumber daya[1][2][3][4].

Queue juga digunakan dalam berbagai situasi, seperti:

- Menangani lalu lintas (traffic) situs web[2].
- Membantu untuk mempertahankan playlist yang ada pada aplikasi media player[2].
- Digunakan dalam sistem operasi untuk menangani interupsi[2].
- Membantu dalam melayani permintaan pada satu sumber daya bersama, seperti printer, penjadwalan tugas CPU, dll[2].
- Digunakan dalam transfer data asinkronus misal pipeline, IO file, dan socket[2].

Dalam implementasinya, queue dapat diklasifikasikan berdasarkan cara implementasinya, seperti Linear/Simple Queue dan Circular Queue, serta berdasarkan penggunaannya, seperti Priority Queue dan Double-ended Queue (Dequeue)[3].

### Operasi pada Queue
Operasi pada Queue meliputi beberapa fungsi dasar yang memungkinkan pengelolaan elemen-elemen dalam struktur data Queue. Berikut adalah beberapa operasi yang umum dilakukan pada Queue:

1. **Enqueue**: Operasi ini menambahkan elemen ke akhir antrian. Elemen yang ditambahkan akan menjadi elemen terbaru dalam urutan FIFO (First In, First Out)[1][2][3].

2. **Dequeue**: Operasi ini menghapus elemen dari depan antrian. Elemen yang dihapus adalah yang pertama dimasukkan ke dalam antrian, sesuai dengan prinsip FIFO[1][2][3].

3. **IsEmpty**: Operasi ini memeriksa apakah antrian kosong atau tidak. Jika antrian kosong, maka tidak ada elemen yang dapat dihapus[2].

4. **IsFull**: Operasi ini memeriksa apakah antrian sudah penuh atau tidak. Jika antrian penuh, maka tidak dapat menambahkan elemen baru[2].

5. **Peek**: Operasi ini mendapatkan nilai bagian depan antrian tanpa menghapusnya. Ini berguna jika ingin melihat elemen terdepan tanpa mengubah urutan antrian[2].

6. **Initialize**: Operasi ini membuat antrian baru tanpa elemen data (kosong). Ini berguna untuk memulai penggunaan antrian dari awal[2].

Dalam implementasinya, Queue dapat diklasifikasikan berdasarkan cara implementasinya, seperti Linear/Simple Queue dan Circular Queue, serta berdasarkan penggunaannya, seperti Priority Queue dan Double-ended Queue (Dequeue)[3].


   
## Guided 

### Guided 1

```C++
//KARTIKAPRINGGOHUTOMO
//2311102196

#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isFull() {
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout  << "Antrian masih kosong" << endl;
    } else {
        for  (int i = 0 ; i < back ; i++ )
            queueTeller[i] = "";
    }
    back = 0;
    front = 0;
}

void viewQueue() {
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}

```

#### Output :
> ![Screenshot 2024-05-13 204847](https://private-user-images.githubusercontent.com/162521019/330094736-b18f008f-e020-464b-9369-b5825bd03dd0.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTU2MTA3NjYsIm5iZiI6MTcxNTYxMDQ2NiwicGF0aCI6Ii8xNjI1MjEwMTkvMzMwMDk0NzM2LWIxOGYwMDhmLWUwMjAtNDY0Yi05MzY5LWI1ODI1YmQwM2RkMC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUxM1QxNDI3NDZaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05NzRjMTEwMzYyZGEzNTcwMDdkMzJmZTk0NjgxZTEzODQ4MTRhMmM5MDMxY2VlMTRmNDQyOWU5NzRhOTkzYjBlJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.-PKwC7QdUQUmplTj3j8bbHByIJ84EKvBPu9aGujEvrQ)


Program di atas adalah implementasi sederhana dari struktur data antrian menggunakan array dalam bahasa C++. Program ini memiliki fungsi untuk menambahkan dan menghapus elemen dari antrian, serta fungsi untuk memeriksa apakah antrian penuh atau kosong, menghitung jumlah elemen dalam antrian, membersihkan antrian, dan menampilkan elemen-elemen dalam antrian.

Array `queueTeller` digunakan untuk menyimpan elemen-elemen antrian, dan dua variabel `front` dan `back` menyimpan posisi depan dan belakang antrian.

Fungsi `enqueueAntrian()` menambahkan elemen ke antrian jika antrian belum penuh. Fungsi `dequeueAntrian()` menghapus elemen dari antrian jika antrian tidak kosong.

Fungsi `isFull()` memeriksa apakah antrian penuh dan `isEmpty()` memeriksa apakah antrian kosong.

Fungsi `countQueue()` menghitung jumlah elemen dalam antrian, sementara `clearQueue()` menghapus semua elemen dari antrian.

Fungsi `viewQueue()` menampilkan elemen-elemen dalam antrian.

Fungsi `main()` mendemonstrasikan penggunaan operasi-operasi antrian dengan menambahkan, menghapus, dan menampilkan elemen-elemen dalam antrian.

Program ini memberikan dasar untuk mengelola antrian dalam sebuah sistem.

## Unguided 

### Unguided 1
### Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list
```C++
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



```

#### Output:
> ![Screenshot 2024-05-13 203305](https://private-user-images.githubusercontent.com/162521019/330095157-4dcb73f2-1506-44ff-980d-4eb211c96de6.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTU2MTA4MzIsIm5iZiI6MTcxNTYxMDUzMiwicGF0aCI6Ii8xNjI1MjEwMTkvMzMwMDk1MTU3LTRkY2I3M2YyLTE1MDYtNDRmZi05ODBkLTRlYjIxMWM5NmRlNi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUxM1QxNDI4NTJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1kZDliNTEyNTJmOTE5MWJlOWMxZTMzMWU0NDFhNTNkNjk5ZWU3NjcwMWVlZDkyNWQyNmRlYWZiZTM1NjQ1MDVmJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.vEZ7Ytst1GmRRzLYEUu02OfiaCk_g4AioJ7G8zC0DcI)


Program di atas adalah implementasi sederhana dari struktur data antrian (queue) dalam bahasa C++. Program ini memiliki fungsi untuk menambahkan dan menghapus elemen dari antrian, serta untuk melihat jumlah dan isi dari antrian.

Pada awalnya, terdapat dua pointer `front` dan `back` yang menunjukkan posisi depan dan belakang antrian. Fungsi `isEmpty()` digunakan untuk memeriksa apakah antrian kosong. Fungsi `enqueueQueue(string data)` menambahkan elemen ke belakang antrian, sedangkan `dequeueQueue()` menghapus elemen dari depan antrian.

Fungsi `countQueue()` mengembalikan jumlah elemen dalam antrian, sementara `clearQueue()` membersihkan seluruh elemen dalam antrian. Fungsi `viewQueue()` menampilkan data dari seluruh elemen dalam antrian.

Dalam fungsi `main()`, program melakukan operasi-operasi dasar pada antrian, seperti menambah, menghapus, dan menampilkan elemen-elemen dalam antrian.

Dengan demikian, program tersebut memberikan contoh penggunaan sederhana dari struktur data antrian dalam bahasa C++.


## Unguided 2
### Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa
```C++
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


```

#### Output:
> ![Screenshot 2024-05-13 204241](https://private-user-images.githubusercontent.com/162521019/330095462-3c29b749-073c-4405-89d6-916a6b367236.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTU2MTA4ODMsIm5iZiI6MTcxNTYxMDU4MywicGF0aCI6Ii8xNjI1MjEwMTkvMzMwMDk1NDYyLTNjMjliNzQ5LTA3M2MtNDQwNS04OWQ2LTkxNmE2YjM2NzIzNi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTEzJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUxM1QxNDI5NDNaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT0yZTBlMGExYWRjMTExODg2ODNiMWZkMzgzMDQ1YWZiMzI1ZmZmNDk4YmRlNmVmMTZlMjNkMmMzYjYwOTU5ZmNlJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.aKescCDEjcadiC8wW_N77i-AU3Def6CSpADRqZM5pK8)



Program di atas adalah implementasi sederhana dari struktur data antrian (queue) dalam bahasa C++. Program ini menggunakan struktur data `Student` untuk menyimpan nama dan nomor identitas mahasiswa.

Dalam program ini, terdapat dua struktur data yaitu `Student` dan `Node`. `Node` digunakan untuk merepresentasikan setiap elemen dalam antrian. Setiap `Node` memiliki dua anggota, yaitu `data` yang bertipe `Student` untuk menyimpan data mahasiswa, dan `next` yang merupakan pointer ke `Node` selanjutnya dalam antrian.

Ada dua pointer `front` dan `back` yang menunjukkan posisi depan dan belakang antrian. Fungsi `isEmpty()` digunakan untuk memeriksa apakah antrian kosong.

Fungsi `enqueueQueue(Student data)` menambahkan elemen baru ke dalam antrian dengan membuat `Node` baru dan menempatkannya di posisi belakang antrian. Fungsi `dequeueQueue()` menghapus elemen dari depan antrian. Fungsi `countQueue()` menghitung jumlah elemen dalam antrian. Fungsi `clearQueue()` membersihkan seluruh elemen dalam antrian. Fungsi `viewQueue()` menampilkan data dari seluruh elemen dalam antrian.

Fungsi `main()` menunjukkan contoh penggunaan operasi-operasi dasar pada antrian, seperti menambahkan, menghapus, dan menampilkan elemen-elemen dalam antrian.

Dengan demikian, program tersebut memberikan contoh penggunaan sederhana dari struktur data antrian dalam bahasa C++.


## Kesimpulan
Kesimpulan dari Queue adalah bahwa struktur data ini sangat berguna dalam mengatur dan mengelola antrean tugas atau operasi secara efisien. Queue dapat digunakan dalam berbagai aplikasi, seperti sistem operasi, manajemen bandwidth, dan pengelolaan sumber daya. Dalam implementasinya, Queue dapat diklasifikasikan berdasarkan cara implementasinya, seperti Linear/Simple Queue dan Circular Queue, serta berdasarkan penggunaannya, seperti Priority Queue dan Double-ended Queue (Dequeue). Queue juga memiliki operasi dasar seperti enqueue, dequeue, isEmpty, isFull, peek, dan initialize yang memungkinkan pengelolaan elemen-elemen dalam struktur data Queue. Dengan demikian, Queue sangat penting dalam pemrograman dan aplikasi komputasi untuk mengoptimalkan penggunaan sumber daya dan mengatur urutan eksekusi tugas[1][2][3][4].



## Referensi
[1] https://dosenit.com/ilmu-komputer/struktur-data-queue
[2] https://www.trivusi.web.id/2022/07/struktur-data-queue.html
