#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	char arr1[] = "Yo woah !";
	char arr2[7];

	for(int i=0 ; i<7 ; i++){
		arr2[i] = 'a';
	}

	//it will behave correctly because it has inserted '\0' at end of string
	printf("%d\n",strlen(arr1));

	//every char array is not a string as here as it is not terminated by '\0' 	arr2[6] = '\0' can make it correct 
	printf("%d\n",strlen(arr2));

	return 0;
}