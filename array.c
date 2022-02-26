#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int a[MAX], n;

void create()
{
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display()
{
    printf("The Elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert()
{
    int ele, p;
    printf("Enter the element to be inserted: \n");
    scanf("%d", &ele);
    printf("Enter the position: \n");
    scanf("%d", &p);
    int temp = a[n];
    n = n + 1;
    for (int i = n; i >= p; i--)
    {
        a[i + 1] = a[i];
    }
    a[p] = ele;
    printf("Element inserted\n");
}

void delete ()
{
    int ele, p;
    printf("Enter the position: \n");
    scanf("%d", &p);
    ele = a[p];
    for (int i = p + 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }
    n = n - 1;
    printf("Element deleted= %d\n", ele);
}

int main()
{
    int n, c;
    while (1)
    {
        printf("Menu\n");
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert\n");
        printf("4.Delete\n");
        printf("5.Exit\n");
        printf("Enter the choice: \n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice!!!");
            break;
        }
    }
    return 0;
}