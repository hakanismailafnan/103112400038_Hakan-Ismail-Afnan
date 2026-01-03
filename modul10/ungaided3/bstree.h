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
