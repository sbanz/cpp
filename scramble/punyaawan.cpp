// Library 
#include<iostream>

// Library file
#include<fstream>

// Library konversi
#include<sstream>

// Library Limit (batasan)
#include<limits>

using namespace std;

// Struct
struct game{
    string nama, genre;
    int tahun, harga;
};

// Jumlah Data Elemen Array & Variabel Parameter Linear Search
int data_game = 0;

// Array Of Struct
game Game[100];

// Deklarasi Variabel Untuk Parameter Linear Search
string cari_nama, cari_genre;
int cari_tahun, cari_harga;

// Deklarasi Variabel Untuk Parameter Binary Search
string nama, genre;
int tahun, harga;

// Variabel global file eksternal
fstream Game_file;

// Prosedur Tambah Data
void tambah_data(){
    Game_file.open("2109106002_ALIF MAULANA SETYAWAN_APL_Posttest7_Data.txt", ios::app);

    cout << "\nMasukkan Nama Game        : "; fflush(stdin);
    getline(cin, Game[data_game].nama);
    cout << "Masukkan Genre Game       : "; fflush(stdin);
    getline(cin, Game[data_game].genre);
    
    // Error Handling Input User
    while(true){
        cout << "Masukkan Tahun Rilis Game : "; cin >> Game[data_game].tahun;
        if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }

    // Error Handling Input User
    while(true){
        cout << "Masukkan Harga Game       : Rp. "; cin >> Game[data_game].harga;
        if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }

    // Untuk menambahkan data ke dalam file eksternal
    Game_file << Game[data_game].nama << ',';
    Game_file << Game[data_game].genre << ',';
    Game_file << Game[data_game].tahun << ',';
    Game_file << Game[data_game].harga << '\n';
    
    Game_file.close();
    data_game++;
}

// Prosedur Ubah Data
void ubah_data(){
    int ubah, no_ubah;

    // Error Handling Input User
    while(true){
        cout << "\nNomor Berapa Yang Ingin Diubah ?? >> "; cin >> ubah;
        if(cin.fail()){
            cin.clear();
            cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
            cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }

    no_ubah = ubah - 1;

    cout << "\nMasukkan Nama Game Yang Baru        : "; fflush(stdin);
    getline(cin, Game[no_ubah].nama);
    cout << "Masukkan Genre Game Yang Baru       : "; fflush(stdin);
    getline(cin, Game[no_ubah].genre);

    // Error Handling Input User
    while(true){
        cout << "Masukkan Tahun Rilis Game Yang Baru : "; cin >> Game[no_ubah].tahun;
        if(cin.fail()){
            cin.clear();
            cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
            cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }

    // Error Handling Input User
    while(true){
        cout << "Masukkan Harga Game Yang Baru       : Rp. "; cin >> Game[no_ubah].harga;
        if(cin.fail()){
            cin.clear();
            cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
            cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }
}

// Prosedur Lihat Data
void lihat_data(){
    for (int i = 0; i < data_game; i++){
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << i+1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
             << "Nama Game        : " << Game[i].nama << endl
             << "Genre Game       : " << Game[i].genre << endl
             << "Tahun Rilis Game : " << Game[i].tahun << endl
             << "Harga Game       : Rp. " << Game[i].harga << endl;
    }
}

// Prosedur Hapus Data
void hapus_data(){
    int hapus, no_hapus, i;

    // Error Handling Input User
    while(true){
        cout << "\nNomor Berapa Yang Ingin Dihapus ?? >> "; cin >> hapus;
        if(cin.fail()){
            cin.clear();
            cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
            cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }

    no_hapus = hapus - 1;
    data_game--;
    for(i = no_hapus; i < data_game; i++){
        Game[i] = Game[i+1];
    }

}

// Prosedur Membaca dan Memindahkan Data dari File ke Program
void pindah_data(){

    Game_file.open("2109106002_ALIF MAULANA SETYAWAN_APL_Posttest7_Data.txt", ios::in);

    string tahun, harga;

    while(!Game_file.eof()){

        getline(Game_file, Game[data_game].nama, ',');
        getline(Game_file, Game[data_game].genre, ',');
        getline(Game_file, tahun, ',');
        getline(Game_file, harga, '\n');

        // Konversi str ke int
        stringstream strtahun(tahun);
        stringstream strharga(harga);

        strtahun >> Game[data_game].tahun;
        strharga >> Game[data_game].harga;
        
        if(Game_file.eof()){
            break;
        }
        data_game++;
    }
    Game_file.close();
}

// Prosedur Memeriksa Keberadaan Sebuah File Eksternal
void openfile(){
    Game_file.open("2109106002_ALIF MAULANA SETYAWAN_APL_Posttest7_Data.txt", ios::in);

    // jika file eksternal tidak ditemukan, maka akan dibuat secara otomatis
    if (!Game_file.is_open()){
        Game_file.open("2109106002_ALIF MAULANA SETYAWAN_APL_Posttest7_Data.txt", ios::out | ios::trunc);
        Game_file.close();
    }
    Game_file.close();
}

// Prosedur Update Data File Eksternal
void updatefile(){
    Game_file.open("2109106002_ALIF MAULANA SETYAWAN_APL_Posttest7_Data.txt", ios::out);

    // Untuk mengupdate seluruh perubahan data di dalam file eksternal
    for (int i = 0; i < data_game; i++){
        Game_file << Game[i].nama << ',';
        Game_file << Game[i].genre << ',';
        Game_file << Game[i].tahun << ',';
        Game_file << Game[i].harga << '\n';
    }

    Game_file.close();
}

// Prosedur Tampilan Menu Utama
void tampilan_menu(){
  cout << "================================================" << endl
       << "|---------------Selamat Datang-----------------|" << endl
       << "|--------Di Data Penjualan Game Online---------|" << endl
       << "================================================" << endl
       << "- Dibuat Oleh Alif Maulana Setyawan" << endl
       << "\n>>> ------------Menu------------ <<<" << endl
       << "1) Tambah Data Penjualan" << endl
       << "2) Lihat Data Penjualan" << endl
       << "3) Ubah Data Penjualan" << endl
       << "4) Hapus Data Penjualan" << endl
       << "5) Urutkan Data (Bubble Sort)" << endl
	   << "6) Urutkan Data (Shell Sort)" << endl
       << "7) Cari Data (Linear Search)" << endl
       << "8) Cari Data (Binary Search)" << endl
       << "9) Hapus file eksternal" << endl
       << "0) Exit" << endl;
}

// Prosedur Tampilan Menu Pengurutan Bubble Sort
void tampilan_pengurutan_bubble(){
  cout << "\n================================================" << endl
       << "|----------------Pengurutan Data---------------|" << endl
       << "|------------------Bubble Sort-----------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "1) Nama" << endl
       << "2) Genre" << endl
       << "3) Tahun Rilis" << endl
       << "4) Harga" << endl;
}

// Prosedur Tampilan Menu Pengurutan Shell Sort
void tampilan_pengurutan_shellsort(){
  cout << "\n================================================" << endl
       << "|----------------Pengurutan Data---------------|" << endl
       << "|-------------------Shell Sort-----------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "1) Nama" << endl
       << "2) Genre" << endl
       << "3) Tahun Rilis" << endl
       << "4) Harga" << endl;
}

// Prosedur Tampilan Menu Pencarian Linear Search
void tampilan_pencarian_linearsearch(){
  cout << "\n================================================" << endl
       << "|-----------------Pencarian Data---------------|" << endl
       << "|------------------Linear Search---------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "\nCari Berdasarkan :" << endl
       << "1) Nama" << endl
       << "2) Genre" << endl
       << "3) Tahun Rilis" << endl
       << "4) Harga" << endl;
}

// Prosedur Tampilan Menu Pencarian Binary Search
void tampilan_pencarian_binarysearch(){
  cout << "\n================================================" << endl
       << "|-----------------Pencarian Data---------------|" << endl
       << "|------------------Binary Search---------------|" << endl
       << "================================================" << endl
       << "\n>>> --------Menu-------- <<<" << endl
       << "\nCari Berdasarkan :" << endl
       << "1) Nama" << endl
       << "2) Genre" << endl
       << "3) Tahun Rilis" << endl
       << "4) Harga" << endl;
}

// Fungsi Pencarian Linear Search Nama
int linear_search_nama(int data_game, string cari_nama){
    bool point;
    int data, index = 0, simpan_data[100];
    
    cout << "\nMasukkan Nama Game Yang Ingin Anda Cari" << endl
         << ">> "; fflush(stdin); 
    getline(cin, cari_nama);

    for (int i = 0; i < data_game ; i++){
        while(cari_nama == Game[i].nama){
            point = true;
            simpan_data[index] = i;
            index++;
            break;
        }
    }

    if(point == 1){
        for (int j = 0; j < index ; j++){
            data = simpan_data[j];
            cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << data + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
                << "Nama Game        : " << Game[data].nama << endl
                << "Genre Game       : " << Game[data].genre << endl
                << "Tahun Rilis Game : " << Game[data].tahun << endl
                << "Harga Game       : Rp. " << Game[data].harga << endl;
        }
    }

    else{
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -DATA TIDAK ADA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    }

    return 0;
}

// Fungsi Pencarian Linear Search Genre
int linear_search_genre(int data_game, string cari_genre){
    bool point;
    int data, index = 0, simpan_data[100];
    
    cout << "\nMasukkan Genre Game Yang Ingin Anda Cari" << endl
         << ">> "; fflush(stdin); 
    getline(cin, cari_genre);

    for (int i = 0; i < data_game ; i++){
        while(cari_genre == Game[i].genre){
            point = true;
            simpan_data[index] = i;
            index++;
            break;
        }
    }

    if(point == 1){
        for (int j = 0; j < index ; j++){
            data = simpan_data[j];
            cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << data + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
                << "Nama Game        : " << Game[data].nama << endl
                << "Genre Game       : " << Game[data].genre << endl
                << "Tahun Rilis Game : " << Game[data].tahun << endl
                << "Harga Game       : Rp. " << Game[data].harga << endl;
        }
    }

    else{
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -DATA TIDAK ADA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    }

    return 0;
}

// Fungsi Pencarian Linear Search Tahun
int linear_search_tahun(int data_game, int cari_tahun){
    bool point;
    int data, index = 0, simpan_data[100];
    
    // Error Handling Input User
    while(true){
        cout << "\nMasukkan Tahun Game Yang Ingin Anda Cari" << endl
             << ">> "; cin >> cari_tahun;
        if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }

    for (int i = 0; i < data_game ; i++){
        while(cari_tahun == Game[i].tahun){
            point = true;
            simpan_data[index] = i;
            index++;
            break;
        }
    }

    if(point == 1){
        for (int j = 0; j < index ; j++){
            data = simpan_data[j];
            cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << data + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
                << "Nama Game        : " << Game[data].nama << endl
                << "Genre Game       : " << Game[data].genre << endl
                << "Tahun Rilis Game : " << Game[data].tahun << endl
                << "Harga Game       : Rp. " << Game[data].harga << endl;
        }
    }

    else{
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -DATA TIDAK ADA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    }

    return 0;
}

// Fungsi Pencarian Linear Search Harga
int linear_search_harga(int data_game, int cari_harga){
    bool point;
    int data, index = 0, simpan_data[100];
    
    // Error Handling Input User
    while(true){
        cout << "\nMasukkan Harga Game Yang Ingin Anda Cari" << endl
             << ">> Rp. "; cin >> cari_harga;
        if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }

    for (int i = 0; i < data_game ; i++){
        while(cari_harga == Game[i].harga){
            point = true;
            simpan_data[index] = i;
            index++;
            break;
        }
    }

    if(point == 1){
        for (int j = 0; j < index ; j++){
            data = simpan_data[j];
            cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << data + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
                << "Nama Game        : " << Game[data].nama << endl
                << "Genre Game       : " << Game[data].genre << endl
                << "Tahun Rilis Game : " << Game[data].tahun << endl
                << "Harga Game       : Rp. " << Game[data].harga << endl;
        }
    }

    else{
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -DATA TIDAK ADA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    }

    return 0;
}

// Fungsi Pencarian Binary Search Nama
int binary_search_nama(int data_game, string nama){

    int awal = 0, akhir = data_game, tengah, index = -1;

    // Pengurutan Data
    for (int x = 0; x < data_game-1; x++){
        for (int y = 0; y < data_game-1; y++){
            if (Game[y].nama > Game[y+1].nama){
                game swap = Game[y];
                Game[y] = Game[y+1];
                Game[y+1] = swap;
            }
        }
    }

    cout<< "\nMasukkan Nama Game Yang Ingin Anda Cari" << endl
        << ">> "; fflush(stdin);
        getline(cin, nama);

    while(awal <= akhir){
        tengah = (akhir + awal) / 2;
        if(Game[tengah].nama == nama){
            index = tengah + 1;

            int NomorData = 0;
            for (int i = 0; i < data_game; i++){
                if (Game[tengah].nama == Game[i].nama){
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << NomorData + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
                            << "Nama Game        : " << Game[i].nama << endl
                            << "Genre Game       : " << Game[i].genre << endl
                            << "Tahun Rilis Game : " << Game[i].tahun << endl
                            << "Harga Game       : Rp. " << Game[i].harga << endl;
                    NomorData++;
                }
			}
            break;
        }

        else{
            if(nama > Game[tengah].nama){
                awal = tengah + 1;
            }
            else{
                akhir = tengah - 1;
            }
		}
    }

    if ( index == -1){
		cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -DATA TIDAK ADA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}

    return 0;
}

// Fungsi Pencarian Binary Search Genre
int binary_search_genre(int data_game, string genre){

    int awal = 0, akhir = data_game, tengah, index = -1;

    // Pengurutan Data
    for (int x = 0; x < data_game-1; x++){
        for (int y = 0; y < data_game-1; y++){
            if (Game[y].genre > Game[y+1].genre){
                game swap = Game[y];
                Game[y] = Game[y+1];
                Game[y+1] = swap;
            }
        }
    }

    cout<< "\nMasukkan Genre Game Yang Ingin Anda Cari" << endl
        << ">> "; fflush(stdin);
        getline(cin, genre);
 
    while(awal <= akhir){
        tengah = (akhir + awal) / 2;
        if(Game[tengah].genre == genre){
            index = tengah + 1;

            int NomorData = 0;
            for (int i = 0; i < data_game; i++){
                if (Game[tengah].genre == Game[i].genre){
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << NomorData + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
                            << "Nama Game        : " << Game[i].nama << endl
                            << "Genre Game       : " << Game[i].genre << endl
                            << "Tahun Rilis Game : " << Game[i].tahun << endl
                            << "Harga Game       : Rp. " << Game[i].harga << endl;
                    NomorData++;
                }
			}
            break;
        }

        else{
            if(genre > Game[tengah].genre){
                awal = tengah + 1;
            }
            else{
                akhir = tengah - 1;
            }
		}
    }

    if ( index == -1){
		cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -DATA TIDAK ADA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}

    return 0;
}

// Fungsi Pencarian Binary Search Tahun
int binary_search_tahun(int data_game, int tahun){

    int awal = 0, akhir = data_game, tengah, index = -1;

    // Pengurutan Data
    for (int x = 0; x < data_game-1; x++){
        for (int y = 0; y < data_game-1; y++){
            if (Game[y].tahun > Game[y+1].tahun){
                game swap = Game[y];
                Game[y] = Game[y+1];
                Game[y+1] = swap;
            }
        }
    }

    // Error Handling Input User
    while(true){
        cout<< "\nMasukkan Tahun Game Yang Ingin Anda Cari" << endl
            << ">> "; cin >> tahun;
        if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }
 
    while(awal <= akhir){
        tengah = (akhir + awal) / 2;
        if(Game[tengah].tahun == tahun){
            index = tengah + 1;

            int NomorData = 0;
            for (int i = 0; i < data_game; i++){
                if (Game[tengah].tahun == Game[i].tahun){
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << NomorData + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
                            << "Nama Game        : " << Game[i].nama << endl
                            << "Genre Game       : " << Game[i].genre << endl
                            << "Tahun Rilis Game : " << Game[i].tahun << endl
                            << "Harga Game       : Rp. " << Game[i].harga << endl;
                    NomorData++;
                }
			}
            break;
        }

        else{
            if(tahun > Game[tengah].tahun){
                awal = tengah + 1;
            }
            else{
                akhir = tengah - 1;
            }
		}
    }

    if ( index == -1){
		cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -DATA TIDAK ADA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}

    return 0;
}

// Fungsi Pencarian Binary Search Harga
int binary_search_harga(int data_game, int harga){

    int awal = 0, akhir = data_game, tengah, index = -1;

    // Pengurutan Data
    for (int x = 0; x < data_game-1; x++){
        for (int y = 0; y < data_game-1; y++){
            if (Game[y].harga > Game[y+1].harga){
                game swap = Game[y];
                Game[y] = Game[y+1];
                Game[y+1] = swap;
            }
        }
    }
    
    // Error Handling Input User
    while(true){
        cout << "\nMasukkan Harga Game Yang Ingin Anda Cari" << endl
             << ">> Rp. "; cin >> harga;
        if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }
 
    while(awal <= akhir){
        tengah = (akhir + awal) / 2;
        if(Game[tengah].harga == harga){
            index = tengah + 1;

            int NomorData = 0;
            for (int i = 0; i < data_game; i++){
                if (Game[tengah].harga == Game[i].harga){
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>    | " << NomorData + 1 << " |   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl 
                            << "Nama Game        : " << Game[i].nama << endl
                            << "Genre Game       : " << Game[i].genre << endl
                            << "Tahun Rilis Game : " << Game[i].tahun << endl
                            << "Harga Game       : Rp. " << Game[i].harga << endl;
                    NomorData++;
                }
			}
            break;
        }

        else{
            if(harga > Game[tengah].harga){
                awal = tengah + 1;
            }
            else{
                akhir = tengah - 1;
            }
		}
    }

    if ( index == -1){
		cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -DATA TIDAK ADA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	}

    return 0;
}

// Prosedur Pengurutan Metode Bubble Sort
void bubble_sort(){
    game swap;
    int nomor, urut, x, y;
    cout << "\n================================================" << endl
         << "|------------Jenis Pengurutan Data-------------|" << endl
         << "================================================" << endl
         << "\n>>> -----------Menu----------- <<<" << endl
         << "1) Ascending  (Kecil ke Besar)" << endl
         << "2) Descending (Besar ke Kecil)" << endl;
    
    // Error Handling Input User
    while(true){
        cout << "\nMasukkan Nomor Menu : "; cin >> urut;
        if(cin.fail()){
            cin.clear();
            cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
            cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }
	
	// Bubble Sort Secara Ascending
    if (urut == 1){

        system("cls");
        cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
        
        // Panggil Prosedur Tampilan Bubble Sort
        tampilan_pengurutan_bubble();

        // Error Handling Input User
        while(true){
            cout << "\nMasukkan Nomor Menu : "; cin >> nomor;
            if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }

        // Sorting Nama
        if (nomor == 1){
            for (int x = 0; x < data_game-1; x++){
                    for (int y = 0; y < data_game-1; y++){
                    if (Game[y].nama > Game[y+1].nama){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Genre
        else if (nomor == 2){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].genre > Game[y+1].genre){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Tahun
        else if (nomor == 3){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].tahun > Game[y+1].tahun){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Harga
        else if (nomor == 4){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].harga > Game[y+1].harga){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        else{
            cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
        }

    }

	// Bubble Sort Secara Descending
    else if(urut == 2){

        system("cls");
        cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
        
        // Panggil Prosedur Tampilan Bubble Sort
        tampilan_pengurutan_bubble();

        // Error Handling Input User
        while(true){
            cout << "\nMasukkan Nomor Menu : "; cin >> nomor;
            if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }

        // Sorting Nama
        if (nomor == 1){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].nama < Game[y+1].nama){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Genre
        else if (nomor == 2){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].genre < Game[y+1].genre){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Tahun
        else if (nomor == 3){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].tahun < Game[y+1].tahun){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        // Sorting Harga
        else if (nomor == 4){
            for (int x = 0; x < data_game-1; x++){
                for (int y = 0; y < data_game-1; y++){
                    if (Game[y].harga < Game[y+1].harga){
                        swap = Game[y];
                        Game[y] = Game[y+1];
                        Game[y+1] = swap;
                    }
                }
            }

            cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
        }

        else{
            cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
        }
        
    }

    else{
        cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
    }
    
}

// Prosedur Pengurutan Metode Shell Sort
void shell_sort(){
	game temporary;
	int nilai, nomor, urut,  x, y;
	cout << "\n================================================" << endl
         << "|------------Jenis Pengurutan Data-------------|" << endl
         << "================================================" << endl
         << "\n>>> -----------Menu----------- <<<" << endl
         << "1) Ascending  (Kecil ke Besar)" << endl
         << "2) Descending (Besar ke Kecil)" << endl;
    
    // Error Handling Input User
    while(true){
        cout << "\nMasukkan Nomor Menu : "; cin >> urut;
        if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else{
            break;
        }
    }

	// Shell Sort Secara Ascending
	if (urut == 1){

		system("cls");
        cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
		
        // Panggil Prosedur Tampilan Shell Sort
        tampilan_pengurutan_shellsort();

        // Error Handling Input User
        while(true){
		    cout << "\nMasukkan Nomor Menu : "; cin >> nomor;
            if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }

        // Sorting Nama
		if (nomor == 1){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].nama > temporary.nama; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Genre
		else if (nomor == 2){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].genre > temporary.genre; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Tahun
		else if (nomor == 3){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].tahun > temporary.tahun; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Harga
		else if (nomor == 4){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].harga > temporary.harga; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

		else{
			cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
		}
	}

	// Shell Sort Secara Descending
	else if (urut == 2){

		system("cls");
        cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
		
        // Panggil Prosedur Tampilan Shell Sort
        tampilan_pengurutan_shellsort();

        // Error Handling Input User
        while(true){
		    cout << "\nMasukkan Nomor Menu : "; cin >> nomor;
            if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }

        // Sorting Nama
		if (nomor == 1){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].nama < temporary.nama; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Genre
		else if (nomor == 2){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].genre < temporary.genre; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

        // Sorting Tahun
		else if (nomor == 3){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].tahun < temporary.tahun; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<]<<<" << endl;

            lihat_data();
		}

        // Sorting Harga
		else if (nomor == 4){
			for (int gap = data_game/2; gap > 0; gap /= 2) {
				for (int x = gap; x < data_game; x += 1){
					temporary = Game[x];
					for (y = x; y >= gap && Game[y - gap].harga < temporary.harga; y -= gap){
						Game[y] = Game[y - gap];
					}
					Game[y] = temporary;
				}
			}

			cout << "\n>>>>> DATA TELAH DIURUT <<<<<" << endl;

            lihat_data();
		}

		else{
			cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
		}
	}

	else{
			cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl;
	}

}

// Prosedur Tampilan Ketika Keluar Dari Program
void keluar(){
	system("cls");
	cout << "========================================================================" << endl;
    cout << "|                            KELUAR PROGRAM                            |" << endl;
    cout << "========================================================================" << endl;
    cout << "| Info: Terima kasih telah menggunakan program dari Awan <3            |" << endl;
    cout << "========================================================================" << endl;
    exit(0);
}

// Program Utama
int main(){

    bool akhiri;
    string ulang;

    // Perulangan While
    while(akhiri == false){

        system("cls");

        openfile();

        tampilan_menu();
        int pilih;

        // Error Handling Input User
        while(true){
            cout << "\nMasukkan Nomor Menu : "; cin >> pilih;
            if(cin.fail()){
                cin.clear();
                cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;

                // Menetapkan jumlah maksimum untuk diabaikan
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else{
                break;
            }
        }
        
        // Percabangan Switch
        switch(pilih){
            
            // Kondisi Menambahkan Data
            case 1:
                system("cls");
                cout << "<<==========================|Menu Tambah Data|==================================>>" << endl;
                
                // Panggil Prosedur Tambah data
                tambah_data();

                cout << "\n>>>> DATA TELAH DITAMBAH <<<<" << endl;
                break;
            
            // Kondisi Melihat Data
            case 2:
                system("cls");
                cout << "<<==========================|Menu Lihat Data|===================================>>" << endl;
                if (data_game == 0){

                    // Panggil Prosedur Pindah Data
                    pindah_data();
                }
                if(data_game > 0){

                    // Reset Data
                    data_game = 0;
                    pindah_data();

                    // Panggil Prosedur Lihat Data
                    lihat_data();
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;
            
            // Kondisi Mengubah Data
            case 3:
                system("cls");
                cout << "<<===========================|Menu Ubah Data|===================================>>" << endl;
                if (data_game == 0){

                    // Panggil Prosedur Pindah Data
                    pindah_data();
                }
                if(data_game > 0){

                    // Reset Data
                    data_game = 0;
                    pindah_data();

                    // Panggil Prosedur Lihat Data
                    lihat_data();

                    // Panggil Prosedur Ubah Data
                    ubah_data();

                    // Panggil Prosedur Update File
                    updatefile();

                    cout << "\n>>>>> DATA TELAH DIUBAH <<<<<" << endl;
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;
            
            // Kondisi Menghapus Data
            case 4:
                system("cls");
                cout << "<<===========================|Menu Hapus Data|==================================>>" << endl;
                if (data_game == 0){

                    // Panggil Prosedur Pindah Data
                    pindah_data();
                }
                if(data_game > 0){

                    // Reset Data
                    data_game = 0;
                    pindah_data();

                    // Panggil Prosedur Lihat Data
                    lihat_data();

                    // Panggil Prosedur Hapus Data
                    hapus_data();

                    // Panggil Prosedur Update File
                    updatefile();

                    cout << "\n>>>> DATA TELAH DIHAPUS <<<<" << endl;
                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;
            
			// Kondisi Mengurutkan Data Metode Bubble Sort
            case 5:
                system("cls");
                cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
                if (data_game == 0){

                    // Panggil Prosedur Pindah Data
                    pindah_data();
                }

                if(data_game > 0){

                    // Panggila Prosedur Bubble Sort
                    bubble_sort();

                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;
			
			// Kondisi Mengurutkan Data Metode Shell Sort
			case 6:
				system("cls");
                cout << "<<===========================|Menu Urut Data|===================================>>" << endl;
                if (data_game == 0){

                    // Panggil Prosedur Pindah Data
                    pindah_data();
                }

                if(data_game > 0){
                    
                    // Panggil Prosedur Shell Sort
                    shell_sort();

                }
                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
				break;


            case 7:
                system("cls");
                cout << "<<===========================|Menu Cari Data|===================================>>" << endl;
                if (data_game == 0){

                    // Panggil Prosedur Pindah Data
                    pindah_data();
                }

                if(data_game > 0){
                    
                    int nomor;

                    // Panggil Prosedur Tampilan Linear Search
                    tampilan_pencarian_linearsearch();

                    // Error Handling Input User
                    while(true){
                        cout << "\nMasukkan Nomor Menu : "; cin >> nomor;
                        if(cin.fail()){
                            cin.clear();
                            cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                            cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else{
                            break;
                        }
                    }

                    if(nomor == 1){
                    
                        // Panggil Fungsi Linear Search Nama
                        linear_search_nama(data_game, cari_nama);
                    }

                    else if(nomor == 2){

                        // Panggil Fungsi Linear Search Genre
                        linear_search_genre(data_game, cari_genre);
                    }

                    else if(nomor == 3){

                        // Panggil Fungsi Linear Search Tahun
                        linear_search_tahun(data_game, cari_tahun);
                    }

                    else if(nomor == 4){

                        // Panggil Fungsi Linear Search Harga
                        linear_search_harga(data_game, cari_harga);
                    }

                    else{
                        cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl;
                    }
                }

                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;

            case 8:

                system("cls");
                cout << "<<===========================|Menu Cari Data|===================================>>" << endl;
                if (data_game == 0){

                    // Panggil Prosedur Pindah Data
                    pindah_data();
                }

                if(data_game > 0){
                    
                    int nomor;

                    // Panggil Prosedur Tampilan Binary Search
                    tampilan_pencarian_binarysearch();

                    // Error Handling Input User
                    while(true){
                        cout << "\nMasukkan Nomor Menu : "; cin >> nomor;
                        if(cin.fail()){
                            cin.clear();
                            cout << "\n>>>> DATA YANG DIMASUKKAN SALAH <<<<" << endl;
                            cout << "---- Masukkan Angka Bukan Huruf ----\n" << endl;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else{
                            break;
                        }
                    }

                    if(nomor == 1){
                    
                        // Panggil Fungsi Binary Search Nama
                        binary_search_nama(data_game, nama);

                    }

                    else if(nomor == 2){

                        // Panggil Fungsi Binary Search Genre
                        binary_search_genre(data_game, genre);

                    }

                    else if(nomor == 3){

                        // Panggil Fungsi Binary Search Tahun
                        binary_search_tahun(data_game, tahun);

                    }

                    else if(nomor == 4){

                        // Panggil Fungsi Binary Search Harga
                        binary_search_harga(data_game, harga);

                    }

                    else{
                        cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl;
                    }
                }

                else{
                    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>> -TIDAK ADA DATA- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
                }
                break;

            // Kondisi Untuk Menghapus File Eksternal
            case 9:

                // Panggil Prosedur Hapus File Eksternal
                remove("2109106002_ALIF MAULANA SETYAWAN_APL_Posttest7_Data.txt");

                cout << "\n>>>>> FILE TELAH DIHAPUS <<<<<" << endl;

                break;

            // Kondisi Untuk Keluar Program
            case 0:

                // Panggil Prosedur Keluar
                keluar();
            
            // Kondisi Default
            default:
                cout << "\n>>>> Menu Tidak Tersedia <<<<" << endl; 
        }
        
        // Konfirmasi Kembali ke Menu Utama
        cout << "\nIngin Kembali Ke Menu Utama ?? (y/t) >> "; cin >> ulang;
        cout << endl;

        // Kondisi Penentu Nilai While
        if (ulang == "y" || ulang == "Y"){
            akhiri = false;
        }
        else if (ulang == "t" || ulang == "T"){
            akhiri = true;
        }
        else{
            akhiri = true;
        }
    }

    // Panggil Prosedur Keluar
    keluar();

    return 0;
}