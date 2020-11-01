#include <stdio.h>
typedef int ElementType;
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a;
	*a = *b;
	*b = t;
}


void InsertionSort(ElementType A[], int N)
{
	int P, i;
	ElementType Tmp;
	for (P=1; P < N; P++)  //从第一个元素开始，第0个认为是已排序的元素
	{
		Tmp = A[P];  //取出未排序序列中的第一个元素
		for (i = P; i > 0 && A[i-1]>Tmp; i--)  //与前面的元素从后往前依次比较和交换
		{
			A[i] = A[i-1];  //往后挪
		}
		A[i] = Tmp;
	}
}


int main()
{
	int i;
	ElementType a[10] = {4, 8, 3, 0, 9, 7, 5, 1, 6, 2};
	
	
	for (i=0; i < 10; i++)
		printf("%d\t", a[i]);
	printf("\n");
	InsertionSort(a, 10);
	
	for (i=0; i < 10; i++)
		printf("%d\t", a[i]);
    printf("\n");
    return 0;
}