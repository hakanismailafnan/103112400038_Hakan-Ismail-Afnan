# <h1 align="center">Analisis Perbandingan Algoritma Iteratif dan Rekursif untuk Menghitung Jumlah Huruf Kapital dalam Kalimat
</h1>
<p align="center">Hakan Ismail Afnan - 103112400038</p>

## 1. Deskripsi Masalah
Tujuan penelitian ini adalah membandingkan **efisiensi waktu eksekusi** dan **kemudahan implementasi** antara dua pendekatan algoritma — **iteratif** dan **rekursif** — dalam menghitung jumlah huruf kapital pada suatu kalimat.

Masalah ini relevan karena kedua pendekatan sering digunakan dalam pemrosesan string, dan memiliki perbedaan kinerja signifikan terutama untuk ukuran data besar.

---

## 2. Algoritma yang Dipilih

### a. Versi Iteratif
Algoritma ini menggunakan loop `for` untuk memeriksa setiap karakter dalam string dan menambah counter jika karakter tersebut berada di antara `'A'` hingga `'Z'`.

**Pseudocode:**
```
function hitungKapitalIteratif(kalimat):
    jumlah = 0
    for setiap karakter c dalam kalimat:
        if 'A' <= c <= 'Z':
            jumlah += 1
    return jumlah
```

### b. Versi Rekursif
Pendekatan rekursif memecah string menjadi elemen pertama dan sisa string, lalu menjumlahkan hasilnya secara berulang hingga akhir string.

**Pseudocode:**
```
function hitungKapitalRekursif(kalimat, index):
    if index == panjang(kalimat):
        return 0
    tambahan = 1 jika kalimat[index] huruf kapital, else 0
    return tambahan + hitungKapitalRekursif(kalimat, index+1)
```

---

## 3. Implementasi Program
Program dibuat menggunakan **C++** dengan library:
- `<iostream>` dan `<string>` untuk input-output dan manipulasi teks.
- `<chrono>` untuk pengukuran waktu eksekusi.
- `<fstream>` untuk menyimpan hasil ke file CSV.

---

## 4. Hasil Eksperimen

Data diperoleh dengan menjalankan program pada ukuran string berbeda (10 hingga 10.000 karakter acak).

| Ukuran | Waktu Iteratif (ns) | Waktu Rekursif (ns) |
|:-------:|:------------------:|:------------------:|
| 10 | ~1,600 | ~3,800 |
| 100 | ~1,900 | ~6,100 |
| 500 | ~5,700 | ~29,000 |
| 1000 | ~11,000 | ~56,000 |
| 5000 | ~53,000 | ~270,000 |
| 10000 | ~109,000 | ~540,000 |

*(Hasil aktual dapat bervariasi tergantung spesifikasi perangkat.)*

---

## 5. Grafik Perbandingan Waktu Eksekusi

![AKA Output](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/HAKAN%20ISMAIL%20AFNAN/AfnanGrafikAKA.png)

```
plot:
  x = Ukuran input
  y1 = Waktu Iteratif
  y2 = Waktu Rekursif
```

Grafik akan memperlihatkan garis iteratif cenderung **lebih landai**, sedangkan garis rekursif naik lebih curam seiring bertambahnya ukuran input.

---

## 6. Analisis Efisiensi

| Aspek | Iteratif | Rekursif |
|-------|-----------|-----------|
| Kompleksitas waktu | O(n) | O(n) |
| Overhead fungsi | Rendah | Tinggi (karena pemanggilan berulang) |
| Kebutuhan memori | Rendah | Lebih tinggi (stack rekursif) |
| Kemudahan implementasi | Sederhana | Lebih konseptual |

**Kesimpulan analisis:**
- Secara teoretis keduanya memiliki kompleksitas waktu yang sama, yaitu O(n).  
- Namun secara empiris, **versi iteratif lebih efisien** karena tidak memiliki overhead pemanggilan fungsi dan tumpukan rekursi.
- Versi rekursif lebih cocok untuk konsep pembelajaran rekursi, bukan untuk pemrosesan string besar.

---

## 7. Kesimpulan
1. Algoritma iteratif memberikan waktu eksekusi lebih cepat untuk semua ukuran input.  
2. Selisih waktu semakin besar seiring bertambahnya ukuran data.  
3. Kompleksitas teoretis sama (O(n)), tetapi konstanta waktu pada iteratif jauh lebih kecil.  
4. Rekursif memiliki kelebihan pada kesederhanaan konsep, namun kurang efisien untuk aplikasi nyata.

---

## 8. Referensi
- Cormen, T. H., et al. *Introduction to Algorithms (3rd ed.)*. MIT Press, 2009.  
- Stroustrup, B. *The C++ Programming Language*. Addison-Wesley, 2013.  
- https://cplusplus.com/reference/chrono/  
- https://www.kaggle.com/code/maiechan/contohtubesaka 
