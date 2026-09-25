#include <iostream>
// Includes the iostream library.
// It is used for input and output operations such as cout.

#include <memory>
// Includes the memory library.
// It provides smart pointers such as unique_ptr
// and the make_unique() function.

#include <string>
// Includes the string library.
// It allows us to use the string data type.

#include <vector>
// Includes the vector library.
// It allows us to store multiple payment objects
// in a single collection.

using namespace std;
// Allows us to use cout, string, vector, etc.
// without writing std:: before them.


// ====================================================
// BASE CLASS: PAYMENT METHOD
// ====================================================

class PaymentMethod
{
// Defines a base class named PaymentMethod.
// This class represents a general payment method.

protected:
// Protected members can be accessed inside this class
// and inside classes derived from this class.

    string transactionId;
    // Stores the unique transaction ID.

    double amount;
    // Stores the payment amount.
    // double is used because the amount may contain decimals.


public:
// Starts the public section.


    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt)
    {
    }
    // Constructor of PaymentMethod.
    //
    // tid -> transaction ID
    // amt -> payment amount
    //
    // transactionId(tid) initializes transactionId.
    // amount(amt) initializes amount.
    //
    // The part after ':' is called the
    // member initializer list.


    virtual bool processPayment() const = 0;
    // Pure virtual function.
    //
    // virtual allows derived classes to provide
    // their own implementation.
    //
    // bool means the function returns true or false.
    //
    // const means the function will not modify
    // the object.
    //
    // = 0 makes this a pure virtual function.
    //
    // Therefore, PaymentMethod becomes an abstract class.
    // We cannot directly create a PaymentMethod object.


    virtual ~PaymentMethod() = default;
    // Virtual destructor.
    //
    // It ensures that derived objects are properly
    // destroyed when accessed through a base-class pointer.
    //
    // = default asks C++ to create the default destructor.
};



// ====================================================
// CREDIT CARD PAYMENT CLASS
// ====================================================

class CreditCardPayment : public PaymentMethod
{
// Defines CreditCardPayment.
//
// It publicly inherits from PaymentMethod.
//
// CreditCardPayment is a derived class.


private:
// Private data of CreditCardPayment.

    string maskedCardNumber;
    // Stores a masked credit card number.
    // Example: XXXX-XXXX-1234.


public:
// Starts the public section.


    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt), maskedCardNumber(card)
    {
    }
    // Constructor of CreditCardPayment.
    //
    // PaymentMethod(tid, amt)
    // calls the constructor of the base class.
    //
    // maskedCardNumber(card)
    // initializes the card number.


    bool processPayment() const override
    {
        // Overrides the pure virtual function
        // from the PaymentMethod class.
        //
        // override tells the compiler that this function
        // is replacing the inherited virtual function.


        cout << "Credit-card transaction " << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;
        // Displays the credit card payment details.


        return true;
        // Returns true to indicate that
        // the payment was successfully processed.
    }
};



// ====================================================
// UPI PAYMENT CLASS
// ====================================================

class UPIPayment : public PaymentMethod
{
// Defines the UPIPayment class.
//
// It inherits from PaymentMethod.


private:
// Private data of UPIPayment.

    string upiId;
    // Stores the UPI ID.
    // Example: student@upi.


public:
// Starts the public section.


    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi)
    {
    }
    // Constructor of UPIPayment.
    //
    // PaymentMethod(tid, amt)
    // initializes the inherited data.
    //
    // upiId(upi)
    // initializes the UPI ID.


    bool processPayment() const override
    {
        // Overrides processPayment()
        // from the PaymentMethod class.


        cout << "UPI transaction " << transactionId
             << " for Rs. " << amount
             << " from " << upiId
             << " completed." << endl;
        // Displays the UPI transaction details.


        return true;
        // Returns true to indicate
        // successful payment.
    }
};



// ====================================================
// NET BANKING PAYMENT CLASS
// ====================================================

class NetBankingPayment : public PaymentMethod
{
// Defines the NetBankingPayment class.
//
// It inherits from PaymentMethod.


private:
// Private data of NetBankingPayment.

    string bankName;
    // Stores the name of the bank.


public:
// Starts the public section.


    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt), bankName(bank)
    {
    }
    // Constructor of NetBankingPayment.
    //
    // PaymentMethod(tid, amt)
    // initializes the inherited data.
    //
    // bankName(bank)
    // initializes the bank name.


    bool processPayment() const override
    {
        // Overrides processPayment()
        // from the PaymentMethod class.


        cout << "Net-banking transaction " << transactionId
             << " for Rs. " << amount
             << " through " << bankName
             << " completed." << endl;
        // Displays the net-banking transaction details.


        return true;
        // Returns true to indicate
        // successful payment.
    }
};



// ====================================================
// MAIN FUNCTION
// ====================================================

int main()
{
    // Program execution starts from main().


    vector<unique_ptr<PaymentMethod>> payments;
    // Creates a vector named payments.
    //
    // The vector stores unique_ptr objects.
    //
    // unique_ptr is a smart pointer that automatically
    // manages dynamically allocated objects.
    //
    // PaymentMethod is the base class, so this vector
    // can store objects of CreditCardPayment,
    // UPIPayment, and NetBankingPayment.


    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001", 2500, "XXXX-XXXX-1234"
        )
    );
    // Creates a CreditCardPayment object dynamically
    // and adds it to the payments vector.
    //
    // Transaction ID = TXN001
    // Amount         = Rs. 2500
    // Card Number    = XXXX-XXXX-1234
    //
    // make_unique() creates a unique_ptr automatically.
    //
    // push_back() adds it to the vector.


    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002", 1200, "student@upi"
        )
    );
    // Creates a UPIPayment object.
    //
    // Transaction ID = TXN002
    // Amount         = Rs. 1200
    // UPI ID         = student@upi
    //
    // The object is stored inside the vector
    // through a unique_ptr.


    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003", 5000, "Example Bank"
        )
    );
    // Creates a NetBankingPayment object.
    //
    // Transaction ID = TXN003
    // Amount         = Rs. 5000
    // Bank           = Example Bank


    cout << "=== Payment Gateway ===" << endl;
    // Displays the heading:
    //
    // === Payment Gateway ===


    for (const auto& payment : payments)
    {
        // Range-based for loop.
        //
        // Goes through every payment stored in
        // the payments vector.
        //
        // const -> prevents modification.
        // auto  -> C++ automatically determines the type.
        // &     -> accesses the existing object by reference.
        // payment -> represents the current smart pointer.


        payment->processPayment();
        // Calls processPayment() through the unique_ptr.
        //
        // -> is used because payment is a pointer.
        //
        // Due to virtual functions, the correct version
        // of processPayment() is called:
        //
        // CreditCardPayment -> its processPayment()
        // UPIPayment        -> its processPayment()
        // NetBankingPayment -> its processPayment()
    }


    return 0;
    // Ends the program successfully.
}