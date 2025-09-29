#include <iostream>
using namespace std;

int main() {
    int tinggi; 
    cout << "Masukkan angka: ";
    cin >> tinggi;

    for (int baris = tinggi; baris >= 1; --baris) {
        for (int spasi = 0; spasi < 2 * (tinggi - baris); ++spasi) {
            cout << " ";
        }

        for (int angka = baris; angka >= 1; --angka) {
            cout << angka << " ";
        }

        cout << "*";

        for (int angka = 1; angka <= baris; ++angka) {
            cout << " " << angka;
        }

        cout << endl;
    }

    switch (tinggi) {
        case 0:
            break;
        default:
            for (int sp = 0; sp < 2 * tinggi; ++sp) {
                cout << " ";
            }
            cout << "*" << endl;
            break;
    }

    return 0;
}

