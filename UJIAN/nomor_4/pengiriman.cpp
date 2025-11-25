#include "pengiriman.h"
#include <iostream>
using namespace std;

bool isEmpty(QueueEkspedisi &Q) {
    return Q.Tail == -1;
}

bool isFull(QueueEkspedisi &Q) {
    return Q.Tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q) {
    Q.Head = -1;
    Q.Tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }

    Paket p;
    cout << "Masukkan Kode Resi: "; cin >> p.KodeResi;
    cout << "Masukkan Nama Pengirim: "; cin >> p.NamaPengirim;
    cout << "Masukkan Berat Barang (kg): "; cin >> p.BeratBarang;
    cout << "Masukkan Tujuan: "; cin >> p.Tujuan;

    if (isEmpty(Q)) {
        Q.Head = Q.Tail = 0;
    } else {
        Q.Tail++;
    }

    Q.dataPaket[Q.Tail] = p;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.Tail--;
    if (Q.Tail < Q.Head) {
        Q.Head = Q.Tail = -1;
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "--- Daftar Paket ---\n";
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << "Kode Resi: " << Q.dataPaket[i].KodeResi << endl;
        cout << "Nama Pengirim: " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "Berat Barang: " << Q.dataPaket[i].BeratBarang << " kg\n";
        cout << "Tujuan: " << Q.dataPaket[i].Tujuan << endl;
        cout << "----------------------\n";
    }
}

int TotalBiayaPengiriman(QueueEkspedisi &Q) {
    int totalBerat = 0;
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBerat += Q.dataPaket[i].BeratBarang;
    }
    return totalBerat * 8250;
}
