#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Hastane
{
private:
	string TC,isim,soyisim,birth,insurance;
	double total;
public:
	Hastane& findAndSet(string);
	Hastane& setTotal(double);
	string getTC()const;
	double calculateBalance();
	void changeTC(string);
	void changeInsurance(string);
};

void main()
{	
	Hastane h;
	string str="";
	string tclookingfor;
	string TC,isim,soyisim,birth,insurance;
	int operation=0,totam;

	ifstream ready("test.txt",ios::out);
	if(!ready)
	{
		cerr<<"File is not created. "<<endl;
		exit(1);
	}
	ofstream changy("temp.txt");
	if(!changy)
	{
		cerr<<"File is not created. "<<endl;
		exit(1);
	}

	cout<<"Press 1 for show balance."<<endl<<"Press 2 for change TC."<<endl<<"Press 3 for change insurance type."<<endl;
	cin>>operation;

	if(operation==1)
	{
		cout<<"Enter the TC: ";
		cin>>tclookingfor;
		while(!ready.eof())
		{
			getline(ready,str);
			if(tclookingfor==str.substr(0,11))
			{
				cout<<"Looking TC Found!"<<endl;
				cout<<str<<endl;
				h.findAndSet(str);//ki�inin bilgilerini classa aktar�yorum
				h.getTC();
			}
		}
		cout<<"Enter the total amount: ";
		cin>>totam;
		h.setTotal(totam);
		cout<<"You need to pay "<<h.calculateBalance()<<"TL"<<endl;
	}
	if(operation==2)
	{
		string newTC,check,change;
		cout<<"You should look temp.txt at the folder.\nEnter the TC you want to change: ";
		cin>>tclookingfor;
		while(getline(ready,check))
		{
			if(check.substr(0,11)==tclookingfor)
			{
				cout<<"Looking TC Found!"<<endl;
				cout<<"Enter the new TC to replace old one: ";
				cin>>newTC;
				change=check.substr(11,check.length()-11);
				check=newTC+change;
			}
		cout<<check;
		check+="\n";
        changy<<check;
		}
	}
	if(operation==3)
	{
		string newInsurance,check,change;
		cout<<"You should look temp.txt at the folder.\nEnter the TC you want to change: ";
		cin>>tclookingfor;
		while(getline(ready,check))
		{
			int pos[4],place=0;
			for(int i=0;i<check.length();i++)//bosluklar� buldum
			{
				if(check[i]==' ')
				{
					pos[place]=i;
					place++;
				}
			}
			if(check.substr(0,11)==tclookingfor)
			{
				cout<<"Looking TC Found!"<<endl;
				cout<<"Enter the new Insurance to replace old one: ";
				cin>>newInsurance;
				change=check.substr(0,pos[3]+1);
				check=change+newInsurance;
			}
		cout<<check;
		check+="\n";
        changy<<check;
		}
	}
	ready.close();
}

Hastane& Hastane::findAndSet(string str)
{
	int pos[4],place=0;
	for(int i=0;i<str.length();i++)//bosluklar� buldum
	{
		if(str[i]==' ')
		{
			pos[place]=i;
			place++;
		}
	}
	TC=str.substr(0,pos[0]);
	isim=str.substr(pos[0]+1,pos[1]-pos[0]-1);
	soyisim=str.substr(pos[1]+1,pos[2]-pos[1]-1);
	birth=str.substr(pos[2]+1,pos[3]-pos[2]-1);
	insurance=str.substr(pos[3]+1);
	cout<<TC<<" "<<isim<<" "<<soyisim<<" "<<birth<<" "<<insurance<<endl;//kontrol ediyorum olmu� mu diye
	return *this;
}
Hastane& Hastane::setTotal(double tutar)
{
	total=tutar;
	return *this;
}
string Hastane::getTC()const
{
	return TC;
}
double Hastane::calculateBalance()
{
	if(insurance=="SGK")
	{
		cout<<"Found1!"<<endl;
		return total*0.1;
	}
	if(insurance=="sigA")
	{
		cout<<"Found2!"<<endl;
		return total*0.2;
	}
	if(insurance=="sigB")
	{
		cout<<"Found3!"<<endl;
		return total*0.4;
	}
}
void Hastane::changeTC(string newTC)
{
	TC=newTC;
}
void Hastane::changeInsurance(string newInsurance)
{
	insurance=newInsurance;
}