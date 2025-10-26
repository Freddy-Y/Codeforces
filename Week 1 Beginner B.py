def main():
    num_test_cases = int(input())
    for test_case in range(num_test_cases):
        array_length = int(input())
        array = [int(x) for x in input()]

        prefix_sum_total = 0
        prefix_sum_array = []

        for element in array:
            prefix_sum_total += element
            prefix_sum_array.append(prefix_sum_total)

        # prefix_sum_array = [sum(array[0:x]) for x in range(len(array) + 1)]

        # print(prefix_sum_array)
    
        good_subarray_count = 0
        # for subarray_length in range(1, len(array) + 1):
        #     for subarray_starting_index in range(len(array) - (subarray_length - 1)):
        #         subarray_sum = prefix_sum_array[subarray_starting_index + subarray_length] - prefix_sum_array[subarray_starting_index]
        #         if subarray_sum == subarray_length:
        #             good_subarray_count += 1
        keys_dict = {0: 1}
        for index, prefix_sum in enumerate(prefix_sum_array):
            key = prefix_sum - (index + 1)
            if key in keys_dict:
                # print(f"Key {key} increases count by 1")
                good_subarray_count += keys_dict[key]
                keys_dict[key] += 1
            else:
                # print(f"Key {key} is new to the list!")
                keys_dict[key] = 1
            
        
        print(good_subarray_count)

if __name__ == "__main__":
    main()