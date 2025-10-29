def main():
    final_solution()

def final_solution():
    num_test_cases = int(input())
    for test_case in range(num_test_cases):
        binary_string_len = int(input())
        binary_string = input()
        index_list = []
        for index, digit in enumerate(binary_string):
            if digit == "0":
                index_list.append(str(index + 1))
        
        print(len(index_list))
        print(" ".join(index_list))


def naive_solution():
    num_test_cases = int(input())
    for test_case in range(num_test_cases):
        binary_string_len = int(input())
        binary_string = input()
        done = False

        for substring_len in range(0, binary_string_len + 1):
            if (done):
                break
            for substring_starting_index in range(0, binary_string_len - substring_len + 1):
                substring_ending_index = substring_starting_index + substring_len
                substring = binary_string[substring_starting_index:substring_ending_index]
                remaining_binary_string = binary_string[:substring_starting_index] + binary_string[substring_ending_index:]
                if "10" not in substring and remaining_binary_string == remaining_binary_string[::-1]:
                    print(len(substring))
                    print(" ".join([str(x) for x in range(substring_starting_index + 1, substring_ending_index + 1)]))
                    done = True
                    break

        if (not done):
            print(-1)

if __name__ == "__main__":
    main()