#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes: ");
    int min = GetInt();
    printf("bottles: %d\n", min * 12);
}