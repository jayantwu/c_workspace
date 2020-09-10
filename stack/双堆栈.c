/*双堆栈*/ 
typedef int Position;
typedef struct SNode* PtrToNode;
struct SNode{
	ElementType *Data;   //存储元素的数组 
	Position Top1;  //堆栈1的栈顶指针 
	Position Top2; //堆栈2的栈顶指针
	int MaxSize; //栈的最大容量 
};
typedef PtrToSNode Stack;

bool Push(Stack S, ElementType X， int Tag)
{  /*tag作为区分两个堆栈的标志，取值为1和2*/
	if(S->Top2 - S->Top1 == 1)
	{
		printf("堆栈满了\n");
		return false;
	} 
	else
	{
		if (Tag == 1)
			S->Data[++(S->Top1)] = X;
		else
			S->Data[--(S->Top2)]
	}
	
} 


ElementType Pop(Stack S, int Tag)

{
	if (Tag == 1)
	{
		if (S->Top1 == -1)
		{
			printf("堆栈1空\n");
			return ERROR;
		}
		else
			return S->Data[(S->Top1)--];
	}
	else
	{
		if (S->Top2 == S->MaxSize)
		{
			printf("堆栈2空\n");
			return ERROR;
		}
		else
			return S->Data[(S->Top2)++];
	}
}
 