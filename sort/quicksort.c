#include <stdio.h>
typedef int ElementType;
void Swap(ElementType *a, ElementType *b)
{
	ElementType t = *a;
	*a = *b;
	*b = t;
}

ElementType Median3(ElementType A[], int left, int right)
{
	int center = (left+right)/2;
	if (A[left] > A[center])
		Swap(&A[left],&A[center]);
	if (A[left] > A[right])
		Swap(&A[left],&A[right]);
	if (A[center] > A[right])
		Swap(&A[center],&A[right]);
	//此时left center  right按从小到大排序
	Swap(&A[center], &A[right-1]);  //将主元放到倒数第二的位置
    /*实际只需要考虑A[left+1]~A[right-2]之间的元素*/
	return A[right-1];
}

void Qsort(ElementType A[], int left, int right)
{
	int pivot, cutoff, low, high;
	
	if (cutoff <= right - left)
	{
		pivot = Median3(A, left, right);
		low = left; high = right-1;
		while (1)
		{
			while (A[++low] < pivot)
				;
			while (A[--high] > pivot)
				;
			if (low < hihg)
				Swap(&A[low], &A[high]);
			else
				break;
		}
		Swap(&A[low], &A[right-1]);
		Qsort(A, left, low-1);
		Qsort(A, low+1, right);
	}
	else
		InsertionSort(A+left, right - left + 1); //实际从数组的 A+left位置开始，长度为right-left+1，这样的一个子序列调用简单插入排序
}

void QuickSort(ElementType A[], int N)
{
	Qsort(A, 0, N-1);
}



