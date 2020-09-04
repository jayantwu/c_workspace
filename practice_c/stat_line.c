#include <stdio.h>
//stat line
int main()
{
	int nl;
	int c;
	nl = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c == '\n') 
		    ++nl;
	}
	printf("%d\n", nl);
}