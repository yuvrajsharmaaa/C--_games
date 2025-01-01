#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

enum Color { RED, GREEN, YELLOW, PURPLE, BLUE };

Color generateRandomColor() {
    return static_cast<Color>(rand() % 5);
}

string colorToString(Color color) {
    switch (color) {
        case RED: return "Red";
        case GREEN: return "Green";
        case YELLOW: return "Yellow";
        case PURPLE: return "Purple";
        case BLUE: return "Blue";
        default: return "Invalid Color";
    }
}

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int main() {
    srand(time(0));

    Color targetColor = generateRandomColor();

    string guess;
    cout << "Welcome to the Color Guessing Game!" << endl;

    while (true) {
        system("cls"); // Clears the screen
        cout << "Guess the color (RED, GREEN, YELLOW, PURPLE, BLUE): ";
        cin >> guess;
        guess = toLowerCase(guess);

        if (guess == "red" || guess == "green" || guess == "blue" ||
            guess == "yellow" || guess == "purple") {

            Color userColor;
            if (guess == "red") userColor = RED;
            else if (guess == "green") userColor = GREEN;
            else if (guess == "yellow") userColor = YELLOW;
            else if (guess == "purple") userColor = PURPLE;
            else if (guess == "blue") userColor = BLUE;

            if (userColor == targetColor) {
                cout << "You guessed it! The color was " << colorToString(targetColor) << "!" << endl;
                break;
            } else {
                cout << "Wrong guess. Try again!" << endl;
                Sleep(1000); // Pause for 1 second
            }
        } else {
            cout << "Invalid input. Please type a valid color name." << endl;
            Sleep(1000); // Pause for 1 second
        }
    }

    return 0;
}
