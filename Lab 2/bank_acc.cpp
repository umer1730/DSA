#include<iostream>
using namespace std;

class BankAccount{
private:
    int account_no;
    int balance;
public:
    public:
    BankAccount(int acc_no,int bal) {
        account_no = acc_no;
        balance = bal;
    }
    void deposit(int amount){
        if(amount > 0){
            balance += amount;
            cout<<"Depsoited: "<<amount<<", New balance: "<<balance<<endl;
        }
        else{
            cout<<"Invalid amount";
        }
    }
    void withdraw(int amount){
        if (amount <=  balance){
            balance -= amount;
            cout<<"Withdrawn: "<<amount<<", Remaining balance: "<<balance<<endl;

        }else{
            cout<<"Invalid balance!Amount is  more then balance...."<<endl;
        }
    }
    
};

int main(){
    BankAccount bank(101,5000);

    
    bank.deposit(2000);
    bank.withdraw(1000);

    return 0;
}