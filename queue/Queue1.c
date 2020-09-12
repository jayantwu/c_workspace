#include <stdio.h>
#include <stdbool.h>

typedef int Position;
typedef struct QNode* PtrToQNode;
struct QNode{
	ElementType *Data;
	Position Front, Rear;
	int MaxSize;
} ;
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize)
{
	Queue Q =(Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType)calloc(MaxSize, sizeof(ElementType));
	Q->Front  = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

bool IsFull(Queue Q)
{
	return (Q->Front == (Q->Rear+1) % Q->MaxSize);
}

bool AddQ(Queue Q, ElementType X)
{
	if (IsFull(Q))
	{
		printf("队满了\n");
		return false;
	}
	else
	{
		Q->Rear = (Q->Rear+1) % Q->MaxSize; //向后移动一个 ，新的rear的位置 
		Q->Data[Q->Rear] = X;
		return true;
	}
}

bool IsEmpty(Queue Q)
{
	return (Q->Front == Q->Rear);
} 

ElementType DeleteQ(Queue Q)
{
	if (IsEmpty(Q))
	{
		printf("队列空\n");
		return ERROR;
	}
	else
	{
		Q->Front = (Q->Front+1) % Q->MaxSize;
		return Q->Data[Q->Front];//???
	}

}

