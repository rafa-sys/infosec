#!/bin/bash

# specify the input file containing the payloads
payloads_file="payloads.txt"

# specify the target URL
target_url="http://example.com/search?q="

# read the payloads from the file
while read -r payload; do
  # inject the payload into the target URL
  response=$(curl -s "$target_url$payload")
  # check for any unusual behavior or errors
  if [ $? -ne 0 ]; then
    echo "Error: $response"
  else
    echo "Response: $response"
  fi
done < "$payloads_file"
