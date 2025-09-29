#include <iostream>
#include <string>

using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "diluar cangkupan!" << endl;
        return 0;
    }

    string teksAngka;

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    switch (angka) {
        case 0:
            teksAngka = "nol";
            break;
        case 100:
            teksAngka = "seratus";
            break;
        default:
            if (angka < 10) {
                teksAngka = satuan[angka];
            } else if (angka < 20) {
                teksAngka = belasan[angka - 10];
            } else {
                teksAngka = puluhan[angka / 10];
                if (angka % 10 != 0) {
                    teksAngka += " " + satuan[angka % 10];
                }
            }
            break;
    }

    cout << teksAngka << endl;

    return 0;
}
