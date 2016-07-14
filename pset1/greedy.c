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
    
    printf("%d\n", num);
    return 0;
}