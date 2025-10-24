def main(): 
    budget = int(input("").split(" ")[1])
    base_prices_so_far = 0
    total_price_so_far = 0
    tentative_total_price = 0
    souvenir_base_prices = [int(x) for x in input("").split(" ")]
    # souvenir_base_prices_dict = dict(zip(range(1, len(souvenir_base_prices) + 1)))
    for index, base_price in enumerate(souvenir_base_prices):
        base_prices_so_far += base_price
        tentative_total_price = base_prices_so_far + (index + 1) * sum(range(0, index + 2))
        if (tentative_total_price > budget):
            index -= 1
            break
        else:
            # print(f"Total base prices so far: {base_prices_so_far}, index prices: {(index + 1) * sum(range(0, index + 2))}")
            total_price_so_far = tentative_total_price
    print(f"{index + 1} {total_price_so_far}")

if __name__ == "__main__":
    main()