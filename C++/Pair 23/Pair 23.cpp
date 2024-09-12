#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {
        cout << "PaymentMethod destroyed." << endl;
    }
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
    string expirationDate;
    string cardHolderName;
public:
    CreditCard(const string& cardNumber, const string& expirationDate, const string& cardHolderName)
        : cardNumber(cardNumber), expirationDate(expirationDate), cardHolderName(cardHolderName) {}

    void processPayment(double amount) override {
        cout << "Processing credit card payment of " << amount << " for " << cardHolderName << endl;
    }

    ~CreditCard() {
        cout << "CreditCard destroyed." << endl;
    }
};

class PayPal : public PaymentMethod {
private:
    string email;
public:
    PayPal(const string& email) : email(email) {}

    void processPayment(double amount) override {
        cout << "Processing PayPal payment of " << amount << " for " << email << endl;
    }

    ~PayPal() {
        cout << "PayPal destroyed." << endl;
    }
};

class BankTransfer : public PaymentMethod {
private:
    string bankAccountNumber;
    string bankName;
public:
    BankTransfer(const string& bankAccountNumber, const string& bankName)
        : bankAccountNumber(bankAccountNumber), bankName(bankName) {}

    void processPayment(double amount) override {
        cout << "Processing bank transfer of " << amount << " to " << bankAccountNumber << " (" << bankName << ")" << endl;
    }

    ~BankTransfer() {
        cout << "BankTransfer destroyed." << endl;
    }
};

int main() {
    vector<PaymentMethod*> payments;

    payments.push_back(new CreditCard("1234-5678-9012-3456", "12/25", "John Doe"));
    payments.push_back(new PayPal("johndoe@example.com"));
    payments.push_back(new BankTransfer("987654321", "National Bank"));

    payments[0]->processPayment(150.00);
    payments[1]->processPayment(200.50);
    payments[2]->processPayment(300.75);

    for (auto payment : payments) {
        delete payment; 
    }
}
