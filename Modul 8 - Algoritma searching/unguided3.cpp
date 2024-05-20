#include <iostream>
using namespace std;

int main() {
    // Inisialisasi array data
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen dalam array
    int target = 4; // Angka yang dicari
    int count = 0; // Variabel untuk menghitung jumlah angka target

    // Menggunakan Sequential Search untuk menghitung jumlah angka 4
    for (int i = 0; i < n; ++i) {
        if (data[i] == target) {
            count++;
        }
    }

    // Menampilkan jumlah angka 4 dalam array
    cout << "Jumlah angka " << target << " dalam array adalah: " << count << endl;

    return 0;
}
