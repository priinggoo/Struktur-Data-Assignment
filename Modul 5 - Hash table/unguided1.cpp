#include <iostream>
#include <string>
#include <list>
using namespace std;

// Struktur untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nim;
    string nama;
    int nilai;
    Mahasiswa(string nim, string nama, int nilai) {
        this->nim = nim;
        this->nama = nama;
        this->nilai = nilai;
    }
};

// Hash table menggunakan list untuk menangani kolisi
list<Mahasiswa> hash_table[100];

// Fungsi hash sederhana
int hashFunction(string nim) {
    int sum = 0;
    for (char c : nim) {
        sum += c;
    }
    return sum % 100;
}

// Fungsi untuk menambahkan data baru
void tambahData(string nim, string nama, int nilai) {
    int index = hashFunction(nim);
    hash_table[index].push_back(Mahasiswa(nim, nama, nilai));
    cout << "Data mahasiswa dengan NIM " << nim << ", Nama: " << nama << ", dan nilai " << nilai << " berhasil ditambahkan." << endl;
}

// Fungsi untuk menghapus data
void hapusData(string nim) {
    int index = hashFunction(nim);
    for (list<Mahasiswa>::iterator it = hash_table[index].begin(); it != hash_table[index].end(); it++) {
        if (it->nim == nim) {
            hash_table[index].erase(it);
            cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
            return;
        }
    }
    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
}

// Fungsi untuk mencari data berdasarkan NIM
void cariDataNIM(string nim) {
    int index = hashFunction(nim);
    for (Mahasiswa mahasiswa : hash_table[index]) {
        if (mahasiswa.nim == nim) {
            cout << "Data mahasiswa dengan NIM " << nim << " ditemukan dengan nilai " << mahasiswa.nilai << "." << endl;
            return;
        }
    }
    cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
}

// Fungsi untuk mencari data berdasarkan rentang nilai
void cariDataNilai(int nilai_bawah, int nilai_atas) {
    cout << "Data mahasiswa dengan nilai antara " << nilai_bawah << " dan " << nilai_atas << ":" << endl;
    for (int i = 0; i < 100; i++) {
        for (Mahasiswa mahasiswa : hash_table[i]) {
            if (mahasiswa.nilai >= nilai_bawah && mahasiswa.nilai <= nilai_atas) {
                cout << "NIM: " << mahasiswa.nim << ", Nama: " << mahasiswa.nama << ", Nilai: " << mahasiswa.nilai << endl;
            }
        }
    }
}

// Fungsi untuk menampilkan semua data
void tampilkanData() {
    cout << "Daftar Mahasiswa:" << endl;
    for (int i = 0; i < 100; i++) {
        if (!hash_table[i].empty()) {
            cout << "Indeks Hash " << i << ":" << endl;
            for (Mahasiswa mahasiswa : hash_table[i]) {
                cout << "NIM: " << mahasiswa.nim << ", Nama: " << mahasiswa.nama << ", Nilai: " << mahasiswa.nilai << endl;
            }
            cout << endl;
        }
    }
}

int main() {
    int pilihan;
    string nim;
    string nama;
    int nilai;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Cari Data Berdasarkan NIM" << endl;
        cout << "4. Cari Data Berdasarkan Rentang Nilai (80-90)" << endl;
        cout << "5. Tampilkan Semua Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan nama: ";
                cin >> nama;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahData(nim, nama, nilai);
                break;
            case 2:
                cout << "Masukkan NIM: ";
                cin >> nim;
                hapusData(nim);
                break;
            case 3:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cariDataNIM(nim);
                break;
            case 4:
                int nilai_bawah, nilai_atas;
                cout << "Masukkan nilai bawah: ";
                cin >> nilai_bawah;
                cout << "Masukkan nilai atas: ";
                cin >> nilai_atas;
                cariDataNilai(nilai_bawah, nilai_atas);
                break;
            case 5:
                tampilkanData();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}