#include <iostream>
#include <string>
using namespace std;

class Peminjam;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    friend class Petugas; // friend class
    friend void lihatStatistik(const Buku *b); // friend function
};

