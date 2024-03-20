#include <iostream>

using namespace std;

int main() {
    int size1, size2, size3;

    // Meminta pengguna untuk memasukkan ukuran elemen array
    cout << "Masukkan ukuran elemen array tiga dimensi:\n";
    cout << "Ukuran dimensi 1: ";
    cin >> size1;
    cout << "Ukuran dimensi 2: ";
    cin >> size2;
    cout << "Ukuran dimensi 3: ";
    cin >> size3;

    // Deklarasi array
    int arr[size1][size2][size3];

    // Input elemen array
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Output elemen array
    cout << "Data Array:\n";
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }

    // Tampilan array
    cout << "\nArray:\n";
    for (int x = 0; x < size1; x++) {
        for (int y = 0; y < size2; y++) {
            for (int z = 0; z < size3; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
