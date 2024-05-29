//KARTIKA PRINGGO HUTOMO
//2311102196

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
