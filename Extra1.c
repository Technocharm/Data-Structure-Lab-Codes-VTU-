#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

typedef struct node* n;

n start=NULL;

n getnode(int ele){
    n newnode=(n)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->link=NULL;
    return newnode;
}

void create_list(){
    int m,ele;
    printf("Enter the no of elements: ");
    scanf("%d",&m);
    printf("Enter elements: ");
    for(int i=0;i<m;i++){
        scanf("%d",&ele);
        n newnode=getnode(ele);
        if(start==NULL){
            start=newnode;
        }
        else{
            newnode->link=start;
            start=newnode;
        }
    }
}

void display(){
    n temp=start;
    while(temp){
        printf(" <- %d",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void sumnode(){
    int m,c=1,sum=0;
    printf("Enter the no of nodes u want sum for: ");
    scanf("%d",&m);
    n temp=start;
    while(temp && c<=m){
        c++;
        sum=sum+temp->data;
        temp=temp->link;
    }
    printf("Sum of %d nodes is: %d\n",m,sum);
}

int main(){
    
    create_list();
    display();
    sumnode();
    return 0;
}