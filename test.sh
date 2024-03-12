#!/bin/bash

# Check if the number of arguments passed is correct
if [ "$#" -ne 1 ]; then
	echo "Usage: $0 <numbers amount>"
	exit 1
fi

# Access the first command-line argument
n=$1

# Run the Python script to get random numbers
python_script_output=$(seq 1 "$n" | shuf | tr "\n" " ")

# Run make to update the bin if anything changed
# and run push_swap with random numbers after
echo -ne "\033[31m*******************************************************"
echo -e "************************************************\033[0m\n"

make
# ./push_swap $python_script_output
echo -e "\033[36;1mChecker result\t| Ops count" &
echo -en $(./push_swap $python_script_output | ./checker_linux $python_script_output)"\t\t| " &
echo $(sleep 0.1 && ./push_swap $python_script_output | wc -l) &
wait
echo -e "\033[0mUsed command: \033[33m./push_swap $python_script_output\033[0m"
echo -ne "\n\033[31m*******************************************************"
echo -e "************************************************\033[0m"
