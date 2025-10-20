# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Hakan Ismail Afnan - 103112400038</p>

## Dasar Teori
Abstract Data Type (ADT) atau Tipe Data Abstrak merupakan konsep penting dalam ilmu komputer yang mendefinisikan apa yang dapat dilakukan oleh suatu tipe data, bukan bagaimana tipe data tersebut diimplementasikan [1].

Dengan kata lain, ADT berfokus pada spesifikasi operasi dan perilaku data, tanpa memperhatikan detail implementasi internalnya. Misalnya, ADT Stack hanya mendefinisikan operasi push, pop, dan peek, tanpa menentukan apakah struktur tersebut disimpan menggunakan array atau linked list [2].

Perbedaan utama antara ADT dan struktur data adalah bahwa ADT merupakan definisi logis, sedangkan struktur data adalah implementasi fisik dari ADT tersebut [4].

Contohnya, ADT List dapat diimplementasikan menggunakan struktur data array (ArrayList) atau linked list (LinkedList). Dengan memisahkan keduanya, perubahan implementasi tidak akan memengaruhi kode program yang menggunakan ADT tersebut.


### A. Hubungan ADT dengan Struktur Data <br/>
Perbedaan utama antara ADT dan struktur data adalah bahwa ADT merupakan definisi logis, sedangkan struktur data adalah implementasi fisik dari ADT tersebut [4].

Contohnya, ADT List dapat diimplementasikan menggunakan struktur data array (ArrayList) atau linked list (LinkedList). Dengan memisahkan keduanya, perubahan implementasi tidak akan memengaruhi kode program yang menggunakan ADT tersebut.

### B. Contoh ADT <br/>
Beberapa contoh ADT yang sering digunakan antara lain:
1) Stack ADT — operasi: push, pop, isEmpty; prinsip LIFO (Last In First Out).
2) Queue ADT — operasi: enqueue, dequeue; prinsip FIFO (First In First Out).
3) List ADT — operasi: insert, remove, get, size.
Semua contoh di atas merupakan representasi konseptual; cara penyimpanan datanya dapat berbeda tergantung implementasi struktur data yang digunakan [1].

### C. Manfaat Penggunaan ADT <br/>
Beberapa manfaat utama dari penerapan ADT dalam pengembangan perangkat lunak antara lain [2][3]:
1) Meningkatkan modularitas karena memisahkan logika abstrak dari implementasi fisik.
2) Mempermudah pemeliharaan kode dan pengujian.
3) Mendorong reusabilitas (kode dapat digunakan ulang tanpa perubahan besar).
4) Meminimalkan kesalahan karena interaksi dilakukan melalui antarmuka yang jelas.


## Guided 

### 1. Mahasiswa

#### Header
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H

//Definisi Tipe (Struct)
struct mahasiswa
{
    char nim[10];
    int nilai1, nilai2;
};

//Deklarasi Primitif (Fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif
```

#### Implementasi Fungsi
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;

//Realisasi dari Fungsi inputMhs
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: ";
    cin >> m.nim;
    cout << "Input Nilai 1: ";
    cin >> m.nilai1;
    cout << "Input Nilai 2: ";
    cin >> m.nilai2;
}

//Realisasi dari Fungsi rata2
float rata2(mahasiswa m){
    return (float)(m.nilai1+m.nilai2)/2;
}
```

#### Program Utama

```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah: " << rata2(mhs) << endl;

    system("pause");

    return 0;
}
```
Program ini digunakan untuk menginput data mahasiswa (NIM dan dua nilai), kemudian menghitung serta menampilkan rata-rata nilainya menggunakan konsep Abstract Data Type (ADT) berbasis struct di C++.

### 2. Struct

```C++
#include<iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2; 
};

void inputMhs(mahasiswa &m){
    cout << "Masukan nama mahasiswa: ";
    cin >> m.nama;
    cout << "Masukan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukan nilai 2: ";
    cin >> m.nilai2;
}

//Realisasi dari fungsi rata2
float rata2(mahasiswa m){
    return float (m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs; //Pemanggilan Struct
    inputMhs(mhs); //Pemanggilan Prosedur
    cout << "Rata-rata: " << rata2(mhs);
    return 0;
}
```
Program ini berfungsi untuk menerima input nama dan dua nilai mahasiswa, lalu menghitung serta menampilkan rata-rata nilai menggunakan struktur data (struct) sebagai penerapan konsep Abstract Data Type (ADT) dalam C++.


## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

#### STRUCT & DEKLARASI FUNGSI

```C++
#include <iostream>
#include <cstdlib>
using namespace std;

struct DataMhs {
    char nama[20], nim[15];
    int uts, uas, tugas;
};

void isiData(DataMhs &dm);
float hitungAkhir(DataMhs dm);
```

#### IMPLEMENTASI FUNGSI

```C++
void isiData(DataMhs &dm) {
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> dm.nama;
    cout << "Masukkan NIM Mahasiswa: ";
    cin >> dm.nim;
    cout << "Masukkan Nilai UTS: ";
    cin >> dm.uts;
    cout << "Masukkan Nilai UAS: ";
    cin >> dm.uas;
    cout << "Masukkan Nilai Tugas: ";
    cin >> dm.tugas;
}

float hitungAkhir(DataMhs dm) {
    return (0.3 * dm.uts) + (0.4 * dm.uas) + (0.3 * dm.tugas);
}
```

#### PROGRAM UTAMA

```C++
int main() {
    DataMhs mhsArr[10]; // Maksimal 10 mahasiswa
    int jumlah;

    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlah;

    if (jumlah > 10) {
        cout << "Jumlah melebihi batas maksimal (10)!" << endl;
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        isiData(mhsArr[i]);
    }

    cout << "\n=== Daftar Nilai Akhir Mahasiswa ===" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama: " << mhsArr[i].nama
             << "\tNIM: " << mhsArr[i].nim
             << "\tNilai Akhir: " << hitungAkhir(mhsArr[i]) << endl;
    }

    system("pause");
    return 0;
}
```

### Output Unguided 1 :

![Screenshot Output Unguided 1](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan3_Modul3/Unguided1.png)

Program ini berfungsi untuk menyimpan data maksimal 10 mahasiswa (nama, NIM, nilai UTS, UAS, dan tugas), lalu menghitung dan menampilkan nilai akhir masing-masing mahasiswa menggunakan fungsi dan struct sebagai penerapan konsep Abstract Data Type (ADT) dalam C++.

### 2.  Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
    Type pelajaran <
        namaMapel : string
        kodeMapel : string
    >
    function create_pelajaran( namapel : string, kodepel: string ) → pelajaran
    procedure tampil_pelajaran( input pel: pelajaran )

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"

    using namespace std;
    int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran (namapel,kodepel);
    tampil_pelajaran(pel);
    return 0;
    }

Contoh output hasil:
    nama pelajaran : Struktur Data
    nilai : STD

#### DEFINISI ADT PELAJARAN

```C++
#include <iostream>
#include <string>
using namespace std;

struct Pelajaran {
    string namaMapel;
    string kodeMapel;
};
```

#### FUNGSI & PROSEDUR ADT

```C++
Pelajaran create_pelajaran(string namapel, string kodepel) {
    Pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(Pelajaran pel) {
    cout << "Nama Pelajaran : " << pel.namaMapel << endl;
    cout << "Kode Pelajaran : " << pel.kodeMapel << endl;
}
```

#### PROGRAM UTAMA

```C++
int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    Pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

![Screenshot Output Unguided 2](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan3_Modul3/Unguided2.png)

Program ini digunakan untuk membuat dan menampilkan data pelajaran menggunakan Abstract Data Type (ADT) dengan atribut nama pelajaran dan kode pelajaran melalui fungsi pembuat dan prosedur penampil data. 

### 3.  Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

#### PROSEDUR UNTUK MENAMPILKAN ARRAY 2D

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
```

#### PROSEDUR UNTUK MENUKAR ELEMEN PADA POSISI TERTENTU ANTAR 2 ARRAY

```C++
void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}
```

#### PROSEDUR UNTUK MENUKAR NILAI YANG DITUNJUK OLEH 2 POINTER

```C++
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```

#### PROGRAM UTAMA

```C++
int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A sebelum pertukaran:\n";
    tampilArray(A);
    cout << "Array B sebelum pertukaran:\n";
    tampilArray(B);

    tukarElemen(A, B, 1, 1);

    cout << "\nArray A sesudah pertukaran elemen [1][1]:\n";
    tampilArray(A);
    cout << "Array B sesudah pertukaran elemen [1][1]:\n";
    tampilArray(B);

    cout << "\nNilai sebelum tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "Nilai sesudah tukar pointer:\n";
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
```
### Output Unguided 3 :

![Screenshot Output Unguided 3](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan3_Modul3/Unguided3.png)

Program ini digunakan untuk menampilkan isi array 2D, menukar elemen antara dua array 3x3 pada posisi tertentu, serta menukar nilai variabel melalui dua pointer.

## Kesimpulan
Abstract Data Type (ADT) merupakan konsep penting dalam pemrograman yang memisahkan definisi logika data dari implementasi teknisnya. Dengan ADT, data dan operasi yang dapat dilakukan terhadap data tersebut dibungkus dalam satu kesatuan (seperti struct, class, atau module), sehingga memudahkan pengelolaan, pemeliharaan, dan pemahaman program.
Melalui penerapan ADT, program menjadi lebih terstruktur, modular, efisien, dan mudah dikembangkan tanpa harus mengubah keseluruhan sistem.

## Referensi
[1] GeeksforGeeks. (2024). Abstract Data Types (ADT) in Data Structures. Diakses dari https://www.geeksforgeeks.org/abstract-data-types/

[2] Wikipedia. (2024). Abstract Data Type. Wikimedia Foundation. Diakses dari https://en.wikipedia.org/wiki/Abstract_data_type

[3] Baeldung. (2023). Support for Abstract Data Types in Computer Science. Diakses dari https://www.baeldung.com/cs/adt

[4] OpenDSA Project. (2022). 1.2 Abstract Data Types – Data Structures and Algorithms. Virginia Tech. Diakses dari https://opendsa.cs.vt.edu/ODSA/Books/CS3/html/ADT.html
