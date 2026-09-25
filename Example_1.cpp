#include <iostream>
// Includes the iostream library.
// It is required for input and output.
// We use cout from this library to display output.

#include <string>
// Includes the string library.
// It allows us to use the string data type.

#include <vector>
// Includes the vector library.
// It allows us to create a vector that can store multiple objects.

using namespace std;
// Allows us to directly use names like cout, string, and vector
// without writing std:: before them.


// ----------------------------------------------------
// SOIL SENSOR CLASS
// ----------------------------------------------------

class SoilSensor
{
// Defines a class named SoilSensor.
// A class is a blueprint for creating objects.
// Each object of this class represents one soil sensor.

private:
// The private section contains data that cannot be
// directly accessed from outside the class.

    string sensorId;
    // Stores the unique ID of the sensor.
    // Example: S001

    double moistureLevel;
    // Stores the moisture level of the soil.
    // double is used because moisture can have decimal values.
    // Example: 45.2

    string timestamp;
    // Stores the time at which the sensor reading was taken.
    // Example: 08:00


public:
// The public section contains functions that can be
// accessed from outside the class.


    SoilSensor(string id, double moisture, string time)
        : sensorId(id), moistureLevel(moisture), timestamp(time)
    {
    }
    // This is the constructor of the SoilSensor class.
    // A constructor is automatically called when an object is created.
    //
    // string id       -> receives the sensor ID.
    // double moisture -> receives the moisture value.
    // string time     -> receives the time.
    //
    // sensorId(id) assigns id to sensorId.
    // moistureLevel(moisture) assigns moisture to moistureLevel.
    // timestamp(time) assigns time to timestamp.
    //
    // The part after ':' is called the member initializer list.


    void readSensor(double newMoisture, string newTime)
    {
        // This function updates the sensor reading.
        //
        // void means the function does not return a value.
        // newMoisture contains the new moisture value.
        // newTime contains the new time.

        moistureLevel = newMoisture;
        // Updates the moistureLevel with the new moisture value.

        timestamp = newTime;
        // Updates the timestamp with the new time.
    }


    void displayData() const
    {
        // This function displays the sensor information.
        //
        // const means this function will not change
        // the data stored inside the object.

        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;
        // Displays:
        // Sensor ID
        // Moisture percentage
        // Reading time
        //
        // endl moves the cursor to the next line.
    }

};
// Ends the SoilSensor class.
// The semicolon after the class is compulsory.



// ----------------------------------------------------
// MAIN FUNCTION
// ----------------------------------------------------

int main()
{
    // Program execution starts from the main() function.


    vector<SoilSensor> farmSensors;
    // Creates a vector named farmSensors.
    //
    // vector<SoilSensor> means this vector will store
    // objects of the SoilSensor class.
    //
    // Initially, the vector is empty.


    farmSensors.emplace_back("S001", 45.2, "08:00");
    // Adds the first SoilSensor object to the vector.
    //
    // Sensor ID     = S001
    // Moisture      = 45.2%
    // Time          = 08:00
    //
    // emplace_back() creates and adds the object
    // directly inside the vector.


    farmSensors.emplace_back("S002", 52.8, "08:00");
    // Adds the second SoilSensor object.
    //
    // Sensor ID     = S002
    // Moisture      = 52.8%
    // Time          = 08:00


    farmSensors.emplace_back("S003", 38.5, "08:00");
    // Adds the third SoilSensor object.
    //
    // Sensor ID     = S003
    // Moisture      = 38.5%
    // Time          = 08:00


    cout << "=== Morning Sensor Readings ===" << endl;
    // Prints the heading:
    //
    // === Morning Sensor Readings ===
    //
    // endl moves the cursor to the next line.


    for (const auto& sensor : farmSensors)
    {
        // This is a range-based for loop.
        //
        // It goes through every object stored in farmSensors.
        //
        // const -> prevents modification of the object.
        // auto  -> C++ automatically determines the data type.
        // &     -> accesses the object by reference.
        // sensor -> represents the current sensor object.
        // farmSensors -> the vector being traversed.


        sensor.displayData();
        // Calls displayData() for the current sensor.
        //
        // It displays the ID, moisture level, and time.
    }


    farmSensors[0].readSensor(47.5, "09:00");
    // Updates the first sensor in the vector.
    //
    // Vector indexing starts from 0.
    //
    // farmSensors[0] = first sensor = S001
    //
    // New moisture = 47.5%
    // New time     = 09:00


    cout << "\n=== Updated Reading ===" << endl;
    // \n creates a blank line before the heading.
    //
    // Prints:
    // === Updated Reading ===


    farmSensors[0].displayData();
    // Displays the updated information of the first sensor.
    //
    // S001 will now show:
    // Moisture = 47.5%
    // Time     = 09:00


    return 0;
    // Ends the main() function successfully.
}