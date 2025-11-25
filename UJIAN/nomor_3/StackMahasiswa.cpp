#include "StackMahasiswa.h"

bool isEmpty(StackMahasiswa &S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa &S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.Top = -1;
}

void Push(StackMahasiswa &S, Mahasiswa mhs) {
    if (isFull(S)) {
        cout << "Stack penuh, tidak bisa push!\n";
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = mhs;
    }
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong, tidak bisa pop!\n";
    } else {
        S.Top--;
    }
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa mhs) {
    int idx = posisi - 1; 
    if (idx < 0 || idx > S.Top) {
        cout << "Posisi tidak valid!\n";
    } else {
        S.dataMahasiswa[idx] = mhs;
    }
}

void View(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    cout << "\n===== DATA STACK =====\n";
    for (int i = S.Top; i >= 0; i--) {
        cout << "Posisi " << i + 1 << ":\n";
        cout << "Nama       : " << S.dataMahasiswa[i].Nama << endl;
        cout << "NIM        : " << S.dataMahasiswa[i].NIM << endl;
        cout << "Tugas      : " << S.dataMahasiswa[i].NilaiTugas << endl;
        cout << "UTS        : " << S.dataMahasiswa[i].NilaiUTS << endl;
        cout << "UAS        : " << S.dataMahasiswa[i].NilaiUAS << endl;
        cout << "NilaiAkhir : " << hitungNilaiAkhir(S.dataMahasiswa[i]) << endl;
        cout << "--------------------------\n";
    }
}

float hitungNilaiAkhir(Mahasiswa mhs) {
    return 0.2 * mhs.NilaiTugas + 0.4 * mhs.NilaiUTS + 0.4 * mhs.NilaiUAS;
}

void SearchNilaiAkhir(StackMahasiswa &S, float minAkhir, float maxAkhir) {
    cout << "\n===== Searching Nilai Akhir " << minAkhir << " - " << maxAkhir << " =====\n";
    bool found = false;

    for (int i = 0; i <= S.Top; i++) {
        float akhir = hitungNilaiAkhir(S.dataMahasiswa[i]);
        if (akhir >= minAkhir && akhir <= maxAkhir) {
            cout << "Ditemukan di posisi " << i+1 << ": "
                 << S.dataMahasiswa[i].Nama
                 << " (NilaiAkhir = " << akhir << ")\n";
            found = true;
        }
    }

    if (!found) cout << "Tidak ada data dalam rentang tersebut.\n";
}

void MaxNilaiAkhir(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return;
    }

    float maxNA = -1;
    int posisi = -1;

    for (int i = 0; i <= S.Top; i++) {
        float akhir = hitungNilaiAkhir(S.dataMahasiswa[i]);
        if (akhir > maxNA) {
            maxNA = akhir;
            posisi = i;
        }
    }

    cout << "\n===== Mahasiswa NilaiAkhir Tertinggi =====\n";
    cout << "Posisi : " << posisi + 1 << endl;
    cout << "Nama   : " << S.dataMahasiswa[posisi].Nama << endl;
    cout << "NIM    : " << S.dataMahasiswa[posisi].NIM << endl;
    cout << "Nilai Akhir : " << maxNA << endl;
}
