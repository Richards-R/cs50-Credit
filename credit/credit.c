// Validate user input credit card numbers

#include <cs50.h>
#include <stdio.h>

long card_input;
int pos_sum;
int accum_sum;
int accum_sum2;
string card_type;

int main(void)
{

    do
    {
        card_input = get_long("Number: ");
    }
    while (card_input < 0 || card_input > 9999999999999999);

    for (long i = 100; i < 100000000000000000; i = i * 100)
    {

        long j = i / 10;
        int test = (card_input % i) / j;
        int dbl_test = test * 2;

        if (dbl_test > 9)
        {
            int tail_sum = dbl_test % 10;
            int head_sum = (dbl_test - tail_sum) / 10;
            pos_sum = tail_sum + head_sum;
        }
        else
        {
            pos_sum = dbl_test;
        }

        accum_sum = accum_sum + pos_sum;
    }

    for (long i = 10; i < 100000000000000000; i = i * 100)
    {
        long j = i / 10;
        int test = (card_input % i) / j;
        accum_sum2 = accum_sum2 + test;
    }

    int validation_num = accum_sum + accum_sum2;
    printf("validation_num %i\n", validation_num);
    if (validation_num % 10 != 0)
    {
        card_type = "not_ten_INVALID\n";
    }
    else if (validation_num % 10 == 0)
    {
        if (card_input > 340000000000000 && card_input < 349999999999999)
        {
            card_type = "AMEX\n";
        }
        else if (card_input > 370000000000000 && card_input < 379999999999999)
        {
            card_type = "AMEX\n";
        }
        else if (card_input > 5100000000000000 && card_input < 5599999999999999)
        {
            card_type = "MASTERCARD\n";
        }
        else if (card_input > 4000000000000 && card_input < 4999999999999)
        {
            card_type = "VISA\n";
        }
        else if (card_input > 4000000000000000 && card_input < 4999999999999999)
        {
            card_type = "VISA\n";
        }
        else
        {
            card_type = "INVALID\n";
        }
    }

    printf("Number: %li\n", card_input);
    printf("%s", card_type);
}
