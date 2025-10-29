import math

first_line = [int(x) for x in input().split()]
num_ingredients = first_line[0]
owned_magic_powder = first_line[1]
required_ingredients = [int(x) for x in input().split()]
owned_ingredients = [int(x) for x in input().split()]

def can_bake_cookies(num_desired_cookies) -> bool:
    total_magic_powder_needed = 0
    for x in range(0, num_ingredients):
        difference_between_needed_and_owned_ingredients = owned_ingredients[x] - (num_desired_cookies * required_ingredients[x])
        if (difference_between_needed_and_owned_ingredients < 0):
            total_magic_powder_needed += abs(difference_between_needed_and_owned_ingredients)
    return (total_magic_powder_needed <= owned_magic_powder)

def final_solution():
    num_cookies_possible_without_magic_powder = [owned_ingredients[x] // required_ingredients[x] for x in range(0, num_ingredients)]
    lower_bound = min(num_cookies_possible_without_magic_powder)
    least_ingredient_index = num_cookies_possible_without_magic_powder.index(lower_bound)
    upper_bound = (owned_ingredients[least_ingredient_index] + owned_magic_powder) // required_ingredients[least_ingredient_index]

    while (lower_bound != upper_bound):
        tentative_num_cookies = math.ceil((lower_bound + upper_bound) / 2)
        # print(tentative_num_cookies)
        if can_bake_cookies(tentative_num_cookies):
            lower_bound = tentative_num_cookies
        elif not can_bake_cookies(tentative_num_cookies):
            upper_bound = tentative_num_cookies - 1
        else:
            lower_bound = tentative_num_cookies
            upper_bound = tentative_num_cookies
    print(upper_bound)

def main():
    final_solution()

if __name__ == "__main__":
    main()