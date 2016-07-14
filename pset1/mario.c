#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
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