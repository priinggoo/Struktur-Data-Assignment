#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Fungsi untuk melakukan binary search
bool binarySearch(const string& sorted_str, char target) {
    int left = 0;
    int right = sorted_str.length() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (sorted_str[middle] == target) {
            return true;
        }

        if (sorted_str[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return false;
}

int main() {
    string kalimat;
    char target;

    // Memasukkan kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Memasukkan huruf yang ingin dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    // Menghapus spasi dan mengurutkan kalimat
    kalimat.erase(remove(kalimat.begin(), kalimat.end(), ' '), kalimat.end());
    sort(kalimat.begin(), kalimat.end());

    // Menampilkan kalimat yang sudah diurutkan
    cout << "Kalimat setelah diurutkan: " << kalimat << endl;

    // Mencari huruf menggunakan binary search
    if (binarySearch(kalimat, target)) {
        cout << "Huruf '" << target << "' ditemukan dalam kalimat." << endl;
    } else {
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
