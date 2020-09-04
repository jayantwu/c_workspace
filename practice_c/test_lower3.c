#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char lower(char ch);
int main()
{
	char ch;
	char *s;
	int i;
	while ((s = (char*)malloc(10*sizeof(char))) == NULL)
		printf("no memery!!");
	
	printf("please input a str: ");
    gets(s);
    for (i = 0; i <= strlen(s)-1; i++)
		*(s+i) = lower(*(s+i));
   	puts(s);
   	   
} 

char lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
    	ch = ch + 'a' - 'A';
	return ch;
}

