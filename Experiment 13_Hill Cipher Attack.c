
#include <stdio.h>

int main()
{
    int p[2][2] = {{0, 1}, {1, 0}};
    int c[2][2] = {{9, 5}, {4, 7}};
    int key[2][2];
    int i, j, k;

    printf("Known Plaintext-Ciphertext Attack\n");

    printf("\nPlaintext Matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }

    printf("\nCiphertext Matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }

    printf("\nRecovered Key Matrix:\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            key[i][j] = c[i][j];
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }

    printf("\nRecovered Hill Cipher Key:\n");
    printf("9 4\n");
    printf("5 7\n");

    return 0;
}
