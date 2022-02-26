#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[20];
    char usn[20];
    char branch[10];
    int sem;
    int phno;
    struct student *link;
};

typedef struct student *Stu;

Stu start = NULL;

Stu create()
{
    Stu node;
    node = (Stu)malloc(sizeof(struct student));
    printf("Enter Name,USN,Branch,Sem,Phno. : ");
    scanf("%s%s%s%d%d", node->name, node->usn, node->branch, &node->sem, &node->phno);
    node->link = NULL;
    return node;
}

void create_list()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Stu node = create();
        if (start == NULL)
        {
            start = node;
        }
        else
        {
            node->link = start;
            start = node;
        }
    }
}

void insertend()
{
    Stu node = create();
    if (start == NULL)
    {
        start = node;
    }
    else
    {
        Stu temp = start;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = node;
    }
}

void deleteend()
{
    Stu prev;
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else if (start->link == NULL)
    {
        start = NULL;
    }
    else
    {
        Stu temp = start;
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        free(temp);
        prev->link = NULL;
    }
}

void insertfront()
{
    Stu node = create();
    if (start == NULL)
    {
        start = node;
    }
    else
    {
        node->link = start;
        start = node;
    }
}

void deletefront()
{
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else if (start->link == NULL)
    {
        start = NULL;
    }
    else
    {
        start = start->link;
    }
}

void display()
{
    Stu temp = start;
    int count = 0;
    while (temp)
    {
        printf("Student %d\n",count+1);
        printf("Name: %s\n USN: %s\n Branch: %s\n Sem: %d\n Phno. : %d\n", temp->name, temp->usn, temp->branch, temp->sem, temp->phno);
        temp = temp->link;
        count++;
    }
    printf("Total node: %d\n", count);
}

int main()
{
    int c;
    while (1)
    {
        printf("Menu\n");
        printf("1.Create\n");
        printf("2.Insertion at front\n");
        printf("3.Insertion at end\n");
        printf("4.Deletion from front\n");
        printf("5.Deletion from end\n");
        printf("6.Display\n");
        printf("7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create_list();
            break;
        case 2:
            insertfront();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deletefront();
            break;
        case 5:
            deleteend();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Choice!!!\n");
            break;
        }
    }
    return 0;
}