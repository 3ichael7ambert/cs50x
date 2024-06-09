//#include <stdio.h>

// int main() {
//     char name[100];
//     printf("Enter your name: ");
//     scanf("%99s", name);
//     printf("hello, %s!\n", name);
//     return 0;
// }

#include <stdio.h>
#include <cs50.h>

int main(void)
{

    string name = get_string("Enter your name: ");
    printf("hello, %s\n", name);

    return 0;
}

