#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
using namespace std;

struct pahala{
	int nomor;
	string nama;
	int sedekah;
};

int size;
pahala phl[100];

void bubble(pahala phl[], int size){
	int j, pilih;
	pahala swap;
	cout << "1. Ascending" << endl
		<< "2. Descending" << endl
		<< "Pengurutan berdasarkan: "; cin >> pilih;
	switch(pilih){
		case 1:
			for (int i=0; i<size-1; i++){
				for(j=0; j<size-1; j++){
					if(phl[j].nama > phl[j+1].nama){
						swap = phl[j];
						phl[j] = phl[j+1];
						phl[j+1] = swap;
					}
				}	
			}
			break;	
		case 2:
			for(int i=0; i<size-1; i++){
				for(j=0; j<size-1; j++){
					if(phl[j].nama < phl[j+1].nama){
						swap = phl[j];
						phl[j] = phl[j+1];
						phl[j+1] = swap;
					}
				}	
			}
			break;
		break;
	}
}

void swap(pahala *xp, pahala *yp)
{
	pahala temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// Prosedur sort atribut barang dengan metode selectionSort
void selectionSort(pahala phl[], int size)
{
	int i, j, min_idx;
	int pilih;
	cout << "1. Ascending" << endl
		<< "2. Descending" << endl
		<< "Pengurutan berdasarkan: "; cin >> pilih;
	for (i = 0; i < size-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < size; j++)
		{
			switch (pilih){
				case 1:
					if (phl[j].sedekah < phl[min_idx].sedekah)
					{
						min_idx = j;	
					}
					break;
				case 2:
					if (phl[j].sedekah > phl[min_idx].sedekah)
					{
						min_idx = j;	
					}
					break;
			}
		}
		swap(&phl[i], &phl[min_idx]);
	}
}

int partition_askending (pahala phl[], int low, int high)
{
	int pivot = phl[high].nomor;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (phl[j].nomor <= pivot)
		{
			i++;
			swap(&phl[i], &phl[j]);
		}
	}
	swap(&phl[i + 1], &phl[high]);
	return (i + 1);
}

int partition_diskending (pahala phl[], int low, int high)
{
	int pivot = phl[high].nomor;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (phl[j].nomor >= pivot)
		{
			i++;
			swap(&phl[i], &phl[j]);
		}
	}
	swap(&phl[i + 1], &phl[high]);
	return (i + 1);
}

void quickSort_askending(pahala phl[], int low, int high)
{
	if (low < high)
	{
		int pi = partition_askending(phl, low, high);
		quickSort_askending(phl, low, pi - 1);
		quickSort_askending(phl, pi + 1, high);
	}
}

void quickSort_diskending(pahala phl[], int low, int high)
{
	if (low < high)
	{
		int pi = partition_diskending(phl, low, high);
		quickSort_diskending(phl, low, pi - 1);
		quickSort_diskending(phl, pi + 1, high);
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
		phl[indeks].nomor = banyakdata;
		cout<<"Nama : ";
		cin>>phl[indeks].nama;
		cout<<"Jumlah Sedekah : Rp.";
		cin>>phl[indeks].sedekah;
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
	for(int indeks=0; indeks<size ; indeks++)
	{
		cout<<"Nomor Donatur "<<phl[indeks].nomor<<endl;
		cout<<"Nama : "<<phl[indeks].nama<<endl;
		cout<<"Jumlah Sedekah : Rp. "<<phl[indeks].sedekah<<endl;
		cout<<"\n";
	}
	cout<<"TEKAN ENTER UNTUK KEMBALI KE MENU AWAL";
	cout<<"\n";
	getch();
	system("cls");
}

void sort_menu(){
	system("cls");
	int pilih, urutan;
	if (size==0)
	{
		cout << "Data loker tidak ada "; getch();
	}
	else if (size>0)
	{
		cout << "=============================	" << endl
	 	<< 	 "Tampilan Berdasarkan Sorting		" << endl
	   	<<   "=============================		" << endl
	 	<<   "[1] Nomor Loker					" << endl
	 	<<   "[2] Nama 							" << endl
	 	<<   "[3] Jumlah Sedekah					" << endl;
		cout << endl;
		cout << "Masukkan pilihan: "; cin >> pilih;
		system("cls");
		if (pilih==1){
			cout << "1. Ascending" << endl
				<< "2. Descending" << endl
				<< "Pengurutan berdasarkan: "; cin >> urutan;
				switch (urutan){
					case 1:
						quickSort_askending(phl, 0, size-1 );
						read();
						break;
					case 2:
						quickSort_diskending(phl, 0, size-1 );
						read();
						break;
				}
		}
		else if (pilih==2){
			bubble(phl, size);	
			read();
		}	
		else if (pilih==3){
			selectionSort(phl, size);
			read();
		}	
		else{
			cout << "Pilihan tidak ada\n"; getch();
		}
	}
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
		cout<<"Nama : "<<phl[indeks].nama<<endl;
		cout<<"Jumlah Sedekah : Rp. "<<phl[indeks].sedekah<<endl;
		cout<<"\n";
	}
	
	int ubah;
	int indeks;
	cout<<"Masukkan Nomor Donatur yang ingin diubah : ";
	cin>>ubah;
	indeks = ubah - 1;
	cout<<"Nama : ";
	cin>>phl[indeks].nama;
	cout<<"Jumlah Sedekah : Rp. ";
	cin>>phl[indeks].sedekah;
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
		cout<<"Nama : "<<phl[indeks].nama<<endl;
		cout<<"Jumlah Sedekah : Rp. "<<phl[indeks].sedekah<<endl;
		cout<<"\n";
	}
	
	int hapus, indeks;
	cout<<"Nomor Donatur yang ingin dihapus : ";
	cin>>hapus;
	indeks = hapus - 1;
	size--;
	for(int z=indeks; z<size; z++){
		phl[z].nama = phl[z+1].nama;
		phl[z].sedekah = phl[z+1].sedekah;
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
		sort_menu();
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
