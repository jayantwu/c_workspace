#include <stdio.h>
void reverse(int num);
int main()
{
	int num = 12345789;
	reverse(num);
	printf("\n");
}

void reverse(int num)
{
	if (num < 10)
		printf("%d", num);
	else
	{
		printf("%d", num % 10);
		reverse(num / 10);
	}
		
}