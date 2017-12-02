#include <stdio.h>
#include <stdlib.h>

char *getStringHeap(){
	char *str = (char*)malloc(sizeof("Will I be printed?"));
    str = "Will I be printed?";    
    return str;
}

//it is allocated on stack
char *getString(){
    char str[] = "Will I be printed?";    
    return str;
}

int main(){
    printf("%s", getString());
    getchar();
}