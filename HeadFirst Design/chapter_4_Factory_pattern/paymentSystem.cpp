#include <iostream>
#include <string>
using namespace std;

class PaymentInterface {
public:
    virtual void makePayment() = 0;
    virtual ~PaymentInterface() {
        // We can do memory management here
    }
};

class CreditCardPayment : public PaymentInterface {
public:
    void makePayment() override {
        cout << "Making Credit Card Payment" << "\n";
    }
};

class PaypalPayment : public PaymentInterface {
public:
    void makePayment() override {
        cout << "Making Paypal Payment" << "\n";
    }
};

class BitCoinPayment : public PaymentInterface {
public:
    void makePayment() override {
        cout << "Making BitCoin Payment" << "\n";
    }
};

class PaymentFactory {
public:
    static PaymentInterface* createGateWay(const string& gatewayType) {
        if (gatewayType == "creditcard") {
            return new CreditCardPayment();
        } else if (gatewayType == "paypal") {
            return new PaypalPayment();
        } else if (gatewayType == "bitcoin") {
            return new BitCoinPayment();
        } else {
            return nullptr;
        }
    }
};

int main() {
    PaymentInterface* payment = PaymentFactory::createGateWay("paypal");
    if (payment) {
        payment->makePayment();
        delete payment;
    } else {
        cout << "Invalid Payment" << "\n";
    }
    return 0;
}
