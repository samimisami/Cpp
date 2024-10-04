#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Siralama
{
private:
	int arr1[10000],arr2[10000],length;
public:
	Siralama();
	void setLength();
	Siralama& setArr1(int arr[]);
	Siralama& setArr2(int arr[]);
	int partition(int arr[],int low,int high);
	void quickS(int arr[],int low,int high);
	void merge(int arr[],int l,int m,int r);
	void mergeS(int arr[], int l, int r);
	void display();
};

void main()
{
	ifstream rndm1("siralama_1.txt",ios::out);
	ifstream rndm2("siralama_2.txt",ios::out);
	ofstream sorted1("sorted_1.txt",ios::out);
	ofstream sorted2("sorted_2.txt",ios::out);
	if(!rndm1)
	{
		cerr<<"File is not created. "<<endl;
		exit(1);
	}
	if(!rndm2)
	{
		cerr<<"File is not created. "<<endl;
		exit(1);
	}
	if(!sorted1)
	{
		cerr<<"File is not created. "<<endl;
		exit(1);
	}
	if(!sorted2)
	{
		cerr<<"File is not created. "<<endl;
		exit(1);
	}

	int arr3[10000],arr4[10000];

	for(int i=0;i<=9999;i++)//take numbers from file to int arrays
	{
		rndm1>>arr3[i];
		rndm2>>arr4[i];
	}
	Siralama sirala;
	sirala.setArr1(arr3);
	sirala.setArr2(arr4);

	sirala.quickS(arr3,0,9999);
	sirala.mergeS(arr4,0,9999);
	for(int i=0;i<10000;i++)
	{
		sorted1<<arr3[i]<<" ";
		sorted2<<arr4[i]<<" ";
	}
	sirala.display();

	rndm1.close();
	rndm2.close();
}

Siralama::Siralama()
{
	cout<<"Odevi yapmistim, constructor ile bir sey yapmak sonradan aklima geldi. :((("<<endl<<endl<<endl<<endl;
}
void Siralama::setLength()
{
	length=10000;
}
Siralama& Siralama::setArr1(int arr[10000])//set array1
{
	for(int i=0;i<=9999;i++)
	{
		arr1[i]=arr[i];
	}
	return *this;
}
Siralama& Siralama::setArr2(int arr[10000])//set array2
{
	for(int i=0;i<=9999;i++)
	{
		arr2[i]=arr[i];
	}
	return *this;
}
int Siralama::partition(int arr[],int low,int high) 
{ 
    int pivot=arr[high],temp;
    int i=(low-1);
  
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
        }
    }
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
    return (i + 1);
}
void Siralama::quickS(int arr[],int low,int high)
{

	if(low<high)
	{
		int p= partition(arr,low,high);
		quickS(arr,low,p-1);
		quickS(arr,p+1,high);
	}
}
void Siralama::merge(int arr[],int l,int m,int r)
{
	int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
	int *L=new int[n1];
	int *R=new int[n2];

    for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}
    for (j = 0; j < n2; j++)
	{
		R[j]=arr[m+1+j];
	}
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2)
    { 
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++; 
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void Siralama::mergeS(int arr[], int l, int r)
{
	if(l<r)
    {
        int m=l+(r-l)/2;
        mergeS(arr,l,m);
        mergeS(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
void Siralama::display()
{
	for(int i=0;i<10000;i++)
	{
		cout<<arr1[i]<<" ";
	}
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	for(int i=0;i<10000;i++)
	{
		cout<<arr2[i]<<" ";
	}
}