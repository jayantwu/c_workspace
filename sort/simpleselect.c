#include <stdio.h>
typedef int ElementType;
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a;
	*a = *b;
	*b = t;
}

void SimpleSelectionSort(ElementType A[], int N)
{
	int i, j, min;
	for (i = 0; i < N-1; i++)
	{
		min = i;    //第一次循环最小元素位置设置为第一个元素位置
		for (j = i+1; j < N; j++)  //遍历后面的元素，找到一个比min小的，记录下来，继续遍历
			if (A[j] < A[min])
				min = j;  //记录最小元素的位置
		//遍历完之后：	
		if (min==i)
			continue;
		else
			Swap(&A[i], &A[min]);
	}
}

int main()
{
	int i;
	ElementType a[10] = {4, 8, 3, 0, 9, 7, 5, 1, 6, 2};
	
	
	for (i=0; i < 10; i++)
		printf("%d\t", a[i]);
	printf("\n");
	SimpleSelectionSort(a, 10);
	
	for (i=0; i < 10; i++)
		printf("%d\t", a[i]);
    printf("\n");
    return 0;
}
	


			