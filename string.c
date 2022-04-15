#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char mainstr[100],pat[50],rep[50],ans[100];
int flag=0;

void stringmatch(){
    int c,m,i,j;
    c=m=i=j=0;
    while(mainstr[c]!='\0'){
        if(mainstr[m]==pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag=1;
                for(int k=0;rep[k]!='\0';j++,k++){
                    ans[j]=rep[k];
                }
                i=0;
                c=m;
            }
        }
        else{
            ans[j]=mainstr[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
}

int main(){
    printf("Enter the main string: ");
    gets(mainstr);
    printf("Enter the pattern string: ");
    gets(pat);
    printf("Enter the replacement string: ");
    gets(rep);
    stringmatch();
    if(flag){
        puts(ans);
    }
    else{
        printf("Pattern not found!!!\n");
    }
    return 0;
}