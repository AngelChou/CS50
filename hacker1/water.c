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