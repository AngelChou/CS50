#load

## TODO: dictionary.c
- load
  - loads the dictionary
- check
  - checks if a given word is in the dictionary
- size
  - returns the number of words in the dictionary
- unload 
  - frees the dictionary from memory

## hash tables
- an array of buckets
- each bucket is a linked list
- hash function
  - returns the bucket that a given key belongs to
  
## linked lists
- Each node has a value, as well as a pointer to the next node
- Important:
  - Don't lose any links!
  - Last node points to NULL
```c
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node* node1 = malloc(sizeof(node));
node* node2 = malloc(sizeof(node));
node1->word = "Hello";
node2->word = "World";
node1->next = node2;
```

## hash table
```c
typedef struct node
{
    char word[LENGTH + 1];
    struct node * next;
}
node;

node* hashtable[500];
```

## make a new word
- ```malloc``` a ```node*``` for each new word
```c
node* new_node = malloc(sizeof(node));
fsanf(file, "%s", new_node->word);
```

## hash functions
- takes a string
- returns an index
  - index < the number of buckets
- deterministic
  - the same value needs to map to the same bucket every time

## hash the word
- ```new_node->word``` has the word from the dictionary
- hashing ```new_node->word``` will give us the index of a bucket in the hash table
- insert into the linked list

## insert into a linked list
```c
new_node->next = head;
head = new_node;
```

## traversing linked lists
```c
node* cursor = head;
while (cursor != NULL)
{
    // do something
    cursor = cursor->next;
}
```

## tries
- Every node contains an array of ```node*```s
  - One for every letter in the alphabet + '\''
  - Each element in the array points to another ```node```
    - if that ```node``` is ``` NULL```, then that letter isn't the next letter of any word in that sequence
- Every node indicates whether it's the last character of a word
```c
typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;

node* root;
```

## load
- for every dictionary word, iterate through the trie
- each element in ```children``` corresponds to a different letter
- check the value at ```children[i]```
  - if ```NULL```, ```malloc``` a new node, have ```children[i]``` point to it
  - if not ```NULL```, move to new node and continue
- if at end of word, set ```is_word``` to ```true```

## "fox"
f: ```root->children[5]```
o: ```root->children[5]->children[15]```
x: ```root->children[5]->children[15]->children[23]```

## "foo"
f: ```root->children[5]```
o: ```root->children[5]->children[15]```
o: ```root->children[5]->children[15]->children[15]```

## "dog"
d: ```root->children[3]```
o: ```root->children[3]->children[15]```
g: ```root->children[3]->children[15]->children[6]```

## "do"
d: ```root->children[3]```
o: ```root->children[3]->children[15]```
