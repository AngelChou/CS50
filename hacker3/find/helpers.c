/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (value == array[i])
        {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // counting sort
    int count[65536] = {0};
    for (int i = 0; i < n; i++)
    {
        count[ values[i] ]++;
    }
        
    for (int i = 0, j = 0; i < n; ++i)
    {
        if (count[i]--)
        {
            values[j++] = i;
        }
    }
    return;
}