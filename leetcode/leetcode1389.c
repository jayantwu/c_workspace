#include<stdio.h>
#include<stdlib.h>
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    
    *returnSize  = numsSize;
	int i;
    int last_index = -1;  //数组为空；
    int *target = (int*)malloc(*returnSize * sizeof(int));
    for (i=0; i < numsSize; i++)
    {
        insert(target, &last_index, nums[i], index[i]);
    }
    
	return target;
}

int insert(int * A, int *last_index, int data, int pos)
{   
    int i;
	if (*last_index == -1)
    {
        A[pos] = data;
        (*last_index)++;
        return 0;
		
    }  
    for (i = *last_index; i > pos-1;  i--)
        A[i+1] = A[i];
    A[pos] = data;
    (*last_index)++;
    return 0;
}


int main()
{
	int i;
	int nums[] = {0, 1, 2, 3, 4};
	int index[] = {0, 1, 2, 2, 1};
	int returnSize;
	int *p;
	p = createTargetArray(nums, 5, index, 5, &returnSize);
	for (i = 0; i < returnSize; i++)
		printf("%d\t", *(p+i));
	return 0;
}
	