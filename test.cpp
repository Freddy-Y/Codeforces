#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main() {
    std::string holderString = "";
    std::getline(std::cin, holderString);
    // std::cout << holderString << std::endl;

    std::stringstream ss(holderString);
    // std::vector<std::string> strings;
    std::string holderWord;
    while (ss >> holderWord) {
        // strings.push_back(holderWord);
        std::cout << holderWord << std::endl;
    }
    // for (int i = 0; i < strings.size(); i++) {
    //     holderWord.pop_back();
    // }
    return 0;
}