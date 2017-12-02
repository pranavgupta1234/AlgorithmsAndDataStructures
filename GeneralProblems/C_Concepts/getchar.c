#include <stdio.h>

int main(){
    int c;
    c = getchar();
    
    while(c != EOF){
         putchar(c);
         c = getchar();
    }

    if(c == EOF){
    	printf("%d\n",c);
    }

    return 0;
}