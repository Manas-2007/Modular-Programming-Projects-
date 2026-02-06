#include<iostream>
#include"bank.h"
#include<string>
#include<cstdlib>
#include<limits>
using namespace std;

void header()
{
  cout<<"********************************************************************************************************\n";
  cout<<"                                 WELCOME TO BANK MANAGEMENT SYSTEM                                      \n";
  cout<<"*******************************************************************************************************\n\n";
}

// Clears screen + shows header again
void clearscreen()
{
    system("cls");  
    header();
}

void pauseAndClear()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    clearscreen();
}

int main()
{
    clearscreen();

    int serviceno, size, idx = -1;
    cout<<"TOTAL NUMBER OF ACCOUNT HOLDERS: ";
    cin>>size;

    Bank *b = new Bank[size];

    do{
        cout<<"Available Banking Services: \n";
        cout<<"1) Registration\n";
        cout<<"2) Login Account\n";
        cout<<"3) Account Holder Information\n";
        cout<<"4) Deposit Balance\n";
        cout<<"5) Withdraw Balance\n";
        cout<<"6) Check Available Balance\n";
        cout<<"7) Exit\n\n";
        cout<<"Select Your Service Number(1-7): ";
        cin>>serviceno;

        clearscreen(); 

  switch(serviceno)
    {
     case 1:
       cout<<"\n                                  WELCOME TO REGISTRATION SERVICE                  \n";
       for(int i=0;i<size;i++)
           {
             cout<<"\nACCOUNT HOLDER: "<<i+1<<endl;
             b[i].input();
             cout<<"\n.........Congratulations! You account has been successfully created...........\n\n";
           }

           pauseAndClear();
           break;

     case 2:
           {
             cout<<"                                   LOGIN YOUR ACCOUNT                            \n";
             int userpin,userid;
            cout<<"Enter User ID :";
            cin>>userid;
            cout<<"Enter User PIN :";
             cin>>userpin;
            idx=-1;

           for(int i=0;i<size;i++)
             {
               if(b[i].getid()==userid  &&  b[i].verifypin(userpin))
                 {
                   idx=i;
                   break;
                 }
            }

               if(idx!=-1)
                {
                    cout<<"\n........LOGIN SUCCESSFUL.............\n";
                }
                else
                {
                    cout<<"\n.......ACCOUNT NOT FOUND!.......\n\n";
                }
                pauseAndClear();
                break;
          }

            case 3:
                if(idx==-1)
                {
                    cout<<"\n===============FIRST LOGIN YOUR ACCOUNT===================\n\n";
                    pauseAndClear();
                    break;
                }
                b[idx].login();
                clearscreen();      
                b[idx].output();
                pauseAndClear();
                break;

            case 4:
                if(idx==-1)
                {
                    cout<<"\n===============FIRST LOGIN YOUR ACCOUNT===================\n\n";
                    pauseAndClear();
                    break;
                }
                cout<<"                                 DEPOSIT AMOUNT SERVICE   \n";
                b[idx].login();
                clearscreen();     
                b[idx].deposit();
                pauseAndClear();
                break;

        case 5:
                if(idx==-1)
                {
                    cout<<"\n===============FIRST LOGIN YOUR ACCOUNT===================\n\n";
                    pauseAndClear();
                    break;
                }
                cout<<"                                 WITHDRAW AMOUNT SERVICE      \n";
                b[idx].login();
                clearscreen();     
                b[idx].withdraw();
                pauseAndClear();
                break;

       case 6:
         if(idx==-1)
             {
                cout<<"\n===============FIRST LOGIN YOUR ACCOUNT===================\n\n";
                pauseAndClear();
               break;
             }
              cout<<"                                  AVAILABLE BALANCE SERVICE          \n";
               b[idx].login();
               clearscreen();     
               b[idx].checkbalance();
               pauseAndClear();
               break;

         case 7:
          cout<<"\n................THANKYOU FOR USING BANK MANAGEMENT SYSTEM...........................\n";
          delete [] b;
           exit(0);
           break;

        default:
         cout<<"\nInvalid Service Number\n";
         pauseAndClear();
        }

        cout<<"\n\n";
    } while(serviceno!=7);

    return 0;
}
