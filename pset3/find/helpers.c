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

void bubbleSort(int values[], int n);
void selectionSort(int values[], int n);
void insertionSort(int values[], int n);
bool linearSearch(int value, int values[], int n);
bool binarySearch(int value, int values[], int n);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //return linearSearch(value, values, n);
    return binarySearch(value, values, n);
}

bool binarySearch(int value, int values[], int n)
{
    int mid = n/2;
    if (mid == 0 && value != values[mid])
    {
        return false;
    }
    else if (value == values[mid])
    {
        return true;
    }
    else if (value < values[mid])
    {
        return binarySearch(value, values, mid);
    }
    else
    {
        return binarySearch(value, values + mid, n - mid);
    }
}

bool linearSearch(int value, int values[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(values[i] == value)
            return true;
    }
    return false;    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    //bubbleSort(values, n);
    //selectionSort(values, n);
    insertionSort(values, n);
    
    return;
}

void bubbleSort(int values[], int n)
{
    bool swap = 0;
    do
    {
        swap = 0;
        for (int i = 0, j = 1; j < n; i++, j++)
        {
            if (values[i] > values[j])
            {
                int tmp = values[i];
                values[i] = values[j];
                values[j] = tmp;
                swap = 1;
            }
        } 
    }
    while (swap);
    
    return;
}

void selectionSort(int values[], int n)
{
    for (int j = 0; j < n; j++)
    {
        int max = 0;
        for (int i = 0; i < n - j; i++)
        {
            if (values[i] > values[max])
            {
                max = i;
            }
        }
        int tmp = values[n - (j + 1)];
        values[n - (j + 1)] = values[max];
        values[max] = tmp;
    }
    
    return;
}

void insertionSort(int values[], int n)
{
    for (int i = 1; i < n; i++) //unsorted index
    {
        for (int j = 0; j < i; j++) //sorted index
        {
            if (values[i] < values[j])
            {
                int tmp = values[j];
                values[j] = values[i];
                values[i] = tmp;
            }
        }
    }
    return;
}