#include <iostream>     // Provides cout and endl
#include <string>       // Provides the string data type
#include <vector>       // Provides the vector container

using namespace std;


// ============================================================
// FUNCTION TEMPLATE: sortItems()
// ============================================================

// template <typename T>
// means this function is a TEMPLATE.
//
// T is a placeholder for a data type.
//
// The same function can work with:
// int
// double
// string
// and other suitable data types.
//
// When we call:
// sortItems(ids)
// T becomes int.
//
// When we call:
// sortItems(scores)
// T becomes double.
//
// When we call:
// sortItems(cities)
// T becomes string.

template <typename T>
void sortItems(vector<T>& values)
{
    // values.size() gives the total number of elements
    // in the vector.
    //
    // size_t is an unsigned integer type commonly used
    // for sizes and indexes.

    // Outer loop.
    //
    // i starts from 0.
    //
    // i < values.size()
    // means continue until i reaches the number of elements.
    //
    // i++ increases i by 1 after every iteration.

    for (size_t i = 0; i < values.size(); i++)
    {

        // Inner loop starts from the element AFTER i.
        //
        // i + 1 means we compare the current element with
        // the elements that come after it.

        for (size_t j = i + 1; j < values.size(); j++)
        {

            // Compare the current element at index j
            // with the element at index i.
            //
            // values[j] < values[i]
            //
            // If the later element is smaller, we need
            // to exchange their positions.

            if (values[j] < values[i])
            {

                // Temporary variable used for swapping.
                //
                // T means the same data type as the vector.
                //
                // If T = int:
                //     T temp becomes int temp
                //
                // If T = double:
                //     T temp becomes double temp
                //
                // If T = string:
                //     T temp becomes string temp.

                T temp = values[i];


                // Put the smaller value into position i.
                values[i] = values[j];


                // Put the original value of position i
                // into position j.
                values[j] = temp;
            }
        }
    }
}


// ============================================================
// FUNCTION TEMPLATE: displayItems()
// ============================================================

// This is another function template.
//
// It can display vectors containing different data types.
//
// const vector<T>& values
//
// const
// -> The function cannot modify the vector.
//
// vector<T>
// -> Vector containing elements of type T.
//
// &
// -> values is passed by reference, so a copy of the
//    entire vector is not created.

template <typename T>
void displayItems(const vector<T>& values)
{

    // Range-based for loop.
    //
    // It automatically goes through every element
    // in the vector.

    for (const auto& value : values)
    {
        // auto automatically determines the data type
        // of value.
        //
        // const means we won't modify value.
        //
        // & means value refers directly to the existing
        // element instead of making a copy.

        cout << value << " ";
    }

    // Move to the next line after displaying all elements.
    cout << endl;
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{

    // ========================================================
    // INTEGER VECTOR
    // ========================================================

    // vector<int>
    // means this vector stores integer values.

    vector<int> ids{
        64, 34, 25, 12, 22, 11, 90
    };


    // ========================================================
    // DOUBLE VECTOR
    // ========================================================

    // vector<double>
    // means this vector stores decimal values.

    vector<double> scores{
        3.14, 2.71, 1.41, 9.99, 0.50
    };


    // ========================================================
    // STRING VECTOR
    // ========================================================

    // vector<string>
    // means this vector stores strings.

    vector<string> cities{
        "Pune",
        "Mumbai",
        "Nashik",
        "Aurangabad"
    };


    // ========================================================
    // SORT INTEGER IDs
    // ========================================================

    cout << "Integer IDs before sorting: ";

    // Display the integer vector before sorting.
    displayItems(ids);


    // Call the template sorting function.
    //
    // Here:
    //
    // T = int
    //
    // So sortItems() works with vector<int>.

    sortItems(ids);


    cout << "Integer IDs after sorting: ";

    // Display the sorted integer vector.
    displayItems(ids);


    // ========================================================
    // SORT DOUBLE SCORES
    // ========================================================

    cout << "Scores before sorting: ";

    // Display scores before sorting.
    displayItems(scores);


    // Here T becomes double.
    sortItems(scores);


    cout << "Scores after sorting: ";

    // Display sorted scores.
    displayItems(scores);


    // ========================================================
    // SORT CITIES
    // ========================================================

    cout << "Cities before sorting: ";

    // Display cities before sorting.
    displayItems(cities);


    // Here T becomes string.
    //
    // Strings can be compared using <,
    // so they are sorted alphabetically.

    sortItems(cities);


    cout << "Cities after sorting: ";

    // Display sorted cities.
    displayItems(cities);


    // Indicate successful program completion.
    return 0;
}