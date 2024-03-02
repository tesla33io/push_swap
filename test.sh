#!/bin/bash

# Check if the number of arguments passed is correct
if [ "$#" -ne 1 ]; then
	echo "Usage: $0 <numbers amount>"
	exit 1
fi

# Access the first command-line argument
n=$1

# Run the Python script to get random numbers
python_script_output=$(python3 ngen.py "$n")

# Run make to update the bin if anything changed
# and run push_swap with random numbers after
make
./push_swap $python_script_output
echo -e "Used command: ./push_swap $python_script_output"