# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama) </h1>
<p align="center">Hakan Ismail Afnan - 103112400038</p>

## Dasar Teori
Singly Linked List merupakan struktur data dinamis yang terdiri dari serangkaian node yang saling terhubung satu arah melalui pointer atau referensi. Setiap node dalam singly linked list biasanya terdiri dari dua bagian utama: data dan pointer (next) yang menunjuk ke node berikutnya dalam daftar [1].

Berbeda dengan array yang memiliki ukuran tetap dan penyimpanan elemen secara berurutan dalam memori, singly linked list memungkinkan penambahan dan penghapusan elemen tanpa perlu menggeser seluruh elemen lain [2]. Hal ini karena setiap node hanya perlu mengatur kembali alamat referensi (pointer) untuk menyesuaikan urutan node. Operasi ini membuat linked list lebih efisien untuk manipulasi data dinamis.

Operasi dasar dalam singly linked list meliputi:
1. **insertFirst(data)** – Menyisipkan node baru di awal list.
2. **insertLast(data)** – Menambahkan node baru di akhir list.
3. **insertAfter(data, key)** – Menyisipkan node baru setelah node dengan nilai tertentu.
4. **deleteFirst()** – Menghapus node pertama dalam list.
5. **deleteLast()** – Menghapus node terakhir dalam list.
6. **deleteAfter(key)** – Menghapus node setelah node dengan nilai tertentu.
7. **nbList()** – Menghitung jumlah node dalam list.
8. **deleteList()** – Menghapus seluruh node dalam list.

Keunggulan singly linked list dibanding array adalah fleksibilitas dalam mengelola memori. Namun, karena bersifat satu arah, traversal hanya dapat dilakukan dari node pertama hingga terakhir, sehingga pencarian elemen memerlukan waktu linear O(n) [3].
    
## Guided

### 1. Implementasi Singly Linked List pada Data Mahasiswa
#### list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif // LIST_H

```

#### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}  
```

#### main.cpp
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Program C++ ini memanfaatkan struktur singly linked list untuk mengelola data mahasiswa. Implementasinya terdiri atas tiga berkas: list.h sebagai header yang mendefinisikan struktur mahasiswa, node, dan linkedlist beserta deklarasi fungsi; list.cpp yang berisi implementasi rinci dari fungsi-fungsi seperti alokasi, insertFirst, insertLast, insertAfter, dan printList; serta main.cpp sebagai program utama yang bertugas membuat list, menambahkan data mahasiswa, dan menampilkannya. Program ini menunjukkan penerapan dasar operasi penyisipan pada singly linked list.

### 2. Operasi Tambahan pada Singly Linked List Mahasiswa
#### list.h
```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

```

#### list.cpp
```C++
// list.cpp
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}  
```

#### main.cpp
```C++
// main.cpp

#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    return 0;
}
```
Program C++ ini merupakan versi lanjutan dari implementasi sebelumnya dengan penambahan fitur penghapusan pada struktur data singly linked list untuk data mahasiswa. Selain fungsi dasar yang telah ada, program ini menambahkan beberapa fungsi baru yaitu delFirst, delLast, dan delAfter yang masing-masing digunakan untuk menghapus node di awal, di akhir, serta setelah node tertentu. Tersedia pula fungsi nbList untuk menghitung total node yang ada, serta deleteList untuk menghapus seluruh isi list. Pada berkas main.cpp, program memperlihatkan rangkaian proses lengkap mulai dari pembuatan list, penambahan dan penampilan data, hingga penghapusan sebagian maupun seluruh node, disertai tampilan jumlah node setelah setiap tahap operasi.

## Unguided 

### 1. Implementasi Singly Linked List Sederhana
#### Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>

// Definisikan struktur Node
struct Node {
    int data;
    Node* next;
};

// Deklarasikan pointer head global
extern Node* head;

// Prototype fungsi
void init();
bool isEmpty();
void insertFirst(int value);
void insertLast(int value);
void insertAfter(int value, int key);
void deleteFirst();
void deleteLast();
void deleteAfter(int key);
void printList();
int nbList();
void deleteList();

#endif // SINGLYLIST_H
```

#### Singlylist.cpp
```C++
#include "Singlylist.h"

Node* head;

void init() {
    head = nullptr;
}

bool isEmpty() {
    return head == nullptr;
}

void insertFirst(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (isEmpty()) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAfter(int value, int key) {
    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst() {
    if (!isEmpty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteLast() {
    if (!isEmpty()) {
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }
}

void deleteAfter(int key) {
    Node* temp = head;
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }
    if (temp != nullptr && temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
}

void printList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int nbList() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteList() {
    while (!isEmpty()) {
        deleteFirst();
    }
}
```

#### main.cpp
```C++
#include "Singlylist.h"
#include <iostream>

int main() {
    init();

    // Soal 1 - Operasi Insert
    std::cout << "Soal 1:\n";

    insertFirst(9);
    insertLast(12);
    insertLast(2);
    insertAfter(8, 12);
    insertAfter(0, 8);

    printList();

    // Soal 2 - Operasi Delete
    std::cout << "\nSoal 2:\n";

    deleteFirst();
    deleteLast();
    deleteAfter(12);

    printList();

    // Jumlah Node dan Penghapusan Seluruh List
    std::cout << "Jumlah node : " << nbList() << '\n';

    deleteList();
    std::cout << "- List Berhasil Terhapus -\n";
    std::cout << "Jumlah node : " << nbList() << '\n';

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/Pertemuan4_Modul4/LAPRAK/Hakan_Ismail_Afnan-Output-Unguided1.png)

Program C++ ini menerapkan struktur data singly linked list sederhana untuk menyimpan nilai bertipe integer. Berbeda dari versi sebelumnya, program ini menggunakan pointer global bernama head sebagai penunjuk utama dalam pengelolaan list. Berkas Singlylist.h berisi deklarasi struktur Node beserta prototipe fungsi, sedangkan Singlylist.cpp memuat implementasi detail dari berbagai fungsi seperti init, isEmpty, insertFirst, insertLast, insertAfter, deleteFirst, deleteLast, deleteAfter, printList, nbList, dan deleteList. Program utama pada main.cpp memperlihatkan bagaimana fungsi-fungsi tersebut digunakan untuk melakukan operasi penambahan dan penghapusan node dalam list, serta menampilkan hasilnya sesuai dengan urutan skenario yang telah ditentukan.

## Kesimpulan
Pada praktikum modul 4 ini, mahasiswa mempelajari konsep serta penerapan Singly Linked List sebagai salah satu bentuk struktur data dinamis. Melalui kegiatan guided dan unguided, dilakukan berbagai operasi dasar pada linked list, seperti proses inisialisasi, penyisipan node (di awal, tengah, dan akhir), penghapusan node (di awal, tengah, dan akhir), serta traversal untuk menampilkan isi list dan menghitung jumlah node yang ada. Implementasi dilakukan secara modular dengan memisahkan antara file header (.h) dan file sumber (.cpp), sehingga struktur program menjadi lebih teratur dan mudah dikelola. Praktikum ini memperkuat pemahaman mengenai cara kerja linked list, pengelolaan memori dinamis menggunakan new dan delete, serta keunggulan struktur ini dalam hal fleksibilitas ukuran dibandingkan dengan struktur data statis seperti array.

## Referensi 
[1] A. Wijoyo, et al., “Evaluasi Efisiensi Struktur Data Linked List pada Implementasi Sistem Antrian,” *JRIIN : Jurnal Riset Informatika Dan Inovasi*, vol. 1, no. 12, 2024. [Tersedia di sini](https://jurnalmahasiswa.com/index.php/jriin/article/view/1060).  

[2] A. Wijoyo, et al., “Perbandingan Struktur Linked List dan Array dalam Manajemen Memori,” *JRIIN : Jurnal Riset Informatika Dan Inovasi*, vol. 1, no. 12, 2024. [Tersedia di sini](https://jurnalmahasiswa.com/index.php/jriin/article/view/957).  

[3] “Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa,” *Jurnal Sains Informatika Terapan*, vol. 4, no. 2, 2025. [Tersedia di sini](https://rcf-indonesia.org/jurnal/index.php/jsit/article/view/591).
