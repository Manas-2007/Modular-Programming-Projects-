#ifndef BANK_H
#define BANK_H
#include<string>
class Bank{
    int id,mainpin;
    std::string name,dob,actype,contact,address;
    float balance;
    public:

    //Constructors
    Bank();
    Bank(int id,std::string name,std::string dob,std::string actype,std::string contact,std::string address,float balance);

    //Input  & output info function
    void input();
    void output();

    //Login Function
    int getid();
    bool verifypin(int userpin);
    void login();

    //Deposit/withdraw/Balance Function
    void deposit();
    void withdraw();
    void checkbalance();
};
#endif
 