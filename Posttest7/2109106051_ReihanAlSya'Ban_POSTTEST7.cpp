#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct pahala{
	int nomor;
	string nama;
	int sedekah;
};

int sizee;
pahala phl[100];

fstream file_phl;

//FUNGSI IMPORT DATA DARI FILE KE PROGRAM
void import(){
    file_phl.open("posttest7_saban.txt", ios::in);
    string nomor, sedekah;
    
    while(!file_phl.eof()){
    	getline(file_phl, nomor, ',');
        getline(file_phl, phl[sizee].nama, ',');
        getline(file_phl, sedekah, '\n');
        
        stringstream strnomor(nomor);
        stringstream strsedekah(sedekah);
        strnomor>>phl[sizee].nomor;
        strsedekah>>phl[sizee].sedekah;
        
        if(file_phl.eof()){
            break;
        }
        sizee++;
    }
    file_phl.close();
}

//FUNGSI UNTUK MENGECEK FILE EKSTERNAL
void file_check(){
	file_phl.open("posttest7_saban.txt", ios::in);

    if (!file_phl.is_open()){
        file_phl.open("posttest7_saban.txt", ios::out | ios::trunc);
        file_phl.close();
    }
    file_phl.close();
}

//FUNGSI MENGUPDATE ISI FILE SETELAH DIUBAH
void update_file(){
    file_phl.open("posttest7_saban.txt", ios::out);

    for (int x=0; x<sizee; x++){
        file_phl<<phl[x].nomor<<',';
        file_phl<<phl[x].nama<<',';
        file_phl<<phl[x].sedekah<<'\n';
    }
    file_phl.close();
}

//BUBBLE SORT
void bubble(pahala phl[], int size){
	int tipe;
	pahala swap;
	cout<<"================== MENU SORT ==================\n"
		<<"=============== TIPE PENGURUTAN ===============\n"
		<<"\n"
		<<"1. Ascending\n"
		<<"2. Descending"
		<<"\n"
		<<"Pilih : ";
	cin>>tipe;
	system("cls");
	switch(tipe){
		case 1:
			for (int x=0; x<size-1; x++){
				for(int y=0; y<size-1; y++){
					if(phl[y].nama > phl[y+1].nama){
						swap = phl[y];
						phl[y] = phl[y+1];
						phl[y+1] = swap;
					}
				}	
			}
			break;	
		case 2:
			for(int x=0; x<size-1; x++){
				for(int y=0; y<size-1; y++){
					if(phl[y].nama < phl[y+1].nama){
						swap = phl[y];
						phl[y] = phl[y+1];
						phl[y+1] = swap;
					}
				}	
			}
			break;
		break;
	}
}
void swap(pahala *xp, pahala *yp){
	pahala temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//SELECTION SORT
void selection(pahala phl[], int size){
	int min;
	int tipe;
	cout<<"================== MENU SORT ==================\n"
		<<"=============== TIPE PENGURUTAN ===============\n"
		<<"\n"
		<<"1. Ascending\n"
		<<"2. Descending"
		<<"\n"
		<<"Pilih : ";
	cin>>tipe;
	system("cls");
	for (int x=0; x<size-1; x++){
		min = x;
		for (int y=x+1; y<size; y++){
			switch (tipe){
				case 1:
					if (phl[y].sedekah < phl[min].sedekah){
						min = y;
					}
					break;
				case 2:
					if (phl[y].sedekah > phl[min].sedekah){
						min = y;	
					}
					break;
			}
		}
		swap(&phl[x], &phl[min]);
	}
}

//QUICK SORT
int partition_ascen(pahala phl[], int low, int high){
	int pivot = phl[high].nomor;
	int x=(low - 1);
	for (int y=low; y<=high- 1; y++){
		if (phl[y].nomor <= pivot){
			x++;
			swap(&phl[x], &phl[y]);
		}
	}
	swap(&phl[x + 1], &phl[high]);
	return (x + 1);
}
int partition_descen (pahala phl[], int low, int high){
	int pivot = phl[high].nomor;
	int x=(low - 1);
	for (int y=low; y<=high- 1; y++){
		if (phl[y].nomor >= pivot){
			x++;
			swap(&phl[x], &phl[y]);
		}
	}
	swap(&phl[x + 1], &phl[high]);
	return (x + 1);
}
void quick_ascen(pahala phl[], int low, int high){
	if (low < high){
		int pi = partition_ascen(phl, low, high);
		quick_ascen(phl, low, pi-1);
		quick_ascen(phl, pi+1, high);
	}
}
void quick_descen(pahala phl[], int low, int high){	
	if (low < high){
		int pi = partition_descen(phl, low, high);
		quick_descen(phl, low, pi-1);
		quick_descen(phl, pi+1, high);
	}
}

//FUNGSI MENAMBAHKAN DATA INPUTAN USER KE DALAM FILE
void create(){
	file_phl.open("posttest7_saban.txt", ios::app);
	
	int banyakdonate, banyakdata;
	cout<<"Masukkan berapa banyak jumlah donatur : ";
	cin>>banyakdonate;
	cout<<"\n";
	banyakdata = 0;
	for(int x=0; x<banyakdonate; x++){
		banyakdata = sizee + 1;
		cout<<"Nomor Donatur : "<<banyakdata<<endl;
		phl[sizee].nomor = banyakdata;
		cout<<"Nama : ";
		cin>>phl[sizee].nama;
		cout<<"Jumlah Sedekah : Rp.";
		cin>>phl[sizee].sedekah;
		cout<<"\n";
		file_phl<<phl[sizee].nomor<< ',';
    	file_phl<<phl[sizee].nama<< ',';
    	file_phl<<phl[sizee].sedekah<< '\n';
		sizee++;
	}
	cout<<"DATA BERHASIL DITAMBAHKAN\n";
	cout<<"\n";
	cout<<"TEKAN ENTER UNTUK KEMBALI KE MENU AWAL";
	getch();
	system("cls");
	file_phl.close();
}

//FUNGSI MELIHAT DATA
void read(){
	cout<<"\n";
	cout<<"DATA DONATUR\n";
	cout<<"\n";
	for(int indeks=0; indeks<sizee ; indeks++){
		cout<<"Nomor Donatur : "<<phl[indeks].nomor<<endl;
		cout<<"Nama : "<<phl[indeks].nama<<endl;
		cout<<"Jumlah Sedekah : Rp. "<<phl[indeks].sedekah<<endl;
		cout<<"\n";
	}
	cout<<"TEKAN ENTER UNTUK KEMBALI KE MENU AWAL";
	cout<<"\n";
	getch();
	system("cls");
}

//DRIVER SORTING
void sort_menu(){
	system("cls");
	int pilih, tipe;
	if (sizee==0){
		cout << "DATA KOSONG !!! ";
		getch();
		system("cls");
	}
	else if (sizee>0){
		cout<<"================== MENU SORT ==================\n"
			<<"==============  URUTKAN BERDASAR ==============\n"
			<<"\n"
			<<"1. Nomor Donatur\n"
			<<"2. Nama Donatur\n"
			<<"3. Jumlah Sedekah\n"
			<<"\n"
			<<"Masukkan pilihan: ";
		cin>>pilih;
		if (pilih==1){
			cout<<"================== MENU SORT ==================\n"
				<<"=============== TIPE PENGURUTAN ===============\n"
				<<"\n"
				<<"1. Ascending\n"
				<<"2. Descending"
				<<"\n"
				<<"Pilih : ";
			cin>>tipe;
			system("cls");
				switch (tipe){
					case 1:
						quick_ascen(phl, 0, sizee-1 );
						read();
						break;
					case 2:
						quick_descen(phl, 0, sizee-1 );
						read();
						break;
				}
		}
		else if (pilih==2){
			bubble(phl, sizee);
			read();
		}	
		else if (pilih==3){
			selection(phl, sizee);
			read();
		}	
		else{
			cout << "Pilihan tidak ada\n"; 
			getch();
			system("cls");
		}
	}
}

//FUNGSI SEARCH NAMA (BINARY SEARCH)
int binary_search(int pilih){
	cout<<endl;
    string num;
	int beg = 0;
	int end=sizee-1;
	int index= -1;
	cout<<"Nama yang dicari : ";
	cin>>num;
	switch (pilih){
		case 1:
			for (int x=0; x<sizee-1; x++){
				for(int y=0; y<sizee-1; y++){
					if(phl[y].nama>phl[y+1].nama){
						pahala swap = phl[y];
						phl[y] = phl[y+1];
						phl[y+1] = swap;
					}
				}	
			}
			while(beg<=end){
				int mid=(end+beg)/2;
				if(phl[mid].nama==num){
					index = mid +1;
					for (int x=0; x<sizee; x++){
						if(phl[mid].nama==phl[x].nama){
							cout<<"Nomor Donatur : "<<phl[x].nomor<<endl;
							cout<<"Nama : "<<phl[x].nama<<endl;
							cout<<"Jumlah Sedekah : Rp. "<<phl[x].sedekah<<endl;
							cout<<"\n";
						}
						getch();
					}
					break;
				}
				else{
					if(num>phl[mid].nama){
						beg= mid+1;
					}
					else{
						end=mid-1;
					}
				}
			}
			break;
	}

	if(index==-1){
		cout << "\nData tidak ditemukan"; getch();
	}
	system("cls");
	return 0;
}

//FUNGSI SEARCH JUMLAH SEDEKAH (INTERPOLATION SEARCH)
int inter_search(int pilih){
	quick_ascen(phl,0,sizee-1);
    int awal = 0, posisi;
    int proses = 0;
    int akhir = sizee - 1;
    int key;
    cout<<"Masukkan Jumlah sedekah yang ingin dicari : ";
    cin>>key;
	switch (pilih){
		case 2:
			while (true){
				proses++;
				posisi = (awal + ((key - phl[awal].sedekah) * (akhir - awal)) / (phl[akhir].sedekah + phl[awal].sedekah));
				if(phl[posisi].sedekah == key){
					for (int x=0; x<sizee; x++){
						if (phl[posisi].sedekah==phl[x].sedekah){
							cout<<"Nomor Donatur : "<<phl[x].nomor<<endl;
							cout<<"Nama : "<<phl[x].nama<<endl;
							cout<<"Jumlah Sedekah : Rp. "<<phl[x].sedekah<<endl;
							cout<<"\n";
						}
						getch();
					}
					break;
				}
				if((phl[posisi].sedekah < key) && (phl[posisi].sedekah >= phl[posisi].sedekah)){
					awal = posisi + 1;
					continue;
				}
				if((phl[posisi].sedekah > key) && (phl[posisi].sedekah <= phl[posisi].sedekah)){
					akhir = posisi - 1;
					continue;
				}
				else{
					cout<<"Nilai yang anda cari tidak ada"<<endl;
					break;
				}
			}
			break;
	}
	system("cls");
	return 0;
}

//FUNGSI DRIVER SEARCH
void search(){
	system("cls");
	int pilih;
		cout<<"================= MENU SEARCH =================\n"
			<<"================ CARI BERDASAR ================\n"
			<<"\n"
			<<"1. Nama Donatur\n"
			<<"2. Jumlah Sedekah\n"
			<<"\n"
			<<"Masukkan pilihan: ";
		cin>>pilih;
	switch (pilih)
	{
	case 1:
		binary_search(1);
		break;
	case 2:
		inter_search(2);
		break;
	default:
		cout<<"Inputan salah"; 
		getch();
		system("cls");
	}
}

//FUNGSI UNTUK MENGUBAH DATA
void update(){
	cout<<"DATA DONATUR\n";
	cout<<"\n";
	int nomor;
	for(int indeks=0; indeks<sizee ; indeks++){
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

//FUNGSI MENGHAPUS DATA
void deletee(){
	cout<<"DATA DONATUR\n";
	cout<<"\n";
	int nomor;
	for(int indeks=0; indeks<sizee ; indeks++){
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
	sizee--;
	for(int z=indeks; z<sizee; z++){
		phl[z].nama = phl[z+1].nama;
		phl[z].sedekah = phl[z+1].sedekah;
	}
	cout<<"DATA TELAH TERHAPUS\n";
	cout<<"\n";
	cout<<"TEKAN ENTER UNTUK KEMBALI KE MENU AWAL";
	getch();
	system("cls");
}

//FUNGSI MAIN
int main(){
	int pilih;
	start:
	file_check();
	cout<<"\n";
	cout<<"================== MENU UTAMA ==================\n"
		<<"==== PENDATAAN SEDEKAH WILAYAH POCHINKI ULU ====\n"
		<<"\n"
		<<"1. Masukkan Data Donatur\n"
		<<"2. Lihat Data Donatur\n"
		<<"3. Cari Data Donatur\n"
		<<"4. Ubah Data Donatur\n"
		<<"5. Hapus Data Donatur\n"
		<<"6. Hapus File\n"
		<<"7. Keluar\n"
		<<"\n"
		<<"Masukkan Pilihan : ";
	cin>>pilih;
	cout<<"\n";
	if(pilih == 1){
		create();
		goto start;
	}
	if(pilih == 2){
		if(sizee == 0){
			import();
			cout << "DATA KOSONG !!! ";
			getch();
			system("cls");
		}
		if(sizee > 0){
			sizee = 0;
			import();
			sort_menu();
		}
		goto start;
	}
	if(pilih == 3){
		search();
		goto start;
	}
	if(pilih == 4){
		if(sizee == 0){
			import();
		}
		if(sizee > 0){
			sizee = 0;
			import();
			update();
			update_file();
		}
		goto start;
	}
	if(pilih == 5){
		if(sizee == 0){
			import();
		}
		if(sizee > 0){
			sizee = 0;
			import();
			deletee();
			update_file();
		}
		goto start;
	}
	if(pilih == 6){
		remove("posttest7_saban.txt");
		system("cls");
		cout<<"DATA BERHASIL DIHAPUS\n";
		getch();
		system("cls");
		goto start;
	}
	if(pilih == 7){
		cout<<"TERIMA KASIH";
	}
	else{
		cout<<"PILIH SESUAI MENU !!!\n";
		goto start;
	}
}
