#include <stdio.h>
#include <cs50.h>

long get_credit_num(void);
bool credit_valid(long);
string credit_type(long);

int main(void)
{
    long credit_num = get_credit_num();

    // Print output of program.
    if (credit_valid(credit_num))
    {
        printf("%s\n", credit_type(credit_num));
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_credit_num(void)
{
    // Get credit card number from user. Reject negative numbers.
    long credit_num = 0;
    while (credit_num <= 0)
    {
        credit_num = get_long("Enter card number: ");
    }

    return credit_num;
}

bool credit_valid(long credit_num)
{
    // Check if credit card number satisfies Luhn's algorithm.
    int count = 0;
    int cur_num = 0;
    long card_num = credit_num;

    int sum_mul_2 = 0;
    int sum_not_mul_2 = 0;

    // Credit card numbers are at least 13 digits starting with 4 (VISA)
    if (card_num > 400000000000)
    {
        while (card_num > 0)
        {
            // Get the last digit of card number.
            cur_num = card_num % 10;

            // Count keeps track of which numbers to multiply by 2.
            if (count % 2 == 0)
            {
                sum_not_mul_2 += cur_num;
            }
            else
            {
                cur_num *= 2;
                while (cur_num > 0)
                {
                    sum_mul_2 += cur_num % 10;
                    cur_num /= 10;
                }
            }

            // Discard the last digit of card number.
            card_num /= 10;
            count++;
        }

        // Check if last digit of sum is 0.
        if ((sum_mul_2 + sum_not_mul_2) % 10 == 0)
        {
            return true;
        }
    }

    return false;
}

string credit_type(long credit_num)
{
    // Check the type of card.
    long num = credit_num;

    // Get first two digits of card number.
    while (num >= 100)
    {
        num /= 10;
    }

    if (num == 34 || num == 37)
    {
        return "AMEX";
    }
    else if (num > 39 && num < 50)
    {
        return "VISA";
    }
    else if (num > 50 && num < 56)
    {
        return "MASTERCARD";
    }

    return "INVALID";
}
