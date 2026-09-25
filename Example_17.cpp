#include <algorithm>    // Provides sort()
#include <iostream>     // Provides cout and endl
#include <map>          // Provides map
#include <string>       // Provides string
#include <utility>      // Provides pair
#include <vector>       // Provides vector

using namespace std;


// ============================================================
// LOG ENTRY STRUCTURE
// ============================================================

// A struct is used to group related data together.
//
// Each LogEntry represents one request in the server log.

struct LogEntry
{
    // Stores the IP address of the client.

    string ip;


    // Stores the HTTP request made by the client.

    string request;
};


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{

    // ========================================================
    // CREATE VECTOR OF LOG ENTRIES
    // ========================================================

    // vector<LogEntry>
    //
    // means the vector stores LogEntry objects.

    vector<LogEntry> logs
    {
        {"192.168.1.1", "GET /index.html"},
        {"192.168.1.2", "POST /api/data"},
        {"192.168.1.1", "GET /about.html"},
        {"192.168.1.3", "GET /contact.html"},
        {"192.168.1.1", "GET /products.html"},
        {"192.168.1.2", "GET /api/users"},
        {"192.168.1.1", "POST /api/order"},
        {"192.168.1.4", "GET /index.html"},
        {"192.168.1.1", "GET /services.html"},
        {"192.168.1.2", "GET /api/products"}
    };


    // ========================================================
    // COUNT REQUESTS FOR EACH IP ADDRESS
    // ========================================================

    // map<string, int>
    //
    // KEY   = IP address
    // VALUE = number of requests from that IP
    //
    // Example:
    //
    // "192.168.1.1" -> 5
    // "192.168.1.2" -> 3
    // "192.168.1.3" -> 1
    // "192.168.1.4" -> 1

    map<string, int> requestCount;


    // Go through every LogEntry in the logs vector.

    for (const auto& entry : logs)
    {
        // entry.ip gives the IP address of the current log.
        //
        // requestCount[entry.ip]
        // accesses the count associated with that IP.
        //
        // ++ increases that count by 1.
        //
        // So every time an IP appears, its count increases.

        requestCount[entry.ip]++;
    }


    // ========================================================
    // CONVERT MAP INTO VECTOR OF PAIRS
    // ========================================================

    // A map is automatically sorted by its KEY.
    //
    // But we want to sort according to the REQUEST COUNT.
    //
    // Therefore we copy the map elements into a vector.
    //
    // pair<string, int>
    //
    // first  = IP address
    // second = request count

    vector<pair<string, int>> ranked(
        requestCount.begin(),
        requestCount.end()
    );


    // ========================================================
    // SORT BY REQUEST COUNT
    // ========================================================

    // sort() sorts the elements inside ranked.
    //
    // ranked.begin()
    // -> first element
    //
    // ranked.end()
    // -> position just after the last element
    //
    // The lambda function tells sort() how to compare
    // two pairs.

    sort(
        ranked.begin(),
        ranked.end(),

        // ====================================================
        // LAMBDA FUNCTION
        // ====================================================

        // auto automatically determines the type.
        //
        // first  -> first pair
        // second -> second pair
        //
        // const& means the pairs are passed by reference
        // without modifying them.

        [](const auto& first, const auto& second)
        {

            // first.second contains the request count
            // of the first IP.
            //
            // second.second contains the request count
            // of the second IP.
            //
            // > means greater than.
            //
            // Therefore larger request counts come first.

            return first.second > second.second;
        }
    );


    // ========================================================
    // DISPLAY RESULT
    // ========================================================

    cout << "=== Request Count by IP Address ==="
         << endl;


    // Go through every pair in the sorted vector.

    for (const auto& item : ranked)
    {
        // item.first
        // -> IP address
        //
        // item.second
        // -> request count

        cout << item.first
             << " : "
             << item.second
             << " requests"
             << endl;
    }


    // Program completed successfully.

    return 0;
}