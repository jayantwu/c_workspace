/*˫��ջ*/ 
typedef int Position;
typedef struct SNode* PtrToNode;
struct SNode{
	ElementType *Data;   //�洢Ԫ�ص����� 
	Position Top1;  //��ջ1��ջ��ָ�� 
	Position Top2; //��ջ2��ջ��ָ��
	int MaxSize; //ջ��������� 
};
typedef PtrToSNode Stack;

bool Push(Stack S, ElementType X�� int Tag)
{  /*tag��Ϊ����������ջ�ı�־��ȡֵΪ1��2*/
	if(S->Top2 - S->Top1 == 1)
	{
		printf("��ջ����\n");
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
			printf("��ջ1��\n");
			return ERROR;
		}
		else
			return S->Data[(S->Top1)--];
	}
	else
	{
		if (S->Top2 == S->MaxSize)
		{
			printf("��ջ2��\n");
			return ERROR;
		}
		else
			return S->Data[(S->Top2)++];
	}
}
 