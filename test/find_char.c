#include <stdio.h>
#include<stdlib.h>
char *find(char const *source, char const *chars);


int main()
{
	char * source = "ABCDEF";
	char * chars = "XRCQEF";
	char * pch;
	pch = find(source, chars);
	printf("%c\n", *pch);
	return 0;
}


char *find(char const *source, char const *chars)
{
	char *p, *q;
	for (q = chars; *q != '\0'; ++ q)
	{	
		for (p = source; *p != '\0'; ++ p)
		{
			if (*q == *p)
				return p;
		}
	}
	return NULL;

}
	
		
	
	
			   
	

