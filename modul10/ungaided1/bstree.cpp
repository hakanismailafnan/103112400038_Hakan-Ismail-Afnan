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
