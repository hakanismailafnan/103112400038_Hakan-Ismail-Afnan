# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama) </h1>
<p align="center"> Hakan Ismail Afnan - 103112400038</p>

## Dasar Teori
Tree merupakan struktur data non-linear yang digunakan untuk merepresentasikan hubungan data secara hierarkis. Setiap elemen dalam tree disebut node, di mana satu node dapat memiliki satu atau lebih child. Node paling atas disebut root, sedangkan node yang tidak memiliki child disebut leaf.
Salah satu bentuk tree yang sering digunakan dalam pemrograman adalah Binary Search Tree (BST). BST adalah pohon biner yang setiap nodenya memiliki maksimal dua child, yaitu child kiri dan child kanan. BST memiliki aturan khusus, yaitu nilai pada subtree kiri harus lebih kecil dari node induk, sedangkan nilai pada subtree kanan harus lebih besar. Aturan ini memungkinkan BST menyimpan data dalam keadaan terurut secara logis.
BST mendukung beberapa operasi dasar seperti penyisipan data (insert), pencarian data (search), serta traversal. Traversal digunakan untuk menelusuri seluruh node dalam tree, yang terdiri dari InOrder, PreOrder, dan PostOrder. Selain itu, BST dapat dianalisis menggunakan fungsi rekursif untuk menghitung jumlah node, total nilai data, dan kedalaman tree.
## Guided

### 1. Rekursif Pangkat 2
```C++
#include<iostream>
using namespace std;

int pangkat_2(int x) { //adalah pengkatnya
    if(x == 0) { //basis
        return 1;
    } else if (x > 0) { //rekurens
        return 2 * pangkat_2(x - 1);
    }
}

int main() {
    cout << "=== REKURSIF PANGKAT 2 ===" << endl;

    int x;
    cout << "Masukkan nilai x: "; 
    cin >> x;
    cout << endl;
    cout << " pangkat 2 dari " << x << " adalah : " << pangkat_2(x) ;

    return 0;
}

//misal x = 3
//pangkat_2(3)
// 2 * pangkat_2(2);
// 2 * (2 * pangkat_2(1));
// 2 * (2 * (2 * pangkat_2(0)));
// = 2 * 2 * 2
// = 8
```

Program ini digunakan untuk menghitung nilai 2 pangkat x (2^x) menggunakan konsep rekursi.

### 2. Binery Search Tree 1
#### BST1.h
```C++
#ifndef BST1_H
#define BST1_H

#include <iostream>

using namespace std;

typedef int infotype;//alias infotype untuk data integer
typedef struct Node *address;//alias address untuk pointer ke struct Node (*Node)
typedef struct Node {
    infotype info;//data integer yang disimpan
    address left;//pointer ke anak kiri
    address right;//pointer ke anak kanan
} Node;

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah tree kosong
void createTree(address &root); //function untuk membuat tree kosong

//alokasi &insertBST
address newNode(infotype x); //function untuk memasukkan data(infotype) ke dalam node baru
address insertNode(address root, infotype x); //function untuk memasukkan node baru ke dalam BST

//Traversal
void preOrder(address root); //function traversal tree secara preOrder (tengah -> kiri -> kanan atau root -> child kiri -> child kanan)
void inOrder(address root); //function traversal tree secara inOrder (kiri -> tengah -> kanan atau child kiri -> root -> child kanan)
void postOrder(address root); //function traversal tree secara postOrder (kiri -> kanan -> tengah atau child kiri -> child kanan -> root)

//Utility
int countNodes(address root); //function untuk menghitung size atau ukurun atau jumlah node yang ada pada tree
int treeDepth(address root); //function untuk menghitung depth atau kedalaman atau level tree

#endif
```

#### BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}

//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

#### main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program C++ ini membuat dan mengelola **Binary Search Tree (BST)** dengan beberapa kemampuan utama, yaitu melakukan insert data, melakukan traversal (preOrder, inOrder, postOrder), menghitung total node dalam tree, serta menentukan kedalaman tree.


### 3. Binery Search Tree 2
#### BST2.h
```C++
#ifndef BST2_H
#define BST2_H

#include <iostream>

using namespace std;

typedef int infotype;//alias infotype untuk data integer
typedef struct Node *address;//alias address untuk pointer ke struct Node (*Node)
typedef struct Node {
    infotype info;//data integer yang disimpan
    address left;//pointer ke anak kiri
    address right;//pointer ke anak kanan
} Node;

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah tree kosong
void createTree(address &root); //function untuk membuat tree kosong

//alokasi &insertBST
address newNode(infotype x); //function untuk memasukkan data(infotype) ke dalam node baru
address insertNode(address root, infotype x); //function untuk memasukkan node baru ke dalam BST

//Traversal
void preOrder(address root); //function traversal tree secara preOrder (tengah -> kiri -> kanan atau root -> child kiri -> child kanan)
void inOrder(address root); //function traversal tree secara inOrder (kiri -> tengah -> kanan atau child kiri -> root -> child kanan)
void postOrder(address root); //function traversal tree secara postOrder (kiri -> kanan -> tengah atau child kiri -> child kanan -> root)

//Utility
int countNodes(address root); //function untuk menghitung size atau ukurun atau jumlah node yang ada pada tree
int treeDepth(address root); //function untuk menghitung depth atau kedalaman atau level tree

//FUNCTION & Prosedur Baru
//searching
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

// Mostleft & Mostright
address mostLeft(address root); //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
address mostRight(address root); //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
void deleteTree(address &root); //prosedur untuk menghapus seluruh node yang ada didalam BST
#endif
```

#### BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}


//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}


//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}


//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```
#### main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }
    return 0;
}
```
Program C++ ini mengembangkan implementasi **Binary Search Tree (BST)** dengan fitur tambahan seperti pencarian data, menampilkan node terkiri (mostleft) dan terkanan (mostright), menghapus node tertentu, serta menghapus seluruh tree.


## Unguided 

### 1. ADT - BST
#### BST1.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);

#endif

```

#### BST1.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x){
    address P = new Node;
    if(P != Nil){
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root){
    if(root == Nil || root->info == x)
        return root;
    if(x < root->info)
        return findNode(x, root->left);
    else
        return findNode(x, root->right);
}

void InOrder(address root){
    if(root != Nil){
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

```

#### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main(){
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/modul10/ungaided1/Cuplikan%20layar%202026-01-03%20192256.png)

Program C++ ini mahasiswa diminta untuk membuat ADT Binary Search Tree secara mandiri. ADT terdiri dari fungsi alokasi node, insert data, dan traversal InOrder. Hasil traversal menunjukkan bahwa data tersusun secara terurut, yang menandakan bahwa aturan BST telah diterapkan dengan benar.

### 2. BST - Hitung Node, Total dan Kedalam
#### BST2.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);

/* traversal */
void InOrder(address root);

/* soal nomor 2 */
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif
```

#### BST2.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x){
    address P = new Node;
    if(P != Nil){
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root){
    if(root == Nil || root->info == x)
        return root;
    if(x < root->info)
        return findNode(x, root->left);
    else
        return findNode(x, root->right);
}

void InOrder(address root){
    if(root != Nil){
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root){
    if(root == Nil)
        return 0;
    return 1 + hitungJumlahNode(root->left) 
             + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root){
    if(root == Nil)
        return 0;
    return root->info 
         + hitungTotalInfo(root->left) 
         + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start){
    if(root == Nil)
        return start;
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}
```

#### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main(){
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    cout << "InOrder : ";
    InOrder(root);
    cout << endl;

    cout << "Kedalaman   : " 
         << hitungKedalaman(root,0) << endl;
    cout << "Jumlah Node : " 
         << hitungJumlahNode(root) << endl;
    cout << "Total Info  : " 
         << hitungTotalInfo(root) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Output Program 1](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/modul10/ungaided2/Cuplikan%20layar%202026-01-03%20192704.png)

Program C++ ini dikembangkan dengan menambahkan fungsi untuk menghitung jumlah node, total nilai seluruh node, dan kedalaman maksimum tree. Seluruh fungsi diimplementasikan menggunakan rekursi. Hasil program menunjukkan bahwa BST dapat dianalisis secara menyeluruh, baik dari jumlah data maupun struktur kedalamannya.

### 3. BST - Pre-Order dan Post-Order Traversal
#### BST3.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;

typedef struct Node* address;
struct Node {
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);

/* traversal */
void InOrder(address root);
void PreOrder(address root);
void PostOrder(address root);

/* soal no 2 */
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif

```

#### BST3.cpp
```C++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype x){
    address P = new Node;
    if(P != Nil){
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    } else if(x < root->info){
        insertNode(root->left, x);
    } else if(x > root->info){
        insertNode(root->right, x);
    }
}

/* Traversal */
void InOrder(address root){
    if(root != Nil){
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

void PreOrder(address root){
    if(root != Nil){
        cout << root->info << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(address root){
    if(root != Nil){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->info << " ";
    }
}

/* Soal no 2 */
int hitungJumlahNode(address root){
    if(root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root){
    if(root == Nil) return 0;
    return root->info
         + hitungTotalInfo(root->left)
         + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start){
    if(root == Nil) return start;
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}
```

#### main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main(){
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    cout << "InOrder   : ";
    InOrder(root);
    cout << endl;

    cout << "PreOrder  : ";
    PreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    PostOrder(root);
    cout << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Output Program 1](https://github.com/hakanismailafnan/103112400038_Hakan-Ismail-Afnan/blob/main/modul10/ungaided3/Cuplikan%20layar%202026-01-03%20192936.png)

Program C++ ini mengimplementasikan traversal PreOrder dan PostOrder. Traversal PreOrder memproses root terlebih dahulu, sedangkan PostOrder memproses root setelah seluruh child selesai diproses. Perbedaan hasil traversal menunjukkan perbedaan urutan penelusuran tanpa mengubah struktur tree.

## Kesimpulan
Berdasarkan hasil praktikum Modul 10, dapat disimpulkan bahwa Binary Search Tree merupakan struktur data yang efektif untuk menyimpan data secara terurut dan mendukung proses pencarian dengan efisien. Penggunaan rekursi sangat membantu dalam implementasi traversal serta perhitungan jumlah node, total nilai data, dan kedalaman tree.
Melalui guided dan unguided, mahasiswa dapat memahami konsep BST secara bertahap, mulai dari dasar hingga pengembangan fungsi tambahan. Praktikum ini memberikan pemahaman yang kuat mengenai struktur data tree sebagai dasar untuk materi lanjutan.

## Referensi  
[1].Programiz. (2023). Binary Search Tree (BST).
https://www.programiz.com/dsa/binary-search-tree

[2]. GeeksforGeeks. (2024). Binary Search Tree Data Structure.
https://www.geeksforgeeks.org/binary-search-tree-data-structure/

[3]. Javatpoint. (2022). Binary Search Tree Tutorial.
https://www.javatpoint.com/binary-search-tree
