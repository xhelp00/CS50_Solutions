#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
//controling user input to be a number, not 0
    long number = 0;
    long temp = 0;
    int len = 2;
    int sum = 0;
    int digit = 0;
    int i = 1;
    do
    {
        number = get_long("Number: ");
    }
    while (number == 0);
    temp = number;
//counter of digits
    while (temp > 100)
    {
        temp /= 10;
        len++;
    }
//checking, invalid when not 13 or 15 or 16 digits long
//printf("%i\n", len);
//if (len != 13 && len != 15 && len != 16)
//printf("INVALID\n");
//printf("%ld", number);
//luhn part
    while (i <= len)
    {
        digit = number % 10;
        if (i % 2 == 0)
        {
            if (digit * 2 > 9)
            {
                sum += (digit * 2) - 9;
            }
            else
            {
                sum += digit * 2;
            }
        }
        else
        {
            sum += digit;
        }
//printf("pred%ld\n", number);
        number /= 10;
//printf("po%ld\n", number);
        i++;
    }
    bool valid = (sum % 10 == 0) ? true : false;
//printf("%i\n", sum);
//printf("%s\n", valid ? "true" : "false");
//printing
    if (len == 15 && (temp == 34 || temp == 37) && valid)
    {
        printf("AMEX\n");
    }
    else if (len == 16 && (temp > 50 && temp < 56) && valid)
    {
        printf("MASTERCARD\n");
    }
    else if ((len == 13 || len == 16) && (temp / 10 == 4) && valid)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}