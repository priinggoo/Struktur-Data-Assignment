#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Mendefinisikan map untuk menyimpan nama dan umur
    map<string, int> dataOrang;

    // Meminta pengguna untuk memasukkan data nama dan umur
    int jumlahOrang;
    cout << "Masukkan jumlah orang: ";
    cin >> jumlahOrang;

    for (int i = 0; i < jumlahOrang; ++i) {
        string nama;
        int umur;
        
        cout << "Masukkan nama orang ke-" << i+1 << ": ";
        cin >> nama;
        cout << "Masukkan umur orang ke-" << i+1 << ": ";
        cin >> umur;

        // Menyimpan data nama dan umur ke dalam map
        dataOrang[nama] = umur;
    }

    // Menampilkan daftar nama dan umur yang telah dimasukkan
    cout << "\nData Orang:\n";
    for (const auto& data : dataOrang) {
        cout << "Nama: " << data.first << ", Umur: " << data.second << endl;
    }

    return 0;
}
