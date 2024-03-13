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

# NORM CHECK

echo -en "\033[35mNorm check: \033[31m"
# Run the command and capture its output
output=$(norminette)

# Flag to indicate whether we've encountered an error or warning
error_flag=false

# Flag to indicate whether any errors or warnings were found
error_found=false

# Loop through each line of the output
while IFS= read -r line; do
    # Check if the line contains "Error" or "Warning"
    if [[ $line =~ Error|Warning ]]; then
        # Set the error flag to true
        error_flag=true
        # Set the error_found flag to true
        error_found=true
    fi

    # If error_flag is true, print the line
    if $error_flag && ! [[ $line =~ OK ]]; then
        echo "$line"
    fi

    # If the line contains "OK", reset the error flag
    if [[ $line =~ OK ]]; then
        error_flag=false
    fi
done <<< "$output"

# If no errors or warnings were found, print "No errors"
if ! $error_found; then
    echo -e "\033[32mOK!\033[0m"
fi

# NORM CHECK

echo -e "\033[0mUsed command: \033[33m./push_swap $python_script_output\033[0m"
echo -ne "\n\033[31m*******************************************************"
echo -e "************************************************\033[0m"
