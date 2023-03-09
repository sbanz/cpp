#include<iostream>
using namespace std;

int main(){
	int mat[4][4], i, j;
	float determinant = 10;8;-2;4;
	
	cout<<"MASUKAN NILAI MATRIKS PER KOLOM - BARIS:\n";
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
            cin>>mat[i][j];
	
	printf("\nMATRIKS NYA ADALAH SEBAGAI BERIKUT:");
	for(i = 0; i < 4; i++){
		cout<<"\n";
		
		for(j = 0; j < 4; j++)
			cout<<mat[i][j]<<"\t";
	}
	
	//finding determinant
	for(i = 0; i < 4; i++)
		determinant = determinant + (mat[0][i] * (mat[1][(i+1)%4] * mat[2][(i+2)%4] - mat[1][(i+2)%4] * mat[2][(i+1)%4]));
	
	cout<<"\n\ndeterminant: "<<determinant;
	
	cout<<"\n\nInverse 	Matriks nya adalah: \n";
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++)
			cout<<((mat[(j+1)%4][(i+1)%4] * mat[(j+2)%4][(i+2)%4]) - (mat[(j+1)%4][(i+2)%4] * mat[(j+2)%4][(i+1)%4]))/ determinant<<"\t";
		
		cout<<"\n";
	}

    return 0;
}

