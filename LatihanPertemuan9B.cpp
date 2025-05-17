#include <iostream>
#include <string>
using namespace std;

class Peminjam; // forward declaration

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

class Peminjam {
private:
    string nama;
    int id;
    int totalPinjaman;

public:
    Peminjam(string n, int i) : nama(n), id(i), totalPinjaman(0) {}

    friend class Petugas; // friend class
    friend void lihatStatistik(const Peminjam *p); // friend function
};

class Petugas {
private:
    string namaPetugas;
    int idPetugas;
    string levelAkses;

public:
    Petugas(string n, int i, string l) : namaPetugas(n), idPetugas(i), levelAkses(l) {}

    void prosesPinjam(Buku *b, Peminjam *p) {
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

    friend class Admin;
};

class Admin {
public:
    void lihatAksesPetugas(const Petugas &p) {
        cout << "Nama Petugas: " << p.namaPetugas << ", Level Akses: " << p.levelAkses << endl;
    }
};


void lihatStatistik(const Buku *b) {
    cout << "[Statistik Buku] Judul: " << b->judul << ", Status: " 
         << (b->dipinjam ? "Dipinjam" : "Tersedia") << endl;
}

void lihatStatistik(const Peminjam *p) {
    cout << "[Statistik Peminjam] Nama: " << p->nama 
         << ", Total Pinjaman: " << p->totalPinjaman << endl;
}

int main() {
    Buku buku1("Algoritma C++", "Budi");
    Peminjam peminjam1("Andi", 101);
    Petugas petugas1("Dina", 201, "Standar");
    Admin admin1;

    petugas1.prosesPinjam(&buku1, &peminjam1);
    lihatStatistik(&buku1);
    lihatStatistik(&peminjam1);

    petugas1.prosesKembali(&buku1, &peminjam1);
    lihatStatistik(&buku1);
    lihatStatistik(&peminjam1);

    petugas1.setLevelAkses("SuperUser");
    admin1.lihatAksesPetugas(petugas1);

    return 0;
}
