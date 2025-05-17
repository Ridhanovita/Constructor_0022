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

    friend class Petugas;
    friend void lihatStatistik(const Buku *b); 
};

class Peminjam {
private:
    string nama;
    int totalPinjaman;
public:
    Peminjam();
    Peminjam(string);

    friend class Petugas;
    friend void lihatStatistik(*Peminjam);
};
