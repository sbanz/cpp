// Library yang digunakan dalam membuat program
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Struct data loker
struct data{
	int nomor;
	string nama;
	string barang;
	string nomorHP;
	string tanggal;
}; 

// deklarasi dari struct
data loker[100];
int size;

// Prosedur sort atribut nama dengan metode bubblesort
void bubble(data loker[], int size){
	int j, pilih;
	data swap;
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

//Prosedur untuk swap data dengan pointer
void swap(data *xp, data *yp)
{
	data temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// Prosedur sort atribut barang dengan metode selectionSort
void selectionSort(data loker[], int size)
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
					if (loker[j].barang < loker[min_idx].barang)
					{
						min_idx = j;	
					}
					break;
				case 2:
					if (loker[j].barang > loker[min_idx].barang)
					{
						min_idx = j;	
					}
					break;
			}
		}
		swap(&loker[i], &loker[min_idx]);
	}
}

// Prosedur sort atribut nomor loker dengan metode quick sort
int partition_askending (data loker[], int low, int high)
{
	int pivot = loker[high].nomor;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (loker[j].nomor <= pivot)
		{
			i++;
			swap(&loker[i], &loker[j]);
		}
	}
	swap(&loker[i + 1], &loker[high]);
	return (i + 1);
}

int partition_diskending (data loker[], int low, int high)
{
	int pivot = loker[high].nomor;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (loker[j].nomor >= pivot)
		{
			i++;
			swap(&loker[i], &loker[j]);
		}
	}
	swap(&loker[i + 1], &loker[high]);
	return (i + 1);
}

void quickSort_askending(data loker[], int low, int high)
{
	if (low < high)
	{
		int pi = partition_askending(loker, low, high);
		quickSort_askending(loker, low, pi - 1);
		quickSort_askending(loker, pi + 1, high);
	}
}

void quickSort_diskending(data loker[], int low, int high)
{
	if (low < high)
	{
		int pi = partition_diskending(loker, low, high);
		quickSort_diskending(loker, low, pi - 1);
		quickSort_diskending(loker, pi + 1, high);
	}
}


//Proser untuk print data
void print()
{
	system("cls");
	int i;
	for (i=0; i < size; i++){
		cout << "\nNomor Loker 			" << ": "<< loker[i].nomor
			<< "\nNama        			" << ": "<< loker[i].nama
			<< "\nNama Barang 			" << ": "<< loker[i].barang
			<< "\nNomor HP    			" << ": "<< loker[i].nomorHP
			<< "\nTanggal (DD-MM-YY)\t\t" << ": "<< loker[i].tanggal <<"\n";
	}
	getch();
}

// Prosedur untuk tampilan judul kodingan
void tampilan(){
	cout << "Nama: Herni Suhartati " << endl;
	cout << "NIM : 2109106001" << endl;
    cout << endl;
    cout << "============================================================================================" << endl
    	<<  "----------------------------------- POSTTEST 4 STRUCT --------------------------------------" << endl
     	<<  "----------------------------- Program Manajemen Data Loker ---------------------------------" << endl
    	<<  "============================================================================================" << endl;
    cout << endl;	
}

// Prosedur untuk tampilan menu manajemen
void menu_utama(){
	cout <<  "======================" << endl
	 	<< 	 "     MENU MANAJEMEN   " << endl
	   	<<   "======================" << endl
	 	<<   "[1] Lihat Data 		" << endl
	 	<<   "[2] Tambah Data		" << endl
		<<   "[3] Ubah Data 		" << endl
		<<   "[4] Hapus Data 		" << endl
		<<   "[5] Keluar Program 	" << endl;
}

// Prosedur untuk menambahkan data loker
void menambahkan(){
	system("cls");
	int jumlah;
	cout << "Jumlah data yang ingin ditambahkan: "; cin >> jumlah;
	cout << endl;
	for (int i=0; i<jumlah; i++){
		cout << "Masukkan nama		             	" << ": "; fflush(stdin);
		getline(cin, loker[size].nama);
		cout << "Masukkan nama barang  yang dititip	" << ": "; cin >> loker[size].barang;
		cout << "Masukkan nomor HP  \t\t\t: "; cin >> loker[size].nomorHP;
		cout << "Masukkan tanggal (DD-MM-YY)		" << ": "; cin >> loker[size].tanggal; cout <<"\n";
		loker[size].nomor=size+1;
		size++;
	}
	
}

// Prosedur untuk menampilkan data loker berdasarkan sorting
void menampilkan(){
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
	 	<<   "[3] Nama Barang					" << endl;
		cout << endl;
		cout << "Masukkan pilihan: "; cin >> pilih;
		system("cls");
		if (pilih==1){
			cout << "1. Ascending" << endl
				<< "2. Descending" << endl
				<< "Pengurutan berdasarkan: "; cin >> urutan;
				switch (urutan){
					case 1:
						quickSort_askending(loker, 0, size-1 );
						print();
						break;
					case 2:
						quickSort_diskending(loker, 0, size-1 );
						print();
						break;
				}
		}
		else if (pilih==2){
			bubble(loker, size);	
			print();
		}	
		else if (pilih==3){
			selectionSort(loker,size);
			print();
		}	
		else{
			cout << "Pilihan tidak ada\n"; getch();
		}
	}
}

// Prosedur untuk mengubah data loker
void ubah_data(){
	system("cls");
	if (size==0){
		cout << "Tidak ada data yang bisa diubah"; getch();
	}
	else {
		print();
		int nomor_ubah;
		cout << "\nMasukkan nomor loker data yang ingin diubah: "; cin >> nomor_ubah;
		system("cls");
		int indeks=nomor_ubah-1;
		cout << "Masukkan nama		             	" << ": "; fflush(stdin); getline(cin, loker[indeks].nama);
		cout << "Masukkan nama barang  yang dititip	" << ": "; cin >> loker[indeks].barang;
		cout << "Masukkan nomor HP  \t\t\t: "; cin >> loker[indeks].nomorHP;
		cout << "Masukkan tanggal (DD-MM-YY)		" << ": "; cin >> loker[indeks].tanggal; cout <<"\n";	
	}	
}

// prosedur untuk menghapus data loker
void hapus_data(){
	system("cls");
	if (size==0){
		cout << "Tidak ada data yang bisa dihapus "; getch();
	}
	else{
		int nomor_ubah;
		char pilih;
		if (size==1){
			system("cls");
			print();
			cout << "\nApakah ingin menghapus data? (y/t) "; cin >> pilih;
			switch (pilih){
				case 'y':
					loker[size]=loker[size+1];
					cout << "\nData berhasil terhapus "; getch();
					size--;
					break;
				default:
					cout << "Data tidak terhapus "; getch();
			} 
		}
		else {
			system("cls");
			print();
			cout << "\nMasukkan nomor loker data yang ingin diubah: "; cin >> nomor_ubah;
			int indeks=nomor_ubah-1;
			for (int i=indeks; i<size; i++){
				cout << "\nNomor Loker 			" << ": "<< loker[i].nomor
					<< "\nNama        			" << ": "<< loker[i].nama
					<< "\nNama Barang 			" << ": "<< loker[i].barang
					<< "\nNomor HP    			" << ": "<< loker[i].nomorHP
					<< "\nTanggal (DD-MM-YY)\t\t" << ": "<< loker[i].tanggal <<"\n"; 
				cout << "\nApakah ingin menghapus data? (y/t) "; cin >> pilih;
				size--;
				switch (pilih){
					case 'y':
						loker[i]=loker[i+1];
						cout << "\nData berhasil terhapus "; getch();
						break;
					default:
						cout << "Data tidak terhapus "; getch();
				}	
			}		
		}		
	}	
}

// prosedur untuk keluar program
void keluar(){
	system("cls");
	cout << "Anda telah keluar dari program "; getch();
}

//fungsi utama program
int main(){
	int pilih;
	awal:
		system("cls");
		tampilan();
		menu_utama();
		cout<<"\n\nMasukkan Pilihan : ";
		cin >> pilih;
		switch(pilih){
				case 1:
					{menampilkan();goto awal;} // kondisi jika user memilih untuk menampilkan data
				case 2:
					{menambahkan();goto awal;} // kondisi jika user memilih untuk menambahkan data
				case 3:
					{ubah_data();goto awal;} // kondisi jika user  memilih untuk ubah data
				case 4:
					{hapus_data(); goto awal;} // kondisi jika user memilih untuk hapus data
				case 5:
					keluar(); // kondisi jika user memilih untuk keluar program
					break;
				default:
					{goto awal;}
		
		}
		
  		
}

