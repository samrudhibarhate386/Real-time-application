#include <iostream>
// Includes the iostream library.
// It is used for input and output operations such as cout.

#include <string>
// Includes the string library.
// It allows us to use the string data type.

using namespace std;
// Allows us to use cout and string directly
// instead of writing std::cout and std::string.


// ====================================================
// BASE CLASS: EMPLOYEE
// ====================================================

class Employee
{
// Defines a base class named Employee.
// This class contains common information
// shared by different types of employees.


protected:
// Protected members can be accessed inside this class
// and also inside classes that inherit from Employee.
// They cannot be directly accessed from main().

    int empId;
    // Stores the employee ID.

    string name;
    // Stores the employee's name.

    string department;
    // Stores the employee's department.


public:
// Starts the public section.
// Public members can be accessed from outside the class.


    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept)
    {
    }
    // Constructor of the Employee class.
    //
    // id   -> employee ID
    // n    -> employee name
    // dept -> employee department
    //
    // empId(id) initializes empId.
    // name(n) initializes name.
    // department(dept) initializes department.
    //
    // The part after ':' is called the member
    // initializer list.


    void displayBasicInfo() const
    {
        // Displays the common information
        // of an employee.
        //
        // const means this function will not
        // modify the Employee object.


        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;
        // Displays:
        // Employee ID
        // Employee name
        // Employee department.
    }


    virtual double calculateSalary() const = 0;
    // This is a pure virtual function.
    //
    // virtual allows derived classes to provide
    // their own version of this function.
    //
    // double means the function returns a decimal value.
    //
    // = 0 makes this a pure virtual function.
    //
    // Because Employee contains a pure virtual function,
    // Employee becomes an abstract class.
    //
    // We cannot create an object directly like:
    // Employee e;
    //
    // Each derived class must provide its own
    // calculateSalary() function.


    virtual ~Employee() = default;
    // This is a virtual destructor.
    //
    // ~Employee() is the destructor.
    //
    // virtual ensures that when a derived object
    // is deleted through an Employee pointer,
    // the correct derived destructor is called.
    //
    // = default tells C++ to automatically generate
    // the default destructor.
};



// ====================================================
// FULL-TIME EMPLOYEE CLASS
// ====================================================

class FullTimeEmployee : public Employee
{
// Defines FullTimeEmployee.
// 
// : public Employee means FullTimeEmployee
// inherits publicly from Employee.
//
// FullTimeEmployee is a derived class.
// Employee is its base class.


private:
// Private data can only be accessed directly
// inside FullTimeEmployee.

    double monthlySalary;
    // Stores the monthly salary of the
    // full-time employee.


public:
// Starts the public section.


    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary)
    {
    }
    // Constructor of FullTimeEmployee.
    //
    // Employee(id, n, dept)
    // calls the constructor of the base Employee class.
    //
    // monthlySalary(salary)
    // initializes the monthly salary.


    double calculateSalary() const override
    {
        // Provides the implementation of the
        // pure virtual calculateSalary() function.
        //
        // override tells the compiler that this function
        // is overriding a virtual function from Employee.


        return monthlySalary;
        // Returns the monthly salary.
    }


    void display() const
    {
        // Displays complete information
        // about the full-time employee.


        displayBasicInfo();
        // Calls the function inherited from Employee.
        // It displays ID, name, and department.


        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary() << endl;
        // Displays the employee type
        // and calculated salary.
    }
};



// ====================================================
// PART-TIME EMPLOYEE CLASS
// ====================================================

class PartTimeEmployee : public Employee
{
// Defines the PartTimeEmployee class.
//
// It inherits from the Employee class.


private:
// Private members of PartTimeEmployee.

    double hourlyRate;
    // Stores the amount paid per hour.

    int hoursWorked;
    // Stores the total number of hours worked.


public:
// Starts the public section.


    PartTimeEmployee(int id, string n, string dept,
                      double rate, int hours)
        : Employee(id, n, dept),
          hourlyRate(rate),
          hoursWorked(hours)
    {
    }
    // Constructor of PartTimeEmployee.
    //
    // Employee(id, n, dept)
    // initializes the inherited Employee information.
    //
    // hourlyRate(rate)
    // initializes the hourly payment.
    //
    // hoursWorked(hours)
    // initializes the number of hours worked.


    double calculateSalary() const override
    {
        // Overrides the calculateSalary()
        // function from the Employee class.


        return hourlyRate * hoursWorked;
        // Calculates salary using:
        //
        // Salary = Hourly Rate × Hours Worked
    }


    void display() const
    {
        // Displays information about the
        // part-time employee.


        displayBasicInfo();
        // Displays ID, name, and department.


        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary() << endl;
        // Displays the employee type
        // and calculated salary.
    }
};



// ====================================================
// INTERN CLASS
// ====================================================

class Intern : public Employee
{
// Defines the Intern class.
//
// It inherits from Employee.


private:
// Private members of Intern.

    double stipend;
    // Stores the stipend received by the intern.


public:
// Starts the public section.


    Intern(int id, string n, string dept, double stipendAmount)
        : Employee(id, n, dept),
          stipend(stipendAmount)
    {
    }
    // Constructor of Intern.
    //
    // Employee(id, n, dept)
    // initializes the inherited employee information.
    //
    // stipend(stipendAmount)
    // initializes the intern's stipend.


    double calculateSalary() const override
    {
        // Overrides the calculateSalary()
        // function from Employee.


        return stipend;
        // Returns the intern's stipend.
    }


    void display() const
    {
        // Displays information about the intern.


        displayBasicInfo();
        // Displays ID, name, and department.


        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary() << endl;
        // Displays the employee type
        // and stipend amount.
    }
};



// ====================================================
// MAIN FUNCTION
// ====================================================

int main()
{
    // Program execution starts from main().


    FullTimeEmployee f1(101, "Amit", "IT", 65000);
    // Creates a FullTimeEmployee object named f1.
    //
    // ID         = 101
    // Name       = Amit
    // Department = IT
    // Salary     = Rs. 65000


    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);
    // Creates a PartTimeEmployee object named p1.
    //
    // ID          = 102
    // Name        = Sneha
    // Department  = HR
    // Hourly Rate = Rs. 250
    // Hours       = 120
    //
    // Salary = 250 × 120
    // Salary = Rs. 30000


    Intern i1(103, "Rohan", "Marketing", 15000);
    // Creates an Intern object named i1.
    //
    // ID         = 103
    // Name       = Rohan
    // Department = Marketing
    // Stipend    = Rs. 15000


    cout << "=== Employee Payroll ===" << endl;
    // Prints the heading:
    //
    // === Employee Payroll ===


    f1.display();
    // Displays the full-time employee's information.


    p1.display();
    // Displays the part-time employee's information.


    i1.display();
    // Displays the intern's information.


    return 0;
    // Ends the program successfully.
}