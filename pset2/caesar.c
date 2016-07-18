/*
Author: Angel Chou
Year: 2016

Course: CS50
PSet: 2, Standard Edition
Title: Hail, Caesar!

Decription:
 A program that encrypts messages using Caesar’s cipher.
*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Get the key
    if (argc != 2)
    {
        printf("You need to input a key for caeser cipher\n");
        return 1;
    }
    int k = atoi(argv[1]);

    // Get the plaintext
    string p = GetString();

    // Encipher
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (!isalpha(p[i]))
            continue;

        p[i] = isupper(p[i]) ? ((p[i] - 'A') + k) % 26 + 'A' : ((p[i] - 'a') + k) % 26 + 'a';
    }

    // Print ciphertext
    printf("%s\n", p);
    return 0;
}