#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    // Prompt the user for the pyramid's height within the specified range
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); // Re-prompt if the input is not within the range

    // Build the pyramids
    for (int row = 0; row < height; row++)
    {
        // Print spaces to align the left pyramid
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // Print hashes for the left pyramid
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }

        // Print the gap between the two pyramids
        printf("  ");

        // Print hashes for the right pyramid
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }

        // Move to the next line after printing each row
        printf("\n");
    }

    return 0;
}
