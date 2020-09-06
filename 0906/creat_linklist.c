#include <stdio.h>
#include <stdlib.h>
typedef struct Node* PtrToNode;
typedef int ElementType; 
	
struct Node{
	ElementType Data;
	PtrToNode Next;
};

PtrToNode Creat_list();
void Print_list(PtrToNode L);


int main()
{

    PtrToNode L;
	L = Creat_list();
	//printf("%d-->%d-->%d\n", L->Data, L->Next->Data, L->Next->Next->Data);
    Print_list(L);
	
}

//创建一个存储整数的单向链表
PtrToNode Creat_list()
{
	ElementType num;
	PtrToNode head, tail, p;
	head = tail = NULL;
	printf("input the nums:\n");
	scanf("%d", &num);
	while (num != 0)
	{
		p = (PtrToNode) malloc(sizeof(struct Node));
		p->Data = num;
		p->Next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->Next = p;
		tail = p;
		
		scanf("%d", &num); 			
	}
	return head;

}

void Print_list(PtrToNode L)
{	
	while (L != NULL)
	{
		printf("%d", L->Data);
		L = L->Next;
		if (L != NULL)
			printf("-->");
		else
			printf("\n");
	} 		
}