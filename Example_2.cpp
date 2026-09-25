#include <iostream>
// Includes the iostream library.
// It is used for input and output operations like cout.

#include <string>
// Includes the string library.
// It allows us to use the string data type.

using namespace std;
// Allows us to use cout and string directly
// without writing std:: before them.


// ----------------------------------------------------
// STUDENT CLASS
// ----------------------------------------------------

class Student
{
// Defines a class named Student.
// This class represents a student and their attendance.

private:
// Private members can only be directly accessed
// inside the Student class.

    int rollNo;
    // Stores the student's roll number.

    string name;
    // Stores the student's name.

    int totalDays;
    // Stores the total number of days
    // on which attendance was marked.

    int presentDays;
    // Stores the number of days
    // on which the student was present.


public:
// Public members can be accessed from outside the class.


    Student(int r, string n)
        : rollNo(r), name(n), totalDays(0), presentDays(0)
    {
    }
    // This is the constructor of the Student class.
    //
    // It is automatically called when a Student object is created.
    //
    // r -> receives the roll number.
    // n -> receives the student's name.
    //
    // rollNo(r) assigns r to rollNo.
    // name(n) assigns n to name.
    // totalDays(0) initializes totalDays to 0.
    // presentDays(0) initializes presentDays to 0.
    //
    // The part after ':' is called the member initializer list.


    void markAttendance(bool isPresent)
    {
        // This function marks the attendance of the student.
        //
        // void means the function does not return any value.
        //
        // bool can contain either:
        // true  -> present
        // false -> absent


        totalDays++;
        // Increases totalDays by 1.
        //
        // Every time attendance is marked,
        // the total number of days increases.


        if (isPresent)
        {
            // Checks whether isPresent is true.
            //
            // If true, the student is present.


            presentDays++;
            // Increases presentDays by 1.
        }
    }
    // Ends the markAttendance() function.


    double getAttendancePercentage() const
    {
        // This function calculates and returns
        // the student's attendance percentage.
        //
        // double is used because the percentage
        // can contain decimal values.
        //
        // const means this function will not
        // modify the student's data.


        if (totalDays == 0)
        {
            // Checks whether attendance has been
            // marked for zero days.


            return 0.0;
            // Returns 0.0% attendance.
            //
            // This also prevents division by zero.
        }


        return (presentDays * 100.0) / totalDays;
        // Calculates the attendance percentage.
        //
        // Formula:
        //
        // Attendance = (Present Days × 100) / Total Days
        //
        // 100.0 is used so that the calculation
        // produces a decimal result.
    }
    // Ends getAttendancePercentage().


    void display() const
    {
        // This function displays the student's
        // attendance information.
        //
        // const means it does not modify the object.


        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: " << getAttendancePercentage()
             << "%" << endl;
        // Displays:
        // Roll number
        // Student name
        // Attendance percentage
        //
        // getAttendancePercentage() is called
        // to calculate the percentage.
    }
    // Ends the display() function.

};
// Ends the Student class.
// The semicolon after the class is compulsory.



// ----------------------------------------------------
// MAIN FUNCTION
// ----------------------------------------------------

int main()
{
    // Program execution starts from main().


    Student s1(101, "Rahul");
    // Creates the first Student object named s1.
    //
    // Roll number = 101
    // Name = Rahul
    // Total days = 0
    // Present days = 0


    Student s2(102, "Priya");
    // Creates the second Student object named s2.
    //
    // Roll number = 102
    // Name = Priya
    // Total days = 0
    // Present days = 0


    s1.markAttendance(true);
    // Marks Rahul as PRESENT.
    //
    // totalDays = 1
    // presentDays = 1


    s1.markAttendance(true);
    // Marks Rahul as PRESENT again.
    //
    // totalDays = 2
    // presentDays = 2


    s1.markAttendance(false);
    // Marks Rahul as ABSENT.
    //
    // totalDays = 3
    // presentDays = 2


    s2.markAttendance(true);
    // Marks Priya as PRESENT.
    //
    // totalDays = 1
    // presentDays = 1


    s2.markAttendance(true);
    // Marks Priya as PRESENT again.
    //
    // totalDays = 2
    // presentDays = 2


    s2.markAttendance(true);
    // Marks Priya as PRESENT again.
    //
    // totalDays = 3
    // presentDays = 3


    cout << "=== Attendance Report ===" << endl;
    // Prints the heading:
    //
    // === Attendance Report ===


    s1.display();
    // Calls display() for Rahul.
    //
    // Rahul's attendance:
    // Present = 2
    // Total = 3
    // Percentage = 66.6667%


    s2.display();
    // Calls display() for Priya.
    //
    // Priya's attendance:
    // Present = 3
    // Total = 3
    // Percentage = 100%


    return 0;
    // Ends the program successfully.
}