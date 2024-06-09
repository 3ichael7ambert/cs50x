#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Enter the height of the pyramid (a positive integer): ");
    }
    while (height <= 0);
    for (int row = 0; row < height; row++)
    {

        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}
