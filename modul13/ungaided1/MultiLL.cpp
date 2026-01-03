#include "MultiLL.h"

/* ====== CEK KOSONG ====== */
bool isEmptyParent(listParent L){
    return L.first == NULL;
}
bool isEmptyChild(listChild L){
    return L.first == NULL;
}

/* ====== CREATE LIST ====== */
void createListParent(listParent &L){
    L.first = L.last = NULL;
}
void createListChild(listChild &L){
    L.first = L.last = NULL;
}

/* ====== ALOKASI ====== */
NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild P = new nodeChild;
    P->isidata.idHewan = idHwn;
    P->isidata.namaHewan = namaHwn;
    P->isidata.habitat = habitat;
    P->isidata.ekor = tail;
    P->isidata.bobot = weight;
    P->next = P->prev = NULL;
    return P;
}

/* ====== DEALOKASI ====== */
void deallocNodeParent(NodeParent &P){
    delete P;
    P = NULL;
}
void deallocNodeChild(NodeChild &P){
    delete P;
    P = NULL;
}

/* ====== INSERT PARENT ====== */
void insertFirstParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ====== DELETE PARENT ====== */
void deleteFirstParent(listParent &L){
    if(!isEmptyParent(L)){
        NodeParent P = L.first;
        deleteListChild(P->L_Child);
        if(L.first == L.last){
            L.first = L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &L, NodeParent Prec){
    NodeParent P = Prec->next;
    deleteListChild(P->L_Child);
    Prec->next = P->next;
    if(P->next != NULL){
        P->next->prev = Prec;
    } else {
        L.last = Prec;
    }
    deallocNodeParent(P);
}

/* ====== INSERT CHILD ====== */
void insertFirstChild(listChild &L, NodeChild P){
    if(isEmptyChild(L)){
        L.first = L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(listChild &L, NodeChild P){
    if(isEmptyChild(L)){
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ====== DELETE CHILD ====== */
void deleteFirstChild(listChild &L){
    if(!isEmptyChild(L)){
        NodeChild P = L.first;
        if(L.first == L.last){
            L.first = L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        deallocNodeChild(P);
    }
}

void deleteAfterChild(listChild &L, NodeChild Prec){
    NodeChild P = Prec->next;
    Prec->next = P->next;
    if(P->next != NULL){
        P->next->prev = Prec;
    } else {
        L.last = Prec;
    }
    deallocNodeChild(P);
}

void deleteListChild(listChild &L){
    while(!isEmptyChild(L)){
        deleteFirstChild(L);
    }
}

/* ====== PRINT ====== */
void printMLLStructure(listParent L){
    int i = 1;
    NodeParent P = L.first;
    while(P != NULL){
        cout << "=== Parent " << i++ << " ===\n";
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if(isEmptyChild(P->L_Child)){
            cout << "(tidak ada child)\n";
        } else {
            NodeChild C = P->L_Child.first;
            int j = 1;
            while(C != NULL){
                cout << "- Child " << j++ << endl;
                cout << "  ID Hewan : " << C->isidata.idHewan << endl;
                cout << "  Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "  Habitat : " << C->isidata.habitat << endl;
                cout << "  Ekor : " << C->isidata.ekor << endl;
                cout << "  Bobot : " << C->isidata.bobot << endl;
                C = C->next;
            }
        }
        cout << "---------------------\n";
        P = P->next;
    }
}

/* ====== SEARCH EKOR ====== */
void searchHewanByEkor(listParent L, bool tail){
    cout << "\nHewan dengan ekor = " << tail << endl;
    NodeParent P = L.first;
    while(P != NULL){
        NodeChild C = P->L_Child.first;
        while(C != NULL){
            if(C->isidata.ekor == tail){
                cout << C->isidata.namaHewan << " (" 
                     << P->isidata.namaGolongan << ")\n";
            }
            C = C->next;
        }
        P = P->next;
    }
}
