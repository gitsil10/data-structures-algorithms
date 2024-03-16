# Longest Substring Without Repeating Characters

## Pseudocode

if |string| in {0,1} 
    return |string|
else
    string_size <- 0
    string_start <- 0
    string_end <- 0
    while string_end < |string|
        if s[string_end] is not in string from start to end then
            string_end <- string_end + 1
            string_size <- max of string_size and (string_end - string_start)
        else
            string_start <- string_start + 1
    return string_size