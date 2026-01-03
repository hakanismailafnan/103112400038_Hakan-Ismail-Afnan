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
