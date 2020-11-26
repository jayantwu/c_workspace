#include <stdio.h>

void quiksort(int*, int, int);
void swap(int*, int*);


int main()
{
	int i;
	int a[10] = {3, 4, 5, 2, 1, 7, 10, 4, 8, 9};
	quiksort(a, 0, 10);
	for (i = 0; i < 10; i++)
		printf("%d ", a[i]);
	
	return 0;
}
	

 void quiksort(int *a, int l, int r)
{
    if (l == r)
		return;
	int left = l;
    int right = r;
    int pivot = a[l];  //第一个元素作为主元
    while (1)
    {
        while(a[++left] < pivot)
			;
        while(a[--right] > pivot)
			;
        if (left < right) 
			swap(&a[left], &a[right]);
        else
            break; 
    }
    swap(&a[right], &a[l]);//把主元放到正确的位置
    quiksort(a, l, right);
    quiksort(a, right+1, r);

}
 
void swap(int *a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
	
}


