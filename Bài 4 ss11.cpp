#include <stdio.h>

int main()
{
    int mang[] = {5, 1, 4, 2, 8};
    int kich_co = sizeof(mang) / sizeof(mang[0]);
    int i, j, temp;

    printf("Mang ban dau: ");
    for (i = 0; i < kich_co; i++)
    {
        printf("%d ", mang[i]);
    }
    printf("\n");

    for (i = 0; i < kich_co - 1; i++)
    {
        for (j = 0; j < kich_co - i - 1; j++)
        {
            if (mang[j] > mang[j + 1])
            {
                temp = mang[j];
                mang[j] = mang[j + 1];
                mang[j + 1] = temp;
            }
        }
    }

    printf("Mang da sap xep: ");
    for (i = 0; i < kich_co; i++)
    {
        printf("%d ", mang[i]);
    }
    printf("\n");

    return 0;
}
