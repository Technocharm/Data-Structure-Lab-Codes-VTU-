#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct poly
{
    float coeff;
    int ex, ey, ez;
    struct poly *link;
};

typedef struct poly *p;

p newnode()
{
    p node = (p)malloc(sizeof(struct poly));
    return node;
}

p create()
{
    p temp, head, curr;
    int n;
    head = newnode();
    head->coeff = -1;
    head->ex = -1;
    head->ey = -1;
    head->ez = -1;
    head->link = head;
    printf("Enter the no of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        temp = newnode();
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%f", &temp->coeff);
        printf("Enter the exponent of x, y and z of term %d: ", i + 1);
        scanf("%d%d%d", &temp->ex, &temp->ey, &temp->ez);
        curr = head;
        while (curr->link != head)
        {
            curr = curr->link;
        }
        curr->link = temp;
        temp->link = head;
    }
    return head;
}

void display(p polynom)
{
    p temp = polynom->link;
    while (temp != polynom)
    {
        printf("%.1f(x^%d)(y^%d)(z^%d)", temp->coeff, temp->ex, temp->ey, temp->ez);
        temp = temp->link;
        if (temp != polynom)
        {
            printf("+");
        }
    }
}

void evaluate()
{
    int x, y, z, sum = 0;
    p polyeval = create();
    display(polyeval);

    printf("\nEnter the values of x,y and z: ");
    scanf("%d%d%d", &x, &y, &z);
    p temp = polyeval->link;
    while (temp != polyeval)
    {
        sum = sum + (temp->coeff * pow(x, temp->ex) * pow(y, temp->ey) * pow(z, temp->ez));
        temp = temp->link;
    }
    printf("The value of the polynomial at x= %d, y= %d and z= %d is %d", x, y, z, sum);
}

int compare(p poly1, p poly2)
{
    if (poly1->ex > poly2->ex || poly1->ey > poly2->ey || poly1->ez > poly2->ez)
    {
        return 1;
    }
    else if (poly1->ex < poly2->ex || poly1->ey < poly2->ey || poly1->ez < poly2->ez)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void attach(p *head, int coeff, int ex, int ey, int ez)
{
    p temp = newnode();
    temp->coeff = coeff;
    temp->ex = ex;
    temp->ey = ey;
    temp->ez = ez;
    (*head)->link = temp;
    *head = temp;
}

void polyadd(p poly1, p poly2)
{
    p start_poly1, poly, last_poly;
    int sum, flag = 0;
    start_poly1 = poly1;
    poly1 = poly1->link;
    poly2 = poly2->link;
    poly = newnode();
    poly->coeff = -1;
    poly->ex = -1;
    poly->ey = -1;
    poly->ez = -1;
    last_poly = poly;
    do
    {
        switch (compare(poly1, poly2))
        {
        case 1:
            if (start_poly1 == poly1)
            {
                flag = 1;
            }
            attach(&last_poly, poly1->coeff, poly1->ex, poly1->ey, poly1->ez);
            poly1 = poly1->link;
            break;
        case 2:
            attach(&last_poly, poly2->coeff, poly2->ex, poly2->ey, poly2->ez);
            poly2 = poly2->link;
            break;
        case 0:
            if (start_poly1 == poly1)
            {
                flag = 1;
            }
            else
            {
                sum = poly1->coeff + poly2->coeff;
                if (sum)
                {
                    attach(&last_poly, sum, poly1->ex, poly1->ey, poly1->ez);
                }
                poly1 = poly1->link;
                poly2 = poly2->link;
            }
            break;
        }
    } while (!flag);
    last_poly->link = poly;
    printf("\nPolynomial 1 + Polynomial 2: \n");
    display(poly);
}

int main()
{
    int c;
    p poly1 = NULL, poly2;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("MENU\n");
        printf("1.Add\n");
        printf("2.Evaluate\n");
        printf("3.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &c);
        printf("\n--------------------------------------\n");
        switch (c)
        {
        case 1:
            printf("\nEnter details of Polynomial 1: \n");
            poly1 = create();
            printf("\nPolynomial 1: \n");
            display(poly1);
            printf("\nEnter details of Polynomial 2: \n");
            poly2 = create();
            printf("\nPolynomial 2: \n");
            display(poly2);
            polyadd(poly1, poly2);
            break;
        case 2:
            evaluate();
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid Input\n");
            break;
        }
    }
    return 0;
}