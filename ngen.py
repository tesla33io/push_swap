import random
import sys

if __name__ == "__main__":
    try:
        n = int(sys.argv[1])  # Get n from command-line argument

        n_lst = list(range(int(-(n / 2)), (n * 2)))
        random.shuffle(n_lst)  # Shuffle the list in-place
        res_list = n_lst[:n]  # Take the first n elements

        # Print all elements except the last one, separated by spaces
        print(*res_list[:-1], sep=" ", end=" ")

        # Print the last element without a newline
        print(res_list[-1])

    except IndexError:
        print("Please provide a number as a command-line argument.")
    except ValueError:
        print("The provided argument is not a valid integer.")
    except Exception as e:
        print("An unexpected error occurred:", e)
