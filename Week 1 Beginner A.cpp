#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include <algorithm>
#include <algorithm>
#include <complex>
#include <functional>
#include <iostream>
#include <ranges>
#include <string>
#include <utility>
#include <vector>


int main() {
    int num_souvenirs; std::cin >> num_souvenirs;
    int budget; std::cin >> budget;
    int base_cost = 0;
    int total_cost = 0;
    
    int cost_of_next_souvenir;
    int i;
    for (i = 0; i <= num_souvenirs; ++i) {
        std::cin >> cost_of_next_souvenir;
        base_cost += cost_of_next_souvenir;
        if (base_cost + (i * (i + 1) / 2) > budget) {
            break;
        } else {
            total_cost = base_cost + (i * (i + 1) / 2);
        }
    }

    std::cout << i - 1 << " " << total_cost << std::endl;
}
