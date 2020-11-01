#include <stdio.h>
typedef int ElementType;
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a;
	*a = *b;
	*b = t;
}

void PercDown(ElementType A[], int p, int N)
{
	int Parent, Child;
	ElementType X;
	X = A[p];
	for (Parent = p; (Parent*2+1) < N; Parent = Child)
	{
		Child = Parent*2+1;
		if((Child != N-1) && (A[Child] < A[Child+1]))
			Child++;
		if (X > A[Child]) break;
		else
			A[Parent] = A[Child];
	}
	
	A[Parent] = X;
}


void HeapSort(ElementType A[], int N)
{
	int i;
	for (i = N/2-1; i >= 0; i--)
		PercDown(A, i, N);   //建立最大堆
	
	for (i = N-1; i >0; i--)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}


	
int main()
{
	int i;
	ElementType a[10] = {4, 8, 3, 0, 9, 7, 5, 1, 6, 2};
	
	
	for (i=0; i < 10; i++)
		printf("%d\t", a[i]);
	printf("\n");
	HeapSort(a, 10);
	
	for (i=0; i < 10; i++)
		printf("%d\t", a[i]);
    printf("\n");
    return 0;
}
	
	