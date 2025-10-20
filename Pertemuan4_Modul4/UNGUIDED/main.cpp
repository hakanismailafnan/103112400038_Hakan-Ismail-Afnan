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
