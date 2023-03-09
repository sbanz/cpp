#include<iostream>

using namespace std;

string array[4] = {"air", "kopi", "jeruk", "anggur"};

void binarySearch(string array[], int indexAwal, int indexAkhir, int yangDicari){
    while(indexAwal <= indexAkhir){
        int m = indexAwal + (yangDicari - indexAwal) / (array[indexAkhir].length() - array[indexAwal].length()) * (indexAkhir - indexAwal) + indexAwal;
        if(array[m].length() == yangDicari){
            cout<<"\""<<array[m]<<"\" ada di index : "<<m<<endl;
        }
        else if(array[m].length() < yangDicari){
            indexAwal = m + 1;
        }
        else{
            indexAkhir = m - 1;
        }
    
    }
}

main(){
    int yangDicari;
    cout<<"\n Masukan panjang string yang di cari : ";
	cin>>yangDicari;
    binarySearch(array, 0, 3, yangDicari);
}
