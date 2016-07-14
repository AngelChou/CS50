#include <cs50.h>
#include <stdio.h>

bool checksum(int count, long input);

int main(void)
{
    printf("Number: ");
    long input = GetLongLong(); 
    int count = 0;
    
    // get number of digits
    long n = input;
    while(n > 0)
    {
        count++;
        n /= 10;
    }
    
    if (checksum(count, input))
    {
        long s = 1;
        for(int i = 0; i < count - 2; i++)
            s*=10;
            
        long head = input / s;
        if(count == 15 && (head == 34 || head == 37))
            printf("AMEX\n");
        else if(count == 16 && (head > 50 && head < 56))
            printf("MASTERCARD\n");
        else if((count == 16 || count == 13) && (head / 10 == 4))
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
    return 0;
}

bool checksum(int count, long n)
{
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < count; i++)
    {
        if(i % 2 == 0)
        {
            sum1 += n % 10;
        }
        else
        {
            int tmp = (n % 10) * 2;
            if(tmp < 10)
            {
                sum2 += tmp;
            }
            else
            {
                sum2 += tmp % 10;
                sum2 += tmp / 10;
            }
        }
        n /= 10;
    }
    if((sum1 + sum2) % 10 == 0)
        return true;
    else
        return false;
}