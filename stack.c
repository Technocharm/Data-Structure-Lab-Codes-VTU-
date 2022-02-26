#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int a[MAX], n, top = -1;

void push(int ele)
{
    if (top == MAX)
    {
        printf("Overflow!!!\n");
    }
    else
    {
        a[++top] = ele;
    }
    printf("Element inserted\n");
}

int pop()
{
    int ele;
    if (top == -1)
    {
        printf("Underflow!!!\n");
    }
    else
    {
        ele = a[top--];
    }
    return ele;
}

void display()
{
    if (top == -1)
    {
        printf("Underflow!!!\n");
    }
    else
    {
        printf("The Elements are: \n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
}

void palindrome()
{
    int m, mid, flag = 0, ele;
    printf("Enter the number: ");
    scanf("%d", &m);
    int temp = m;
    int c = 0;
    while (temp)
    {
        c++;
        push(temp % 10);
        temp = temp / 10;
    }
    if ((c - 1) % 2 == 0)
    {
        mid = c / 2;
    }
    else
    {
        mid = (c + 1) / 2;
    }
    int t = top;
    for (int i = t; i >= mid; i--)
    {
        if (a[t - i] == pop())
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("It's palindrome\n");
    }
    else
    {
        printf("It's not palindrome\n");
    }
    printf("%d", c);
    for (int i = top; i >= 0; i--)
    {
        ele = pop();
    }
}

int main()
{
    int n, c, ele;
    while (1)
    {
        printf("Menu\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Palindrome\n");
        printf("5.Exit\n");
        printf("Enter the choice: \n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Element: ");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            ele = pop();
            printf("Element deleted= %d\n", ele);
            break;
        case 3:
            display();
            break;
        case 4:
            palindrome();
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