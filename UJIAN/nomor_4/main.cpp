#include "pengiriman.h"
#include <iostream>
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    do {
        cout << "--- Komaniya Ekspress ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "0. Keluar\n";
        cout << "Pilihan anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                enQueue(Q);
                break;
            case 2:
                deQueue(Q);
                break;
            case 3:
                viewQueue(Q);
                break;
            case 4:
                cout << "Total Biaya Pengiriman: Rp. " << TotalBiayaPengiriman(Q) << endl;
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
