#include <iostream>

int main() {
    int numTestCases; std::cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {


        int maxWrittenNumber; std::cin >> maxWrittenNumber;
        int arrayLength; std::cin >> arrayLength;
        std::vector<int> array;

        int nextElement;
        int maxDesiredNumber = 0;
        for (int j = 0; j < arrayLength; j++) {
            std::cin >> nextElement;
            array.push_back(nextElement);

            if ()
        }

    }
    return 0;
}

// THEORETICAL UNTESTED SOLUTION
// IF THE FIRST DIGIT IS NOT A 1, AND THERE IS AT LEAST ONE 1, THE SOLUTION IS 1
// OTHERWISE, THE SOLUTION IS JUST MAX WRITTEN NUMBER - MAX DESIRED NUMBER + 1
