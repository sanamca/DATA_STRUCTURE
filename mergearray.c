#include <stdio.h>
void read(int *, int);
void main()
{
    int a[20], b[20], c[20], n1, n2, i, j, k = 0;
    printf("Enter the number of elements in first array:");
    scanf("%d", &n1);
    read(a, n1);

    printf("\nEnter the number of elements in second array:");
    scanf("%d", &n2);
    read(b, n2);

    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else if (a[i] > b[j])
        {
            c[k] = b[j];
            j++;
        }
        else
        {
            c[k] = a[i];
            i++;
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        c[k] = b[j];
        j++;
        k++;
    }
    printf("\nFirst array:\n");
    for (i = 0; i < n1; i++)
        printf("%d\t", a[i]);
    printf("\nSecond array:\n");
    for (i = 0; i < n2; i++)
        printf("%d\t", b[i]);
    printf("\nMerged Array:\n");
    for (i = 0; i < k; i++)
        printf("%d\t", c[i]);
    printf("\n");
}

void read(int *p, int m)
{
    int i;
    printf("\nEnter the elements:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &p[i]);
}
