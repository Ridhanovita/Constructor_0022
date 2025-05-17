#include <iostream>
using namespace std;

class angka{
private:
    int *arr;
    int panjang;
public:
    angka(int); //Constructor
    ~angka(); //Destructor
    void cekData();
    void isiData();
};
//Definisi member Function
angka::angka(int i){ //Constructor
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka(){ //Destructor
    cout<<endl;
    cekData();
    delete[]arr;
    cout<<"Alamat Array Sudah Dilepaskan"<<endl;    
}
