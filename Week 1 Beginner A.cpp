#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>

int num_souvenirs;
unsigned long budget; 
std::vector<unsigned long> souvenir_base_prices;

unsigned long calculate_total_price(int tentative_num_souvenirs) {
    std::vector<unsigned long> souvenir_prices = {};
    for (int i = 0; i < num_souvenirs; i++) {
        souvenir_prices.push_back(souvenir_base_prices[i] + (i + 1) * tentative_num_souvenirs);
    }
    std::sort(souvenir_prices.begin(), souvenir_prices.end());
    return std::accumulate(souvenir_prices.begin(), souvenir_prices.begin() + tentative_num_souvenirs, 0);
}

void final_solution() {
    std::cin >> num_souvenirs;
    std::cin >> budget;
    unsigned long souvenir_cost;
    for (int i = 0; i < num_souvenirs; i++) {
        std::cin >> souvenir_cost;
        souvenir_base_prices.insert(souvenir_base_prices.begin() + i, souvenir_cost);
    }

    int num_souvenirs_upper_bound = num_souvenirs;          // inclusive
    int num_souvenirs_lower_bound = 0;                      // inclusive
    int tentative_num_souvenirs;
    unsigned long tentative_total_price;
    while (num_souvenirs_upper_bound != num_souvenirs_lower_bound) {
        tentative_num_souvenirs = ceil((num_souvenirs_upper_bound + num_souvenirs_lower_bound) / 2.0);
        tentative_total_price = calculate_total_price(tentative_num_souvenirs);

        if (tentative_total_price > budget) {
            num_souvenirs_upper_bound = tentative_num_souvenirs - 1;
        } else if (tentative_total_price < budget) {
            num_souvenirs_lower_bound = tentative_num_souvenirs;
        } else {
            num_souvenirs_lower_bound = tentative_num_souvenirs;
            num_souvenirs_upper_bound = tentative_num_souvenirs;
        }
    }

    std::cout << num_souvenirs_upper_bound << " " << calculate_total_price(num_souvenirs_upper_bound) << std::endl;
}

void naive_solution() {
    int num_souvenirs; std::cin >> num_souvenirs;
    int budget; std::cin >> budget;
    std::vector<long> souvenir_base_prices;
    int souvenir_cost;
    for (int i = 0; i < num_souvenirs; i++) {
        std::cin >> souvenir_cost;
        souvenir_base_prices.insert(souvenir_base_prices.begin() + i, souvenir_cost);
    }

    int confirmed_num_souvenirs = 0;
    int tentative_num_souvenirs = 0;
    int confirmed_total_price = 0;
    int tentative_total_price = 0;
    std::vector<long> souvenir_prices;
    while (confirmed_num_souvenirs < num_souvenirs) {
        souvenir_prices = {};
        ++tentative_num_souvenirs;
        for (int i = 0; i < num_souvenirs; i++) {
            souvenir_prices.insert(souvenir_prices.begin() + 0, souvenir_base_prices[i] + (i + 1) * tentative_num_souvenirs);
        }
        std::sort(souvenir_prices.begin(), souvenir_prices.end());
        tentative_total_price = std::accumulate(souvenir_prices.begin(), souvenir_prices.begin() + tentative_num_souvenirs, 0);
        if (tentative_total_price > budget) break;
        confirmed_num_souvenirs = tentative_num_souvenirs;
        confirmed_total_price = tentative_total_price;
    }

    std::cout << confirmed_num_souvenirs << " " << confirmed_total_price << std::endl;
}

int main() {
    final_solution();
}