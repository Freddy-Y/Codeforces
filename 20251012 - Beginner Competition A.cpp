#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>  


int main() {
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::stringstream inputStream1(inputLine);

    int numProblems; inputStream1 >> numProblems;

    int a = 1;
    std::getline(std::cin, inputLine);
    std::stringstream inputStream2(inputLine);
    int v = numProblems;

    int b; inputStream2 >> b;
    std::getline(std::cin, inputLine);
    std::stringstream inputStream3(inputLine);
    std::string b_direction; inputStream3 >> b_direction;
    
    int a_increment = 1;
    int b_increment; b_increment = (b_direction == "L") ? -1 : 1;
    int v_increment = -1;

    int a_problems = 1;
    int b_problems = 1;
    int v_problems = 1;

    int a_init = a;
    int b_init = b;
    int v_init = v;

    while (a_increment != 0 || b_increment != 0 || v_increment != 0) {
        if (a + a_increment >= b_init || a + a_increment >= b) {
            a_increment = 0;
        } 
        if (b + b_increment >= v || b + b_increment <= a) {
            b_increment = 0;
        }
        if (v + v_increment <= b_init || v + v_increment <= b) {
            v_increment = 0;
        }

        // std::cout << a << " ";
        // std::cout << b << " ";
        // std::cout << v << std::endl;

        a += a_increment;
        a_problems += abs(a_increment);
        b += b_increment;
        b_problems += abs(b_increment);
        v += v_increment;
        v_problems += abs(v_increment);
    }

    std::cout << a_problems << " ";
    std::cout << b_problems << " ";
    std::cout << v_problems << std::endl;
}