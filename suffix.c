#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define MAX 20
double a[MAX];
int top = -1;

void push(double ele)
{
    if (top == MAX-1)
    {
        printf("Overflow!!!\n");
    }
    else
    {
        a[++top] = ele;
    }
    printf("Element inserted\n");
}

double pop()
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

double eval(double op1, double op2, char opr){
    switch(opr){
        case '+': return op1 + op2;
        case '*': return op1*op2;
        case '-': return op1-op2;
        case '/': return op1/op2;
        case '%': return fmod(op1,op2);
        case '^': return pow(op1,op2);
        case '#': return 0;
    }
}

int main()
{
    double r,op1,op2,res;
    char s[MAX];
    printf("Enter the suffix: ");
    scanf("%s",s);
    push('#');
    for(int i=0;s[i]!='\0';i++){
        if(isdigit(s[i])){
            push(s[i]-='0');
        }
        else{
            op1=pop();
            op2=pop();
            r=eval(op1,op2,s[i]);
            push(r);
        }
    }
    res=pop();
    printf("%lf",res);
    return 0;
}