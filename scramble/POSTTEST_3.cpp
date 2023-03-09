#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

struct data
{
	string nama[20],jumlah[20];
};

data batas[100];

void inputdata()
{   
	int banyakinput,x,y,z;
	cout<<"Jumlah Data yang ingin diinput : ";
	cin>>banyakinput;
	z=0;
	for(y=0;y<banyakinput;y++)
	{
   		z=z+1;
   		cout<<"\nData ke-"<<z;
   		cout<<"Nama : \n";
		 cin>>batas[x].nama;
   		cout<<"Jumlah Sedekah : \n";
   		cin>>batas[x].jumlah;
   		x++;
	}
}


void lihatdata()
{
	int i,j;
 	cout<<"\n================================Menampilkan Data===============================\n\n";
 	cout<<"===============================================================================\n";
 	cout<<"||\tNO\t||\tNIM\t||\tNama\t\t||\tKelas\t||\n";
 	j=0;
 	for(i=0;i<a;i++)
 	{
	 	j=j+1;
  		cout<<"===============================================================================\n";
  		cout<<"||\t"<<j<<"\t||";
  		cout<<batas[i].nim<<"\t||";
  		cout<<batas[i].nama<<"\t\t\t||";
  		cout<<batas[i].kelas<<"\t\t||";cout<<endl;
  	}
}

void hapusdata()
{
	int x,y;
 	cout<<"Hapus data ke-";cin>>x;
 	y=x-1;
 	a--;
 	for(int i=y;i<a;i++)
 	{batas[i]=batas[i+1];}
 	cout<<"\n\n\n\n\n\n\n\n\n++++++++++++++++++++++++++++++ Data ke-"<<x<<" Terhapus ++++++++++++++++++++++++++++++";
	getch();
}

void editdata()
{
	int k,l;
	cout<<"Masukan Data yang akan diedit : ";cin>>k;
	l=k-1;
	cout<<"Nama : ";cin>>batas[l].nama;
	cout<<"Jumlah Sedekah : ";cin>>batas[l].jumlah;
	lihatdata();
}

int main()
{     
	int pilih;
  	awal:
  	cout<<"MENU\n";
  	cout<<"1. Masukkan data\n";
  	cout<<"2. Hapus Data\n";
  	cout<<"3. Lihat Data\n";
  	cout<<"4. Edit Data\n";
  	cout<<"5. Keluar\n";
  	cout<<"Masukkan Pilihan : \n";
  	cin>>pilih;
  	if(pilih==1)
   	{
	   inputdata();
	   goto awal;
	}
  	if(pilih==2)
   	{
	   hapusdata();
	   goto awal;
	}
  	if(pilih==3)
   	{	
	   lihatdata();
	   goto awal;
	}
  	if(pilih==4)
   	{	
	   editdata();
	   goto awal;
	}
  	if(pilih==5)
   	{
   		char w;
    	cout<<"\n\n\n\n\n\n\n\n                     APAKAH ANDA YAKIN KELUAR DARI PROGRAM??\n\n";
    	cout<<"                         [Y]                         [N]                  \n"<<endl;
    	cout<<"                                         ";
		cin>>w;
    	if(w=='y'||w=='Y')
    	{
     		cout<<"\n\n\n\n\n******************************* PROGRAM SELESAI *******************************";}
    	if(w=='n'||w=='N')
        {
			goto awal;
			}
	}
  	else
   	{
	   	cout<<"Pilihan 1-5";getch();
		goto awal;
	}
}
