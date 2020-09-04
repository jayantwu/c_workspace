#include <stdio.h>
void squeeze(char *s, char c ); 
int main()
{
	char s[80];
	char c;
	printf("input a str:");
	gets(s);
	printf("input the char you want to del:");
	scanf("%c", &c);
	squeeze(s, c);
	puts(s);
	
}

void squeeze(char *s, char c)
{
	int i, j;
	for (i=j=0; *(s+i) != '\0'; i++)
		if (*(s+i) != c)
			
		{
			*(s+j) = *(s+i);
			j++;	
		}
		    
	
	*(s+j) = '\0';
	
}
