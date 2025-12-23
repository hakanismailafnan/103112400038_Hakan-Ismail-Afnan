#ifndef MLL_H
#define MLL_H

#include <iostream>
using namespace std;

struct Child {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    Child *next, *prev;
};

struct Parent {
    string IDGenre;
    string namaGenre;
    Parent *next, *prev;
    Child *firstChild, *lastChild;
};

struct ListParent {
    Parent *first, *last;
};

class MLL {
private:
    ListParent LP;

public:
    void createListParent();
    void createListChild(Parent *P);

    Parent* alokasiNodeParent(string id, string nama);
    Child* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating);
    void dealokasiNodeParent(Parent *P);
    void dealokasiNodeChild(Child *C);

    void insertFirstParent(Parent *P);
    void insertLastChild(Parent *P, Child *C);

    void hapusListChild(Parent *P);
    void deleteAfterParent(string idParent);

    void searchFilmByRatingRange(float min, float max);

    void printStrukturMLL();
};

#endif