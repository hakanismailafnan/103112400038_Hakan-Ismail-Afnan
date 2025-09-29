# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Hakan Ismail Afnan - 103112400038</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

## Guided 

### 1. Program Input dan Output

```C++
#include<iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka pertama: ";
    cin >> angka;
    cout << "Masukkan yang dimaskukan adalah " << angka << endl;
    return 0;
}
```
Secara formal, program ini memperlihatkan penggunaan dasar input-output pada bahasa C++ dan penggunaan variabel bertipe integer.

### 2. Kalkulator Sederhana Operasi Aritmatika

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pengurangan: " << angka1 - angka2 << endl;
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 / angka2 << endl;
    cout << "modulus: " << angka1 % angka2 << endl;

    return 0;
}
```
Program ini adalah kalkulator sederhana untuk dua bilangan bulat (angka1 dan angka2).

### 3. Perbandingan Dua Angka dan Kalkulator Sederhana

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2 ) {
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << " angka berbeda " << endl;
    }

     int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "masukan pilihan: ";
    cin >> pilihan;

    switch (pilihan){
        case 1:
        cout << "Penjumlahan :" << angka1 + angka2 << endl;
        cout << endl;
        break; 
        case 2:
        cout << "Pengurangan :" << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "Pilihan Salah" << endl;

    }
    return 0;
}
```
Program membandingkan dua angka, menampilkan hasil perbandingan, lalu memungkinkan pengguna memilih operasi penjumlahan atau pengurangan.

### 4. Program Demonstrasi Loop

```C++
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
 }
```
Program ini mencontohkan penggunaan tiga tipe loop berbeda (for, while, do-while) untuk mencetak deretan angka naik atau turun berdasarkan input pengguna.

### 5. Pengelolaan Data Siswa dengan Struct

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", nilai : " << siswa[j].nilai << endl;
    }
    return 0;
}
```
Program ini digunakan untuk merekam data rapot siswa berupa nama dan nilai, kemudian menampilkan data tersebut.

## Unguided 

### 1. Kalkulator Sederhana

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pengurangan: " << angka1 - angka2 << endl;
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 / angka2 << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://raw.githubusercontent.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/master/Pertemuan1_Modul1/LAPRAK1/Hakan_Ismail_Afnan-Unguided1.png)

Program ini berfungsi sebagai kalkulator sederhana untuk dua bilangan bulat, melakukan operasi aritmatika dasar.

### 2. Program Konversial

```C++
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
```
Program ini berfungsi untuk mengubah angka (0–100) menjadi bentuk kata dalam bahasa Indonesia.

### 3. Diagram Visual

```C++
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
```
Program ini mencetak pola segitiga angka simetris dengan bintang di tengah setiap baris, diakhiri dengan satu bintang pada baris paling bawah.


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
