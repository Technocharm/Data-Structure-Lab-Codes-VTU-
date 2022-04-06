#include <stdio.h>

void LP(int k1, int k, int n, int HT[])
{
    int L = k1 % n;
    if (HT[L] == 0)
    {
        HT[L] = k;
    }
    else
    {
        LP(k1 + 1, k, n, HT);
    }
}

int main()
{
    int i, n;
    printf("Enter the array size: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the key of the employees: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int HT[n];
    for (i = 0; i < n; i++)
    {
        HT[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        int L = a[i] % n;
        if (HT[L] == 0)
        {
            HT[L] = a[i];
        }
        else
        {
            LP(a[i] + 1, a[i], n, HT);
        }
    }

    printf("The HASH TABLE is: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", HT[i]);
    }
    return 0;
}