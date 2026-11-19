
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[200], cipher[200], plain[200];
    int key[2][2] = {{9, 4}, {5, 7}};
    int inv[2][2] = {{5, 12}, {15, 25}};
    int i, k = 0;
    int p1, p2, c1, c2;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)text[i]))
            plain[k++] = tolower(text[i]);
    }

    if (k % 2 != 0)
        plain[k++] = 'x';

    plain[k] = '\0';

    printf("\nEncrypted Text: ");

    for (i = 0; i < k; i += 2)
    {
        p1 = plain[i] - 'a';
        p2 = plain[i + 1] - 'a';

        c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
        c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;

        cipher[i] = c1 + 'a';
        cipher[i + 1] = c2 + 'a';

        printf("%c%c", cipher[i], cipher[i + 1]);
    }

    cipher[k] = '\0';

    printf("\n\nDecrypted Text: ");

    for (i = 0; i < k; i += 2)
    {
        c1 = cipher[i] - 'a';
        c2 = cipher[i + 1] - 'a';

        p1 = (inv[0][0] * c1 + inv[0][1] * c2) % 26;
        p2 = (inv[1][0] * c1 + inv[1][1] * c2) % 26;

        printf("%c%c", p1 + 'a', p2 + 'a');
    }

    printf("\n");

    return 0;
}
