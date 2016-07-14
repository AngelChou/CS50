#include <cs50.h>
#include <stdio.h>

void drawing(int num, int type);

int main(void)
{
    int height;
    do
    {
        printf("Enter a non-negative integer < 24: ");
        height = GetInt();
    }
    while (height < 0 || height > 23);
    
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
