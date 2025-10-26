def main():
    naive_solution()

def naive_solution(): 
    budget = int(input("").split(" ")[1])
    
    souvenir_base_prices = [int(x) for x in input("").split(" ")]
    # souvenir_prices_dict = dict()
    # for souvenir_base_price in souvenir_base_prices:
    #     souvenir_prices_dict[souvenir_base_price] = 0
    
    num_souvenirs = 0
    confirmed_total_price = 0
    tentative_total_price = 0
    while num_souvenirs < len(souvenir_base_prices):
        num_souvenirs += 1
        souvenir_prices_list = []
        for index, souvenir_base_price in enumerate(souvenir_base_prices):
            souvenir_prices_list.append(souvenir_base_price + (index + 1) * num_souvenirs)
        # print(f"Before sorting: {souvenir_prices_list}")
        souvenir_prices_list.sort()
        # print(f"After sorting: {souvenir_prices_list}")
        tentative_total_price = sum(souvenir_prices_list[:num_souvenirs])
        # print(f"For {num_souvenirs} souvenirs, the minimum cost total cost is expected to be {tentative_total_price}")
        if (tentative_total_price > budget):
            num_souvenirs -= 1
            break
        else:
            confirmed_total_price = tentative_total_price

    print(f"{num_souvenirs} {confirmed_total_price}")

if __name__ == "__main__":
    main()