import math


def main():
    first_solution()

    

def first_solution():
    num_array_length = int(input())
    num_array = [int(x) for x in input().split()]
    max_num = int(math.sqrt(max([x for x in num_array if math.sqrt(x) == int(math.sqrt(x))])))

    # The ith element represents the primeness of (i * 2) + 3
    # For example, array_of_primeness[0] represents 3, array_of_primeness[1] represents 5...
    array_of_primeness = sieve_of_erastosthenes_for_odds_only(max_num)

    for i in range(num_array_length):
        if num_array[i] == 1:
            print("NO")
        elif math.sqrt(num_array[i]) != int(math.sqrt(num_array[i])):
            print("NO")
        elif math.sqrt(num_array[i]) == 2:
            print("YES")
        else:
            print("YES" if array_of_primeness[int((math.sqrt(i) - 3) / 2)] else "NO")

def sieve_of_erastosthenes_for_odds_only(max_num):
    array_of_primeness = [True for _ in range(int((max_num - 1) / 2))]
    # i is every number between 3 and max_num that might be prime or composite
    for i in range(3, max_num + 1, 2):
        # number_of_multiples_in_range = math.floor((max_num / i) / 2)

        # j is every multiple of i that might be prime or composite
        for j in range(3 * i, max_num + 1, 2 * i):
            array_of_primeness[int((j - 3) / 2)] = False
    return array_of_primeness

if __name__ == "__main__":
    main()