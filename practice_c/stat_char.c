#include <stdio.h>
//统计字符数 
int main()
{
	long int nc;
	nc = 0;
	while (getchar() != '\n')
	{
		++nc;
	}
	printf("%d\n", nc);
}