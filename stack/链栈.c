/*��ջ����ʽ�洢----��ͷ�ڵ����ջ*/ 
typedef struct Snode* PtrToSNode;
struct SNode
{
	ElementType Data;
	PtrToSNode Next;
} 

typedef PtrToSNode Stack;

//����һ����ջ 
Stack CreatStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
} 

//�ж�һ����ջ�Ƿ�Ϊ�� 
bool IsEmpty(Stack S)
{
	return (S->Next == NULL);
}

bool Push(Stack S�� ElementType X)
{  /*����ͷΪջ��������βΪջ�ף���������һ���յ�ͷ�ڵ�*/
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
		printf("ջ��\n");
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

