#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[])
{
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            k++;
        }
    }

    printf("\nPlayfair Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%c ", matrix[i][j]);

        printf("\n");
    }
}

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char text[])
{
    int i, r1, c1, r2, c2;
    char a, b;

    printf("\nEncrypted Text: ");

    for (i = 0; text[i] != '\0'; i += 2)
    {
        a = text[i];
        b = text[i + 1];

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        if (r1 == r2)
        {
            a = matrix[r1][(c1 + 1) % 5];
            b = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            a = matrix[(r1 + 1) % 5][c1];
            b = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            a = matrix[r1][c2];
            b = matrix[r2][c1];
        }

        printf("%c%c", a, b);
    }

    printf("\n");
}

int main()
{
    char key[100], plaintext[200], text[200];
    int i, j = 0;

    printf("Enter keyword: ");
    scanf("%99s", key);

    printf("Enter plaintext: ");
    scanf("%199s", plaintext);

    generateMatrix(key);

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha((unsigned char)plaintext[i]))
        {
            char ch = toupper(plaintext[i]);

            if (ch == 'J')
                ch = 'I';

            text[j++] = ch;
        }
    }

    text[j] = '\0';

    char prepared[200];
    int k = 0;

    for (i = 0; i < j; )
    {
        prepared[k++] = text[i++];

        if (i < j && text[i] == prepared[k - 1])
        {
            prepared[k++] = 'X';
        }
        else if (i < j)
        {
            prepared[k++] = text[i++];
        }
    }

    if (k % 2 != 0)
        prepared[k++] = 'X';

    prepared[k] = '\0';

    printf("\nPrepared Plaintext: %s\n", prepared);

    encrypt(prepared);

    return 0;
}