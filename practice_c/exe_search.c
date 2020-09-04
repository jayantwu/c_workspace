#include <stdio.h> 
#include <stdlib.h>

int main()
{
	int n, i, x;
	int a[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &x);
	
	if (search(a, n, x) != -1)
		printf("%d\n", search(a, n, x));
	else
		printf("not found");


}


int search(int list[], int n, int x)
{
	int i, k = -1;
	for (i=0; i < n; i++)
	{
		if (list[i] == x )
			k = i;
	}
	return k;	
}




