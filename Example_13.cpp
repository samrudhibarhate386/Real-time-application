#include <exception>      // Provides the standard exception class
#include <iostream>      // Provides cout and endl
#include <stdexcept>     // Provides standard exceptions like invalid_argument
#include <string>        // Provides the string data type

using namespace std;


// ============================================================
// CUSTOM EXCEPTION CLASS
// ============================================================

// InsufficientFundsException is our own custom exception class.
//
// ": public exception" means this class inherits from the
// standard C++ exception class.
//
// So InsufficientFundsException IS-A type of exception.
class InsufficientFundsException : public exception
{
private:

    // Stores the account balance available when
    // the exception occurred.
    double balance;

    // Stores the amount the user tried to withdraw.
    double requestedAmount;


public:

    // Constructor of InsufficientFundsException.
    //
    // currentBalance -> current account balance
    // requested      -> amount requested for withdrawal
    InsufficientFundsException(double currentBalance, double requested)

        // Initializer list.
        //
        // balance(currentBalance)
        // means:
        //     balance = currentBalance
        //
        // requestedAmount(requested)
        // means:
        //     requestedAmount = requested
        : balance(currentBalance),
          requestedAmount(requested)
    {
    }


    // what() is a function provided by the standard exception class.
    //
    // const
    // means this function will not modify the exception object.
    //
    // noexcept
    // means this function promises that it will not throw another
    // exception.
    //
    // override
    // means we are overriding the what() function inherited
    // from the exception class.
    //
    // const char*
    // means the function returns a pointer to a constant character
    // sequence (C-style string).
    const char* what() const noexcept override
    {
        return "Insufficient balance for withdrawal.";
    }


    // Getter function to return the available balance.
    //
    // const means this function does not modify the object.
    double getBalance() const
    {
        return balance;
    }


    // Getter function to return the amount that was requested.
    double getRequestedAmount() const
    {
        return requestedAmount;
    }
};


// ============================================================
// BANK ACCOUNT CLASS
// ============================================================

class BankAccount
{
private:

    // Stores the bank account number.
    int accountNumber;

    // Stores the account holder's name.
    string holderName;

    // Stores the current account balance.
    double balance;


public:

    // Constructor of BankAccount.
    //
    // number         -> account number
    // name           -> account holder's name
    // openingBalance -> initial balance
    BankAccount(int number, string name, double openingBalance)

        // Initializer list.
        //
        // accountNumber gets number
        // holderName gets name
        // balance gets openingBalance
        : accountNumber(number),
          holderName(name),
          balance(openingBalance)
    {

        // Check whether the opening balance is negative.
        //
        // "< 0.0" means less than zero.
        if (openingBalance < 0.0)
        {
            // throw is used to generate an exception.

            // invalid_argument is a standard C++ exception
            // used when an argument has an invalid value.
            throw invalid_argument(
                "Opening balance cannot be negative."
            );
        }
    }


    // ========================================================
    // DEPOSIT FUNCTION
    // ========================================================

    void deposit(double amount)
    {
        // A deposit must be greater than zero.
        //
        // "<= 0.0" means:
        // less than OR equal to zero.
        if (amount <= 0.0)
        {
            // Throw a standard exception because the
            // supplied deposit amount is invalid.
            throw invalid_argument(
                "Deposit amount must be positive."
            );
        }

        // Add the deposited amount to the balance.
        //
        // += means:
        // balance = balance + amount
        balance += amount;
    }


    // ========================================================
    // WITHDRAW FUNCTION
    // ========================================================

    void withdraw(double amount)
    {
        // Withdrawal amount must be greater than zero.
        if (amount <= 0.0)
        {
            // Throw a standard invalid_argument exception.
            throw invalid_argument(
                "Withdrawal amount must be positive."
            );
        }


        // Check whether the requested amount is greater
        // than the available balance.
        if (amount > balance)
        {
            // If there is not enough money, throw our
            // CUSTOM exception.
            //
            // We send the current balance and requested
            // withdrawal amount to the exception object.
            throw InsufficientFundsException(
                balance,
                amount
            );
        }


        // If enough money is available, subtract the
        // withdrawal amount from the balance.
        //
        // -= means:
        // balance = balance - amount
        balance -= amount;
    }


    // ========================================================
    // DISPLAY FUNCTION
    // ========================================================

    void display() const
    {
        // Display account information.
        cout << "Account: " << accountNumber
             << " | Holder: " << holderName
             << " | Balance: Rs. " << balance
             << endl;
    }
};


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    // ========================================================
    // TRY BLOCK
    // ========================================================
    //
    // Code that might generate an exception is placed
    // inside the try block.

    try
    {
        // Create a BankAccount object.
        //
        // Account number = 1001
        // Holder name   = Rahul
        // Opening balance = Rs. 5000
        BankAccount account(
            1001,
            "Rahul",
            5000.0
        );


        // Deposit Rs. 2000.
        //
        // Balance:
        // 5000 + 2000 = 7000
        account.deposit(2000.0);


        // Withdraw Rs. 1500.
        //
        // Balance:
        // 7000 - 1500 = 5500
        account.withdraw(1500.0);


        // Try to withdraw Rs. 10000.
        //
        // Available balance = Rs. 5500
        //
        // Requested amount = Rs. 10000
        //
        // Since:
        //
        // 10000 > 5500
        //
        // InsufficientFundsException will be thrown.
        account.withdraw(10000.0);
    }


    // ========================================================
    // FIRST CATCH BLOCK
    // ========================================================
    //
    // This catch handles our CUSTOM exception.
    //
    // const InsufficientFundsException&
    //
    // const
    // -> We will not modify the exception object.
    //
    // &
    // -> Pass the exception by reference instead of making
    //    another copy.
    //
    // error
    // -> Name of the exception object.

    catch (const InsufficientFundsException& error)
    {
        // error.what() calls our overridden what() function.
        cout << "Transaction failed: "
             << error.what()
             << endl;


        // Display the balance stored inside the exception.
        cout << "Available balance: Rs. "
             << error.getBalance()
             << endl;


        // Display the amount that was requested.
        cout << "Requested amount: Rs. "
             << error.getRequestedAmount()
             << endl;
    }


    // ========================================================
    // SECOND CATCH BLOCK
    // ========================================================
    //
    // This handles other standard exceptions.
    //
    // exception is the base class of many standard
    // C++ exception types.

    catch (const exception& error)
    {
        cout << "System error: "
             << error.what()
             << endl;
    }


    // Program completed successfully.
    return 0;
}