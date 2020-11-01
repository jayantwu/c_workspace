#include <stdio.h>
#include <stdbool.h>
typedef int ElementType;
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a;
	*a = *b;
	*b = t;
}



void BubbleSort(ElementType A[], int N)
{
	int P, i;
	bool flag;
	
	for (P = N-1; P >=0 ; P--)
	{
		flag = false;
		for (i=0; i < P; i++)
		{
			if (A[i] > A[i+1])
			{
				Swap(&A[i], &A[i+1]);
				flag = true;
			}
		}
		if (flag == false)
			break;
	}
}

int main()
{
	int i;
	ElementType a[10] = {4, 8, 3, 0, 9, 7, 5, 1, 6, 2};
	
	
	for (i=0; i < 10; i++)
		printf("%d\t", a[i]);
	printf("\n");
	BubbleSort(a, 10);
	
	for (i=0; i < 10; i++)
		printf("%d\t", a[i]);
    printf("\n");
    return 0;
}