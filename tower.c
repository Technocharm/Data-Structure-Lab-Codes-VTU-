#include <stdio.h>

void tower(int n,char src,char mid, char dest){
    if(n==1){
        printf("%c ----> %c\n",src,dest);
    }
    else{
        tower(n-1,src,dest,mid);
        tower(1,src,mid,dest);
        tower(n-1,mid,src,dest);
    }
}

int main(){
    int n;
    printf("Enter the no of disks: ");
    scanf("%d",&n);
    tower(n,'A','B','C');
    return 0;
}