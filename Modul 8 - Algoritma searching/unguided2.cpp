#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Fungsi untuk memeriksa apakah sebuah karakter adalah huruf vokal
bool isVowel(char c) {
    // Mengubah karakter menjadi huruf kecil untuk pemeriksaan
    c = tolower(c);
    // Memeriksa apakah karakter termasuk dalam huruf vokal
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    string kalimat;
    int vowelCount = 0;

    // Memasukkan kalimat dari pengguna
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghitung jumlah huruf vokal dalam kalimat
    for (char c : kalimat) {
        if (isVowel(c)) {
            vowelCount++;
        }
    }

    // Menampilkan jumlah huruf vokal
    cout << "Jumlah huruf vokal dalam kalimat: " << vowelCount << endl;

    return 0;
}
