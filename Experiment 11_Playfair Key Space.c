
#include <stdio.h>
#include <math.h>

int main()
{
    double keys = 1;
    int i;

    for (i = 1; i <= 25; i++)
    {
        keys *= i;
    }

    printf("Total possible keys = 25! = %.0f\n", keys);

    printf("Approximate power of 2 = 2^%.2f\n",
           log2(keys));

    printf("\nEffectively unique keys = 25! / 4\n");

    printf("Approximate power of 2 = 2^%.2f\n",
           log2(keys / 4));

    return 0;
}
