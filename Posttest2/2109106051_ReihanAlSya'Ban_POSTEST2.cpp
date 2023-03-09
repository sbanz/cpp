#include <iostream>
using namespace std;

int main() 
{
  //deklarasi matriks
  int matriks1[3][3], matriks2[3][3], hasil[3][3];
  
  cout<<"======MASUKKAN JUMLAH BARIS DAN KOLOM======"<<endl;
  int bm1, km1, bm2, km2;
  cout<<"Jumlah baris matriks pertama: ";
  cin>>bm1; //baris matriks 1
  cout<<"Jumlah kolom matriks pertama: ";
  cin>>km1; //kolom matriks 1
  cout<<endl;
  
  cout<<"Jumlah baris matriks kedua: ";
  cin>>bm2; //baris matriks 2
  cout<<"Jumlah kolom matriks kedua: ";
  cin>>km2; //Kolom matriks 2
  cout<<endl;
  //variabel perulangan
  int x, y, z;
  if(bm1 != bm2){
    cout<<"Samakan ordo matriks !!!"<<endl;
  } 
  
  else {
  	cout<<"======MASUKKAN ELEMEN MATRIKS======"<<endl;
    int *a;
	a = &matriks1[bm1][km1];
    for(x=0;x<bm1;x++){ //perulangan untuk mengisi elemen matriks
    	for(y=0;y<km1;y++){
        cout<<"Masukkan elemen matriks pertama = ";
        cin>>matriks1[x][y];
    	}
	}
	cout<<endl;
	cout<<"======MASUKKAN ELEMEN MATRIKS======"<<endl;
	int *b;
	b = &matriks2[bm2][km2];
    for(x = 0; x < bm2; x++){ //perulangan untuk mengisi matriks
      for(y = 0; y < km2; y++){
      	cout<<"Masukkan elemen matriks kedua = ";
        cin>>matriks2[x][y];
      }
	}

    for(x=0;x<bm1;x++){ //perulangan untuk perkalian matriks
      for(y=0;y<km2;y++){
        for(z=0;z<bm1;z++){
        	hasil[x][y] = matriks1[x][z] * matriks2[z][y];
        }
      }
    }
    
	cout<<endl;
    cout<<"======HASIL PERKALIAN KEDUA MATRIKS======"<<endl; //output hasil perkalian
    for(x=0;x<bm1;x++){
      for(y=0;y<km2;y++){
        cout<<hasil[x][y] <<"\t";
		;
      }
      cout<<endl;
    }
  }
}
