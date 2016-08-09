#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Get ciphertext
    if (argc != 2)
    {
        printf("You need to input a ciphertext for decryption.\n");
        return 1;
    }
    string c = argv[1];
    
    // Get value of salt
    char salt[3] = {0};
    memcpy(salt, c, 2);
    
    // Dictionary Attack
    FILE* fp = fopen("/usr/share/dict/words", "r");
    if (fp == NULL)
    {
        printf("File does not exist.\n");
        return 2;
    }
    
    char p[50];
    //int i=0;
    while (1)
    {
        if(feof(fp))
        {
            printf("feof\n");
            break;
        }
        else
            fgets(p, 50, fp);
            
        // Found match result
        if (strcmp(c, crypt(p, salt)) == 0)
        {
            for (int i = 0, n = strlen(p); i < n; i++)
            {
                if (isprint(p[i]))
                {
                    printf(" === %c", p[i]);
                }
                else
                {
                    printf(" --- ");
                }
            }
            printf("HI\n");
            break;
        }
        /*printf("%s >>> %s\n", s, crypt(s, salt));
        i++;
        if (i > 10)
            break;*/
    }
    
    
    // Print plaintext
    printf("%s", p);
    
    fclose(fp);
    return 0;
}