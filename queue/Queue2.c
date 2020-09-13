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

//���룬��β����һ���ڵ� 
bool addQ(Queue Q, ElementType X)
{
	PtrToNode s = (PtrToNode)malloc(sizeof(struct Node));
	if(!s)
	{
		printf("û�пռ���\n");
		return false;
	}
	
	s->Data = X;
	s->Next = NULL;
	Q->Rear->Next = s;
	Q->Rear = s; //��s����Ϊ��ǰ�Ķ�β 
	return true;
} 
//ɾ�����Ӷ�ͷɾ��һ���ڵ� ��front����ƣ����ͷŸýڵ�ռ�õĿռ� 
ElementType deleteQ(Queue Q)
{
	ElementType e;
	PtrToNode s;
	//PtrToNode s = (PtrToNode)malloc(sizeof(struct Node));
	if (IsEmpty(Q))
	{
		printf("��Ϊ��\n");
		return ERROR;
	}
	else
	{
		s = Q->Front; //��Ҫɾ���Ķ��׽ڵ�ĵ�ַ�ݴ���s 
		if (Q->Front == Q->Rear)
			Q->Front = Q->Rear = NULL;  //ɾ���󽫶����ÿ� 
		else
		{
			Q->Front = Q->Front->Next; //���׽ڵ�ĵ�ַָ����һ���ڵ� 
			e = s->Data; 
			free(s);
			return e;
		}
	
	}
} 


/*
����
 1�����Ĵ�����data�� nextָ�� 
 2�����еĴ�����front�ڵ㣬 rear�ڵ㣬 size 

*/ 
