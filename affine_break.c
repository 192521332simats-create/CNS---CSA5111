
#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[100];
    int i, c, p;

    printf("Enter ciphertext: ");
    scanf("%99s", text);

    printf("\nDecrypted Text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            c = toupper(text[i]) - 'A';
            p = (9 * (c - 15 + 26)) % 26;

            printf("%c", p + 'A');
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");

    return 0;
}
