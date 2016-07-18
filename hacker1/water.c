/*
Author: Angel Chou
Year: 2016

Course: CS50
PSet: 1, Hacker Edition
Title: Smart Water

Decription:
A program that prompts the user to the length of his or her shower in minutes (as a positive integer, re-prompting as needed) and then prints the equivalent number of bottles of water (as an integer).
1-minutes shower = 12 bottles of water. (1.5 * 128 / 16 = 12)
*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i;
    do
    {
        printf("minutes: ");
        i = GetInt();
    }
    while(i < 1);

    printf("bottles: %d\n", i * 12);
    return 0;
}