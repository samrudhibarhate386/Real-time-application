#include <iostream>     // Provides cout and endl
#include <stdexcept>    // Provides invalid_argument, overflow_error,
                        // and underflow_error
#include <string>       // Provides the string data type

using namespace std;


// ============================================================
// TEMPLATE STACK CLASS
// ============================================================

// template <typename T>
//
// This makes Stack a GENERIC class.
//
// T is a placeholder for a data type.
//
// For example:
//
// Stack<int>    -> T becomes int
// Stack<string> -> T becomes string
//
// So we can use the same Stack class for different data types.

template <typename T>
class Stack
{
private:

    // Pointer to dynamically allocated memory.
    //
    // data will point to an array that stores the stack elements.
    T* data;


    // Stores the maximum number of elements that the
    // stack can contain.
    int capacity;


    // Stores the index of the current top element.
    //
    // -1 means the stack is empty.
    int topIndex;


public:

    // ========================================================
    // CONSTRUCTOR
    // ========================================================

    // explicit prevents unwanted implicit conversion from int
    // to Stack.
    //
    // Example:
    //
    // Stack<int> stack(5);
    //
    // is allowed.
    //
    // But the compiler should not automatically convert:
    //
    // Stack<int> stack = 5;
    //
    // because the constructor is explicit.

    explicit Stack(int size)

        // Initializer list.
        //
        // capacity gets size.
        // topIndex starts at -1 because the stack is empty.

        : capacity(size),
          topIndex(-1)
    {

        // Stack size must be greater than zero.

        if (size <= 0)
        {
            // throw sends an exception.

            // invalid_argument is used when an argument
            // passed to a function/constructor is invalid.

            throw invalid_argument(
                "Stack capacity must be positive."
            );
        }


        // Dynamically create an array containing
        // 'capacity' elements of type T.
        //
        // new allocates memory during runtime.
        //
        // [] means we are creating an array.

        data = new T[capacity];
    }


    // ========================================================
    // COPY CONSTRUCTOR DISABLED
    // ========================================================

    // Normally C++ can create a copy constructor automatically.
    //
    // But this class owns dynamically allocated memory.
    //
    // Copying it directly could cause two objects to point
    // to the same memory.
    //
    // Therefore copying is disabled.

    Stack(const Stack&) = delete;


    // ========================================================
    // COPY ASSIGNMENT DISABLED
    // ========================================================

    // This disables statements such as:
    //
    // stack2 = stack1;
    //
    // because this class manages its own dynamically
    // allocated memory.

    Stack& operator=(const Stack&) = delete;


    // ========================================================
    // DESTRUCTOR
    // ========================================================

    // Destructor is automatically called when the Stack
    // object is destroyed.

    ~Stack()
    {
        // Release the dynamically allocated array.
        //
        // Since new[] was used, delete[] must be used.

        delete[] data;
    }


    // ========================================================
    // PUSH FUNCTION
    // ========================================================

    // Adds a new element to the TOP of the stack.

    void push(const T& value)
    {
        // Check whether the stack is already full.
        //
        // If capacity = 5:
        //
        // valid indexes are:
        // 0, 1, 2, 3, 4
        //
        // Therefore topIndex == capacity - 1
        // means the stack is full.

        if (topIndex == capacity - 1)
        {
            // Stack cannot accept another element.
            // Therefore throw overflow_error.

            throw overflow_error("Stack overflow.");
        }


        // ++topIndex increases topIndex FIRST.
        //
        // Suppose:
        //
        // topIndex = -1
        //
        // ++topIndex makes it:
        //
        // 0
        //
        // Then:
        //
        // data[0] = value
        //
        // So the first element goes into index 0.

        data[++topIndex] = value;
    }


    // ========================================================
    // POP FUNCTION
    // ========================================================

    // Removes and returns the TOP element of the stack.

    T pop()
    {
        // If topIndex is less than 0,
        // there is no element in the stack.

        if (topIndex < 0)
        {
            // Trying to remove an element from an empty stack
            // causes stack underflow.

            throw underflow_error("Stack underflow.");
        }


        // Return the current top element.
        //
        // topIndex-- is POST-DECREMENT.
        //
        // It means:
        //
        // 1. Use the current topIndex.
        // 2. Then decrease topIndex by 1.
        //
        // Example:
        //
        // topIndex = 2
        //
        // data[2] is returned.
        //
        // Then topIndex becomes 1.

        return data[topIndex--];
    }


    // ========================================================
    // ISEMPTY FUNCTION
    // ========================================================

    // const means this function does not modify
    // the Stack object.

    bool isEmpty() const
    {
        // If topIndex is less than 0,
        // the stack is empty.

        return topIndex < 0;
    }


    // ========================================================
    // DISPLAY FUNCTION
    // ========================================================

    // Displays stack elements from TOP to BOTTOM.

    void display() const
    {
        // Start from topIndex.
        //
        // Continue while i >= 0.
        //
        // i-- moves toward the bottom of the stack.

        for (int i = topIndex; i >= 0; i--)
        {
            // Print the element at index i.

            cout << data[i] << " ";
        }

        // Move to the next line.

        cout << endl;
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
    // Operations that may throw exceptions are placed
    // inside try.

    try
    {

        // ====================================================
        // INTEGER STACK
        // ====================================================

        // Create a Stack that stores integers.
        //
        // Stack<int>
        // means T = int.
        //
        // (5)
        // means maximum capacity is 5.

        Stack<int> integerStack(5);


        // Push 10 onto the stack.

        integerStack.push(10);


        // Push 20 onto the stack.

        integerStack.push(20);


        // Push 30 onto the stack.

        integerStack.push(30);


        // Display the integer stack.

        cout << "Integer stack: ";

        integerStack.display();


        // Pop the top element.
        //
        // Since Stack follows LIFO:
        //
        // Last In -> First Out
        //
        // 30 was inserted last,
        // so 30 will be removed first.

        cout << "Popped: "
             << integerStack.pop()
             << endl;


        // ====================================================
        // STRING STACK
        // ====================================================

        // Create a Stack that stores strings.
        //
        // Stack<string>
        // means T = string.
        //
        // Maximum capacity = 3.

        Stack<string> commandStack(3);


        // Add "Open file".

        commandStack.push("Open file");


        // Add "Edit text".

        commandStack.push("Edit text");


        // Add "Save file".

        commandStack.push("Save file");


        // Display the string stack.

        cout << "Command stack: ";

        commandStack.display();
    }


    // ========================================================
    // CATCH BLOCK
    // ========================================================

    // This catches standard exceptions.
    //
    // const
    // -> The exception object will not be modified.
    //
    // &
    // -> Pass the exception by reference.
    //
    // exception
    // -> Base class for standard C++ exceptions.
    //
    // error
    // -> Name of the exception object.

    catch (const exception& error)
    {
        // what() returns the error message.

        cout << "Error: "
             << error.what()
             << endl;
    }


    // Program finished successfully.

    return 0;
}