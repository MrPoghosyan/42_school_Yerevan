#!/bin/bash

# Create an empty array
declare -a liste=()

# Line counter
ligne=0

# Read the /etc/passwd file line by line
while IFS= read -r pass; do
    # Skip commented lines
    if [[ ${pass:0:1} != "#" ]]; then
        ligne=$((ligne + 1))
        # If the line number is even
        if ((ligne % 2 == 0)); then
            # Extract the username and reverse it
            user=$(echo "$pass" | awk -F':' '{print $1}' | rev)
            liste+=( "$user" )
        fi
    fi
done < /etc/passwd

# Sort the array in reverse order
sorted=($(printf "%s\n" "${liste[@]}" | sort -r))

# Extract the range of elements based on FT_LINE1 and FT_LINE2
result=("${sorted[@]:FT_LINE1-1:FT_LINE2-FT_LINE1+1}")

# Format the output string
output=$(printf ", %s" "${result[@]}")
output=${output:2} # Remove the leading comma and space
output+="."        # Add a period at the end

# Print the result
echo "$output"

