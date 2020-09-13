#include <stdio.h> 
#include <stdbool.h> 
#define ERROR -1000

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode Next;	
};
typedef PtrToNode Position;

typedef struct QNode *PtrToQNode;
struct QNode{
	Position Front, Rear;
	int MaxSize; 
};
typedef PtrToQNode Queue;


Queue CreateQ(int MaxSize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));// 
	Q->Front = Q->Rear = NULL;
	return Q;
}

bool IsEmpty(Queue Q)
{
	return (Q->Front == NULL);
}

//插入，队尾插入一个节点 
bool addQ(Queue Q, ElementType X)
{
	PtrToNode s = (PtrToNode)malloc(sizeof(struct Node));
	if(!s)
	{
		printf("没有空间了\n");
		return false;
	}
	
	s->Data = X;
	s->Next = NULL;
	Q->Rear->Next = s;
	Q->Rear = s; //将s设置为当前的队尾 
	return true;
} 
//删除，从队头删掉一个节点 ，front向后移，并释放该节点占用的空间 
ElementType deleteQ(Queue Q)
{
	ElementType e;
	PtrToNode s;
	//PtrToNode s = (PtrToNode)malloc(sizeof(struct Node));
	if (IsEmpty(Q))
	{
		printf("队为空\n");
		return ERROR;
	}
	else
	{
		s = Q->Front; //把要删除的队首节点的地址暂存在s 
		if (Q->Front == Q->Rear)
			Q->Front = Q->Rear = NULL;  //删除后将队列置空 
		else
		{
			Q->Front = Q->Front->Next; //队首节点的地址指向下一个节点 
			e = s->Data; 
			free(s);
			return e;
		}
	
	}
} 


/*
链队
 1、结点的创建：data， next指针 
 2、队列的创建：front节点， rear节点， size 

*/ 
