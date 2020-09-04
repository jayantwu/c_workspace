#include <stdio.h>
//#include <stdlib.h>
void strmcpy(char *s, char *t, int m);
int main()
{
	char t[100], s[100];
	int m;
	printf("input a str:");
	gets(t);
	printf("input a num:");
	scanf("%d", &m);
	strmcpy(s, t, m);
	puts(s);
		
}

void strmcpy(char *s, char *t, int m)
{
	int i, j;
	for (i = m - 1, j = 0; t[i] != '\0'; i++, j++)
		s[j] = t[i];
	s[j] = '\0';
	
}
