#!/usr/bin/env bash
# Write your solution here, in place of this line
find . -type f -name "*int*" exec ls grep -l  {} \; 