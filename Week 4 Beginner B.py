def main():
    return 0

def binary_search_solution():
    num_test_cases = int(input())
    for test_case in range(num_test_cases):
        num_piles = int(input())
        stones_per_pile = [int(x) for x in input().split(" ")]
        pile_lower_bound = 1                        # inclusive
        pile_upper_bound = len(stones_per_pile)     # inclusive

        

if __name__ == "__main__":
    main()