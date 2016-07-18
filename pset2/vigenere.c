/*
Author: Angel Chou
Year: 2016

Course: CS50
PSet: 2, Standard Edition
Title: Parlez-vous français?

Decription:
 A program that encrypts messages using Vigenère’s cipher.
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Get the key
    if (argc != 2)
    {
        printf("You need to input a key for vigenere cipher.\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("You can't input non-alphabetical character.\n");
            return 1;
        }
    }
    string k = argv[1];


    // Get the plaintext
    string p = GetString();

    // Encipher
    for (int i = 0, j = 0, n = strlen(p); i < n; i++)
    {
        if (!isalpha(p[i]))
            continue;

        int key = isupper(k[j]) ? k[j] - 'A' : k[j] - 'a';
        p[i] = isupper(p[i]) ? ((p[i] - 'A') + key) % 26 + 'A' : ((p[i] - 'a') + key) % 26 + 'a';
        j++;
        if (j == strlen(k))
            j = 0;
    }

    // Print ciphertext
    printf("%s\n", p);

    return 0;
}

