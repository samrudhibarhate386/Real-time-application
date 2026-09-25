#include <iostream>     // #include tells the compiler to include a library
                        // <iostream> provides input/output functions
                        // such as cout and endl

#include <memory>       // <memory> provides smart pointers
                        // such as unique_ptr and make_unique

#include <vector>       // <vector> provides the vector container
                        // which can store multiple values/objects

using namespace std;    // Allows us to use cout, vector, etc.
                        // without writing std:: before them



// ============================================================
// BASE CLASS: Shape
// ============================================================

class Shape             // class is used to create a class
{                       // { starts the body of the class

public:                 // public members can be accessed from outside
                        // the class


    // Pure virtual function for calculating area
    virtual double area() const = 0;

    // virtual
    // Means this function can be overridden by child classes

    // double
    // Means the function returns a decimal number

    // area()
    // Function name

    // const
    // Means this function will not modify the object

    // = 0
    // Makes this a PURE VIRTUAL FUNCTION

    // Because Shape contains pure virtual functions,
    // Shape becomes an ABSTRACT CLASS.



    // Pure virtual function for drawing the shape
    virtual void draw() const = 0;

    // virtual -> allows overriding
    // void -> function does not return a value
    // draw() -> function name
    // const -> does not modify the object
    // = 0 -> pure virtual function



    // Virtual destructor
    virtual ~Shape() = default;

    // ~Shape()
    // This is the destructor of Shape

    // virtual
    // Makes the destructor work correctly with inheritance

    // = default
    // Tells C++ to use the automatically generated destructor
};



// ============================================================
// DERIVED CLASS: Circle
// ============================================================

class Circle : public Shape

// class
// Creates a new class

// Circle
// Name of the new class

// :
// Used to specify inheritance

// public Shape
// Circle publicly inherits from Shape

// Therefore Circle is a type of Shape

{
private:                // private members can only be accessed
                        // directly inside the Circle class

    double radius;      // Stores the radius of the circle

                        // double is used because radius can contain
                        // decimal values


public:                 // Members below this line can be accessed
                        // from outside the class


    // Constructor of Circle
    explicit Circle(double r)
        : radius(r)
    {
    }

    // explicit
    // Prevents unwanted automatic conversion

    // Circle
    // Constructor has the same name as the class

    // double r
    // Receives the radius value

    // :
    // Starts the constructor initializer list

    // radius(r)
    // Initializes the data member radius using r



    // Override the area() function from Shape
    double area() const override
    {
        // double
        // Function returns a decimal value

        // area()
        // Name of the function

        // const
        // Function does not modify Circle

        // override
        // Tells the compiler that we are overriding
        // the parent's virtual function


        return 3.14159265359 * radius * radius;

        // return
        // Sends a value back from the function

        // 3.14159265359
        // Value of PI

        // radius * radius
        // radius squared

        // Formula:
        // Area = PI × radius × radius
    }



    // Override the draw() function from Shape
    void draw() const override
    {
        // void
        // Function does not return a value

        // draw()
        // Function name

        // const
        // Does not modify the Circle

        // override
        // Overrides Shape's draw() function


        cout << "Drawing circle with radius "
             << radius
             << endl;

        // cout
        // Used to display output

        // <<
        // Insertion operator
        // Sends data to cout

        // "Drawing circle with radius "
        // Text that will be displayed

        // radius
        // Displays the circle's radius

        // endl
        // Moves the cursor to the next line
    }
};



// ============================================================
// DERIVED CLASS: Rectangle
// ============================================================

class Rectangle : public Shape

// Rectangle inherits from Shape

{
private:

    double length;      // Stores the length of rectangle

    double width;       // Stores the width of rectangle


public:


    // Constructor of Rectangle
    Rectangle(double l, double w)
        : length(l), width(w)
    {
    }

    // Rectangle
    // Constructor name

    // double l
    // Receives length

    // double w
    // Receives width

    // length(l)
    // Initializes length

    // width(w)
    // Initializes width



    // Override area() from Shape
    double area() const override
    {
        return length * width;

        // Formula for rectangle:
        //
        // Area = Length × Width
    }



    // Override draw() from Shape
    void draw() const override
    {
        cout << "Drawing rectangle "
             << length
             << " x "
             << width
             << endl;

        // cout -> displays output
        // << -> sends data to cout
        // length -> displays rectangle length
        // " x " -> displays x between length and width
        // width -> displays rectangle width
        // endl -> moves to next line
    }
};



// ============================================================
// DERIVED CLASS: Triangle
// ============================================================

class Triangle : public Shape

// Triangle publicly inherits from Shape

{
private:

    double base;        // Stores the base of triangle

    double height;      // Stores the height of triangle


public:


    // Constructor of Triangle
    Triangle(double b, double h)
        : base(b), height(h)
    {
    }

    // Triangle -> constructor name
    // double b -> receives base
    // double h -> receives height
    // base(b) -> initializes base
    // height(h) -> initializes height



    // Override area() from Shape
    double area() const override
    {
        return 0.5 * base * height;

        // Formula for triangle:
        //
        // Area = 1/2 × Base × Height
        //
        // 0.5 represents 1/2
    }



    // Override draw() from Shape
    void draw() const override
    {
        cout << "Drawing triangle with base "
             << base
             << " and height "
             << height
             << endl;

        // cout -> displays output
        // << -> sends values to cout
        // base -> displays triangle's base
        // height -> displays triangle's height
        // endl -> moves to next line
    }
};



// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    // main()
    // Program execution starts here


    // Create a vector of smart pointers to Shape objects
    vector<unique_ptr<Shape>> shapes;

    // vector
    // Container used to store multiple elements

    // unique_ptr
    // Smart pointer that automatically manages memory

    // <Shape>
    // The smart pointer points to Shape objects

    // shapes
    // Name of the vector

    // Therefore:
    //
    // vector<unique_ptr<Shape>> shapes;
    //
    // means:
    // "Create a vector that stores smart pointers
    //  to Shape objects."



    // ========================================================
    // ADD CIRCLE
    // ========================================================

    shapes.push_back(make_unique<Circle>(5.0));

    // make_unique<Circle>(5.0)
    // Creates a Circle object with radius 5.0

    // unique_ptr automatically manages this Circle object

    // push_back()
    // Adds the object/pointer to the vector

    // So the vector now contains:
    //
    // Circle
    // radius = 5.0



    // ========================================================
    // ADD RECTANGLE
    // ========================================================

    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));

    // Creates a Rectangle object

    // 4.0 -> length
    // 6.0 -> width

    // push_back()
    // Adds the Rectangle to the vector



    // ========================================================
    // ADD TRIANGLE
    // ========================================================

    shapes.push_back(make_unique<Triangle>(3.0, 8.0));

    // Creates a Triangle object

    // 3.0 -> base
    // 8.0 -> height

    // push_back()
    // Adds the Triangle to the vector



    // Display heading
    cout << "=== CAD Shape System ===" << endl;

    // cout
    // Displays text

    // << 
    // Sends text to cout

    // endl
    // Moves to the next line



    // ========================================================
    // LOOP THROUGH ALL SHAPES
    // ========================================================

    for (const auto& shape : shapes)
    {
        // for
        // Starts a loop

        // const
        // We do not modify the current vector element

        // auto
        // C++ automatically determines the variable's type

        // &
        // Creates a reference instead of making a copy

        // shape
        // Name of the current element

        // :
        // Means "from"

        // shapes
        // The vector we are going through

        // In simple English:
        //
        // "For every shape inside shapes..."



        // Call draw()
        shape->draw();

        // shape
        // Current smart pointer

        // ->
        // Used to access a member/function through a pointer

        // draw()
        // Calls the draw function

        // Because draw() is virtual,
        // C++ calls the correct derived-class version.
        //
        // Circle    -> Circle::draw()
        // Rectangle -> Rectangle::draw()
        // Triangle  -> Triangle::draw()



        // Display area
        cout << "Area: "
             << shape->area()
             << " square units"
             << endl;

        // "Area: "
        // Displays the word Area

        // shape->area()
        // Calls the correct area() function

        // Circle:
        // 3.14159265359 × radius × radius

        // Rectangle:
        // length × width

        // Triangle:
        // 0.5 × base × height

        // " square units"
        // Displays the unit after the calculated area

        // endl
        // Moves to the next line
    }


    // Successful program termination
    return 0;

    // return 0
    // Sends 0 back to the operating system
    // 0 generally means the program completed successfully
}