#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    for (int i = 0, n = strlen(name); i < n; i++)
    {
        // change lowercase to uppercase
        if (islower(name[i]))
            name[i] -= 32;
        
        // print initials
        if (isalpha(name[i]) && (i == 0 || name[i-1] == ' '))
            printf("%c", name[i]);    
    }
    printf("\n");
    
    return 0;
}