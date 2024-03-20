#include <iostream>

using namespace std;

int main() {
    int size;
    
    // Meminta pengguna untuk memasukkan ukuran elemen array
    cout << "Masukkan jumlah elemen array: ";
    cin >> size;

    // Meminta pengguna untuk memasukkan elemen array
    int arr[size];
    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    int choice;
    cout << "\nPilih operasi yang ingin dilakukan:\n";
    cout << "1. Mencari nilai maksimum\n";
    cout << "2. Mencari nilai minimum\n";
    cout << "3. Mencari nilai rata-rata\n";
    cout << "Pilihan: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            // Mencari nilai maksimum
            int maxIndex = 0;
            for (int i = 1; i < size; ++i) {
                if (arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }
            cout << "Nilai maksimum dari array adalah: " << arr[maxIndex] << " pada indeks " << maxIndex << endl;
            break;
        }
        case 2: {
            // Mencari nilai minimum
            int minIndex = 0;
            for (int i = 1; i < size; ++i) {
                if (arr[i] < arr[minIndex]) {
                    minIndex = i;
                }
            }
            cout << "Nilai minimum dari array adalah: " << arr[minIndex] << " pada indeks " << minIndex << endl;
            break;
        }
        case 3: {
            // Mencari nilai rata-rata
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                sum += arr[i];
            }
            double average = sum / size;
            cout << "Nilai rata-rata dari array adalah: " << average << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid.\n";
    }

    return 0;
}

