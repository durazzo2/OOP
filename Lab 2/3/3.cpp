#include <iostream>
#include <cstring>
using namespace std;

// your code here
class BankAccount{
private:
    char accountNumber[100];
    char accountHolder[100];
    int balance;
    float InterestRate;

public:
    BankAccount()
    {

    }
    BankAccount(char *_accountNumber,char *_accountHolder,int _balance,float _InterestRate){
        strcpy(accountNumber,_accountNumber);
        strcpy(accountHolder,_accountHolder);
        InterestRate=_InterestRate;
        balance=_balance;
    }
    ~BankAccount(){
    }
    void setAccountNumber(char *_accountNumber){
        strcpy(accountNumber,_accountNumber);
    }
    void setAccountHolder(char *_accountHolder){
        strcpy(accountHolder,_accountHolder);
    }
    void setBalance(int _balance){
        balance=_balance;
    }
    void setInterestRate(float _InterestRate){
        InterestRate=_InterestRate;
    }

    char *getAccountNumber(){
        return accountNumber;
    }
    char *getAccountHolder(){
        return accountHolder;
    }
    int getBalance(){
        return balance;
    }
    float getInterestRate(){
        return InterestRate;
    }

    void display(){
        cout<<"Account number: "<<accountNumber<<endl;
        cout<<"Account holder: "<<accountHolder<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    void deposit(int amount){
        balance += amount;
    }
    void withdraw(int amount){
        balance -= amount;
    }
};

void printBestAccount(BankAccount *bankAccounts,int n){
    int i,j,max=0,I;
    for(i=0;i<n;i++){
        if(bankAccounts[i].getBalance()>max){
            max=bankAccounts[i].getBalance();
            I=i;
        }
    }
    bankAccounts[I].display();
}

// DO NOT CHANGE THE MAIN FUNCTION
int main() {
    int n;
    cin >> n;
    BankAccount bankAccounts[100];

    char accountNumber[100];
    double interestRate;
    int balance;
    char accountHolder[100];

    for (int i = 0; i < n; i++)  {
        cin >> accountNumber;
        cin >> accountHolder;
        cin >> balance;
        cin >> interestRate;

        // testing set methods
        bankAccounts[i].setAccountNumber(accountNumber);
        bankAccounts[i].setAccountHolder(accountHolder);
        bankAccounts[i].setBalance(balance);
        bankAccounts[i].setInterestRate(interestRate);
    }

    // testing constructor with arguments
    cin >> accountNumber;
    cin >> accountHolder;
    cin >> balance;
    cin >> interestRate;
    bankAccounts[n] = BankAccount(accountNumber, accountHolder, balance, interestRate);

    // testing withdraw and deposit functions
    bankAccounts[0].deposit(1000);
    bankAccounts[0].withdraw(50);

    // testing printBestAccount function
    printBestAccount(bankAccounts, n + 1);

    return 0;
}