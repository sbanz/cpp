#include<iostream>
#include<string>
using namespace std;

struct mahasiswa
{
    string nama;
    int nim;
    int nilai;
};

void output(mahasiswa mhs[1])
{
	int i=0;
	for(i;i<1;i++){
		cout<<"Nama : "<<mhs[i].nama<<endl;
		cout<<"Nim : "<<mhs[i].nim<<endl;
		cout<<"Nilai : "<<mhs[i].nilai<<endl;
		cout<<endl;
	}
}

void input(mahasiswa mhs[1])
{
	int i=0;
	for(i;i<1;i++){
		cout<<"Nama : ";
		cin>>mhs[i].nama;
		cout<<"Nim : ";
		cin>>mhs[i].nim;
		cout<<"Nilai : ";
		cin>>mhs[i].nilai;
	}
}
int main()
{
	mahasiswa mhs[1];
	input(mhs);
	output(mhs);
	return 0;
}
