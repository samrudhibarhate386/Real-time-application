#include <fstream>
// #include = includes a library
// <fstream> = file stream library
// Used for reading and writing files.
// ofstream -> writes to a file
// ifstream -> reads from a file


#include <iostream>
// <iostream> = input/output library
// Provides cout, cerr, endl, etc.


#include <sstream>
// <sstream> = string stream library
// Allows us to process a string like a stream.
// We use stringstream to separate CSV values.


#include <string>
// <string> = provides the string data type


using namespace std;
// Allows us to write cout, string, ofstream, etc.
// instead of std::cout, std::string, std::ofstream, etc.



class Student
// class = keyword used to create a class
// Student = name of the class
{
private:
    // private = members can only be directly accessed
    // inside the Student class

    int rollNo;
    // int = integer data type
    // rollNo = stores the student's roll number

    string name;
    // string = stores text
    // name = stores the student's name

    double marks;
    // double = decimal number
    // marks = stores student's marks


public:
    // public = members can be accessed from outside
    // the class


    Student() : rollNo(0), marks(0.0)
    {
        // Student() = default constructor
        //
        // It has no parameters.
        //
        // It is called when we write:
        //
        // Student student;
        //
        // : = starts the member initializer list
        //
        // rollNo(0) -> rollNo is initialized to 0
        //
        // marks(0.0) -> marks is initialized to 0.0
        //
        // name automatically becomes an empty string.
    }


    Student(int r, string n, double m)
        : rollNo(r), name(n), marks(m)
    {
        // This is a parameterized constructor.
        //
        // int r = roll number
        // string n = student name
        // double m = marks
        //
        // : starts the initializer list.
        //
        // rollNo(r) -> rollNo gets the value of r
        // name(n)   -> name gets the value of n
        // marks(m)  -> marks gets the value of m
    }


    void saveToFile(ofstream& out) const
    {
        // void = function does not return anything
        //
        // saveToFile = function name
        //
        // ofstream = output file stream
        // Used for writing into a file.
        //
        // & = reference
        // We pass the original file stream instead
        // of creating a copy.
        //
        // out = name of the file stream
        //
        // const = this function will not modify
        // the Student object.


        out << rollNo << ',' << name << ',' << marks << '\n';
        // out = file where data will be written
        //
        // << = insertion operator
        //
        // rollNo = writes roll number
        //
        // ',' = writes a comma
        //
        // name = writes student's name
        //
        // marks = writes marks
        //
        // '\n' = moves to the next line
        //
        // Example:
        //
        // 101,Rahul Patil,85.5
    }


    bool loadFromLine(const string& line)
    {
        // bool = returns true or false
        //
        // loadFromLine = function name
        //
        // const string& line
        //
        // string = text
        //
        // & = reference, avoids making a copy
        //
        // const = line cannot be modified


        string rollText;
        // Stores the roll number temporarily as text.


        string marksText;
        // Stores marks temporarily as text.


        stringstream stream(line);
        // stringstream = treats a string like a stream.
        //
        // Example line:
        //
        // "101,Rahul Patil,85.5"
        //
        // We can now separate this into:
        //
        // 101
        // Rahul Patil
        // 85.5


        if (!getline(stream, rollText, ','))
            return false;
        // getline() reads data from stream.
        //
        // stream = source
        // rollText = destination
        // ',' = delimiter
        //
        // Delimiter means the character at which
        // reading should stop.
        //
        // So the first part becomes:
        //
        // rollText = "101"
        //
        // ! = NOT
        //
        // If getline() fails,
        // return false.


        if (!getline(stream, name, ','))
            return false;
        // Reads the second part of the CSV line.
        //
        // Example:
        //
        // name = "Rahul Patil"
        //
        // Again, comma is the delimiter.


        if (!getline(stream, marksText))
            return false;
        // Reads the remaining part of the line.
        //
        // There is no comma delimiter here.
        // Therefore it reads until the end.
        //
        // marksText = "85.5"


        rollNo = stoi(rollText);
        // stoi = String To Integer
        //
        // Converts:
        //
        // "101"
        //
        // into:
        //
        // 101
        //
        // and stores it in rollNo.


        marks = stod(marksText);
        // stod = String To Double
        //
        // Converts:
        //
        // "85.5"
        //
        // into:
        //
        // 85.5
        //
        // and stores it in marks.


        return true;
        // Everything was successfully loaded.
        // Therefore return true.
    }


    void display() const
    {
        // void = does not return anything
        //
        // display = function name
        //
        // const = does not modify the Student object


        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Marks: " << marks << endl;

        // cout = displays output on the screen
        //
        // << = insertion operator
        //
        // rollNo = student's roll number
        //
        // name = student's name
        //
        // marks = student's marks
        //
        // endl = moves to the next line
    }
};



int main()
{
    // main() = starting point of the program


    ofstream outFile("students.csv");
    // ofstream = output file stream
    // Used to WRITE data into a file.
    //
    // outFile = file stream object
    //
    // "students.csv" = name of the file.
    //
    // If the file does not exist,
    // C++ creates it.
    //
    // If it already exists, its old contents
    // are normally overwritten.


    if (!outFile)
    {
        // Checks whether the file opened successfully.
        //
        // !outFile means the file is NOT in
        // a successful state.


        cerr << "Unable to open students.csv for writing."
             << endl;
        // cerr = standard error output
        //
        // Displays an error message.


        return 1;
        // 1 indicates that the program ended
        // because of an error.
    }


    Student s1(101, "Rahul Patil", 85.5);
    // Creates Student object s1.
    //
    // rollNo = 101
    // name = Rahul Patil
    // marks = 85.5


    Student s2(102, "Priya Sharma", 92.0);
    // Creates Student object s2.
    //
    // rollNo = 102
    // name = Priya Sharma
    // marks = 92.0


    Student s3(103, "Amit Kulkarni", 78.5);
    // Creates Student object s3.
    //
    // rollNo = 103
    // name = Amit Kulkarni
    // marks = 78.5


    s1.saveToFile(outFile);
    // Calls saveToFile() for s1.
    // Writes s1's data into students.csv.


    s2.saveToFile(outFile);
    // Writes s2's data into the file.


    s3.saveToFile(outFile);
    // Writes s3's data into the file.


    outFile.close();
    // close() closes the output file.
    //
    // We have finished writing.


    ifstream inFile("students.csv");
    // ifstream = input file stream
    // Used to READ from a file.
    //
    // inFile = input file stream object
    //
    // "students.csv" = file we want to read.


    if (!inFile)
    {
        // Checks whether the file opened successfully.


        cerr << "Unable to open students.csv for reading."
             << endl;
        // Displays an error message if the file
        // cannot be opened.


        return 1;
        // Ends the program because of an error.
    }


    cout << "=== Student Report ===" << endl;
    // Prints the report heading.


    string line;
    // Creates a string variable called line.
    //
    // It will store one complete line from
    // the CSV file at a time.


    while (getline(inFile, line))
    {
        // while = repeats while the condition is true
        //
        // getline(inFile, line)
        // reads one complete line from the file.
        //
        // The loop continues until the file has
        // no more lines.


        Student student;
        // Creates a Student object called student.
        //
        // No arguments are provided,
        // so the DEFAULT CONSTRUCTOR is called.
        //
        // Initially:
        //
        // rollNo = 0
        // name = ""
        // marks = 0.0


        if (student.loadFromLine(line))
        {
            // Sends the current CSV line to
            // loadFromLine().
            //
            // The function separates:
            //
            // roll number
            // name
            // marks
            //
            // If successful, it returns true.


            student.display();
            // Displays the student's information.
        }
    }


    return 0;
    // Program finished successfully.
}