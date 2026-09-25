#include <fstream>
// #include = tells the compiler to include a library
// <fstream> = file stream library
// Used for reading and writing files.
// ofstream -> writes to a file
// ifstream -> reads from a file


#include <iostream>
// <iostream> = input/output library
// Provides cout, cerr, endl, etc.


#include <string>
// <string> = provides the string data type
// Also provides functions such as find()


#include <vector>
// <vector> = provides the vector container
// A vector is a dynamic list that can grow in size.


using namespace std;
// Allows us to use string, vector, cout, etc.
// instead of writing std:: before them.



struct LogEntry
// struct = creates a structure
// LogEntry = name of the structure
{
    string line;
    // string = stores text
    //
    // line = stores one complete log entry
};



int main()
{
    // main() = starting point of the program


    ofstream sampleLog("server.log");
    // ofstream = output file stream
    // Used to WRITE data into a file.
    //
    // sampleLog = name of our file stream object
    //
    // "server.log" = name of the file.
    //
    // If the file does not exist, it will be created.


    if (!sampleLog)
    {
        // Checks whether the file was opened successfully.
        //
        // ! = NOT
        //
        // !sampleLog means the file stream is
        // not in a successful state.


        cerr << "Unable to create log file." << endl;
        // cerr = standard error output
        //
        // Displays an error message.


        return 1;
        // 1 indicates that the program ended
        // because of an error.
    }


    sampleLog << "2026-09-09 08:00:00 INFO Server started\n";
    // << = insertion operator
    //
    // Writes this log entry into server.log.
    //
    // \n = newline
    // Moves to the next line.


    sampleLog << "2026-09-09 08:10:00 WARNING High memory usage\n";
    // Writes a WARNING log entry.


    sampleLog << "2026-09-09 08:20:00 ERROR Database connection failed\n";
    // Writes an ERROR log entry.


    sampleLog << "2026-09-09 08:30:00 INFO Backup completed\n";
    // Writes an INFO log entry.


    sampleLog << "2026-09-09 08:40:00 CRITICAL Disk space low\n";
    // Writes a CRITICAL log entry.


    sampleLog.close();
    // close() closes the file.
    //
    // We have finished writing the log entries.



    ifstream logFile("server.log");
    // ifstream = input file stream
    // Used to READ data from a file.
    //
    // logFile = name of the input file object
    //
    // "server.log" = file we want to read.


    if (!logFile)
    {
        // Checks whether server.log opened successfully.


        cerr << "Unable to open server.log." << endl;
        // Prints an error message if opening failed.


        return 1;
        // Ends the program with an error.
    }


    vector<LogEntry> errors;
    // vector = dynamic container
    //
    // <LogEntry>
    // means this vector will store LogEntry objects.
    //
    // errors = name of the vector.
    //
    // Initially it is empty.
    //
    // It will store only ERROR and CRITICAL log entries.


    string line;
    // Creates a string variable called line.
    //
    // It will temporarily hold one complete line
    // from the log file.


    while (getline(logFile, line))
    {
        // while = repeats while the condition is true
        //
        // getline(logFile, line)
        // reads one complete line from the file.
        //
        // The loop continues until there are no more lines.


        if (line.find("ERROR") != string::npos ||
            line.find("CRITICAL") != string::npos)
        {
            // find() searches for text inside a string.
            //
            // line.find("ERROR")
            // searches the current line for "ERROR".
            //
            // string::npos
            // means "not found".
            //
            // :: = scope resolution operator.
            //
            // string::npos means the npos constant
            // belonging to the string class.
            //
            // If ERROR is found:
            //
            // line.find("ERROR") != string::npos
            //
            // becomes true.
            //
            // || = logical OR
            // At least ONE condition must be true.
            //
            // The second condition searches for "CRITICAL".
            //
            // Therefore the whole if condition means:
            //
            // "If the line contains ERROR
            // OR contains CRITICAL..."


            errors.push_back({line});
            // push_back() adds an element to the end
            // of the vector.
            //
            // {line}
            // creates a LogEntry object containing
            // the current line.
            //
            // Example:
            //
            // If line is:
            // "2026-09-09 08:20:00 ERROR Database connection failed"
            //
            // it gets stored inside errors.
        }
    }



    cout << "=== Critical Log Events ===" << endl;
    // Prints the heading.


    for (const auto& entry : errors)
    {
        // for = loop
        //
        // const = entry will not be modified
        //
        // auto = C++ automatically determines the type.
        //
        // & = reference
        // Avoids making a copy of each LogEntry.
        //
        // entry = current LogEntry object
        //
        // : = "from"
        //
        // errors = vector being traversed.
        //
        // The loop visits every element in errors.


        cout << entry.line << endl;
        // entry = current LogEntry
        //
        // . = accesses a member of an object
        //
        // line = member inside LogEntry
        //
        // Therefore entry.line gives us the actual
        // log message.
    }


    cout << "Total critical events: "
         << errors.size() << endl;
    // errors.size()
    // returns the number of elements stored in errors.
    //
    // If there are 2 matching entries:
    //
    // errors.size() = 2



    return 0;
    // Program finished successfully.
}