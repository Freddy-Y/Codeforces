#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::stringstream numTestCasesStream(inputLine);
    int numTestCases; numTestCasesStream >> numTestCases;

    for (int i = 0; i < numTestCases; i++) {
        int finalAnswer;
        bool finalAnswerIsOne = false;

        std::getline(std::cin, inputLine);
        std::stringstream inputLineStringStream(inputLine);
        int maxWrittenNumber; inputLineStringStream >> maxWrittenNumber;
        int numDesiredNumbers; inputLineStringStream >> numDesiredNumbers;
        int maxDesiredNumber = 0;

        int desiredNumber;

        std::string desiredNumbers; std::getline(std::cin, desiredNumbers);
        std::stringstream desiredNumbersStringStream(desiredNumbers);

        for (int j = 0; j < numDesiredNumbers; j++) {
            desiredNumbersStringStream >> desiredNumber;
            if (j != 0 && desiredNumber == 1) {
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
