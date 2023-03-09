#include<iostream>
using namespace std;

int kali(int x, int y){
	return x*y;
}

int bagi(int x, int y){
	return x/y;
}

int tambah(int x, int y){
	return x+y;
}

int kurang(int x, int y){
	return x-y;
}

int main(){
	int a, b;
	cout<<"Bilangan pertama = ";
	cin>>a;
	cout<<"Bilangan kedua = ";
	cin>>b;
	
	cout<<"Hasil kali = "<< kali(a,b);
	cout<<"Hasil pbagi = "<< bagi(a,b);
	cout<<"Hasil tambah = "<< tambah(a,b);
	cout<<"Hasil kurang = "<< kurang(a,b);
}
