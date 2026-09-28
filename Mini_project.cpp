#include <fstream>   // Provides file handling classes such as ifstream and ofstream.
#include <iostream>  // Provides input/output functions such as cout, cin, and endl.
#include <string>    // Provides the string data type.
#include <vector>    // Provides the vector container.
using namespace std; // Allows us to use cout, cin, string, etc. without std::.

// Structure used to store the details of one library book.
struct Book {

    string isbn;         // Stores the ISBN number of the book.
    string title;        // Stores the title of the book.
    string author;       // Stores the author's name.
    string category;     // Stores the category of the book.
    string availability; // Stores whether the book is Available or Issued.
};


// Function used to add a new book to the file.
void addBook() {

    // Creates an output file stream.
    // ios::app opens the file in append mode so existing books are not deleted.
    ofstream file("library.txt", ios::app);

    // Creates a Book object.
    Book book;

    // Takes the ISBN from the user.
    cout << "Enter ISBN: ";
    cin >> book.isbn;

    // Clears the newline left in the input buffer.
    cin.ignore();

    // Takes the book title.
    cout << "Enter Title: ";
    getline(cin, book.title);

    // Takes the author's name.
    cout << "Enter Author: ";
    getline(cin, book.author);

    // Takes the category.
    cout << "Enter Category: ";
    getline(cin, book.category);

    // Every newly added book is initially available.
    book.availability = "Available";

    // Stores all book information in the text file.
    // '|' is used as a separator between different fields.
    file << book.isbn << "|"
         << book.title << "|"
         << book.author << "|"
         << book.category << "|"
         << book.availability << "\n";

    // Closes the file.
    file.close();

    // Displays a success message.
    cout << "Book added successfully!\n";
}


// Function used to convert one line from the file into a Book object.
bool parseBook(const string& line, Book& book) {

    // Creates a string stream using the given line.
    // This allows the line to be separated using '|'.
    size_t first = line.find('|');

    // If the first separator is not found, the record is invalid.
    if (first == string::npos) {
        return false;
    }

    // Finds the second separator after the ISBN.
    size_t second = line.find('|', first + 1);

    // Finds the third separator after the title.
    size_t third = line.find('|', second + 1);

    // Finds the fourth separator after the author.
    size_t fourth = line.find('|', third + 1);

    // Checks whether all required separators were found.
    if (second == string::npos ||
        third == string::npos ||
        fourth == string::npos) {
        return false;
    }

    // Extracts the ISBN from the line.
    book.isbn = line.substr(0, first);

    // Extracts the title from the line.
    book.title = line.substr(first + 1, second - first - 1);

    // Extracts the author from the line.
    book.author = line.substr(second + 1, third - second - 1);

    // Extracts the category from the line.
    book.category = line.substr(third + 1, fourth - third - 1);

    // Extracts the availability status.
    book.availability = line.substr(fourth + 1);

    // Returns true because the book was successfully read.
    return true;
}


// Function used to display details of a book.
void displayBook(const Book& book) {

    // Displays the ISBN.
    cout << "ISBN: " << book.isbn << endl;

    // Displays the title.
    cout << "Title: " << book.title << endl;

    // Displays the author.
    cout << "Author: " << book.author << endl;

    // Displays the category.
    cout << "Category: " << book.category << endl;

    // Displays whether the book is available or issued.
    cout << "Availability: " << book.availability << endl;

    // Prints a separator line.
    cout << "-----------------------------" << endl;
}


// Function used to search for a book using its ISBN.
void searchBook() {

    // Opens the library file for reading.
    ifstream file("library.txt");

    // Stores the ISBN entered by the user.
    string searchISBN;

    // Takes the ISBN to search for.
    cout << "Enter ISBN to search: ";
    cin >> searchISBN;

    // Stores one line from the file.
    string line;

    // Keeps track of whether the book was found.
    bool found = false;

    // Reads the file one line at a time.
    while (getline(file, line)) {

        // Creates a Book object.
        Book book;

        // Converts the current line into a Book object.
        if (parseBook(line, book)) {

            // Compares the entered ISBN with the book's ISBN.
            if (book.isbn == searchISBN) {

                // Displays the matching book.
                displayBook(book);

                // Changes found to true.
                found = true;

                // Stops searching because the book was found.
                break;
            }
        }
    }

    // If no matching book was found.
    if (!found) {
        cout << "Book not found.\n";
    }

    // Closes the file.
    file.close();
}


// Function used to issue or return a book.
void changeAvailability(string isbn, string newStatus) {

    // Opens the existing library file for reading.
    ifstream input("library.txt");

    // Creates a temporary file for storing updated records.
    ofstream output("temp.txt");

    // Stores one line at a time.
    string line;

    // Keeps track of whether the book was found.
    bool found = false;

    // Reads every record from the library file.
    while (getline(input, line)) {

        // Creates a Book object.
        Book book;

        // Converts the line into a Book object.
        if (parseBook(line, book)) {

            // Checks whether this is the requested book.
            if (book.isbn == isbn) {

                // Checks whether the user wants to issue the book.
                if (newStatus == "Issued") {

                    // If the book is already issued, it cannot be issued again.
                    if (book.availability == "Issued") {
                        cout << "Book is already issued.\n";
                        found = true;
                    }
                    else {

                        // Changes the availability to Issued.
                        book.availability = "Issued";

                        // Marks the book as found.
                        found = true;

                        // Displays a success message.
                        cout << "Book issued successfully.\n";
                    }
                }

                // Checks whether the user wants to return the book.
                else {

                    // If the book is already available, it cannot be returned again.
                    if (book.availability == "Available") {
                        cout << "Book is already available.\n";
                        found = true;
                    }
                    else {

                        // Changes the availability to Available.
                        book.availability = "Available";

                        // Marks the book as found.
                        found = true;

                        // Displays a success message.
                        cout << "Book returned successfully.\n";
                    }
                }
            }

            // Writes the book information into the temporary file.
            output << book.isbn << "|"
                   << book.title << "|"
                   << book.author << "|"
                   << book.category << "|"
                   << book.availability << "\n";
        }
    }

    // Closes the input file.
    input.close();

    // Closes the temporary output file.
    output.close();

    // Deletes the old library file.
    remove("library.txt");

    // Renames the temporary file as the original library file.
    rename("temp.txt", "library.txt");

    // Displays a message if the ISBN was not found.
    if (!found) {
        cout << "Book not found.\n";
    }
}


// Function used to update book information.
void updateBook() {

    // Opens the existing library file for reading.
    ifstream input("library.txt");

    // Creates a temporary file for updated records.
    ofstream output("temp.txt");

    // Stores the ISBN to be updated.
    string isbn;

    // Takes the ISBN from the user.
    cout << "Enter ISBN of book to update: ";
    cin >> isbn;

    // Stores one line from the file.
    string line;

    // Keeps track of whether the book was found.
    bool found = false;

    // Reads every book record.
    while (getline(input, line)) {

        // Creates a Book object.
        Book book;

        // Converts the current line into a Book object.
        if (parseBook(line, book)) {

            // Checks whether the current book matches the entered ISBN.
            if (book.isbn == isbn) {

                // Clears the input buffer before using getline().
                cin.ignore();

                // Takes the new title.
                cout << "Enter new title: ";
                getline(cin, book.title);

                // Takes the new author.
                cout << "Enter new author: ";
                getline(cin, book.author);

                // Takes the new category.
                cout << "Enter new category: ";
                getline(cin, book.category);

                // Marks the book as found.
                found = true;

                // Displays a success message.
                cout << "Book updated successfully!\n";
            }

            // Writes the current or updated book to the temporary file.
            output << book.isbn << "|"
                   << book.title << "|"
                   << book.author << "|"
                   << book.category << "|"
                   << book.availability << "\n";
        }
    }

    // Closes the input file.
    input.close();

    // Closes the temporary file.
    output.close();

    // Deletes the original library file.
    remove("library.txt");

    // Renames the temporary file to library.txt.
    rename("temp.txt", "library.txt");

    // Displays a message if the book was not found.
    if (!found) {
        cout << "Book not found.\n";
    }
}


// Function used to generate an availability report.
void availabilityReport() {

    // Opens the library file for reading.
    ifstream file("library.txt");

    // Stores one line at a time.
    string line;

    // Counts available books.
    int available = 0;

    // Counts issued books.
    int issued = 0;

    // Prints the report heading.
    cout << "\n=== Availability Report ===\n";

    // Reads the file line by line.
    while (getline(file, line)) {

        // Creates a Book object.
        Book book;

        // Converts the current line into a Book object.
        if (parseBook(line, book)) {

            // Displays the book details.
            displayBook(book);

            // Checks whether the book is available.
            if (book.availability == "Available") {

                // Increases the available book count.
                available++;
            }
            else {

                // Increases the issued book count.
                issued++;
            }
        }
    }

    // Displays the total number of available books.
    cout << "Total Available Books: " << available << endl;

    // Displays the total number of issued books.
    cout << "Total Issued Books: " << issued << endl;

    // Closes the file.
    file.close();
}


// Main function.
// Program execution starts from here.
int main() {

    // Stores the user's menu choice.
    int choice;

    // do-while loop keeps showing the menu until the user chooses Exit.
    do {

        // Displays the main menu.
        cout << "\n===== Library Book Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Update Book\n";
        cout << "6. Availability Report\n";
        cout << "7. Exit\n";

        // Takes the user's choice.
        cout << "Enter your choice: ";
        cin >> choice;

        // switch selects an operation based on the user's choice.
        switch (choice) {

            // Option 1 adds a new book.
            case 1:
                addBook();
                break;

            // Option 2 searches for a book.
            case 2:
                searchBook();
                break;

            // Option 3 issues a book.
            case 3: {
                string isbn;

                cout << "Enter ISBN to issue: ";
                cin >> isbn;

                changeAvailability(isbn, "Issued");
                break;
            }

            // Option 4 returns a book.
            case 4: {
                string isbn;

                cout << "Enter ISBN to return: ";
                cin >> isbn;

                changeAvailability(isbn, "Available");
                break;
            }

            // Option 5 updates a book.
            case 5:
                updateBook();
                break;

            // Option 6 generates the availability report.
            case 6:
                availabilityReport();
                break;

            // Option 7 exits the program.
            case 7:
                cout << "Exiting Library Management System...\n";
                break;

            // Handles an invalid menu choice.
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    // Continues the loop until choice becomes 7.
    } while (choice != 7);

    // Returns 0 to indicate successful program execution.
    return 0;
}