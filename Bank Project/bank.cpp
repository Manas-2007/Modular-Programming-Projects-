#include<iostream>
#include<string>
#include"bank.h"
#include<limits>
using namespace std;

int getNumber(string msg)
{
    int x;
    while(true)
    {
     cout<<msg;
     cin>>x;
        if(cin.fail()) 
        {
          cout<<"Invalid input! Enter numbers only.\n";
           cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        else
        {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
         return x; 
        }
    }
}

//Construtor Declaration
Bank::Bank()
{
    id=0;
    name="N/A";
    dob="N/A";
    address="N/A";
    actype="N/A";
    contact="N/A";
    balance=0.0;
}
Bank::Bank(int id,std::string name,std::string dob,std::string actype,std::string contact,std::string address,float balance)
{
    this->id=id;
    this->name=name;
    this->dob=dob;
    this->address=address;
    this->contact=contact;
    this->actype=actype;
    this->balance=balance;
}

//input & output function
void Bank::input()
{
    id=getNumber("ID: ");

    cout<<"NAME: ";
    getline(cin,name);

    cout<<"ACCOUNT TYPE (Saving/Current): ";
    getline(cin,actype);

    mainpin=getNumber("Set Security PIN: ");

    cout<<"Date of Birth: ";
    getline(cin,dob);

    cout<<"CONTACT NO: ";
    getline(cin,contact);  

    cout<<"ADDRESS: ";
    getline(cin,address);
}


void Bank::output()
{
    cout<<"\n=================================================================================================\n";
    cout<<"                                  ACCOUNT HOLDER INFORMATION                                       \n";
    cout<<"\n=================================================================================================\n";
    cout<<"ID            : "<<id<<"\n";
    cout<<"NAME          : "<<name<<endl;
    cout<<"ACCOUNT       : "<<actype<<endl;
    cout<<"DATE OF BIRTH : "<<dob<<endl;
    cout<<"CONTACT NO.   : "<<contact<<endl;  
    cout<<"ADDRESS       :  "<<address<<endl;
}

//Login Function
int Bank::getid()
{
    return id;
}
bool Bank::verifypin(int userpin)
{
    return userpin==mainpin;
}
void Bank::login()
{
    int userpin;
    while(true)
    {
    userpin = getNumber("Enter Security PIN: ");
        if(userpin == mainpin)
            break;
        cout<<"Invalid PIN! Try again\n";
    }

    cout<<"......LOGIN SUCCESSFUL.......\n";
}

//Deposit Function
void Bank::deposit()
{
    int userdeposit = getNumber("Enter Amount: ");
    if(userdeposit>0)
    {
        balance =balance + userdeposit;
        cout<<"...........Deposit successful............\n";
    }
    else
    {
        cout<<"......Invalid Amount! Try Again........\n";
    }
}

//Withdraw function
void Bank::withdraw()
{
    int userwithdraw;
    cout<<"Enter Amount : ";
    cin>>userwithdraw;
    if(userwithdraw>0 && userwithdraw<=balance)
    {
        balance=balance-userwithdraw;
         cout<<".......................WITHDRAW SUCCESSFUL...........................\n\n";
    }
    else
    {
        cout<<".......INSUFFICIENT ACCOUNT BALANCE.........\n\n";
    }

}

//Balance Check function
void Bank::checkbalance()
{
    cout<<"AVAILABLE BALANCE : "<<balance<<endl;
}

