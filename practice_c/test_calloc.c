#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char * str;
	int i, num;
	printf("please input the num: ");
	scanf("%d", &num);
	getchar();
	printf("%d\n", num);
	str = (char *)calloc(num, sizeof(char));
	printf("pleas input a string:");
	gets(str);
    printf("%s\n", str);
    printf("%d\n", strlen(str));
    for (i=0; i < strlen(str); i++){
    	printf("%c", *(str + i));
    }
	    

} 