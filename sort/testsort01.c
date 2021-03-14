#include<stdio.h>
#include<stdbool.h>
#include<string.h>
 
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
} 

//简单插入排序 
void insertsort(int a[], int n)
{
	int p,  i;
	int temp;
	for (p = 1;  p < n;  p++)   //初始时，第一个元素认为是已排序的 
	{
		temp = a[p];
		for (i = p; i >  0  && (temp<a[i-1]); i--)    //未排序的第一个元素从后往前与已排序的元素逐个比较，小于时，已排序的元素后移 
		{
			a[i] = a[i-1];  //后移 
		}
		a[i] = temp;
	}
} 

//冒泡排序 
void bubblesort(int a[], int n)
{
	int p,i;
	bool flag;
	for (p = n-1; p >=0; p--)  //n-1趟冒泡 
	{
		flag = false;
		for(i = 0; i < p; i++)
		{
			if(a[i] > a[i+1])
			{
				swap(&a[i], &a[i+1]); 
				flag = true;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
} 
//快速排序 
void myqsort(int a[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int pivot = a[left];  //选第一个作为主元
	int low = left+1;
	int high  = right;
	while(1)
	{
		while(a[low] < pivot)
			low++;
		while(a[high] > pivot)
			high--;
		if (low < high)
			swap(&a[low], &a[high]);
		else
			break;
	}
	printf("aaa\n");
	swap(&a[high], &a[left]);
	myqsort(a, left, high-1);
	myqsort(a, high+1, right);	 
}

void quiksort(int a[], int n)
{
	myqsort(a, 0, n-1);
}


//归并排序
void merge(int a[], int temp[], int L, int R, int Rightend)
{
	//将a[l]-a[r-1]  和  a[r]-a[rightend]归并成一个
	int num = Rightend - L + 1;
	int Tmp = L;   //辅助数组的L位置开始放 
	int Leftend = R - 1;
	int i;
	
	while (L <= Leftend && R <= Rightend)
	{
		if (a[L] <= a[R])
			temp[Tmp++] = a[L++];
		else
			temp[Tmp++] = a[R++];
			 
	} 
	while(L <= Leftend)
		temp[Tmp++] = a[L++];
		
	while(R<=Rightend)
		temp[Tmp++] = a[R++];
		
	for (i = 0; i < num; i++, Rightend--)
		a[Rightend] = temp[Rightend];//从后往前放会a[] 
	 
} 

void merge1(int a[], int temp[], int L, int R, int Rightend)
{
	//将a[l]-a[r-1]  和  a[r]-a[rightend]归并成一个
	int num = Rightend - L + 1;
	int Tmp = L;   //辅助数组的L位置开始放 
	int Leftend = R - 1;
	int i;
	
	while (L <= Leftend && R <= Rightend)
	{
		if (a[L] <= a[R])
			temp[Tmp++] = a[L++];
		else
			temp[Tmp++] = a[R++];
			 
	} 
	while(L <= Leftend)
		temp[Tmp++] = a[L++];
		
	while(R<=Rightend)
		temp[Tmp++] = a[R++];
		
} 



void Msort(int a[], int temp[], int L,  int Rightend)
{
	int center;
	if (L < Rightend)
	{
		center = L + (Rightend-L)/2;
		Msort(a,temp, L,center);
		Msort(a, temp, center+1, Rightend);
		merge(a, temp, L, center+1,  Rightend);	
	}
	
}

void mergesort(int a[], int n)
{
	int *temp = (int *)malloc(n*sizeof(int));
	if (temp != NULL)
	{
		Msort(a, temp, 0, n-1);
		free(temp);
	}
	else
		return;;
}


//迭代方式 
void mergepass(int a[], int temp[], int N, int length)//length为当前子序列的长度，一趟之后length乘以2 
{
	int i,j;
	for (i=0; i <= N-2*length; i+= 2*length)
	{
		merge1(a, temp, i, i+length, i+2*length-1);
	}	
	if(i+length < N)
		merge1(a, temp, i, i+length, N-1);
	else
	{
		for (j = i; j < N; j++)
			temp[j] = a[j];
	}
		
} 


void merge_sort(int a[], int n)
{
	int length = 1;
	int *temp = (int*)malloc(n*sizeof(int));
	if (temp != NULL)
	{
		while(length < n)
		{
			mergepass(a, temp, n, length);
			length *= 2;
			mergepass(temp, a, n, length);
			length *= 2;
		}
		free(temp);
	}
	else
		return -1;
}



int main()
{
	int a[5] =  {
	3, 5,  2, 1, 4
	};
	//insertsort(a, 5);
	//bubblesort(a, 5);
	//quiksort(a,5);
	//mergesort(a, 5);
	merge_sort(a, 5);
	int i;
	for (i=0; i  <  5; i++)
		printf("%d ", a[i]);
		
	return 0;
}