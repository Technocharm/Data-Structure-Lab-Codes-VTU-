#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char name[20];
    char ssn[20];
    char dept[20];
    char designation[20];
    int salary;
    int phno;
    struct employee *rlink;
    struct employee *llink;
};

typedef struct employee *EMPLOYEE;
EMPLOYEE start = NULL;

EMPLOYEE create()
{
    EMPLOYEE node;
    node = (EMPLOYEE)malloc(sizeof(struct employee));
    if (node == NULL)
    {
        printf("Memory allocation failed!!!\n");
        exit(0);
    }
    else
    {
        printf("Enter the data: \n");
        printf("Enter name, ssn, dept, designation, salary, phno : \n");
        scanf("%s%s%s%s%d%d", node->name, node->ssn, node->dept, node->designation, &node->salary, &node->phno);
        node->rlink = NULL;
        node->llink = NULL;
        return node;
    }
}

void create_list()
{
    int i, n;
    EMPLOYEE new, temp;
    printf("No of employees to be added: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        new = create();
        if (start == NULL)
        {
            start = new;
        }
        else
        {
            temp=start;
            while (temp->rlink != NULL)
            {
                temp=temp->rlink;
            }
            temp->rlink=new;
            new->llink=temp;
        }
    }
}

void display()
{
    int count = 0;
    EMPLOYEE temp;
    temp = start;

    if (start == NULL)
    {
        printf("It's empty!!!\n");
        return;
    }
    while (temp != NULL)
    {
        printf("Employee %d Details\n",count+1);
        printf("name : %s\n ,ssn : %s\n,dept : %s\n , designation : %s\n , salary : %d\n , phno : %d\n  \n", temp->name, temp->ssn, temp->dept, temp->designation, temp->salary, temp->phno);
        temp = temp->rlink;
        count++;
    }
    printf("The total no of nodes: %d\n", count);
}

void insert_front()
{
    EMPLOYEE node;
    node=create();
    if(start==NULL)
    {
        start=node;
    }
    else
    {
        node->rlink=start;
        start->llink=node;
        start=node;
    }
}

void insert_end()
{
    EMPLOYEE node,temp;
    
    node=create();
    if(start==NULL)
    {
        start=node;
    }
    else
    {
        temp=start;
        while(temp->rlink != NULL)
        {
            temp=temp->rlink;
        }
        temp->rlink=node;
        node->llink=temp;
    }
}

void delete_end()
{
    EMPLOYEE temp,prev;
    temp=start;
    if(temp==NULL)
    {
        printf("List is empty!!!");
        exit(0);
    }
    else if(temp->rlink==NULL)
    {
        printf("Deleted ssn %s",temp->ssn);
        free(temp);
        start=NULL;
    }
    else
    {
        while(temp->rlink!=NULL)
        {
            prev=temp;
            temp=temp->rlink;
        }
        prev->rlink=NULL;
        printf("Deleted ssn %s",temp->ssn);
        free(temp);
    }
}

void delete_front()
{
    EMPLOYEE temp;
    temp=start;
    if(temp==NULL)
    {
        printf("List is empty!!!");
        exit(0);
    }
    else if(temp->rlink==NULL)
    {
        printf("Deleted ssn %s",temp->ssn);
        free(temp);
        start=NULL;
    }
    else
    {
        start=temp->rlink;
        start->llink=NULL;
        printf("Deleted ssn %s",temp->ssn);
        free(temp);
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("______________________\n");
        printf("MENU:\n");
        printf("1.Create\n");
        printf("2.Display\n");
        printf("3.Insert at front\n");
        printf("4.Insert at end\n");
        printf("5.Delete from front\n");
        printf("6.Delete from end\n");
        printf("7.Exit\n");
        printf("________________________\n");
        printf("Enter your choice: \n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create_list();
            break;
        case 2:
            display();
            break;
        case 3: 
            insert_front();
            break;
        case 4: 
            insert_end();
            break;
        case 5: 
            delete_front();
            break;
        case 6: 
            delete_end();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice!!!\n");
            break;
        }
    }
    return 0;
}