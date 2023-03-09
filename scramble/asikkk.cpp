#include<iostream>
#include<string>
using namespace std;

typedef struct{
	float hp;
	int rpm;
}mesin;

struct mobil{
	string model;
	int tempat_duduk;
	mesin mesin;
};

void outputmobil(struct mobil mobill){

	cout<<"Model : "<<mobill.model<<endl
		<<"Jumlah Seat : "<<mobill.tempat_duduk<<endl
		<<"Power : "<<mobill.mesin.hp<<endl
		<<"RPM : "<<mobill.mesin.rpm<<endl;
}

struct mobil inputmobil(){
	struct mobil mobill;
	mobill = *mobill;
	cout<<"Masukkan Spesifikasi Mobil\n";
	cout<<"Model : ";
	cin>>mobill.model;
	cout<<"Jumlah Seat : ";
	cin>>mobill.tempat_duduk;
	cout<<"Power : ";
	cin>>mobill.mesin.hp;
	cout<<"RPM : ";
	cin>>mobill.mesin.rpm;
	return mobill;
}

int main(){
	//Declare array of struct
	struct mobil garasi[10];
	
	struct mobil mobill = inputmobil();
	
	garasi[0] = mobill;
	
	cout<<"SPEC\n";
	outputmobil(garasi[0]);
	
	
	//struct mobil mx5;
	//mesin mazda;
	//mazda.hp = 191.2;
	//mazda.rpm = 7000;
	//mx5.model = "Mazda Mx5";
	//mx5.tempat_duduk = 2;
	//mx5.mesin = mazda;
	
	//cout<<"Mx5 \n"
		//<<"Model : "<<mx5.model<<endl
		//<<"Jumlah Tempat : "<<mx5.tempat_duduk<<endl
		//<<"Mesin Mx5 \n"
		//<<"HorsePower : "<<mx5.mesin.hp<<endl
		//<<"RPM : "<<mx5.mesin.rpm<<endl;
}
