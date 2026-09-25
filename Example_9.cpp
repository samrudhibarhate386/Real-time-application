#include <cctype>
// #include = includes a library
// <cctype> = C++ library containing character functions
// We use isalpha() from this library.


#include <iostream>
// <iostream> = Input/Output library
// Provides cout and endl.


#include <string>
// <string> = provides the string data type


using namespace std;
// Allows us to use cout, string, endl, etc.
// without writing std:: before each one.


class Validator
// class = keyword used to create a class
// Validator = name of the class
{
public:
    // public = everything below this can be accessed
    // from outside the class


    bool validate(int marks) const
    {
        // bool = Boolean return type
        // A bool can contain true or false.
        //
        // validate = function name
        //
        // int marks = function receives an integer called marks
        //
        // const at the end means this function
        // will not modify the Validator object.

        return marks >= 0 && marks <= 100;
        // return = sends the result back
        //
        // marks >= 0
        // checks whether marks are greater than or equal to 0
        //
        // && = logical AND
        // BOTH conditions must be true
        //
        // marks <= 100
        // checks whether marks are less than or equal to 100
        //
        // Therefore valid marks are:
        // 0 to 100
        //
        // Example:
        // 88 >= 0  -> true
        // 88 <= 100 -> true
        // true && true -> true
    }


    bool validate(double amount) const
    {
        // This is another validate() function.
        //
        // It has the SAME function name,
        // but a DIFFERENT parameter type.
        //
        // double amount = decimal number

        return amount > 0.0 && amount <= 1000000.0;
        // amount > 0.0
        // amount must be greater than 0
        //
        // amount <= 1000000.0
        // amount cannot be greater than 10 lakh
        //
        // Both conditions must be true.
    }


    bool validate(const string& name) const
    {
        // Another validate() function.
        //
        // This time it accepts a string.
        //
        // const string& name
        //
        // string = text data type
        //
        // & = reference
        // The original string is passed without making
        // an unnecessary copy.
        //
        // const = the function promises not to modify name.


        if (name.empty())
        {
            // if = checks a condition
            //
            // name.empty()
            // checks whether the string contains nothing.
            //
            // Example:
            // "" -> empty
            // "Priya" -> not empty

            return false;
            // If the name is empty,
            // it is invalid.
        }


        for (char ch : name)
        {
            // for = loop
            //
            // char ch
            // creates a character variable called ch
            //
            // :
            // means "take each element from"
            //
            // name
            // the loop goes through every character
            //
            // Example:
            // "Priya"
            //
            // ch = 'P'
            // ch = 'r'
            // ch = 'i'
            // ch = 'y'
            // ch = 'a'


            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ')
            {
                // isalpha()
                // checks whether ch is an alphabetic character.
                //
                // For example:
                // 'P' -> true
                // 'r' -> true
                // '1' -> false
                //
                // static_cast<unsigned char>(ch)
                // converts ch into unsigned char before
                // passing it to isalpha().
                //
                // ! = NOT
                // Reverses true to false and false to true.
                //
                // !isalpha(...)
                // means:
                // "ch is NOT an alphabet"
                //
                // && = AND
                //
                // ch != ' '
                // checks that ch is NOT a space.
                //
                // Therefore this condition means:
                //
                // "If the character is NOT a letter
                // AND it is NOT a space..."


                return false;
                // Invalid character found.
                // So the name is invalid.
            }
        }


        return true;
        // If the loop finishes without finding
        // an invalid character,
        // the name is valid.
    }
};


int main()
{
    // main() = starting point of the program


    Validator validator;
    // Creates an object called validator
    // from the Validator class.


    cout << boolalpha;
    // boolalpha tells cout to display Boolean values as:
    //
    // true
    // false
    //
    // instead of:
    //
    // 1
    // 0


    cout << "Marks 88 valid: "
         << validator.validate(88)
         << endl;
    // validator.validate(88)
    //
    // 88 is an int.
    // Therefore C++ selects:
    //
    // validate(int marks)
    //
    // 88 is between 0 and 100,
    // so the result is true.


    cout << "Marks 120 valid: "
         << validator.validate(120)
         << endl;
    // 120 is an int.
    //
    // C++ again selects:
    // validate(int marks)
    //
    // 120 is greater than 100,
    // so the result is false.


    cout << "Amount 4500.50 valid: "
         << validator.validate(4500.50)
         << endl;
    // 4500.50 is a decimal number.
    //
    // Therefore C++ selects:
    //
    // validate(double amount)
    //
    // 4500.50 is greater than 0
    // and less than 1,000,000.
    //
    // Result = true.


    cout << "Name Priya Sharma valid: "
         << validator.validate(string("Priya Sharma"))
         << endl;
    // string("Priya Sharma")
    // creates a string object.
    //
    // C++ selects:
    //
    // validate(const string& name)
    //
    // The loop checks:
    //
    // P -> letter
    // r -> letter
    // i -> letter
    // y -> letter
    // a -> letter
    // ' ' -> allowed space
    // S -> letter
    // h -> letter
    // a -> letter
    // r -> letter
    // m -> letter
    // a -> letter
    //
    // Everything is valid.
    //
    // Result = true.


    cout << "Name Priya123 valid: "
         << validator.validate(string("Priya123"))
         << endl;
    // C++ selects the string version of validate().
    //
    // P -> valid
    // r -> valid
    // i -> valid
    // y -> valid
    // a -> valid
    // 1 -> NOT an alphabet
    //
    // Therefore:
    // return false;


    return 0;
    // 0 means the program ended successfully.
}