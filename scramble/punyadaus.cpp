//================================================
//Nama		: Muhammad Firdaus
//Nim		: 2109106052
//Kelas		: Informatika A'21
//Program	: Program Pendataan Obat Di Apotek
//Tugas		: Posttest 7
//================================================
//Note: cara pemanggilan struct dengan cara variable_struct.nama_field;

#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

struct Batas{
	string nama;
	string jenis; 
	int harga;
	
};	
int jumlahdata = 0;
Batas batas[100];
int a,b,c,d,i;
fstream fileobat;

void baca_file(){
	string isi_txt;
	fileobat.open("posttest7apl.txt", ios::in);
	while (!fileobat.eof()){
		getline(fileobat,isi_txt);
		cout << isi_txt << endl;
	}getch();
	fileobat.close();	
}

void tambah_file(){
	fileobat.open("posttest7apl.txt", ios::app);
		fileobat <<"\n"
				<< "\nNama			" << ": " << batas[i].nama
				<<"\nJenis			" << ": " << batas[i].jenis
				<<"\nHarga			" << ": " << batas[i].harga
				<<"\n";
	fileobat.close();
}

void nulis_file(){
	fileobat.open("posttest7apl.txt", ios::out);
	for (int i=0; i<jumlahdata; i++){
		fileobat <<"\n"
				<< "\nNama			" << ": " << batas[i].nama
				<<"\nJenis			" << ": " << batas[i].jenis
				<<"\nHarga			" << ": " << batas[i].harga
				<<"\n";
	}fileobat.close();
}

void buka_file(){
	fileobat.open("posttrsest7apl.txt", ios::in);
	if(!fileobat.is_open()){
		fileobat.open("posttest7apl.txt", ios ::in | ios::trunc);
		fileobat.close();
	}fileobat.close();
}

void file_manajemen(){
	int pilih;
	cout << "=============================	" << endl
	 	<< 	 "       MENU FILE MANAJEMEN		" << endl
	   	<<   "=============================		" << endl
	 	<<   "[1] Lihat File					" << endl
	 	<<   "[2] Hapus File					" << endl
		<<   "[3] Kembali					" << endl;
	cout << endl;
	cout << "Masukkan pilihan: "; cin >> pilih;
	switch(pilih){
		case 1:
			nulis_file();
			baca_file();
			file_manajemen();
			break;
		case 2:
			remove("posttest7apl.txt");
			cout << "File berhasil dihapus"; getch();
			break;
		case 3:
			break;
	}
}

void swap(Batas* a, Batas* b)//rumus tukar di menu sorting
{
Batas temp = *a;
*a = *b;
*b = temp;
}

int partition_askending (Batas batas[], int low, int high)//rumus pivot atau titik tengah askending
{
	int pivot = batas[high].harga;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (batas[j].harga <= pivot)
		{
			i++;
			swap(&batas[i], &batas[j]);
		}
	}
	swap(&batas[i + 1], &batas[high]);
	return (i + 1);
}

int partition_diskending (Batas batas[], int low, int high)//rumus pivot atau titik tengah deskending
{
	int pivot = batas[high].harga;
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
		if (batas[j].harga >= pivot)
		{
		i++;
		swap(&batas[i], &batas[j]);
		}
	}
	swap(&batas[i + 1], &batas[high]);
	return (i + 1);
}

int binarySearch_nama(Batas batas[100], int jumlahdata){
    int beg = 0, end = jumlahdata , mid, index = -1;
    string num;

    // data diurutkan
    for (int i = 0; i < jumlahdata - 1; i++){
        for (int j = 0; j < jumlahdata -j; j++){
            if (batas[j].nama > batas[j + 1].nama){
                Batas swap = batas[j];
                batas[j] = batas[j + 1];
                batas[j + 1] = swap;
            }
        }
    }

	cout<< "Searching Nama Obat : "; fflush(stdin);
	getline(cin, num);
 
    while(beg <= end){
        mid = (end + beg) / 2;
        if(batas[mid].nama == num){ // perbandingan data dicari dengan data di struct
            index = mid + 1;

            for (int k = 0; k < jumlahdata; k++){ // perulangan untuk data duplikat
                if (batas[mid].nama == batas[k].nama){ // perbandingan data
					cout << "\nNama Obat      			" << ": "<< batas[k].nama << endl;
					cout << "\nJenis Obat			" << ": "<< batas[k].jenis << endl;
					cout << "\nHarga     			" << ": "<< batas[k].harga<< endl;
 
                }
			}
            break;
        }

        else{
            if(num > batas[mid].nama){ // perbandingan jika lebih besar
                beg = mid + 1;
            }
            else{
                end = mid - 1;
            }
		}
    }

    if ( index == -1){ // data tidak ditemukan bila bernilai -1
		cout<<"\nDATA TERSEBUT TIDAK ADA!" << endl; 
	}
    return 0;
}

int binarySearch_jenis(Batas batas[100], int jumlahdata){
    int beg = 0, end = jumlahdata , mid, index = -1;
    string cari_jenis;

    // data diurutkan
    for (int i = 0; i < jumlahdata - 1; i++){
        for (int j = 0; j < jumlahdata -j; j++){
            if (batas[j].jenis > batas[j + 1].jenis){
                Batas swap = batas[j];
                batas[j] = batas[j + 1];
                batas[j + 1] = swap;
            }
        }
    }

	cout<< "Searching Jenis Obat : "; fflush(stdin);
	getline(cin, cari_jenis);
 
    while(beg <= end){
        mid = (end + beg) / 2;
        if(batas[mid].jenis == cari_jenis){ // perbandingan data dicari dengan data di struct
            index = mid + 1;

            for (int k = 0; k < jumlahdata; k++){ // perulangan untuk data duplikat
                if (batas[mid].jenis == batas[k].jenis){ // perbandingan data
					cout << "\nNama Obat      			" << ": "<< batas[k].nama << endl;
					cout << "\nJenis Obat			" << ": "<< batas[k].jenis << endl;
					cout << "\nHarga     			" << ": "<< batas[k].harga<< endl;
 
                }
			}
            break;
        }

        else{
            if(cari_jenis > batas[mid].jenis){ // perbandingan jika lebih besar
                beg = mid + 1;
            }
            else{
                end = mid - 1;
            }
		}
    }

    if ( index == -1){ // data tidak ditemukan bila bernilai -1
		cout<<"\nDATA TERSEBUT TIDAK ADA!" << endl; 
	}
    return 0;
}

void quickSort_askending(Batas batas[], int low, int high)//rumus quicksort secara askending
{
	if (low < high)
	{
		int pi = partition_askending(batas, low, high);
		quickSort_askending(batas, low, pi - 1);
		quickSort_askending(batas, pi + 1, high);
	}
}

void quickSort_deskending(Batas batas[], int low, int high)//rumus quicksort secara deskending
{
	if (low < high)
{
	int pi = partition_diskending(batas, low, high);
	quickSort_deskending(batas, low, pi - 1);
	quickSort_deskending(batas, pi + 1, high);
}
}

void inter_search(Batas batas[100], int jumlahdata){
quickSort_askending(batas, 0, jumlahdata-1);
    // inisiasi nilai variabel indeks
    int i = jumlahdata;
    int i_awal = 0, i_posisi;
    int proses = 0;
    int i_akhir = jumlahdata - 1;
    // input nilai yang ingin dicari
    int key;
    cout << "Masukkan Jumlah Harga : ";
    cin >> key;
   	while(true){
				proses++;
				// rumus interpolation search
				i_posisi = (i_awal + ((key - batas[i_awal].harga) * (i_akhir - i_awal)) / (batas[i_akhir].harga + batas[i_awal].harga));
				// proses pembandingan search
				if (batas[i_posisi].harga == key){
					for (int i=0; i<jumlahdata; i++){
						cout << "\nNama Obat      			" << ": "<< batas[i_posisi].nama << endl;
						cout << "\nJenis Obat			" << ": "<< batas[i_posisi].jenis << endl;
						cout << "\nHarga     			" << ": "<< batas[i_posisi].harga<< endl;
						}
					break;
					}
				else if ((batas[i_posisi].harga < key) && (batas[i_posisi].harga >= batas[i_posisi].harga))
				{
					i_awal = i_posisi + 1;
					continue;
				}
				else if ((batas[i_posisi].harga > key) && (batas[i_posisi].harga <= batas[i_posisi].harga))
				{
					i_akhir = i_posisi - 1;
					continue;
				}
				else
				{
					cout << "Nilai yang anda cari tidak ada" << endl;
					break;
				}
			}
}

void bubbleSort(Batas batas[], int jumlahdata)//rumus bubble sort yang dapat memilih secara askending ataupun deskending
{ 
	int j, milih;
	Batas swap;
	cout << "1. Ascending" << endl
		<< "2. Descending" << endl
		<< "Pengurutan berdasarkan: "; cin >> milih;
   switch(milih){
        case 1:
			for (int i=0; i<jumlahdata-1; i++){
				for(j=0; j<jumlahdata-1; j++){
					if(batas[j].nama>batas[j+1].nama){
						swap = batas[j];
						batas[j] = batas[j+1];
						batas[j+1] = swap;
					}
				}	
			}
			break;
			
		case 2:
			for (int i=0; i<jumlahdata-1; i++){
				for(j=0; j<jumlahdata-1; j++){
					if(batas[j].nama>batas[j+1].nama){
						swap = batas[j];
						batas[j] = batas[j+1];
						batas[j+1] = swap;
					}
				}	
			}
			break;
}
}

void selectionSort(Batas batas[], int jumlahdata)//rumus selection sort yang dapat memilih secara askending ataupun deskending
{ 
    int i, j, Min;
    int milih;
   	    cout<<"\n Tampilkan Dengan Urutan : \n"<<endl
		<<" 1. Ascending (Menaik)\n"<<endl
		<<" 2. Decending (Menurun)\n"<<endl
		<<"Masukan pilihan : ";cin>>milih;
		          
	for (i = 0; i < jumlahdata-1; i++){ 
	    Min = i;  
		for (j = i+1; j < jumlahdata; j++){
			switch(milih){  
	        case 1:
	            if (batas[j].jenis < batas[Min].jenis){
					Min = j;	
				}
	            break;
	            
	        case 2:
	            if (batas[j].jenis > batas[Min].jenis){
	                Min = j; 
	            }
	            break;
    		}
        }
        swap(&batas[Min], &batas[i]); 
	}        
} 

void inputdata(){ //fungsi void inputdata yang berisikan program input data yang berisikan jenis, nama, dan harga dari obat
	int i = jumlahdata;
	int array = 100;
	if (i < array){
	   cout<<"Jenis Obat\t: ";
	   cin>>batas[i].jenis;
	   cout<<"Nama Obat\t: ";
	   cin>>batas[i].nama;
	   cout<<"Harga\t\t: ";
	   cin>>batas[i].harga;
	   tambah_file();
	   jumlahdata++;}
		cout<< "\n===Data Telah Ditambahkan===";   
		cout << "\n===================================\n\n";
		}
		
 void lihatdata(){ //fungsi void lihatdata yang akan menampilkan data yang telah diinput ke dalam tabel
 cout<<"\n================================Menampilkan Data===========================================\n\n";
 int i = jumlahdata;
 if (i > 0){
	 for(i=0;i<jumlahdata;i++)
	 {
	  cout<<"============================================================================================\n";
	  cout<<"Jenis : "<< batas[i].jenis<< endl;
	  cout<<"Nama : "<<batas[i].nama<< endl;
	  cout<<"Harga: "<<batas[i].harga<< endl;
	  }
 }
	cout<<"============================================================================================ ";}

	
void hapusdata() //fungsi void hapusdata yang berisikan program hapus data yang ingin dihapus
{int x,y;
 lihatdata();
 cout << "\n===================================";
 cout<<"\nHapus data ke-";cin>>x;
  cout << "\n===================================";
 y=x-1;
 a--;
 for(int i=y;i<a;i++)
 {batas[i]=batas[i+1];}
 cout<<"\n+++++++ Data ke-"<<x<<" Berhasil Terhapus +++++++";
  cout << "\n===================================";}


void editdata(){ //fungsi void editdata yang mana program ini menanyakan data mana yang akan di ubah dan menginput ulang jenis, nama, dan harga obat
int k,l;
lihatdata();
	cout<<"\nMasukan Data yang akan diedit : ";
	cin>>k;
	l=k-1;
	cout<<"Jenis Obat\t: ";
	cin>>batas[l].jenis;
	cout<<"Nama Obat\t: ";
	cin>>batas[l].nama;
	cout<<"Harga Obat\t: ";
	cin>>batas[l].harga;
	cout<<"\n===Data telah diganti===";}
	

void sort_menu(){//Menu sorting yang dapat dipilih secara descending atai ascending
	int pilih, urutan;
	{
		cout << "=============================	" << endl
	 	<< 	 "   Sorting Berdasarkan		" << endl
	   	<<   "=============================		" << endl
	 	<<   "[1] Nama					" << endl
	 	<<   "[2] Jenis 							" << endl
	 	<<   "[3] Harga					" << endl;
		cout << endl;
		cout << "Masukkan pilihan: "; cin >> pilih;
		if (pilih==1){
			cout << "1. Ascending" << endl
				<< "2. Descending" << endl
				<< "Pengurutan berdasarkan: "; cin >> urutan;
				switch (urutan){
					case 1:
						quickSort_askending(batas, 0, jumlahdata-1 );
						lihatdata();
						break;
					case 2:
						quickSort_deskending(batas, 0, jumlahdata-1 );
						lihatdata();
				}
		}
				else if (pilih==2){
					bubbleSort(batas, jumlahdata);	
					lihatdata();
				}	
				else if (pilih==3){
					selectionSort(batas, jumlahdata);
					lihatdata();
				}	
				else{
					cout << "Pilihan tidak ada\n"; getch();
		}
	}
}
   
void search_menu(){//search menu yang dapat memilih mencari berdasarkan nama atau jenis
	int pilih;
	{
		cout << "=============================	" << endl
	 	<< 	 "      Searching Berdasarkan     	" << endl
	   	<<   "=============================		" << endl
	 	<<   "[1] Nama					" << endl
	 	<<   "[2] Jenis 				" << endl
	 	<<   "[3] Harga 				" << endl;
		cout << endl;
		cout << "Masukkan pilihan: "; cin >> pilih;			
		switch(pilih){
		case 1:
			binarySearch_nama(batas, jumlahdata);
			break;	
					
		case 2:
			binarySearch_jenis(batas, jumlahdata);
			break;
			
		case 3:
			inter_search(batas, jumlahdata);
			break;	
				
		default:
		cout << "Pilihan tidak ada\n"; getch();
		}	
}
}



int main()//program utama dimana program pilihan menu berada
{
int pilih;
char kembali;
 char w;
  cout<<"\n=============================================================================";
 cout<<"\n=                          PROGRAM DATA OBAT                               =";
 cout<<"\n=============================================================================";
cout<<"\n\n=============================================================================";
cout<<"\n\t\t\t\t==> PILIHAN MENU <==";
cout<<"\n\t\t\t\t[1] Masukkan data";
cout<<"\n\t\t\t\t[2] Hapus Data";
cout<<"\n\t\t\t\t[3] Lihat Data";
cout<<"\n\t\t\t\t[4] Cari Data";  
cout<<"\n\t\t\t\t[5] Edit Data";
cout<<"\n\t\t\t\t[6] Menu File";
cout<<"\n\t\t\t\t[7] Keluar";
  cout<<"\n=============================================================================";
  cout<<"\n\t\t\t\tMasukkan Pilihan : ";
  cin>>pilih;
  if(pilih==1){
	tambah : // blokg
		inputdata();
		cout << "\nApakah ingin menambah data lagi? (y/n) : "; cin >> kembali ; 
		if (kembali == 'y' || kembali == 'Y'){
			goto tambah; // pergi ke blok add_more
			cout<< endl; 
				}
				
			else{
				main(); // pergi ke blok start program
				}
			}
  else if(pilih==2)
   {hapusdata();baca_file();main();}
  else if(pilih==3)
   {sort_menu();main();}
  else if(pilih==4)
   {search_menu();main();}
  else if(pilih==5)
   {editdata();baca_file();main();}
   else if(pilih==6)
   {file_manajemen();main();}
  else if(pilih==7)
	cout << "TERIMA KASIH TELAH MENGGUNAKAN PROGRAM";
}