#include <iostream>

using namespace std;

// Fungsi untuk menghitung luas persegi
double hitungLuasPersegi(double sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung rata-rata sejumlah bilangan
double hitungRataRata(double *bilangan, int jumlahBilangan) {
    double total = 0;
    for (int i = 0; i < jumlahBilangan; ++i) {
        total += bilangan[i];
    }
    return total / jumlahBilangan;
}

// Fungsi untuk menghitung luas lingkaran
double hitungLuasLingkaran(double jariJari) {
    return 3.14 * jariJari * jariJari;
}

int main() {
    // Contoh pemanggilan fungsi hitungLuasPersegi
    double sisiPersegi = 5.5;
    double luasPersegi = hitungLuasPersegi(sisiPersegi);
    cout << "Luas persegi dengan sisi " << sisiPersegi << " adalah: " << luasPersegi << endl;

    // Contoh pemanggilan fungsi hitungRataRata
    double bilangan[] = {10.5, 20.75, 15.25, 12.0, 8.75};
    int jumlahBilangan = sizeof(bilangan) / sizeof(bilangan[0]); // Menghitung jumlah elemen dalam array
    double rataRata = hitungRataRata(bilangan, jumlahBilangan);
    cout << "Rata-rata dari bilangan yang diberikan adalah: " << rataRata << endl;

    // Contoh pemanggilan fungsi hitungLuasLingkaran
    double jariJari = 3.0;
    double luasLingkaran = hitungLuasLingkaran(jariJari);
    cout << "Luas lingkaran dengan jari-jari " << jariJari << " adalah: " << luasLingkaran << endl;

    return 0;
}
