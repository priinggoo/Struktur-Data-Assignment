#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah angka: ";
    cin >> n;

    int numbers[n];
    int evenNumbers[n];
    int oddNumbers[n];
    int evenCount = 0;
    int oddCount = 0;

    // Meminta pengguna untuk memasukkan angka ke dalam array
    cout << "Masukkan " << n << " angka:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Angka ke-" << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Memisahkan angka genap dan ganjil
    for (int i = 0; i < n; ++i) {
        if (numbers[i] % 2 == 0) {
            evenNumbers[evenCount++] = numbers[i];
        } else {
            oddNumbers[oddCount++] = numbers[i];
        }
    }

    // Menampilkan data array
    cout << "\nData Array: ";
    for (int i = 0; i < n; ++i) {
        cout << numbers[i];
        if (i < n - 1) {
            cout << " ";
        }
    }

    // Menampilkan angka genap
    cout << "\nNomor Genap: ";
    for (int i = 0; i < evenCount; ++i) {
        cout << evenNumbers[i];
        if (i < evenCount - 1) {
            cout << ", ";
        }
    }

    // Menampilkan angka ganjil
    cout << "\nNomor Ganjil: ";
    for (int i = 0; i < oddCount; ++i) {
        cout << oddNumbers[i];
        if (i < oddCount - 1) {
            cout << ", ";
        }
    }

    return 0;
}
