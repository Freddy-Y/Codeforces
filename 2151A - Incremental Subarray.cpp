#include <iostream>

int main() {
    int numTestCases; std::cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        int finalAnswer;
        bool finalAnswerIsOne = false;

        int maxWrittenNumber; std::cin >> maxWrittenNumber;
        int numDesiredNumbers; std::cin >> numDesiredNumbers;
        int maxDesiredNumber = 0;


        bool firstDesiredNumberIsOne = false;
        int desiredNumber; std::cin >> desiredNumber;
        if (desiredNumber == 1) {
            firstDesiredNumberIsOne = true;
        }

        for (int j = 1; j < numDesiredNumbers; j++) {
            std::cin >> desiredNumber;
            if (!firstDesiredNumberIsOne && desiredNumber == 1) {
                finalAnswerIsOne = true;
                break;
            }
            if (desiredNumber > maxDesiredNumber) maxDesiredNumber = desiredNumber;
        }

        finalAnswer = (finalAnswerIsOne) ? 1 : maxWrittenNumber - maxDesiredNumber + 1;
        std::cout << finalAnswer << std::endl;

    }
    return 0;
}

// THEORETICAL UNTESTED SOLUTION
// IF THE FIRST DIGIT IS NOT A 1, AND THERE IS AT LEAST ONE 1, THE SOLUTION IS 1
// OTHERWISE, THE SOLUTION IS JUST MAX WRITTEN NUMBER - MAX DESIRED NUMBER + 1
