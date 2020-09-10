/*堆栈的链式存储----带头节点的链栈*/ 
typedef struct Snode* PtrToSNode;
struct SNode
{
	ElementType Data;
	PtrToSNode Next;
} 

typedef PtrToSNode Stack;

//创建一个链栈 
Stack CreatStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
} 

//判断一个链栈是否为空 
bool IsEmpty(Stack S)
{
	return (S->Next == NULL);
}

bool Push(Stack S， ElementType X)
{  /*链表头为栈顶，链表尾为栈底，并包含了一个空的头节点*/
	PtrToSNode TmpCell;
	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
// 0-->4-->3-->2-->1-->null 
} 

ElementType Pop(Stack S)
{
	PtrToSNode FirstCell;
	ElementType TopElem;
	
	if (IsEmpty(S))
	{
		printf("栈空\n");
		return ERROR;
	}
	
	else
	{
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
		 
	}
	
	
}

