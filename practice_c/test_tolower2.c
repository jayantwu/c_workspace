#include <stdio.h>
int lower(char *ch);
int main()
{
	char *ch;
	printf("please input a letter: ");
    scanf("%c", ch);
    lower(ch);
   	printf("%c", *ch);
   	   
} 

int lower(char *ch)
{
	if (*ch >= 'A' && *ch <= 'Z')
    	*ch = *ch + 'a' - 'A';
	return 0;
}
