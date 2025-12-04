#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h> // For colors and sleep
using namespace std;

// Function to set console color easily
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to print line slowly (animation)
void typeWriter(string text, int speed = 20) {
    for (char c : text) {
        cout << c;
        Sleep(speed);
    }
    cout << endl;
}

int main() {
    system("cls");
    srand(time(0));

    setColor(11);
    cout << "\n==============================================\n";
    setColor(14);
    typeWriter("           WHATS YOUR MOOD   ", 15);
    setColor(11);
    cout << "==============================================\n\n";

    setColor(10);
    cout << " Enter your current mood ";
    setColor(15);
    cout << "(happy / sad / angry / confused / motivated): ";

    string mood;
    getline(cin, mood);

    string quotes[5][5] = {
        // Happy
        {
            "Keep smiling, the world needs your light!",
            "Happiness looks good on you :)",
            "You are a walking sunshine today!",
            "Stay happy, stay blessed!",
            "Your smile can make someone's day!"
        },
        // Sad
        {
            "It is okay to feel sad. Even the sun takes a break at night.",
            "Tough times never last, but tough people do.",
            "Crying does not mean you are weak—it means you are human.",
            "Remember, no storm lasts forever.",
            "Every pain makes you stronger!"
        },
        // Angry
        {
            "Take a deep breath. Let go of what you cannot control.",
            "Anger is just energy — use it to create, not destroy.",
            "You cannot calm the storm, so stop trying. Calm yourself.",
            "Stay silent when angry, it saves a thousand regrets.",
            "Patience is not weakness, it is power."
        },
        // Confused
        {
            "It is okay not to have all the answers yet.",
            "Confusion is the beginning of clarity.",
            "Sometimes being lost is how you find your path.",
            "Take a pause. The answers will come.",
            "Even Google takes time to search!"
        },
        // Motivated
        {
            "Dream big, work hard, stay humble.",
            "Your future depends on what you do today!",
            "Success starts with the first step.",
            "dont watch the clock—do what it does: keep going.",
            "Push yourself, because no one else will."
        }
    };

    int index = -1;
    if (mood == "happy") index = 0;
    else if (mood == "sad") index = 1;
    else if (mood == "angry") index = 2;
    else if (mood == "confused") index = 3;
    else if (mood == "motivated") index = 4;
    else {
        setColor(12);
        typeWriter("\n Sorry, I dont recognize that mood. Try again!", 25);
        setColor(7);
        return 0;
    }

    int randomIndex = rand() % 5;

    setColor(13);
    cout << "\n Quote for your mood:\n";
    setColor(10);
    typeWriter(" \"" + quotes[index][randomIndex] + "\"", 30);

    setColor(11);
    cout << "\n----------------------------------------------\n";
    setColor(14);
    typeWriter("        Made with in C++ by FCODE TEAM", 20);
    setColor(11);
    cout << "----------------------------------------------\n";

    setColor(7); // Reset color
    return 0;
}
