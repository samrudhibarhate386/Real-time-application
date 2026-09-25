#include <iostream>
// Includes the iostream library.
// It is used for input and output operations such as cout.

#include <string>
// Includes the string library.
// It allows us to use the string data type.

using namespace std;
// Allows us to use cout and string directly
// without writing std:: before them.


// ----------------------------------------------------
// PRODUCT CLASS
// ----------------------------------------------------

class Product
{
// Defines a class named Product.
// This class represents a product in a product catalog.

private:
// The private section contains data that can only
// be directly accessed inside the Product class.

    int productId;
    // Stores the unique ID of the product.
    // Example: 1001

    string productName;
    // Stores the name of the product.
    // Example: Laptop

    double price;
    // Stores the price of the product.
    // double is used because the price can contain decimals.

    int stockQuantity;
    // Stores the number of products currently available in stock.

    static int totalProducts;
    // A static data member.
    //
    // It is shared by all Product objects.
    // There is only ONE copy of totalProducts
    // for the entire Product class.
    //
    // It keeps track of how many Product objects currently exist.


public:
// The public section contains functions that can be
// accessed from outside the class.


    Product(int id, string name, double p, int stock)
        : productId(id), productName(name), price(p), stockQuantity(stock)
    {
        // This is the constructor of the Product class.
        //
        // It is automatically called when a Product object is created.
        //
        // id    -> product ID
        // name  -> product name
        // p     -> product price
        // stock -> stock quantity


        totalProducts++;
        // Increases totalProducts by 1.
        //
        // Every time a new Product object is created,
        // the total number of products increases.
    }


    inline int getId() const
    {
        return productId;
    }
    // inline function that returns the product ID.
    //
    // inline suggests that the compiler may replace
    // the function call with the function code.
    //
    // const means the function will not modify the object.


    inline string getName() const
    {
        return productName;
    }
    // Returns the product name.
    //
    // const means this function does not modify
    // the Product object.


    inline double getPrice() const
    {
        return price;
    }
    // Returns the product price.
    //
    // double is used because the price may contain decimals.


    void updateStock(int quantity)
    {
        // Function used to update the stock quantity.
        //
        // quantity contains the new stock value.


        stockQuantity = quantity;
        // Replaces the old stock quantity
        // with the new quantity.
    }


    static int getTotalProducts()
    {
        // Static member function.
        //
        // It belongs to the Product class rather than
        // to one particular Product object.


        return totalProducts;
        // Returns the current value of totalProducts.
    }


    void display() const
    {
        // Displays all the important information
        // about the product.
        //
        // const means this function does not modify
        // the Product object.


        cout << "ID: " << productId
             << " | Product: " << productName
             << " | Price: Rs. " << price
             << " | Stock: " << stockQuantity << endl;

        // Displays:
        // Product ID
        // Product name
        // Product price
        // Stock quantity
        //
        // endl moves the cursor to the next line.
    }


    ~Product()
    {
        // This is the destructor of the Product class.
        //
        // A destructor is automatically called when
        // a Product object is destroyed.


        totalProducts--;
        // Decreases totalProducts by 1
        // when a Product object is destroyed.
    }

};
// Ends the Product class.
// The semicolon after the class is compulsory.



// ----------------------------------------------------
// STATIC DATA MEMBER DEFINITION
// ----------------------------------------------------

int Product::totalProducts = 0;
// Defines and initializes the static data member.
//
// Product::totalProducts means:
// totalProducts belongs to the Product class.
//
// It starts with a value of 0.
//
// This definition is required because
// static data members need to be defined outside the class.



// ----------------------------------------------------
// MAIN FUNCTION
// ----------------------------------------------------

int main()
{
    // Program execution starts from main().


    Product p1(1001, "Laptop", 55000, 15);
    // Creates the first Product object named p1.
    //
    // Product ID     = 1001
    // Product Name   = Laptop
    // Price          = 55000
    // Stock Quantity = 15
    //
    // Constructor is called.
    // totalProducts becomes 1.


    Product p2(1002, "Mouse", 450, 50);
    // Creates the second Product object named p2.
    //
    // Product ID     = 1002
    // Product Name   = Mouse
    // Price          = 450
    // Stock Quantity = 50
    //
    // totalProducts becomes 2.


    Product p3(1003, "Keyboard", 1200, 30);
    // Creates the third Product object named p3.
    //
    // Product ID     = 1003
    // Product Name   = Keyboard
    // Price          = 1200
    // Stock Quantity = 30
    //
    // totalProducts becomes 3.


    cout << "=== Product Catalog ===" << endl;
    // Displays the heading:
    //
    // === Product Catalog ===


    p1.display();
    // Displays information about the Laptop.


    p2.display();
    // Displays information about the Mouse.


    p3.display();
    // Displays information about the Keyboard.


    cout << "\nTotal Products in Catalog: "
         << Product::getTotalProducts() << endl;
    // \n creates a blank line.
    //
    // Product::getTotalProducts()
    // calls the static function using the class name.
    //
    // It returns the current value of totalProducts.
    //
    // At this point:
    // totalProducts = 3.


    return 0;
    // Ends the program successfully.
}