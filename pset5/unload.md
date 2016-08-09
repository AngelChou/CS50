# unload

## freeing linked lists in hash tables
```c
node* cursor = head;

while (cursor != NULL)
{
    node* temp = cursor;
    cursor = cursor->next;
    free(temp);
}
```

## unload in tries
- Unload from bottom to top
- Travel to lowest possible node
  - free all pointers in children
  - backtrack upwards, freeing all elements in each children array until you hit root node
- Recursion!

## Valgrind
```shell
valgrind -v --lead-check=full ./speller ~cs50/pset5/texts/austinpowers.txt
```

## Tips
- Pass in a smaller dictionary
  - usage: ```./speller [dictionary] text```
  - default: ```~cs50/pset5/dictionaries/large```
  - ```~cs50/pset5/dictionaries/small```
  - make your own!
- Pen and paper!
