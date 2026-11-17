
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf("%99s", text);

    printf("Enter key: ");
    scanf("%99s", key);

    printf("\nEncrypted Text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        char ch = toupper(text[i]);
        char k = toupper(key[j % strlen(key)]);

        char encrypted = ((ch - 'A' + k - 'A') % 26) + 'A';

        printf("%c", encrypted);
        j++;
    }

    printf("\n");
    return 0;
}
