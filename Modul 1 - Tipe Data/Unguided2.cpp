#include <iostream>
#include <string>
using namespace std;

// Deklarasi struct untuk representasi kendaraan
struct KendaraanStruct {
    string jenis;
    string merk;
    int tahunProduksi;
    double harga;
};

// Deklarasi class untuk representasi kendaraan
class KendaraanClass {
public:
    // Atribut dari class
    string jenis;
    string merk;
    int tahunProduksi;
    double harga;

    // Metode untuk menampilkan informasi kendaraan
    void displayInfo() {
        cout << "Jenis: " << jenis << endl;
        cout << "Merk: " << merk << endl;
        cout << "Tahun Produksi: " << tahunProduksi << endl;
        cout << "Harga: " << harga << endl;
    }
};

int main() {
    // Menggunakan struct
    KendaraanStruct mobil1;
    mobil1.jenis = "Mobil";
    mobil1.merk = "Toyota";
    mobil1.tahunProduksi = 2020;
    mobil1.harga = 250000000;

    cout << "Informasi Kendaraan Menggunakan Struct:" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Jenis: " << mobil1.jenis << endl;
    cout << "Merk: " << mobil1.merk << endl;
    cout << "Tahun Produksi: " << mobil1.tahunProduksi << endl;
    cout << "Harga: " << mobil1.harga << endl << endl;

    // Menggunakan class
    KendaraanClass mobil2;
    mobil2.jenis = "Mobil";
    mobil2.merk = "Honda";
    mobil2.tahunProduksi = 2018;
    mobil2.harga = 200000000;

    cout << "Informasi Kendaraan Menggunakan Class:" << endl;
    cout << "-------------------------------------" << endl;
    mobil2.displayInfo();

    return 0;
}
