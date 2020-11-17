#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int lena, int *b, int lenb);

int main()
{
	int i;
	int a[100] = {1,3,5,7,9};
	int b[] = {2, 4, 6, 8};
	merge(a, 5, b, 4);
	for (i = 0; i < 9; i++)
		printf("%d ", a[i]);
}
void merge(int* a, int lena, int *b, int lenb)
{
	int *p = a +lena + lenb-1;
	int *pa = a+lena-1;
	int *pb = b + lenb-1;
	while(lena && lenb)
	{
		if (*pa > *pb)
		{
			*p-- = *pa--;
			lena--;
		}
		else
		{
			
			*p-- = *pb--;
			lenb--;
		}
		
	}
	if (lena)
	{
		*p-- = *pa--;
		lena--;
	}
	else
	{
		*p-- = *pb--;
		lenb--;
	}

}



		
			
	
	
	