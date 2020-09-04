#include <stdio.h>
int add_arr(int ar1[], int ar2[], int ar3[], int n);

int main()
{
	int i;
	int ar1[] = {1, 2, 3, 4};
	int ar2[] = {5, 6, 7, 8};
	int ar3[4];
	add_arr(ar1, ar2, ar3, 4);
	for (i = 0; i < 4; i++)
		printf("%d ", ar3[i]);
	return 0;
}


int add_arr(int ar1[], int ar2[], int ar3[], int n)
{
	int i;
	for (i = 0; i < n ; i++)
		ar3[i] = ar1[i] + ar2[i];
	return 0;
}