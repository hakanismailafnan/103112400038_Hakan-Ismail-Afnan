#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

void insertAkhir(string x) {
    Node* baru = new Node{x, nullptr};
    if(!head) head = baru;
    else {
        Node* p = head;
        while(p->next) p = p->next;
        p->next = baru;
    }
}

void deleteNama(string x) {
    if(!head) return;
    if(head->nama == x) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }
    Node* p = head;
    while(p->next && p->next->nama != x) p = p->next;
    if(p->next) {
        Node* del = p->next;
        p->next = p->next->next;
        delete del;
    }
}

void view() {
    Node* p = head;
    while(p) {
        cout << p->nama;
        if(p->next) cout << " -> ";
        p = p->next;
    }
    cout << "\n";
}

void hitungGenap() {
    Node* p = head;
    int count = 0;
    while(p) {
        if(p->nama.length() % 2 == 0) {
            cout << p->nama << " ";
            count++;
        }
        p = p->next;
    }
    cout << "\nJumlah: " << count << "\n";
}

int main() {
    int pil;
    string nama;
    while(true) {
        cout << "1 Insert\n2 Delete\n3 View\n4 Hitung Genap\n0 Exit\nPilih: ";
        cin >> pil;
        cin.ignore();
        if(pil == 1) {
            cout << "Masukkan nama: "; getline(cin, nama);
            insertAkhir(nama);
        } else if(pil == 2) {
            cout << "Nama yang dihapus: "; getline(cin, nama);
            deleteNama(nama);
        } else if(pil == 3) view();
        else if(pil == 4) hitungGenap();
        else if(pil == 0) break;
    }
}
