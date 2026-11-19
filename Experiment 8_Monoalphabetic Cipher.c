
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char text[100];
    char key[] = "CIPHER";
    char cipher[26];
    char used[26] = {0};
    int i, j, k = 0;

    for (i = 0; key[i] != '\0'; i++)
    {
        int ch = toupper(key[i]) - 'A';

        if (!used[ch])
        {
            cipher[k++] = toupper(key[i]);
            used[ch] = 1;
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (!used[i])
            cipher[k++] = 'A' + i;
    }

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("\nEncrypted Text: ");

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
        {
            int p = toupper(text[i]) - 'A';
            printf("%c", cipher[p]);
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    printf("\n");

    return 0;
}
