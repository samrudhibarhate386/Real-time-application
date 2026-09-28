//Mini Project

#include <iostream>  // Includes the input/output stream library for cout and endl.
#include <memory>    // Includes smart pointers such as unique_ptr and make_unique.
#include <string>    // Includes the string data type.
#include <vector>    // Includes the vector container.
using namespace std; // Allows us to use cout, string, vector, etc. without writing std::.

// Base class representing general media.
class Media {  // Defines a class named Media.

protected:  // Protected members can be accessed by this class and its derived classes.
    string title;  // Stores the title of the media item.

public:  // Public members can be accessed from outside the class.

    // Constructor of the Media class.
    Media(string t) : title(t) {}  // Initializes title with the value of t.

    // Virtual function to play the media.
    virtual void play() const {
        cout << "Playing media: " << title << endl;  // Displays the media title.
    }

    // Virtual function to pause the media.
    virtual void pause() const {
        cout << "Pausing media: " << title << endl;  // Displays the pause message.
    }

    // Virtual function to stop the media.
    virtual void stop() const {
        cout << "Stopping media: " << title << endl;  // Displays the stop message.
    }

    // Virtual function to display media details.
    virtual void showDetails() const {
        cout << "Media Title: " << title << endl;  // Displays the title of the media.
    }

    // Virtual destructor.
    virtual ~Media() = default;  // Allows proper destruction of derived objects.
};


// Derived class representing audio media.
class Audio : public Media {  // Audio publicly inherits from Media.

private:  // Private members can only be accessed inside the Audio class.
    string artist;  // Stores the name of the artist.

public:  // Public members can be accessed from outside the class.

    // Constructor of Audio.
    Audio(string t, string a)
        : Media(t), artist(a) {}  // Calls Media constructor and initializes artist.

    // Overrides the play() function of Media.
    void play() const override {
        cout << "Playing audio: " << title
             << " by " << artist << endl;  // Displays audio information.
    }

    // Overrides the pause() function of Media.
    void pause() const override {
        cout << "Audio paused: " << title << endl;  // Displays the pause message.
    }

    // Overrides the stop() function of Media.
    void stop() const override {
        cout << "Audio stopped: " << title << endl;  // Displays the stop message.
    }

    // Overrides the showDetails() function.
    void showDetails() const override {
        cout << "Audio | Title: " << title
             << " | Artist: " << artist << endl;  // Displays audio details.
    }
};


// Derived class representing video media.
class Video : public Media {  // Video publicly inherits from Media.

private:  // Private members of Video.
    int duration;  // Stores video duration in minutes.

public:  // Public members of Video.

    // Constructor of Video.
    Video(string t, int d)
        : Media(t), duration(d) {}  // Calls Media constructor and initializes duration.

    // Overrides the play() function.
    void play() const override {
        cout << "Playing video: " << title
             << " (" << duration << " minutes)" << endl;  // Displays video information.
    }

    // Overrides the pause() function.
    void pause() const override {
        cout << "Video paused: " << title << endl;  // Displays the pause message.
    }

    // Overrides the stop() function.
    void stop() const override {
        cout << "Video stopped: " << title << endl;  // Displays the stop message.
    }

    // Overrides the showDetails() function.
    void showDetails() const override {
        cout << "Video | Title: " << title
             << " | Duration: " << duration
             << " minutes" << endl;  // Displays video details.
    }
};


// Derived class representing image media.
class Image : public Media {  // Image publicly inherits from Media.

private:  // Private members of Image.
    string resolution;  // Stores the image resolution.

public:  // Public members of Image.

    // Constructor of Image.
    Image(string t, string r)
        : Media(t), resolution(r) {}  // Calls Media constructor and initializes resolution.

    // Overrides the play() function.
    void play() const override {
        cout << "Displaying image: " << title << endl;  // Displays the image.
    }

    // Overrides the pause() function.
    void pause() const override {
        cout << "Image pause operation: " << title << endl;  // Displays pause message.
    }

    // Overrides the stop() function.
    void stop() const override {
        cout << "Image closed: " << title << endl;  // Displays the stop/close message.
    }

    // Overrides the showDetails() function.
    void showDetails() const override {
        cout << "Image | Title: " << title
             << " | Resolution: " << resolution << endl;  // Displays image details.
    }
};


// Main function.
// Program execution starts from here.
int main() {

    // Creates a vector containing unique pointers to Media objects.
    // It can store objects of Media and its derived classes.
    vector<unique_ptr<Media>> mediaCollection;

    // Creates an Audio object and adds it to the collection.
    mediaCollection.push_back(
        make_unique<Audio>(
            "Shape of You",       // Audio title.
            "Ed Sheeran"          // Artist name.
        )
    );

    // Creates a Video object and adds it to the collection.
    mediaCollection.push_back(
        make_unique<Video>(
            "C++ Tutorial",       // Video title.
            45                    // Duration in minutes.
        )
    );

    // Creates an Image object and adds it to the collection.
    mediaCollection.push_back(
        make_unique<Image>(
            "College Memories",   // Image title.
            "1920x1080"           // Image resolution.
        )
    );

    // Prints the main heading.
    cout << "=== Media Player ===" << endl;

    // Range-based for loop to access every media item.
    for (const auto& media : mediaCollection) {

        // Displays the details of the current media item.
        media->showDetails();

        // Calls the appropriate play() function.
        // Because play() is virtual, the derived class version is called.
        media->play();

        // Calls the appropriate pause() function.
        media->pause();

        // Calls the appropriate stop() function.
        media->stop();

        // Prints an empty line between media items.
        cout << endl;
    }

    // Returns 0 to indicate successful program execution.
    return 0;
}