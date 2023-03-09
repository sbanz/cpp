#include<iostream>
#include<string>
using namespace std;

string currentArray;

int main()
{
	cout<<"Masukkan Kata : ";
	cin>>currentArray;
	MergeSortA(0,5);
	cout<<currentArray;
	return 0;
}

void MergeSortA(int low , int high)
{
    int mid = 0;
    if(low < high)
    {
        mid = ((low+high)/2);
        MergeSortA(low , mid);
        MergeSortA(mid+1,high);
        MergeA(low,mid,high);
    }
}

void MergeA(int low ,int mid , int high)
{
    int i = low, j = mid+1 , k = low;
    string Temp[5];

    while(i <= mid && j <= high)
    {
        if( currentArray[i] < currentArray[j] )
        {
            Temp[k].assign(currentArray[i]);
            i++;
        }
        else
        {
            Temp[k].assign(currentArray[j]);
            j++;
        }
        k++;
    }
    if(i > mid )
    {
        for(int h = j ;h <= high ; h++ )
        {
            Temp[k].assign(currentArray[h]);
            k++;
        }
    }
    else
        for(int h = i; h<= mid ; h++ )
        {
            Temp[k].assign(currentArray[h]);
            k++;
        }
   for(int i = low; i <= high ; i++)
   {
       currentArray[i].assign(Temp[i]);
   }
}


