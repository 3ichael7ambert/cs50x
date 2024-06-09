#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool only_digits(string str);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the argument contains only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert command-line argument to an integer
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    // Encrypt plaintext and print ciphertext
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

bool only_digits(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    if (isalpha(c))
    {
        char base = isupper(c) ? 'A' : 'a';
        return ((c - base + key) % 26) + base;
    }
    return c;
}
