# check

## check
- case-insensitivity
- assume strings with only alphabetical characters and/or apostrophes

## check in hash table
- if the word exists, it can be found in the hash table
- which bucket would the word be in?
  - ```hashtable[hash(word)]]```
- search in that linked list
  - ```strcmp```

## check in tries
- for each letter in input word
  - go to corresponding element in children
  - if NULL, word is misspelled
  - if not NULL, move to the next letter
  - once at end of input word
  - check if is_word is true
