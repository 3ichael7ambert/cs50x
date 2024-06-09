#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Initialize variables to count the number of coins
    int coins = 0;

    // Calculate the number of quarters needed
    int quarters = cents / 25;
    coins += quarters;
    cents %= 25;

    // Calculate the number of dimes needed
    int dimes = cents / 10;
    coins += dimes;
    cents %= 10;

    // Calculate the number of nickels needed
    int nickels = cents / 5;
    coins += nickels;
    cents %= 5;

    // Pennies remaining are the number of pennies needed
    coins += cents;

    // Print the minimum number of coins needed
    printf("%d\n", coins);

    return 0;
}
