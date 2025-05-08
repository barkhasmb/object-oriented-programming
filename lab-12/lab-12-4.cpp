#include <iostream>
#include <vector>
using namespace std;

inline void hr() {
    cout << "-------------------------------------------------------" << endl;
}

inline void lb() {
    cout << endl;
}

class Account {
    protected:
        float balance, totalDeposit, totalWithdraw;
    public:
        virtual void deposit(float n) = 0;
        virtual void withdraw(float n) = 0;
        virtual void getBalance() = 0;
        virtual void printInfo() = 0;
};

class SavingsAccount: public Account {
    float interest;
    public:
        SavingsAccount(float balance = 0) {
            this -> balance = balance;
            totalDeposit = 0;
            totalWithdraw = 0;
            interest = 0.1;
        }
        void deposit(float n) override {
            balance += n;
            totalDeposit += n;
        }
        void withdraw(float n) override {
            cout << "Can't withdraw from SavingsAccount." << endl;
        }
        void getBalance() override {
            cout << "SavingsAccount balance: " << balance << endl;
        }
        void printInfo() override {
            balance += balance * interest; 

            hr();
            cout << "SavingsAccount:" << endl;
            cout << "    totalDeposit - " << totalDeposit << endl;
            cout << "    totalWithdraw - " << totalWithdraw << endl;
            cout << "    balance - " << balance << endl;
            hr();
        }
};

class DebitAccount: public Account {
    float fee;
    public:
        DebitAccount(float balance = 0) {
            this -> balance = balance;
            totalDeposit = 0;
            totalWithdraw = 0;
            fee = 20000;
        }
        void deposit(float n) override {
            balance += n;
            totalDeposit += n;
        }
        void withdraw(float n) override {
            balance -= n;
            totalWithdraw += n;
        }
        void getBalance() override {
            cout << "DebitAccount balance: " << balance << endl;
        }
        void printInfo() override {
            balance -= fee; 
            
            hr();
            cout << "DebitAccount:" << endl;
            cout << "    totalDeposit - " << totalDeposit << endl;
            cout << "    totalWithdraw - " << totalWithdraw << endl;
            cout << "    balance - " << balance << endl;
            hr();
        }
};

int main() {
    Account* acc1 = new SavingsAccount;
    Account* acc2 = new DebitAccount;

    acc1 -> deposit(100000);
    acc1 -> deposit(150000);
    acc1 -> withdraw(40000);
    acc1 -> getBalance();

    acc2 -> deposit(50000);
    acc2 -> deposit(40000);
    acc2 -> withdraw(30000);
    acc2 -> getBalance();

    acc1 -> printInfo();
    acc2 -> printInfo();
    return 0;
}