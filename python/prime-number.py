used_numbers = []
prime_numbers = []
non_prime = []

stop = ""
number = 1  # number going up
counter = 0
current_num = 0

while (stop != "s"):
    used_numbers.append(number)
    # x is the biggest number

    current_num = number

    # y is the number that keeps going up
    for y in range(len(used_numbers)):
        test_num = used_numbers[y]
        #print("testing number", current_num, " / ", test_num)

        if(current_num == test_num):
            pass

            # if no remainder
        elif(current_num % test_num == 0 and test_num != 1):
            counter += 1

            # if there is a remainder
        elif(current_num % test_num != 0):
            pass

        else:
            pass

    if(counter == 0):
        prime_numbers.append(current_num)
        print(current_num, " is a prime number")

    else:
        non_prime.append(current_num)

    counter = 0
    stop = input("")
    number += 1

print(prime_numbers)
