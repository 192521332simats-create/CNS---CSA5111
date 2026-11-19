
#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    printf("\nEncrypted Text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            p = toupper(text[i]) - 'A';
            c = (a * p + b) % 26;

            printf("%c", c + 'A');
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");
    return 0;
}
