/*
Author: Angel Chou
Year: 2016

Course: CS50
PSet: 2, Standard Edition
Title: Initializing

Decription:
 A program that prompts a user for their name and then outputs their initials in uppercase with no spaces or periods.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // Change lowercase to uppercase
        if (islower(name[i]))
            name[i] -= 32;

        // Print initials
        if (i == 0 || name[i-1] == ' ')
            printf("%c", name[i]);
    }
    printf("\n");

    return 0;
}