#include <algorithm>    // Provides sort(), min_element(), max_element()
#include <iostream>     // Provides cout and endl
#include <map>          // Provides map
#include <numeric>      // Provides accumulate()
#include <queue>        // Provides priority_queue
#include <set>          // Provides set
#include <vector>       // Provides vector

using namespace std;


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{

    // ========================================================
    // STORE STUDENT MARKS
    // ========================================================

    // vector<double>
    //
    // Creates a vector that stores decimal numbers.
    //
    // Each value represents the marks of one student.

    vector<double> marks{
        85.5,
        92.0,
        78.5,
        88.0,
        95.5,
        72.0,
        89.5,
        91.0
    };


    // ========================================================
    // CALCULATE TOTAL MARKS
    // ========================================================

    // accumulate() calculates the sum of all elements.
    //
    // marks.begin()
    // -> points to the first element.
    //
    // marks.end()
    // -> points just after the last element.
    //
    // 0.0
    // -> initial value of the total.
    //
    // Because 0.0 is a double, the result is also calculated
    // as a double.

    double total = accumulate(
        marks.begin(),
        marks.end(),
        0.0
    );


    // ========================================================
    // CALCULATE AVERAGE
    // ========================================================

    // Average = Total / Number of students.
    //
    // marks.size() returns the number of elements
    // in the vector.

    double average = total / marks.size();


    // Display the average.

    cout << "Average: "
         << average
         << endl;


    // ========================================================
    // FIND MINIMUM MARK
    // ========================================================

    // min_element() returns an iterator pointing to
    // the smallest element.
    //
    // * is used to dereference the iterator and obtain
    // the actual value.

    cout << "Minimum: "
         << *min_element(
                marks.begin(),
                marks.end()
            )
         << endl;


    // ========================================================
    // FIND MAXIMUM MARK
    // ========================================================

    // max_element() returns an iterator pointing to
    // the largest element.
    //
    // Again, * gets the actual value from the iterator.

    cout << "Maximum: "
         << *max_element(
                marks.begin(),
                marks.end()
            )
         << endl;


    // ========================================================
    // SORT MARKS
    // ========================================================

    // sort() arranges the marks in ascending order.
    //
    // Ascending means:
    //
    // smallest → largest

    sort(
        marks.begin(),
        marks.end()
    );


    // Display heading.

    cout << "\nMarks in ascending order: ";


    // ========================================================
    // DISPLAY SORTED MARKS
    // ========================================================

    // Range-based for loop.
    //
    // Each mark is taken from the vector one by one.

    for (double mark : marks)
    {
        cout << mark << " ";
    }

    cout << endl;


    // ========================================================
    // PRIORITY QUEUE FOR TOP PERFORMERS
    // ========================================================

    // priority_queue is a container adaptor.
    //
    // By default, it behaves like a MAX-HEAP.
    //
    // That means the largest element is always at the TOP.

    priority_queue<double> topPerformers(
        marks.begin(),
        marks.end()
    );


    // Display heading.

    cout << "\nTop three marks:"
         << endl;


    // ========================================================
    // DISPLAY TOP THREE MARKS
    // ========================================================

    // i = 0
    // i < 3
    // !topPerformers.empty()
    //
    // We continue while:
    //
    // 1. We have printed fewer than 3 marks.
    // 2. The priority queue is not empty.

    for (
        int i = 0;
        i < 3 && !topPerformers.empty();
        i++
    )
    {
        // top() returns the largest element currently
        // present in the priority queue.

        cout << topPerformers.top()
             << endl;


        // pop() removes the element at the top.
        //
        // This allows the next-highest mark to become
        // the new top.

        topPerformers.pop();
    }


    // ========================================================
    // CREATE SET OF UNIQUE MARKS
    // ========================================================

    // A set stores unique values.
    //
    // If duplicate values existed in marks,
    // the set would keep only one copy.
    //
    // A set also stores its values in sorted order.

    set<double> uniqueMarks(
        marks.begin(),
        marks.end()
    );


    // Display heading.

    cout << "\nUnique marks: ";


    // Display all values in the set.

    for (double mark : uniqueMarks)
    {
        cout << mark << " ";
    }

    cout << endl;


    // ========================================================
    // GRADE DISTRIBUTION
    // ========================================================

    // map<char, int>
    //
    // KEY   = grade character
    // VALUE = number of students having that grade
    //
    // Example:
    //
    // 'A' -> 3
    // 'B' -> 3
    // 'C' -> 2

    map<char, int> gradeDistribution;


    // Go through every mark.

    for (double mark : marks)
    {

        // ====================================================
        // GRADE A
        // ====================================================

        // If mark is 90 or more,
        // increase the count of grade A.

        if (mark >= 90)
        {
            gradeDistribution['A']++;
        }


        // ====================================================
        // GRADE B
        // ====================================================

        // If mark is 80 or more but less than 90,
        // increase the count of grade B.

        else if (mark >= 80)
        {
            gradeDistribution['B']++;
        }


        // ====================================================
        // GRADE C
        // ====================================================

        // If mark is 70 or more but less than 80,
        // increase the count of grade C.

        else if (mark >= 70)
        {
            gradeDistribution['C']++;
        }


        // ====================================================
        // GRADE D
        // ====================================================

        // Anything below 70 receives grade D.

        else
        {
            gradeDistribution['D']++;
        }
    }


    // ========================================================
    // DISPLAY GRADE DISTRIBUTION
    // ========================================================

    cout << "\nGrade distribution:"
         << endl;


    // Go through every key-value pair in the map.

    for (const auto& item : gradeDistribution)
    {
        // item.first
        // -> grade character
        //
        // item.second
        // -> number of students having that grade.

        cout << "Grade "
             << item.first
             << ": "
             << item.second
             << " student(s)"
             << endl;
    }


    // Program completed successfully.

    return 0;
}