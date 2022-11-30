

//SIMPLE ELECTRICITY BILLING SYSTEM

#include <iostream>
#include <conio.h>
using namespace std;

int i = 0;
int price_per_unit = 10;

struct Customer{
	int id;
	string name;
	string address;
	int house_no;
	string month;
	float consume;
	
}c[35];



//adding the customer info from s array 
void add(){
	//initialization of values
	char name[50];
	char addr[50];
	int house_num;
	int cons;	
	
	//clearing the screen
	system("Cls");
	cout<<"\n\n\t\t\t *** ADD CUSTOMER ***";
	cin.ignore();
	cout<<"\n\n Enter Customer Name: ";
	cin.getline(name, 50);
	
	//adding into the s object to name variable
	c[i].name = name;
	cout<<"\n\n Enter Address: ";
	cin.getline(addr, 50);
	c[i].address = addr;
	
	cout<<"\n\n Enter Customer Id: ";
	cin>>c[i].id;
	
	cout<<"\n\n Enter House number: ";
	cin>>c[i].house_no;
	
	cout<<"\n\n Enter Month of billing: ";
	cin>>c[i].month;

	cout<<"\n\n Enter unit consumed in 1 month: ";
	cin>>cons;
	
	cons = cons * price_per_unit;
	cout<<"\n\n Total amount bill is "<<cons<<".00"<<" for the month of "<<c[i].month<<".";
	c[i].consume = cons;
	
	cout<<"\n\n\tAdded customer Successfully!";
	cout<<"\n\n\tPlease click Enter to continue.";
	i++;
}

void payingBill(){
	system("CLS");
	int id;
	char choice;
	float paid;
	cout<<"\n\n Enter Customer ID: ";
	cin>>id;
	
	for(int x = 0; x < i; x++){
		if(id == c[x].id){
			cout<<"\n\n Do you want to pay "<<c[x].name<<"'s electric bill? [Y/N]: ";
			cin>>choice;
			if(choice == 'y' || choice == 'Y'){
				cout<<"\n\n Enter amount: ";
				cin>>paid;
				if(paid == c[x].consume){
					cout<<"\n\n Available Balance: "<<0.0<<".00";
					c[x].consume = 0.0;
				
				}
				else if(paid < c[x].consume){
					paid = c[x].consume - paid;
					cout<<"\n\n Available Balance: "<< paid<<".00";
					c[x].consume = paid;
				
				}
				else if(paid > c[x].consume){
					cout<<"\n\n Fully paid.";
					c[x].consume = 0.0;
				}
				cout<<"\n\n Please click Enter to continue.";
		   }
		}
	}
	
}

void showBill(){
	system("CLS");
	int id;
	char choice;
	float paid;
	
	
	cout<"\n\n\t\t\t *** SHOW BILL RECORD OF CUSTOMER ***";
	if(i == 0){
		cout<<"\n\n ***No Record Found ***";
		cout<<"\n\n Please click Enter to continue.";
	}
	else{
		cout<<"\n\n Enter Customer ID: ";
		cin>>id;
		for(int x = 0; x < i; x++){
			if(id == c[x].id){
				cout<<"================================================"<<endl;
				cout<<"                Customer                       "<<endl;
				cout<<"================================================"<<endl;
				cout<<"\n\n Customer Name: "<<c[x].name;
				cout<<"\n\n Address: "<<c[x].address;
				cout<<"\n\n House number: "<<c[x].house_no;
				cout<<"\n\n Month of "<<c[x].month;
				cout<<"\n\n Total amount bill: "<<c[x].consume<<".00";
				cout<<"\n\n Please click Enter to continue.";
			}
			
		}
		
	}
}

int main(){
	int choice;
	
	do{
		system("cls");
	cout<<"\n\n\t\t\t *****Electric Billing  System*****";
	cout<<"\n\n 1.  ADD CUSTOMER";
	cout<<"\n\n 2.  PAY BILL OF CUSTOMER";
	cout<<"\n\n 3.  SHOW BILL OF CUSTOMER";
	cout<<"\n\n 4.  EXIT";
	cout<<"\n\n PLEASE ENTER YOUR CHOICE: ";
	//limiting the input into integer only
	while(!(cin>>choice)){
		cout<<"\n Error! Choice must be integer."<<endl;
		cout<<"\n PLEASE ENTER YOUR CHOICE: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	switch(choice){
		case 1:
			//call tthis function if case == 1 
			add();
			break;
		case 2:
			//call tthis function if case == 2
			payingBill();
			break;

		case 3:
			//call this function if case == 3
			showBill();
			break;
		case 4:
			//terminating or exit the program
			cout<<"\n\n\t\t\t *****THANK YOU!*****";
			exit(0);
		default:
			// if choice is not equal to 1 2 3
			cout<<"\n\n ***INVALID CHOICE! ***";
			cout<<"\n\n Please click Enter to continue.";
		}
		getch();
	}while(true);
	

}
