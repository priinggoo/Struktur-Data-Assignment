# <h1 align="center">Laporan Praktikum GRAPH DAN TREE</h1>
<p align="center">Karika Pringgo Hutomo</p>


# Dasar Teori
 Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi). Graf dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Graf dapat dinyatakan dengan menyatakan objek sebagai noktah (vertex), bulatan, atau titik, sedangkan hubungan antara objek dinyatakan dengan garis (edge). Graf dapat dinyatakan dengan notasi G = (V, E), di mana G adalah graf, V adalah himpunan titik (vertex), dan E adalah himpunan garis (edge).
Graf dapat dibedakan menjadi beberapa jenis, seperti graf tak berarah (undirected graph), graf berarah (directed graph), dan graf bipartite. Graf tak berarah adalah graf yang tidak memiliki arah, di mana setiap garis menghubungkan dua titik secara simetris. Graf berarah adalah graf yang memiliki arah, di mana setiap garis memiliki arah yang spesifik. Graf bipartite adalah graf yang memiliki dua himpunan titik yang tidak kosong, di mana setiap garis menghubungkan titik dari satu himpunan dengan titik dari himpunan lain.
Pohon adalah suatu bentuk khusus dari struktur suatu graf. Pohon dapat didefinisikan sebagai kumpulan simpul (node) dengan satu elemen khusus yang disebut Root dan node lainnya. Pohon dapat dibedakan menjadi beberapa sifat, seperti pohon akislik (acyclic), pohon sederhana (simple), dan pohon terhubung (connected). Pohon akislik adalah pohon yang tidak memiliki loop (siklus). Pohon sederhana adalah pohon yang tidak memiliki garis paralel. Pohon terhubung adalah pohon yang tidak memiliki titik yang tidak terhubung dengan titik lain.
Pohon juga dapat digunakan untuk merepresentasikan struktur data yang terurut, seperti binary search tree (BST). BST adalah pohon biner yang boleh kosong, di mana setiap node harus memiliki identifier/value. Value pada semua node subpohon sebelah kiri adalah selalu lebih kecil dari value root, sedangkan value subpohon di sebelah kanan adalah sama atau lebih besar dari value root. Penerapan pohon dapat ditemukan dalam berbagai bidang, seperti pencarian dan jaringan.
# Guided1
```C++
 #include <iostream>
#include <iomanip>
using namespace std;
string simpul[7] = {
"Ciamis",
"Bandung",
"Bekasi",
"tasikmalaya",
"Cianjur",
"Purwokerto",
"Yogyakarta"
};
int busur[7][7] = {
{0, 7, 8, 0, 0, 0, 0},
{0, 0, 5, 0, 0, 15, 0},
{0, 6, 0, 0, 5, 0, 0},
{0, 5, 0, 0, 2, 4, 0},
{23, 0, 0, 10, 0, 0, 8},
{0, 0, 0, 0, 7, 0, 3},
{0, 0, 0, 0, 9, 4, 0}
};
void tampilGraph(){
for (int baris = 0; baris <7; baris ++){
cout <<" " << setiosflags (ios::left)<<setw (15)
<< simpul [baris] << " : ";
for (int kolom = 0; kolom<7; kolom++){
if (busur[baris][kolom]!=0){
cout << " " << simpul[kolom]<< "(" << busur[baris][kolom]

<< ")";
}
}
cout << endl;
}
}
int main(){
tampilGraph();
return 0;
}

 


```
> ![Screenshot 2024-05-29 222510](https://private-user-images.githubusercontent.com/162521019/334864757-32f22b90-ddaa-4437-9d49-2d8e888aac26.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTY5OTcyMDEsIm5iZiI6MTcxNjk5NjkwMSwicGF0aCI6Ii8xNjI1MjEwMTkvMzM0ODY0NzU3LTMyZjIyYjkwLWRkYWEtNDQzNy05ZDQ5LTJkOGU4ODhhYWMyNi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTI5JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyOVQxNTM1MDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT00OWY0ZWVkNmJmYjdmNGUxOGQ5ZDg2MWFiMGNmN2Q0MGI4YzhlNDJmZjk1ODlkMzk5Y2EzYjE2NjU2MGVmMjY5JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.YyE6ipgKbEUnopkUgRP9ftRBD_YFruSdY6nxjv6Ozu4)



Program di atas adalah sebuah program C++ yang menampilkan representasi graf berarah (directed graph) dengan menggunakan matriks adjacency. Pertama, program mengimpor header `<iostream>` dan `<iomanip>` yang digunakan untuk operasi input-output dan manipulasi format output. Kemudian, program mendeklarasikan array `simpul` yang berisi nama-nama simpul (kota-kota) dalam graf, yaitu "Ciamis", "Bandung", "Bekasi", "tasikmalaya", "Cianjur", "Purwokerto", dan "Yogyakarta".

Selanjutnya, program mendefinisikan sebuah matriks dua dimensi `busur` berukuran 7x7 yang menyimpan bobot (weight) dari busur (edges) yang menghubungkan simpul-simpul tersebut. Jika `busur[i][j]` bernilai 0, berarti tidak ada busur langsung dari simpul `i` ke simpul `j`. Jika `busur[i][j]` tidak nol, nilai tersebut merepresentasikan bobot busur dari simpul `i` ke simpul `j`.

Fungsi `tampilGraph` digunakan untuk menampilkan graf. Fungsi ini mengiterasi setiap baris dalam matriks `busur`. Untuk setiap simpul (baris), program mencetak nama simpul tersebut, kemudian memeriksa setiap kolom dalam baris tersebut untuk melihat apakah ada busur (nilai bukan nol). Jika ada, program mencetak nama simpul tujuan beserta bobot busur dalam format "nama_simpul(bobot)".

Fungsi `main` hanya memanggil fungsi `tampilGraph` untuk menampilkan graf dan kemudian mengakhiri program. Ketika program dijalankan, ia akan mencetak semua simpul dan busur yang ada di graf, menunjukkan koneksi dan bobot antara simpul-simpul tersebut. Contoh outputnya akan menampilkan tiap simpul beserta simpul-simpul yang terhubung dengannya, serta bobot dari setiap koneksi tersebut.

guided2
``` C++
#include <iostream>
using namespace std;
// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon {
char data;
Pohon *left, *right, *parent; //pointer
};
//pointer global
Pohon *root;
// Inisialisasi
void init() {
root = NULL;
}
bool isEmpty() {
return root == NULL;
}
Pohon *newPohon(char data) {
Pohon *node = new Pohon();
node->data = data;
node->left = NULL;
node->right = NULL;
node->parent = NULL;
return node;
}
void buatNode(char data) {
if (isEmpty()) {
root = newPohon(data);
cout << "\nNode " << data << " berhasil dibuat menjadi root." <<
endl;
} else {
cout << "\nPohon sudah dibuat" << endl;
}
}
Pohon *insertLeft(char data, Pohon *node) {
if (isEmpty()) {
cout << "\nBuat tree terlebih dahulu!" << endl;
return NULL;
} else {
if (node->left != NULL) {
cout << "\nNode " << node->data << " sudah ada child kiri!"

<< endl;

return NULL;
} else {
Pohon *baru = newPohon(data);
baru->parent = node;
node->left = baru;
cout << "\nNode " << data << " berhasil ditambahkan ke childkiri " << node->data << endl;
return baru;
}
}
}
Pohon *insertRight(char data, Pohon *node) {
if (isEmpty()) {
cout << "\nBuat tree terlebih dahulu!" << endl;
return NULL;
} else {
if (node->right != NULL) {
cout << "\nNode " << node->data << " sudah ada child kanan!"

<< endl;

return NULL;
} else {
Pohon *baru = newPohon(data);
baru->parent = node;
node->right = baru;
cout << "\nNode " << data << " berhasil ditambahkan ke childkanan " << node->data << endl;
return baru;
}
}
}
void update(char data, Pohon *node) {
if (isEmpty()) {
cout << "\nBuat tree terlebih dahulu!" << endl;
} else {
if (!node)
cout << "\nNode yang ingin diganti tidak ada!!" << endl;
else {
char temp = node->data;
node->data = data;
cout << "\nNode " << temp << " berhasil diubah menjadi " <<

data << endl;
}
}
}
void retrieve(Pohon *node) {
if (isEmpty()) {
cout << "\nBuat tree terlebih dahulu!" << endl;
} else {
if (!node)
cout << "\nNode yang ditunjuk tidak ada!" << endl;
else {
cout << "\nData node : " << node->data << endl;
}
}
}
void find(Pohon *node) {
if (isEmpty()) {
cout << "\nBuat tree terlebih dahulu!" << endl;
} else {
if (!node)
cout << "\nNode yang ditunjuk tidak ada!" << endl;
else {
cout << "\nData Node : " << node->data << endl;
cout << "Root : " << root->data << endl;
if (!node->parent)
cout << "Parent : (tidak punya parent)" << endl;
else
cout << "Parent : " << node->parent->data << endl;
if (node->parent != NULL && node->parent->left != node &&

node->parent->right == node)

cout << "Sibling : " << node->parent->left->data << endl;
else if (node->parent != NULL && node->parent->right != node

&& node->parent->left == node)

cout << "Sibling : " << node->parent->right->data <<

endl;

else
cout << "Sibling : (tidak punya sibling)" << endl;
if (!node->left)
cout << "Child Kiri : (tidak punya Child kiri)" << endl;
else
cout << "Child Kiri : " << node->left->data << endl;
if (!node->right)
cout << "Child Kanan : (tidak punya Child kanan)" <<

endl;

else
cout << "Child Kanan : " << node->right->data << endl;
}
}
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node) {
if (isEmpty())
cout << "\nBuat tree terlebih dahulu!" << endl;
else {
if (node != NULL) {
cout << " " << node->data << ", ";
preOrder(node->left);
preOrder(node->right);
}
}
}
// inOrder
void inOrder(Pohon *node) {
if (isEmpty())
cout << "\nBuat tree terlebih dahulu!" << endl;
else {
if (node != NULL) {
inOrder(node->left);
cout << " " << node->data << ", ";
inOrder(node->right);
}
}
}
// postOrder
void postOrder(Pohon *node) {
    if (isEmpty())
cout << "\nBuat tree terlebih dahulu!" << endl;
else {
if (node != NULL) {
postOrder(node->left);
postOrder(node->right);
cout << " " << node->data << ", ";
}
}
}
// Hapus Node Tree
void deleteTree(Pohon *node) {
if (isEmpty())
cout << "\nBuat tree terlebih dahulu!" << endl;
else {
if (node != NULL) {
if (node != root) {
if (node->parent->left == node)
node->parent->left = NULL;
else if (node->parent->right == node)
node->parent->right = NULL;
}
deleteTree(node->left);
deleteTree(node->right);
if (node == root) {
delete root;
root = NULL;
} else {
delete node;
}
}
}
}
// Hapus SubTree
void deleteSub(Pohon *node) {
if (isEmpty())
cout << "\nBuat tree terlebih dahulu!" << endl;
else {
deleteTree(node->left);
deleteTree(node->right);
cout << "\nNode subtree " << node->data << " berhasil dihapus."
<< endl;
}
}
// Hapus Tree
void clear() {
    if (isEmpty())
cout << "\nBuat tree terlebih dahulu!!" << endl;
else {
deleteTree(root);
cout << "\nPohon berhasil dihapus." << endl;
}
}
// Cek Size Tree
int size(Pohon *node) {
if (isEmpty()) {
cout << "\nBuat tree terlebih dahulu!!" << endl;
return 0;
} else {
if (!node) {
return 0;
} else {
return 1 + size(node->left) + size(node->right);
}
}
}
// Cek Height Level Tree
int height(Pohon *node) {
if (isEmpty()) {
cout << "\nBuat tree terlebih dahulu!" << endl;
return 0;
} else {
if (!node) {
return 0;
} else {
int heightKiri = height(node->left);
int heightKanan = height(node->right);
if (heightKiri >= heightKanan) {
return heightKiri + 1;
} else {
return heightKanan + 1;
}
}
}
}
// Karakteristik Tree
void characteristic() {
int s = size(root);
int h = height(root);
cout << "\nSize Tree : " << s << endl;
cout << "Height Tree : " << h << endl;
if (h != 0)
cout << "Average Node of Tree : " << s / h << endl;
else
cout << "Average Node of Tree : 0" << endl;
}
int main() {
init();
buatNode('A');
Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
*nodeJ;
nodeB = insertLeft('B', root);
nodeC = insertRight('C', root);
nodeD = insertLeft('D', nodeB);
nodeE = insertRight('E', nodeB);
nodeF = insertLeft('F', nodeC);
nodeG = insertLeft('G', nodeE);
nodeH = insertRight('H', nodeE);
nodeI = insertLeft('I', nodeG);
nodeJ = insertRight('J', nodeG);
update('Z', nodeC);
update('C', nodeC);
retrieve(nodeC);
find(nodeC);
cout << "\nPreOrder :" << endl;
preOrder(root);
cout << "\n" << endl;
cout << "InOrder :" << endl;
inOrder(root);
cout << "\n" << endl;
cout << "PostOrder :" << endl;
postOrder(root);
cout << "\n" << endl;
characteristic();
deleteSub(nodeE);
cout << "\nPreOrder :" << endl;
preOrder(root);
cout << "\n" << endl;
characteristic();
}
```
> ![Screenshot 2024-05-29 222539](https://private-user-images.githubusercontent.com/162521019/334865432-443f399d-ff98-4647-b183-fa1f10fc7841.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTY5OTcyOTAsIm5iZiI6MTcxNjk5Njk5MCwicGF0aCI6Ii8xNjI1MjEwMTkvMzM0ODY1NDMyLTQ0M2YzOTlkLWZmOTgtNDY0Ny1iMTgzLWZhMWYxMGZjNzg0MS5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTI5JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyOVQxNTM2MzBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT04ZDExZTNmMDYzZTlkMjk5MGQwYzZhMWYzNWI1NzQ4ZmQ1Y2M1MTk1NzczOWI3MDgzZjA1M2I3OTI3OWMwOGY5JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.GmtZFVxMF1X7dFW04mvmpa1rYJmkAXRLhFdKRUlU4zM)



Program ini mengimplementasikan pohon biner dalam C++. Struktur `Pohon` memiliki pointer `left`, `right`, dan `parent`, serta variabel `data` bertipe `char`. Pointer global `root` menunjuk ke akar pohon dan diinisialisasi dengan `init()`.

Fungsi `isEmpty()` memeriksa apakah pohon kosong, dan `newPohon(char data)` membuat node baru. `buatNode(char data)` membuat node akar jika pohon kosong. Node tambahan dapat dibuat dengan `insertLeft(char data, Pohon *node)` dan `insertRight(char data, Pohon *node)`.

Fungsi `update(char data, Pohon *node)` mengubah data node, dan `retrieve(Pohon *node)` mengambil data node. `find(Pohon *node)` menampilkan data node serta informasi root, parent, sibling, dan children.

Traversals pohon dilakukan dengan `preOrder(Pohon *node)`, `inOrder(Pohon *node)`, dan `postOrder(Pohon *node)`. Penghapusan dilakukan dengan `deleteTree(Pohon *node)` dan `deleteSub(Pohon *node)`. Fungsi `clear()` menghapus seluruh pohon.

Fungsi `size(Pohon *node)` menghitung jumlah node, `height(Pohon *node)` menghitung tinggi pohon, dan `characteristic()` menampilkan ukuran, tinggi, dan rata-rata node per tinggi. Dalam `main()`, pohon diinisialisasi, node-root dibuat, node ditambahkan, operasi seperti update, retrieve, find, traversal dilakukan, karakteristik pohon ditampilkan, dan subtree dihapus. Program ini menunjukkan pengelolaan dan operasi dasar pada pohon biner.


Unguided
1. [Soal]
``` C++
///Kartika Pringgo Hutomo
///2311102196

#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

// Struktur untuk merepresentasikan simpul dalam graph
struct Vertex {
    string name;
    int distance;
};

// Fungsi untuk membuat graph yang direpresentasikan sebagai adjacency matrix
vector<vector<int>> createGraph(vector<string>& vertices) {
    // Mendapatkan jumlah simpul dari user
    int numVertices2311102187;
    cout << "Masukkan jumlah simpul: ";
    cin >> numVertices2311102187;

    // Memasukkan nama simpul
    vertices.resize(numVertices2311102187);
    for (int i = 0; i < numVertices2311102187; i++) {
        cout << "Masukkan nama simpul " << i + 1 << ": ";
        cin >> vertices[i];
    }

    // Membangun adjacency matrix
    vector<vector<int>> adjacencyMatrix(numVertices2311102187, vector<int>(numVertices2311102187));
    for (int i = 0; i < numVertices2311102187; i++) {
        for (int j = 0; j < numVertices2311102187; j++) {
            if (i == j) {
                // Bobot untuk simpul yang sama selalu 0
                adjacencyMatrix[i][j] = 0;
            } else {
                cout << "Masukkan bobot " << vertices[i] << "-->" << vertices[j] << ": ";
                cin >> adjacencyMatrix[i][j];
            }
        }
    }

    return adjacencyMatrix;
}

// Fungsi untuk mencari jarak antara dua kota (simpul) dalam graph
int findDistance(const vector<vector<int>>& adjacencyMatrix, const vector<string>& vertices,
                 const string& startCity, const string& endCity) {
    // Mencari indeks kota awal dan kota tujuan dalam daftar simpul
    auto startIt = find(vertices.begin(), vertices.end(), startCity);
    auto endIt = find(vertices.begin(), vertices.end(), endCity);

    if (startIt == vertices.end() || endIt == vertices.end()) {
        return -1; // Kota tidak ditemukan
    }

    int startIndex = distance(vertices.begin(), startIt);
    int endIndex = distance(vertices.begin(), endIt);

    // Menghitung jarak menggunakan algoritma Dijkstra
    vector<int> distances(vertices.size(), INT_MAX);
    distances[startIndex] = 0;

    // Menginisialisasi set simpul yang belum dikunjungi
    set<int> unvisitedVertices;
    for (int i = 0; i < vertices.size(); i++) {
        unvisitedVertices.insert(i);
    }

    // Menjalankan algoritma Dijkstra
    while (!unvisitedVertices.empty()) {
        // Menemukan simpul dengan jarak terpendek dari simpul awal yang belum dikunjungi
        int currentVertex = *min_element(unvisitedVertices.begin(), unvisitedVertices.end(),
                                         [&](int i, int j) { return distances[i] < distances[j]; });

        // Menghapus simpul dari set simpul yang belum dikunjungi
        unvisitedVertices.erase(currentVertex);

        // Memperbarui jarak simpul yang terhubung dengan simpul saat ini
        for (int neighbor = 0; neighbor < vertices.size(); neighbor++) {
            if (adjacencyMatrix[currentVertex][neighbor] > 0 &&
                distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor] < distances[neighbor]) {
                distances[neighbor] = distances[currentVertex] + adjacencyMatrix[currentVertex][neighbor];
            }
        }
    }

    // Mengembalikan jarak ke kota tujuan
    return distances[endIndex];
}

int main() {
    // Membangun graph
    vector<string> vertices;
    vector<vector<int>> adjacencyMatrix = createGraph(vertices);

    // Mencari jarak antara dua kota
    string startCity, endCity;
    cout << "Masukkan nama kota awal: ";
    cin >> startCity;
    cout << "Masukkan nama kota tujuan: ";
    cin >> endCity;

    int distance = findDistance(adjacencyMatrix, vertices, startCity, endCity);

    // Menampilkan hasil
    if (distance == -1) {
        cout << "Tidak ada jalur dari " << startCity << " ke " << endCity << "." << endl;
    } else {
        cout << "Jarak dari " << startCity << " ke " << endCity << " adalah " << distance << " kilometer." << endl;
    }

    return 0;
}


```

Output: 
> ![Screenshot 2024-05-29 222826](https://private-user-images.githubusercontent.com/162521019/334865824-96f2096d-dad0-42c7-99ee-800577be880c.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTY5OTczNjEsIm5iZiI6MTcxNjk5NzA2MSwicGF0aCI6Ii8xNjI1MjEwMTkvMzM0ODY1ODI0LTk2ZjIwOTZkLWRhZDAtNDJjNy05OWVlLTgwMDU3N2JlODgwYy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTI5JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyOVQxNTM3NDFaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1kMDU1NzBjNjcwZjAyNzgzZDM3Zjc2ZDIwZGJjMjM1ZTJhZWU5OGE4MzRiOWY1OGFiYmI5OGQ5OTg0NzQ0OTI1JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.ihqcWHaLTu127aW52b0HjE0sRSk5y1408rA0jDU7mcU)


Program ini menggunakan algoritma Dijkstra untuk mencari jarak terpendek antara dua kota dalam sebuah graph berbobot yang direpresentasikan sebagai adjacency matrix. Pertama, program meminta pengguna memasukkan jumlah simpul, nama setiap simpul, dan bobot (jarak) antara setiap pasangan simpul melalui fungsi `createGraph`.

Setelah adjacency matrix dibangun, program meminta nama kota awal dan tujuan dari pengguna. Fungsi `findDistance` kemudian menggunakan algoritma Dijkstra untuk menghitung jarak terpendek dari kota awal ke kota tujuan. Algoritma ini bekerja dengan menginisialisasi jarak semua simpul ke nilai maksimum (`INT_MAX`), kecuali simpul awal yang diinisialisasi ke nol. Program secara iteratif memilih simpul dengan jarak terpendek yang belum dikunjungi, memperbarui jarak ke simpul tetangganya, dan menghapus simpul tersebut dari set simpul yang belum dikunjungi.

Hasilnya adalah jarak terpendek yang ditampilkan kepada pengguna. Jika salah satu kota tidak ditemukan, program menginformasikan bahwa tidak ada jalur antara dua kota tersebut. Program ini mengimplementasikan algoritma Dijkstra untuk memecahkan masalah jalur terpendek dalam graph.

2. [Soal]
``` C++
///KartikaPringgoHutomo
///2311102196

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Struktur untuk node tree
struct Node {
    string name_167;
    vector<Node*> children;
};

// Fungsi untuk mencari node berdasarkan nama
Node* findNode(Node* root, const string& name) {
    if (root == nullptr) return nullptr;
    if (root->name_167 == name) return root;
    for (Node* child : root->children) {
        Node* result = findNode(child, name);
        if (result != nullptr) return result;
    }
    return nullptr;
}

// Fungsi untuk menambahkan child pada node
void addChild(Node* root, const string& parentName, const string& childName) {
    Node* parentNode = findNode(root, parentName);
    if (parentNode != nullptr) {
        Node* newChild = new Node{childName, {}};
        parentNode->children.push_back(newChild);
    } else {
        cout << "Parent node tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan semua child dari node
void showChildren(Node* root, const string& name) {
    Node* node = findNode(root, name);
    if (node != nullptr) {
        cout << "Children dari " << name << ": ";
        for (Node* child : node->children) {
            cout << child->name_167 << " ";
        }
        cout << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

// Fungsi rekursif untuk menampilkan semua descendant dari node
void showDescendants(Node* node) {
    if (node == nullptr) return;
    for (Node* child : node->children) {
        cout << child->name_167 << " ";
        showDescendants(child);
    }
}

// Fungsi untuk menampilkan semua descendant dari node
void showAllDescendants(Node* root, const string& name) {
    Node* node = findNode(root, name);
    if (node != nullptr) {
        cout << "Descendants dari " << name << ": ";
        showDescendants(node);
        cout << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

int main() {
    Node* root = new Node{"Root", {}};

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambahkan node" << endl;
        cout << "2. Tampilkan children dari node" << endl;
        cout << "3. Tampilkan descendants dari node" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore(); // Untuk mengabaikan karakter newline setelah input pilihan

        if (choice == 1) {
            string parentName, childName;
            cout << "Masukkan nama parent: ";
            getline(cin, parentName);
            cout << "Masukkan nama child: ";
            getline(cin, childName);
            addChild(root, parentName, childName);
        } else if (choice == 2) {
            string name;
            cout << "Masukkan nama node: ";
            getline(cin, name);
            showChildren(root, name);
        } else if (choice == 3) {
            string name;
            cout << "Masukkan nama node: ";
            getline(cin, name);
            showAllDescendants(root, name);
        } else if (choice != 4) {
            cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}
```
Output:
> ![Screenshot 2024-05-29 223315](https://private-user-images.githubusercontent.com/162521019/334866177-5cd18b26-231f-4eb5-9df6-62990b3413e0.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTY5OTc0MzIsIm5iZiI6MTcxNjk5NzEzMiwicGF0aCI6Ii8xNjI1MjEwMTkvMzM0ODY2MTc3LTVjZDE4YjI2LTIzMWYtNGViNS05ZGY2LTYyOTkwYjM0MTNlMC5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTI5JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUyOVQxNTM4NTJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT02ODZmMGIwNThmNmZlZTk1OTg5YjlhZThmODk2YzQ2ZjI0YmNhZTUzNzkxY2U2N2YyMzMzNTAzNTM2YTlmMmYyJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.9xIBehgroT0xmcDqBG4E5MSiZOPJVI69gTzzDJbHS14)


Program ini adalah implementasi sederhana dari struktur data pohon (tree) menggunakan C++. Setiap node dalam pohon memiliki sebuah nama dan dapat memiliki beberapa anak (children). Program memberikan opsi kepada pengguna untuk menambahkan node baru, menampilkan anak-anak dari suatu node, atau menampilkan semua keturunan dari suatu node.

Node root pertama kali dibuat dengan nama "Root". Pengguna kemudian dapat memilih opsi dari menu yang disediakan: menambahkan node baru, menampilkan anak-anak dari suatu node, menampilkan semua keturunan dari suatu node, atau keluar dari program.

Fungsi `addChild` menambahkan sebuah node anak ke dalam pohon. Fungsi ini mencari node parent yang sesuai berdasarkan namanya, dan jika ditemukan, menambahkan node anak baru ke dalam list anak-anak dari node parent tersebut.

Fungsi `showChildren` menampilkan semua anak dari suatu node. Program mencari node yang sesuai berdasarkan namanya, dan jika ditemukan, menampilkan semua nama anak-anaknya.

Fungsi `showAllDescendants` menampilkan semua keturunan dari suatu node. Program mencari node yang sesuai berdasarkan namanya, dan jika ditemukan, menampilkan semua keturunannya secara rekursif.

Pilihan pengguna diproses menggunakan loop `do-while` dan variabel `choice`. Program terus berjalan hingga pengguna memilih untuk keluar, di mana program akan mengakhiri eksekusi dan menampilkan pesan penutup.

# Kesimpulan
Dalam sintesis, graf dan pohon adalah struktur data yang digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Graf dapat digunakan untuk merepresentasikan jaringan, seperti jaringan jalan raya, di mana kota sebagai simpul dan jalan sebagai sisi. Pohon dapat digunakan untuk merepresentasikan struktur data yang terurut, seperti binary search tree (BST), dan digunakan dalam berbagai bidang, seperti pencarian dan jaringan


# Referensi
[1] https://ahmadhadari77.blogspot.com/2019/05/graph-graf-dan-tree-pohon-algoritma.html
