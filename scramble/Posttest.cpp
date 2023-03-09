#include<iostream>
using namespace std;

int main()
{
	int nilaiN, nilaiR, selisih, hasil, pilih;
	string ulang;
	
	do
	{
		cout<<"Masukkan Nilai n : ";
		cin>>nilaiN;
		cout<<"Masukkan Nilai r : ";
		cin>>nilaiR;
		cout<<endl;
		
		selisih = nilaiN-nilaiR;
		int faktorN = 1;
		int faktorR = 1;
		int faktorS = 1;
		
		for(int x=1;x<=nilaiN;x++){
            faktorN *= x;
        }
        for(int x=1;x<=nilaiR;x++){
            faktorR *= x;
        }
        for(int x=1;x<=selisih;x++){
            faktorS *= x;
        }
        //perulangan for diatas digunakan untuk menentukan faktorial
		//Variabel x digunakan untuk perulangan for 
		
		cout<<"PERMUTASI DAN KOMBINASI"<<endl;
		cout<<"1. Permutasi"<<endl;
		cout<<"2. Kombinasi"<<endl;
		cout<<"Pilih (1/2) : ";
		cin>>pilih;
		cout<<endl;
		
		if(pilih == 1)
		{
			hasil = faktorN / faktorS;
			cout<<"Hasil permutasi adalah "<<hasil<<endl;
			cout<<endl;
		}
		else if(pilih == 2)
		{
			hasil = faktorN/(faktorS*faktorR);
			cout<<"Hasil kombinasi adalah "<<hasil<<endl;
			cout<<endl;
		}
		else{
			cout<<"PILIH SESUAI MENU !!!"<<endl;
		}
    	cout<<"Gunakan kembali? (y/t) : ";
    	cin>>ulang;
    	cout<<endl;
	}
	while(ulang == "y" || ulang == "Y");
}
