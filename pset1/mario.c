/*
Author: Angel Chou
Year: 2016

Course: CS50
PSet: 1, Standard Edition
Title: Itsa Mario

Decription:
A program that recreates half-pyramid using hashes (#) for blocks.
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get height
    int height;
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);

    // Create blocks
    for (int i = 0; i < height; i++)
    {
        for (int j = height - 1 - i; j > 0; j--)
            printf(" ");

        for (int k = i + 2; k > 0; k--)
            printf("#");

        printf("\n");
    }
    return 0;
}