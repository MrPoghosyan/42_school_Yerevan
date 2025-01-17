declare -a liste=()
ligne=0

# Reading the /etc/passwd file and removing spaces
for pass in $(cat /etc/passwd | tr -d ' ')
do
    # Skip lines that are comments
    if [[ ${pass:0:1} != '#' ]]
    then
        # Increment the line counter
        ligne=$((ligne + 1))
        
        # Skip odd-numbered lines
        if (( ligne % 2 == 0 ))
        then
            # Extract the login and reverse it
            pass=$(echo "$pass" | awk -F':' '{print $1}' | rev)
            # Add the result to the array
            liste+=("$pass")
        fi
    fi
done

# Sort the array in reverse alphabetical order
sorted=($(printf "%s\n" "${liste[@]}" | sort -r))

# Select elements between FT_LINE1 and FT_LINE2
out=("${sorted[@]:$((FT_LINE1 - 1)):$((FT_LINE2 - FT_LINE1 + 1))}")

# Combine the selected logins into a single string, separated by ", ", and end with a period
echo "${out[*]}" | sed 's/ /, /g' | sed 's/$/./'

