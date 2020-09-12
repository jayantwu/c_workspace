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
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = NULL;
	return Q;
}

bool IsEmpty(Queue Q)
{
	return (Q->Front == NULL);
}

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
	return true； 
} 

ElementType deleteQ(Queue Q)
{
	ElementType e;
	PtrToNode s = (PtrToNode)malloc(sizeof(struct Node));
	if (IsEmpty(Q))
	{
		printf("队为空\n");
		return ERROR;
	}
	else
	{
		s = Q->Front;
		if (Q->Front == Q->Rear)
			Q->Front = Q->Next = NULL;
		else
		{
			Q->Front = Q->Front->Next;
			e = s->Data; 
			free(s);
			return e;
		}
		
		
	}
} 