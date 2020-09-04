#include <stdio.h> 
#include <stdlib.h>
void circle_mov(int *a, int n, int m); 
int main()
{
	
	int n, m, i, *a;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		while ((a = (int *)malloc(n * sizeof(int))) == NULL)
 			printf("no memery");
		
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		circle_mov(a, n, m);
		
		for (i = 0; i < n; i++)
			printf("%d ", a[i]);
	}
}



 void circle_mov(int *a, int n, int m)
 {
 	int *t, i, j;
 	while ((t = (int *)malloc(n * sizeof(int))) == NULL)
 		printf("no memery");	
 	m = m % n;
 	for (i = 0; i < n; i++)
 		t[i] = a[i];
		
	for (i = m , j=0; i < n; i++, j++)
		a[i] = t[j];
		
	for (i = n - m, j=0; i < n; i++, j++)
		a[j] = t[i];
	
 } 