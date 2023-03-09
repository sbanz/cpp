#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
using namespace std;

//DEKLARASI STRUCT
struct pahala{
	string nama;
	int sedekah;
};

int size;
pahala phl[100];

void bubble(pahala loker[], int size){
	int j, pilih;
	pahala swap;
	cout << "1. Ascending" << endl
		<< "2. Descending" << endl
		<< "Pengurutan berdasarkan: "; cin >> pilih;
	switch(pilih){
		case 1:
			for (int i=0; i<size-1; i++){
				for(j=0; j<size-1; j++){
					if(loker[j].nama>loker[j+1].nama){
						swap = loker[j];
						loker[j] = loker[j+1];
						loker[j+1] = swap;
					}
				}	
			}
			break;	
		case 2:
			for(int i=0; i<size-1; i++){
				for(j=0; j<size-1; j++){
					if(loker[j].nama<loker[j+1].nama){
						swap = loker[j];
						loker[j] = loker[j+1];
						loker[j+1] = swap;
					}
				}	
			}
			break;
		break;
	}
}

void create() //FUNGSI MENAMBAHKAN DATA INPUTAN USER KE DALAM ARRAY STRUCT
{
	int banyakdonate, banyakdata;
	int indeks;
	cout<<"Masukkan berapa banyak jumlah donatur : ";
	cin>>banyakdonate;
	cout<<"\n";
	banyakdata = 0;
	for(indeks=0; indeks<banyakdonate; indeks++)
	{
		banyakdata = banyakdata + 1;
		cout<<"Nomor Donatur : "<<banyakdata<<endl;
		cout<<"Nama : ";
		cin>>phl.nama[indeks];
		cout<<"Jumlah Sedekah : Rp.";
		cin>>phl.sedekah[indeks];
		cout<<"\n";
		size++;
	}
	cout<<"DATA BERHASIL DITAMBAHKAN\n";
	cout<<"\n";
	cout<<"TEKAN ENTER UNTUK KEMBALI KE MENU AWAL";
	getch();
	system("cls");
}

void read() //FUNGSI MELIHAT ISI ARRAY
{
	cout<<"DATA DONATUR\n";
	cout<<"\n";
	int nomor;
	int n = sizeof(phl.nama)/sizeof(phl.nama[0]);
	bubblesort(sedekah, n);
	for(int indeks=0; indeks<size ; indeks++)
	{
		nomor = indeks + 1;
		cout<<"Nomor Donatur "<<nomor<<endl;
		cout<<"Nama : "<<phl.nama[indeks]<<endl;
		cout<<"Jumlah Sedekah : Rp. "<<phl.sedekah[indeks]<<endl;
		cout<<"\n";
	}
	cout<<"TEKAN ENTER UNTUK KEMBALI KE MENU AWAL";
	cout<<"\n";
	getch();
	system("cls");
}

void update() //FUNGSI UNTUK MENGUBAH ISI ARRAY
{
	cout<<"DATA DONATUR\n";
	cout<<"\n";
	int nomor;
	for(int indeks=0; indeks<size ; indeks++)
	{
		nomor = indeks + 1;
		cout<<"Nomor Donatur "<<nomor<<endl;
		cout<<"Nama : "<<phl.nama[indeks]<<endl;
		cout<<"Jumlah Sedekah : Rp. "<<phl.sedekah[indeks]<<endl;
		cout<<"\n";
	}
	
	int ubah;
	int indeks;
	cout<<"Masukkan Nomor Donatur yang ingin diubah : ";
	cin>>ubah;
	indeks = ubah - 1;
	cout<<"Nama : ";
	cin>>phl.nama[indeks];
	cout<<"Jumlah Sedekah : Rp. ";
	cin>>phl.sedekah[indeks];
	cout<<"\n";
	cout<<"Data Berhasil Diubah !!!"<<endl;
	cout<<"\n";
	cout<<"TEKAN ENTER UNTUK KEMBALI KE MENU AWAL";
	getch();
	system("cls");
}

void deletee() //FUNGSI UNTUK MENGHAPUS DATA DI DALAM ARRAY SESUAI INPUTAN USER
{
	cout<<"DATA DONATUR\n";
	cout<<"\n";
	int nomor;
	for(int indeks=0; indeks<size ; indeks++)
	{
		nomor = indeks + 1;
		cout<<"Nomor Donatur "<<nomor<<endl;
		cout<<"Nama : "<<phl.nama[indeks]<<endl;
		cout<<"Jumlah Sedekah : Rp. "<<phl.sedekah[indeks]<<endl;
		cout<<"\n";
	}
	
	int hapus, indeks;
	cout<<"Nomor Donatur yang ingin dihapus : ";
	cin>>hapus;
	indeks = hapus - 1;
	size--;
	for(int z=indeks; z<size; z++){
		phl.nama[z] = phl.nama[z+1];
		phl.sedekah[z] = phl.sedekah[z+1];
	}
	cout<<"DATA TELAH TERHAPUS\n";
	cout<<"\n";
	cout<<"TEKAN ENTER UNTUK KEMBALI KE MENU AWAL";
	getch();
	system("cls");
}

int main() //FUNGSI MAIN
{
	int pilih;
	start:
	cout<<"\n";
	cout<<"================== MENU UTAMA ==================\n"
		<<"==== PENDATAAN SEDEKAH WILAYAH POCHINKI ULU ====\n"
		<<"\n"
		<<"1. Masukkan Data Donatur\n"
		<<"2. Lihat Data Donatur\n"
		<<"3. Ubah Data Donatur\n"
		<<"4. Hapus Data Donatur\n"
		<<"5. Keluar\n"
		<<"\n"
		<<"Masukkan Pilihan : ";
	cin>>pilih;
	cout<<"\n";
	if(pilih == 1){
		create();
		goto start;
	}
	if(pilih == 2){
		read();
		goto start;
	}
	if(pilih == 3){
		update();
		goto start;
	}
	if(pilih == 4){
		deletee();
		goto start;
	}
	if(pilih == 5){
		cout<<"TERIMA KASIH";
	}
	else{
		cout<<"PILIH SESUAI MENU !!!\n";
		goto start;
	}
}
