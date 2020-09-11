#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#define Maxsize 1000
#define MAXOP 100
#define INFINITY 1e9
#define ERROR -10

typedef double ElementType;

typedef enum {
	num, opr, end
}Type;


typedef int Position;
typedef struct SNode* PtrToSNode;
struct SNode{
	ElementType *Data;
	Position Top;
	int MaxSize;
};
typedef PtrToSNode Stack;


Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType*)malloc(Maxsize*sizeof(ElementType));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

//��ջ����

bool IsFull(Stack S)
{
	return (S->Top == S->MaxSize); 
} 


bool Push(Stack S, ElementType X)
{
	if (IsFull(S))
	{
		printf("ջ����");
		return false; 
	} 
	else
	{
		S->Data[++(S->Top)] = X;
		printf("�ɹ�ѹ����%f\n", X);
		return true; 
	}

}


//��ջ����
bool IsEmpty(Stack S)
{
	return (S->Top == -1);
} 



ElementType Pop(Stack S)
{
	if (IsEmpty(S))
	{
		printf("ջΪ��");
		return ERROR;	 
	}
	else
	{
		printf("����ǰtopΪ%d\n", S->Top);
		printf("������topΪ%d, �ɹ�������%f\n", S->Top, S->Data[(S->Top)--]);
		return (S->Data[(S->Top)+1]);	
	}
		
}


Type GetOp(char *Expr, int *start, char *str)
{
	
	int i = 0;
	 //���� ���ʽǰ�Ŀո�����ѭ��ʱ��str[0]Ϊ�ǿո񣬿�����'\0'�����֣��������
	 //��ʱ��startָ������һ���ַ� 
	while ((str[0] = Expr[(*start)++]) == ' ')
	 	 ;
	while (str[i] != ' ' && str[i] != '\0')
		str[++i] = Expr[(*start)++];  //��һ���ַ�����i+1�� start�����Ųһ���ַ�
	if(str[i] == '\0')
		(*start)--;
	str[i] = '\0';
	 
	if (i == 0)
	 	return end;
 	else if (isdigit(str[0]) || isdigit(str[1]))
		 return num;
	else
		return opr;
		  
}

ElementType PostfixExp(char *Expr)
{
	Stack S;
	Type T;
	ElementType Op1, Op2;
	char str[MAXOP];
	int start = 0;
	
	S = CreateStack(MAXOP);
	
	Op1 = Op2 = 0;
	while ((T = GetOp(Expr, &start, str)) != end)
	{
		//��δ�����������ʱ
		
		if (T == num)
			Push(S, atof(str));
		else
		{
			if (!IsEmpty(S))
				Op2 = Pop(S);
			else
				Op2 = INFINITY;
		
			if (!IsEmpty(S))
				Op1 = Pop(S);
			else
				Op2 = INFINITY;
			
			switch(str[0])
			{
			case '+': 
				Push(S, Op1 + Op2); 
				break;
			case '-': 
				Push(S, Op1 - Op2);
				break;
		    case '*':
			 	Push(S, Op1 * Op2);
				break;
			case '/':
				if (Op2 != 0.0)
					Push(S, Op1 / Op2);
				else
				{
					printf("��ĸ����Ϊ0\n");
					Op2 = INFINITY;
				}
				break;
			default:
				printf("δ֪�������\n");
				Op2 = INFINITY;
				break; 
			}
			if (Op2 >= INFINITY)
				break;  //����ѭ�� 
			
		}
			 
	}
	
	if (Op2 < INFINITY)
		if(!IsEmpty(S))
			Op2  = Pop(S);
		else
			Op2 = INFINITY;
	free(S);
	return Op2;
	 
}

int main()
{
	char Expr[MAXOP];
	ElementType f;
	puts("�������׺���ʽ��"); 
	gets(Expr);
	f = PostfixExp(Expr);
	if (f < INFINITY)
		printf("%.4f\n", f);
	else
		printf("���ʽ����\n");
	return 0;
}




/*windows���������еĽ���� 
�������׺���ʽ��
1.2 1.3 + 2 4.2 * -
�ɹ�ѹ����1.200000
�ɹ�ѹ����1.300000
����ǰtopΪ1
������topΪ0, �ɹ�������1.300000
����ǰtopΪ0
������topΪ-1, �ɹ�������1.200000
�ɹ�ѹ����2.500000
�ɹ�ѹ����2.000000
�ɹ�ѹ����4.200000
����ǰtopΪ2
������topΪ1, �ɹ�������4.200000
����ǰtopΪ1
������topΪ0, �ɹ�������2.000000
�ɹ�ѹ����8.400000
����ǰtopΪ1
������topΪ0, �ɹ�������8.400000
����ǰtopΪ0
������topΪ-1, �ɹ�������2.500000
�ɹ�ѹ����-5.900000
����ǰtopΪ0
������topΪ-1, �ɹ�������-5.900000
-5.9000
�밴���������. . .

*/