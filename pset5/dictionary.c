/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"


// struct of tries
typedef struct node
{
    bool is_word;
    struct node* children[27];
}
node;

node* root = NULL;
unsigned int words = 0;

node* init(void)
{
    node* ptr = malloc(sizeof(node));
    if (ptr == NULL)
    {
        printf("malloc struct node failed.\n");
        return NULL;
    }
    
    ptr->is_word = false;
    
    for(int i = 0; i < 27; i++)
    {
        ptr->children[i] = NULL;
    }
    
    return ptr;
}

void release(node* ptr)
{
    for (int i = 0; i < 27; i++)
    {
        if (ptr->children[i] != NULL)
            release(ptr->children[i]);
    }
    
    free(ptr);
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* trav = root;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (trav == NULL)
            return false;
        
        if (!(isalpha(word[i]) || word[i] == '\''))
            return false;
            
        if (word[i] == '\'')
        {
            if (trav->children[26] == NULL)
                return false;
            trav = trav->children[26];
        }
        else
        {
            int c = tolower(word[i]);
            int index = c - 97;
            if (trav->children[index] == NULL)
                return false;
            trav = trav->children[index];
        }
        
        if (i == n - 1 && trav != NULL)
        {
            return true;
        }
        
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // try to open dictionary
    FILE* fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    
    root = init();
    if (root == NULL)
        return false;
        
    node* trav = root;
    
    // read each word in dictionary
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        // allow only alphabetical characters and apostrophes
        if (isalpha(c))
        {
            // assume that each word in dictionary will contain only lowercase alphabetical characters
            int index = c - 97;
            
            if (trav->children[index] == NULL)
            {
                trav->children[index] = init();
                if (trav->children[index] == NULL)
                    return false;
            }
            
            trav = trav->children[index];
        }
        else if (c == '\'')
        {
            if (trav->children[26] == NULL)
            {
                trav->children[26] = init();
                if (trav->children[26] == NULL)
                    return false;
            }
                
                
            trav = trav->children[26];
        }
        else
        {
            words += 1;
            trav->is_word = true;   
            trav = root;
        }
    }
    
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (root)
        return words;
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    release(root);
    return true;
}
