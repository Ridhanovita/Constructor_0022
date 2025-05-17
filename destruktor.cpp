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

void angka::cekData(){
    for(int i=1;1<=panjang;i++){
        cout<<i<<"= ";cin>>arr[i];
    }
    cout<<endl;
}

int main(){
    angka belajarcpp(3); //Constructor Dipanggil
    angka *ptrBelajarcpp = new angka(5); //Constructor Dipanggil
    delete ptrBelajarcpp; //Destructor Dipanggil

    return 0;
}//Destructor Dipanggil