#include <cstring>
// #include = tells the compiler to include a library
// <cstring> = C-style string library
// It provides functions for working with character arrays.
// In this particular program, the library is not actually
// required for the current code, but it can be included.


#include <fstream>
// <fstream> = file stream library
// Used for reading from and writing to files.
//
// ofstream -> writing to a file
// ifstream -> reading from a file


#include <iostream>
// <iostream> = input/output library
// Provides cout, cerr, endl, etc.


using namespace std;
// Allows us to write cout, ifstream, ofstream, etc.
// instead of std::cout, std::ifstream, std::ofstream, etc.



struct ImageMetadata
// struct = keyword used to create a structure
// ImageMetadata = name of the structure
{
    int width;
    // int = integer data type
    // width = stores image width in pixels


    int height;
    // int = integer data type
    // height = stores image height in pixels


    char format[10];
    // char = character data type
    //
    // format = character array
    //
    // [10] = can store up to 10 characters
    // including the '\0' string terminator.
    //
    // Examples:
    // "PNG"
    // "JPEG"
};



int main()
{
    // main() = starting point of the program


    ImageMetadata image1{1920, 1080, "PNG"};
    // Creates an ImageMetadata object called image1.
    //
    // width  = 1920
    // height = 1080
    // format = "PNG"
    //
    // {} = initializes the structure members
    // in their declared order.


    ImageMetadata image2{1280, 720, "JPEG"};
    // Creates image2.
    //
    // width  = 1280
    // height = 720
    // format = "JPEG"


    ImageMetadata image3{3840, 2160, "PNG"};
    // Creates image3.
    //
    // width  = 3840
    // height = 2160
    // format = "PNG"



    ofstream output("images.bin", ios::binary);
    // ofstream = output file stream
    // Used to WRITE into a file.
    //
    // output = name of the file stream object
    //
    // "images.bin" = binary file name
    //
    // ios::binary = opens the file in BINARY mode.
    //
    // Binary mode means data is stored as raw bytes
    // rather than normal human-readable text.



    if (!output)
    {
        // Checks whether the file was opened successfully.
        //
        // !output means the file stream is not valid.


        cerr << "Unable to open binary file for writing."
             << endl;
        // cerr = standard error output
        //
        // Displays an error message.


        return 1;
        // Ends the program with an error status.
    }



    output.write(
        reinterpret_cast<const char*>(&image1),
        sizeof(ImageMetadata)
    );
    // write() writes raw bytes into the file.
    //
    // &image1
    // & = address-of operator
    //
    // It gives the memory address of image1.
    //
    // reinterpret_cast<const char*>
    // converts that memory address into a character pointer.
    //
    // Why?
    // write() works with a sequence of bytes,
    // so we provide the address as a char pointer.
    //
    // sizeof(ImageMetadata)
    // tells C++ how many bytes should be written.
    //
    // Therefore this line writes the complete image1
    // structure into the binary file.



    output.write(
        reinterpret_cast<const char*>(&image2),
        sizeof(ImageMetadata)
    );
    // Writes image2 into the binary file.
    //
    // Again:
    // address of image2
    // converted to const char*
    // and sizeof(ImageMetadata) bytes are written.



    output.write(
        reinterpret_cast<const char*>(&image3),
        sizeof(ImageMetadata)
    );
    // Writes image3 into the binary file.



    output.close();
    // close() closes the binary file.
    //
    // We have finished writing.



    ifstream input("images.bin", ios::binary);
    // ifstream = input file stream
    // Used to READ from a file.
    //
    // input = name of the input stream object
    //
    // "images.bin" = file we want to read.
    //
    // ios::binary = read the file in binary mode.



    if (!input)
    {
        // Checks whether the file opened successfully.


        cerr << "Unable to open binary file for reading."
             << endl;
        // Prints an error message.


        return 1;
        // Ends the program because of an error.
    }



    ImageMetadata item{};
    // Creates an ImageMetadata object named item.
    //
    // {} = value-initializes the object.
    //
    // Initially:
    //
    // width = 0
    // height = 0
    // format = empty



    int recordNo = 1;
    // Creates an integer called recordNo.
    //
    // It keeps track of which record
    // we are currently displaying.
    //
    // Starts at 1.



    cout << "=== Image Metadata ===" << endl;
    // Prints the heading.



    while (
        input.read(
            reinterpret_cast<char*>(&item),
            sizeof(ImageMetadata)
        )
    )
    {
        // while = repeats as long as the condition is true.
        //
        // input.read()
        // reads raw bytes from the binary file.
        //
        // reinterpret_cast<char*>(&item)
        // gives read() the memory address where
        // the bytes should be placed.
        //
        // sizeof(ImageMetadata)
        // tells read() how many bytes to read.
        //
        // Each successful read fills the 'item' object
        // with one ImageMetadata record.
        //
        // The loop stops when there are no more complete
        // records to read.



        cout << "Record " << recordNo++ << ": "
             << item.width << " x " << item.height
             << " | " << item.format << endl;

        // cout = prints output
        //
        // "Record " = text
        //
        // recordNo++ = prints the current record number
        // and then increases it by 1.
        //
        // Example:
        // First time -> prints 1
        // Then recordNo becomes 2
        //
        // item.width = image width
        //
        // " x " = displays x between width and height
        //
        // item.height = image height
        //
        // item.format = image format
        //
        // endl = moves to the next line.
    }



    return 0;
    // Program finished successfully.
}