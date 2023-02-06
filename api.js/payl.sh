#!/bin/bash

# specify the input file containing the payloads
payloads_file="payloads.txt"

# specify the target software
target_software="./my_software"

# read the payloads from the file
while read -r payload; do
  # inject the payload into the target software
  "$target_software" "$payload"
done < "$payloads_file"
