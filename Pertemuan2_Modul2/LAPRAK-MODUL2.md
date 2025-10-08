# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Hakan Ismail Afnan - 103112400038</p>

## Dasar Teori
Array adalah struktur data yang menyimpan sekumpulan elemen data yang memiliki tipe yang sama dalam blok memori yang berurutan[1]  

### A. Array satu dimensi dan Array dua dimensi <br/>
Array satu dimensi digunakan untuk menyimpan data dalam deretan linier yang dapat diakses menggunakan indeks mulai dari nol [1].
Array dua dimensi memperluas konsep ini dengan penambahan indeks kedua, membentuk matriks yang tersusun dalam baris dan kolom [1].

### B. Pointer dan Operator <br/>
Pointer adalah variabel yang menyimpan alamat memori dari variabel lain, sehingga programmer dapat mengakses dan memanipulasi data secara langsung melalui alamat tersebut. Operator pointer * dan & digunakan untuk mengakses nilai dan alamat variabel secara eksplisit [2]. Contoh pemakaian pointer pada array adalah menyimpan alamat elemen pertama array sebagai pointer untuk iterasi elemen array [2].

## Guided 

### 1. Array and Pointer

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10,20,30,40,50};
    int* ptr= arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i=0; i < 5; i++) {
        cout << "Elemen array ke-" << i+1 << "menggunakan pointer: "<< *(ptr+i) << endl;
    }
    //mengakses elemen array menggunakan indeks
    for(int i = 0; i < 5; i++) {
        cout << "Elemen array ke-" << i+1 << "menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}
```
Program ini digunakan untuk menampilkan isi array dengan dua cara: menggunakan pointer yang menunjuk ke elemen pertama array, dan menggunakan indeks biasa. Tujuannya untuk memperlihatkan cara akses elemen array melalui pointer maupun indeks.

### 2. Call by Pointer

```C++
#include <iostream>
using namespace std;

void ubahNilai(int*ptr) {
    *ptr = 20; //mengubah nilai yang ditunjuk oleh pointer
}
int main() {
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(&x); //mengirimkan alamat memori x ke fungsi
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}
```
Program ini digunakan untuk mengubah nilai variabel dengan cara mempassing alamatnya ke fungsi menggunakan pointer. Jadi, fungsi bisa mengubah nilai asli variabel lewat alamat memori yang diterima.

### 3. Call by Reference

```C++
#include <iostream>

using namespace std;

void ubahNilai(int& ref) {
    ref = 20; //mengubah nilai melalui referensi
}

int main() {
    int x = 10;
    cout << "Nilai sebelum diubah: " << x << endl;

    ubahNilai(x); //mengirim referensi ke x
    cout << "Nilai setelah diubah: " << x << endl;

    return 0;
}
```
Program ini mengubah nilai variabel langsung lewat referensi, sehingga tanpa pakai pointer pun nilai asli bisa diubah melalui fungsi.

### 4. Function Procedure

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int MAX = arr[0];
    for(int i = 1; i < ukuran; i++) {
        if(arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for(int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "total penjumlahan : " << totalJumlah << endl;
    int totalKali = 1;
    for(int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "total perkalian : " << totalKali << endl;
}

int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for(int i = 0; i < ukuran; i++) {
        cout << "masukkan nilai array ke-" << i << " : ";
        cin >> arr [i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}
```
Program ini meminta pengguna memasukkan nilai ke dalam array, kemudian mencari nilai terbesar dan menghitung jumlah serta perkalian seluruh elemen array.


## Unguided 

### 1. Diketahui 2 buah matriks 3x3 seperti dibawah ini : <br/>matriksA = [7 12 22, 31 6 41, 15 19 36]<br/> MatriksB = [11 34 7, 3 25 41, 5 18 33].<br/>Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini :
<br/>--- Menu Program Matriks ---<br/>1. Penjumlahan matriks<br/>2. Pengurangan matriks<br/>3. Perkalian matriks<br/>4. Keluar

```C++
#include <iostream>
using namespace std;

void tampilkanMatriks(int matriks[3][3]) {
    for(int baris = 0; baris < 3; baris++) {
        for(int kolom = 0; kolom < 3; kolom++) {
            cout << matriks[baris][kolom] << " ";
        }
        cout << endl;
    }
}

void jumlahMatriks(int matriksA[3][3], int matriksB[3][3], int hasil[3][3]) {
    for(int baris = 0; baris < 3; baris++) {
        for(int kolom = 0; kolom < 3; kolom++) {
            hasil[baris][kolom] = matriksA[baris][kolom] + matriksB[baris][kolom];
        }
    }
}

void kurangMatriks(int matriksA[3][3], int matriksB[3][3], int hasil[3][3]) {
    for(int baris = 0; baris < 3; baris++) {
        for(int kolom = 0; kolom < 3; kolom++) {
            hasil[baris][kolom] = matriksA[baris][kolom] - matriksB[baris][kolom];
        }
    }
}

void kaliMatriks(int matriksA[3][3], int matriksB[3][3], int hasil[3][3]) {
    for(int baris = 0; baris < 3; baris++) {
        for(int kolom = 0; kolom < 3; kolom++) {
            hasil[baris][kolom] = 0;
            for(int k = 0; k < 3; k++) {
                hasil[baris][kolom] += matriksA[baris][k] * matriksB[k][kolom];
            }
        }
    }
}

int main() {
    int pilihan;
    int matriksA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int matriksB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int matriksHasil[3][3];

    cout << "Matriks A:" << endl;
    tampilkanMatriks(matriksA);
    cout << endl;

    cout << "Matriks B:" << endl;
    tampilkanMatriks(matriksB);
    cout << endl;

    cout << "--- Menu Program Matriks ---" << endl;
    cout << "1. Penjumlahan matriks" << endl;
    cout << "2. Pengurangan matriks" << endl;
    cout << "3. Perkalian matriks" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            jumlahMatriks(matriksA, matriksB, matriksHasil);
            cout << "Hasil Penjumlahan Matriks:" << endl;
            tampilkanMatriks(matriksHasil);
            break;
        case 2:
            kurangMatriks(matriksA, matriksB, matriksHasil);
            cout << "Hasil Pengurangan Matriks:" << endl;
            tampilkanMatriks(matriksHasil);
            break;
        case 3:
            kaliMatriks(matriksA, matriksB, matriksHasil);
            cout << "Hasil Perkalian Matriks:" << endl;
            tampilkanMatriks(matriksHasil);
            break;
        case 4:
            cout << "Keluar dari program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan2_Modul2/Unguided1_1PenjumlahanMatriks.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan2_Modul2/Unguided1_2PenguranganMatriks.png)

##### Output 3
![Screenshot Output Unguided 1_3](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan2_Modul2/Unguided1_3PerkalianMatriks.png)

##### Output 4
![Screenshot Output Unguided 1_4](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan2_Modul2/Unguided1_4Keluar.png)

Program ini melakukan operasi matriks 3x3 yaitu penjumlahan, pengurangan, dan perkalian melalui prosedur terpisah. Pengguna dapat memilih operasi yang diinginkan lewat menu, kemudian hasilnya ditampilkan ke layar

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan
luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar
yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas.
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui
pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa
nilainya telah berubah.


```C++
#include <iostream>
using namespace std;

void ubahDimensi(int *ptrPanjang, int *ptrLebar) {
    *ptrPanjang = 12;
    *ptrLebar = 6;
}

int hitungLuas(int *ptrPanjang, int *ptrLebar) {
    return (*ptrPanjang) * (*ptrLebar);
}

int hitungKeliling(int *ptrPanjang, int *ptrLebar) {
    return 2 * (*ptrPanjang) + 2 * (*ptrLebar);
}

int main() {
    int panjangPersegi = 10;
    int lebarPersegi = 5;
    int luasPersegi = 0;

    int* ptrPanjangPersegi = &panjangPersegi;
    int* ptrLebarPersegi = &lebarPersegi;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjangPersegi << endl;
    cout << "Lebar: " << lebarPersegi << endl << endl;

    luasPersegi = hitungLuas(ptrPanjangPersegi, ptrLebarPersegi);
    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luasPersegi << endl;
    cout << "Keliling Persegi Panjang: " << hitungKeliling(ptrPanjangPersegi, ptrLebarPersegi) << endl << endl;

    ubahDimensi(ptrPanjangPersegi, ptrLebarPersegi);

    cout << "--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << *ptrPanjangPersegi << endl;
    cout << "Lebar Baru: " << *ptrLebarPersegi << endl;
    cout << "Luas Baru: " << hitungLuas(ptrPanjangPersegi, ptrLebarPersegi) << endl;
    cout << "Keliling Baru: " << hitungKeliling(ptrPanjangPersegi, ptrLebarPersegi) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan2_Modul2/Unguided2.png)

Program ini menghitung luas dan keliling persegi panjang dengan menggunakan pointer untuk mengakses dan mengubah nilai panjang dan lebar. Program juga menunjukkan perubahan nilai panjang dan lebar melalui pointer dan menghitung ulang luas dan keliling setelah perubahan.

## Kesimpulan
Pointer sangat berguna dalam pemrograman C++ untuk mengakses dan mengubah data langsung di memori, membuat kode lebih efisien dan cepat. Dengan pointer, kita dapat menghemat penggunaan memori, mengirim data antar fungsi tanpa menyalin, dan mengelola struktur data kompleks dengan lebih mudah. Jadi, pointer membantu membuat program lebih hemat sumber daya dan performanya optimal.

## Referensi
[1] Putra, A. & Wijaya, B. 2024. 'Struktur Data Array dan Penerapannya dalam Bahasa C++', Jurnal Ilmiah Teknologi Informasi.
<br/> [2] Setiawan, E. B. (2010). BAB XI POINTER. Laporan Akademik.
<br/>