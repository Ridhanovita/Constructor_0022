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
    friend void lihatStatistik(Peminjam*);
};

class Petugas {
private:
    string namaPetugas;
    int idPetugas;
    string levelAkses;

public:
    Petugas(string n, int i, string l) : namaPetugas(n), idPetugas(i), levelAkses(l) {}

    void prosesPinjam(Buku* b, Peminjam* p) {
        if (!b->dipinjam) {
            b->dipinjam = true;
            p->totalPinjaman++;
            cout << "Buku \"" << b->judul << "\" berhasil dipinjam oleh " << p->nama << endl;
        } else {
            cout << "Buku \"" << b->judul << "\" sedang dipinjam." << endl;
        }
    }

    void prosesKembali(Buku *b, Peminjam *p) {
        if (b->dipinjam) {
            b->dipinjam = false;
            p->totalPinjaman--;
            cout << "Buku \"" << b->judul << "\" dikembalikan oleh " << p->nama << endl;
        } else {
            cout << "Buku \"" << b->judul << "\" tidak sedang dipinjam." << endl;
        }
    }

    void setLevelAkses(string level) {
        levelAkses = level;
        cout << "Level akses petugas diubah menjadi: " << levelAkses << endl;
    }

    friend class Admin; // Admin jadi friend class Petugas
};

