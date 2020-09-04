#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char lower(char ch);
char upper(char ch); 
int main()
{
	char ch;
	char *s;
	int i;
	while ((s = (char*)malloc(10*sizeof(char))) == NULL)
		printf("no memery!!");
	
	printf("please input a str: ");
    gets(s);
    
	if (*s <= 'z' && *s >= 'a')
    	*s = upper(*s);
	else if ((*s <= 'Z' && *s >= 'A'))
		 *s = lower(*s);
    
	for (i = 1; i <= strlen(s)-1; i++)	
		if (*(s+i-1)== ' ' && *(s + i) >= 'a' && *(s + i) <= 'z')
			*(s+i) = upper(*(s+i));
		else if (*(s+i-1) != ' ' && *(s + i) >= 'A' && *(s + i) <= 'Z')
		    *(s+i) = lower(*(s+i));
   	puts(s);
   	   
} 

char lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
    	ch = ch + 'a' - 'A';
	return ch;
}


char upper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
    	ch = ch - ('a' - 'A');
	return ch;
}




/*
   wu jaiyang
wu jiayang





*/