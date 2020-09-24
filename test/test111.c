#include <stdio.h>
char lower(char ch);
int main()
{
	char ch;
	while ((ch = getchar())!= '\n')
	{
		printf("%c", ch = lower(ch));
	}
	
} 

char lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
    	ch = ch + 'a' - 'A';
	return ch;
}


