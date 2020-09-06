#include <stdio.h>
int main()
{
	int i,a,n,k = 0,s = 0;
	scanf("%d %d", &n, &a);
	for(i = 1; i < n; i++)
	{	
		k = k*10+a;
		s += k;
	}
	printf("s = %d",k * 10 + a - s);
}