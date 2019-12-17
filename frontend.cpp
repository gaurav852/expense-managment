#include<iostream>
#include<fstream>
using namespace std;
class record
{
	int quantity;
	float cost;
	char iteam_name[50];
	public:
		void input()
		{
			cout<<"                          ENTER THE ITEAM NAME = ";
			cin>>iteam_name;
			cout<<"                          ENTER NO OF ITEAM PURCHASED = ";
			cin>>quantity;
			cout<<"                          ENTER THE ITEAM COST = ";
			cin>>cost;
		}
		void output()
		{
			cout<<"                          ITEAM NAME = "<<iteam_name<<"\n";
			cout<<"                          ITEAM COST = "<<cost<<"\n";
			cout<<"                          QUANTITY   = "<<quantity<<"\n";
			cout<<"                          TOTAL EXP  = "<<quantity*cost<<"\n";
		}
	
};



void menu()
{
	cout<<endl;
	cout<<endl;
	cout<<"                                     ****** EXPENSE MANAGEMENT SYSTEM *******";
	cout<<endl;
	cout<<endl;
	cout<<"\n";
	cout<<"                 PRESS 1 FOR ADDING EXPENSE\n";
	cout<<"                 PRESS 2 FOR DISPLAYING EXPENSES\n";
	cout<<"                 PRESS 3 FOR EXIT THE SYSTEM\n"; 
	cout<<endl;
	cout<<endl;
		
}

fstream file;
int main() 
{

	record obj;
	cout<<"\n";
	int choice;
	while(1)
	{
		menu();
		cout<<"                 ENTER YOUR CHOICE = ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					obj.input();
					file.open("data",ios::out | ios::app | ios::binary);  
					file.write((char*)&obj, sizeof(obj));
					file.close();
					system("CLS");  
					cout<<"data returned sucessfully\n";
					system("pause");  
					break;
				}
			case 2:
				{
					file.open("data",ios::in | ios::binary);  
					while(file.read((char*) &obj, sizeof(obj)))
					{
						obj.output();
						cout<<endl;
					}
					system("pause");
					break;	
				}
			case 3:
				{
					 exit (0);
				}
		}
	}
	return 0;
}




