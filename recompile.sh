#!/bin/bash

# Set the directory to search. Change "." to the desired directory if needed.
directory="."

# Find and delete files with .o, .rej, or .orig extensions
find "$directory" -type f \( -name "*.o" -o -name "*.rej" -o -name "*.orig" \) -exec rm -f {} +

# Remove the config.h file if it exists
if [ -f "$directory/config.h" ]; then
    rm "$directory/config.h"
fi

# Run sudo make clean install
sudo make clean install

find "$directory" -type f \( -name "*.o" -o -name "*.rej" -o -name "*.orig" \) -exec rm -f {} +
