//include header files
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;


//global variablex
string fname, lname,phNum;

//functions
void addContact();
void searchContact();
void help();
void self_exit();
bool check_digit(string);
bool check_num(string);

int main()
{
	short int choice;
	system("cls");
	system("color 0A");
	cout<<"\n\n\n\n~~~~~~~~~~~~~~~~~~~~ Contact Management!!! ~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n---------------------------------------------------------------";
	cout<<"\n\t\tOPTIONS: ";
	cout<<"\n\n\t1. Add Contact\n\t2. Search Contact\n\t3. Help\n\t4. Exit\n\t>";
	cin>>choice;

	switch (choice)
	{
		case 1:
		addContact();
		break;
		case 2:
		searchContact();
		break;
		case 3:
		help();
		break;
		case 4:
		self_exit();
		break;
		default:
			cout<<"\n\n\tOOps!! Invalid Input";
			cout<<"\n\n\t Press Any Key to continue!...";
			getch();
			main();
	}
	return 0;
}

void self_exit(){
	system("cls");
	cout<<"\n\n\tThank You For Using!!";
	exit(1);
}

void help(){
	cout<<"\n\n\tThis Displays Help!";
}

void addContact(){
	ofstream phone("number.txt", ios::app);
	system("cls");
	cout<<"\n\n\tEnter First Name: ";
	cin>>fname;
	cout<<"\n\tEnter last Name: ";
	cin>>lname;
	cout<<"\n\n\t Enter 10 digits phone Number: ";
	cin>>phNum;

	//check for 10 digits phone number
	if(check_digit(phNum))
	{
		if(check_num(phNum))
		{
			if(phone.is_open())
			{
				phone<<fname<<" "<<lname<<": "<< phNum<<endl;
				cout<<"\n\tContact Saved Successfully!";
			}
			else
			{
				cout<<"\n\t OOPS!! SOmething went wrong!";
			}
		}
		else{
			system("cls");
			cout<<"\n\n\t OOPS! You entered a non Integer value!";
		}
	}
	else
	{
		cout<<"\n\n\t Please Enter  10 DIGITS!!!!.";
		addContact();
	}

	phone.close();
}

//TODO: Search Contact

void searchContact()
{
	system("cls");
	ifstream myfile("number.txt");
	bool found = false;
	string keyword;
	cout<<"\n\t Enter Name To Search: ";
	cin>>keyword;
	while(myfile >> fname>> lname>> phNum)
	{
		if(keyword == fname|| keyword == lname)
		{
			system("cls");
			cout<<"\n\n\n\t Hurray!! Contact Find!!!!";
			cout<<"\n\n\tFirst Name: "<<fname;
			cout<<"\n\tLast Name : "<<lname;
			cout<<"\n\tPhone Number: "<<phNum;
			found = true;
			break;
		}
	}
	if(!found){
		cout<<"\n\n\t OOPS!! No Contact Found!!!";
	}

}

//TODO: Check for 10 digit

bool check_digit(string x)
{
	if(x.length() == 10)
		return true;
	return false;
}

//TODO: CHeck for integer


bool check_num(string x){
	bool check = true;
	//check for each char of string that if it is number or not
	for(int i = 0; i<x.length(); i++)
	{
		if(!(int(x[i]) >= 48 && int(x[i]) <=57))
		{
			check = false;
		}
	}
	return check;
}
