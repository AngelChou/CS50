/*
Author: Angel Chou
Year: 2016

Course: CS50
PSet: 1, Hacker Edition
Title: Itsa Mario

Decription:
A program that recreates half-pyramid using hashes (#) for blocks.
*/

#include <cs50.h>
#include <stdio.h>

void drawing(int num, int type);

int main(void)
{
    // Get height of half-pyramid
    int height;
    do
    {
        printf("Enter a non-negative integer < 24: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);

    // Create blocks
    for (int i = 1; i < height + 1; i++)
    {
        for(int j = 0; j < height - i; j++)
            printf(" ");

        for(int j = 0; j < i; j++)
            printf("#");

        printf("  ");

        for(int j = 0; j < i; j++)
            printf("#");

        printf("\n");
    }
    return 0;
}
