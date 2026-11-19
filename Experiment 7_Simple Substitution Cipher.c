
#include <stdio.h>
#include <string.h>

struct Map
{
    char *symbol;
    char letter;
};

int main()
{
    char text[1000];
    int i, j, found;

    struct Map key[] = {
        {"5",'a'}, {"3",'g'}, {"‡",'o'},
        {"†",'d'}, {"0",'l'}, {")",'e'},
        {"6",'s'}, {"*",'t'}, {";",'h'},
        {"4",'i'}, {"8",'n'}, {"2",'b'},
        {".",'r'}, {"¶",'f'}, {"]",'u'},
        {":",'c'}, {"(",'w'}, {"9",'v'},
        {"1",'p'}, {"?",'y'}, {"—",'m'}
    };

    int n = sizeof(key) / sizeof(key[0]);

    printf("Enter ciphertext:\n");
    int ch;
i = 0;

while ((ch = getchar()) != EOF && ch != '\n')
{
    text[i++] = ch;
}
text[i] = '\0';
    printf("\nDecrypted Text:\n");

    for (i = 0; text[i] != '\0'; )
    {
        found = 0;

        for (j = 0; j < n; j++)
        {
            int len = strlen(key[j].symbol);

            if (strncmp(&text[i], key[j].symbol, len) == 0)
            {
                printf("%c", key[j].letter);
                i += len;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            if (text[i] != '\n' && text[i] != '\r')
                printf("%c", text[i]);

            i++;
        }
    }

    printf("\n");

    return 0;
}
