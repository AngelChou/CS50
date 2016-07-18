/*
Author: Angel Chou
Year: 2016

Course: CS50
PSet: 1, Standard Edition
Title: Time for Change

Decription:
 A program that first asks the user how much change is owed and then spits out the minimum number of coins with which said change can be made.
*/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float f;

    printf("O hai! ");
    do
    {
        printf("How much change is owed?\n");
        f = GetFloat();
    }
    while(f < 0);

    int coins = (int)round(f * 100);
    int num = 0;

    // Start change from largest coins
    while(coins >= 25)
    {
        num++;
        coins -= 25;
    }
    while(coins >= 10)
    {
        num++;
        coins -= 10;
    }
    while(coins >= 5)
    {
        num++;
        coins -= 5;
    }
    while(coins >= 1)
    {
        num++;
        coins -= 1;
    }

    // Print result
    printf("%d\n", num);
    return 0;
}