#include <stdio.h>
char lower(char ch);
int main()
{
	char ch;
	printf("please input a letter: ");
    scanf("%c", &ch);
    ch = lower(ch);
   	printf("%c", ch);
   	   
} 

char lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
    	ch = ch + 'a' - 'A';
	return ch;
}

/* a  97   
   A  65   */