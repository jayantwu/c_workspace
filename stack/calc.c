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

//入栈操作

bool IsFull(Stack S)
{
	return (S->Top == S->MaxSize); 
} 


bool Push(Stack S, ElementType X)
{
	if (IsFull(S))
	{
		printf("栈满了");
		return false; 
	} 
	else
	{
		S->Data[++(S->Top)] = X;
		printf("成功压入了%f\n", X);
		return true; 
	}

}


//出栈操作
bool IsEmpty(Stack S)
{
	return (S->Top == -1);
} 



ElementType Pop(Stack S)
{
	if (IsEmpty(S))
	{
		printf("栈为空");
		return ERROR;	 
	}
	else
	{
		printf("弹出前top为%d\n", S->Top);
		printf("弹出后top为%d, 成功弹出了%f\n", S->Top, S->Data[(S->Top)--]);
		return (S->Data[(S->Top)+1]);	
	}
		
}


Type GetOp(char *Expr, int *start, char *str)
{
	
	int i = 0;
	 //跳过 表达式前的空格，跳出循环时，str[0]为非空格，可能是'\0'或数字，或运算符
	 //此时，start指向了下一个字符 
	while ((str[0] = Expr[(*start)++]) == ' ')
	 	 ;
	while (str[i] != ' ' && str[i] != '\0')
		str[++i] = Expr[(*start)++];  //下一个字符付给i+1， start再向后挪一个字符
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
		//当未读到输入结束时
		
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
					printf("分母不能为0\n");
					Op2 = INFINITY;
				}
				break;
			default:
				printf("未知的运算符\n");
				Op2 = INFINITY;
				break; 
			}
			if (Op2 >= INFINITY)
				break;  //跳出循环 
			
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
	puts("请输入后缀表达式："); 
	gets(Expr);
	f = PostfixExp(Expr);
	if (f < INFINITY)
		printf("%.4f\n", f);
	else
		printf("表达式错误\n");
	return 0;
}




/*windows环境下运行的结果： 
请输入后缀表达式：
1.2 1.3 + 2 4.2 * -
成功压入了1.200000
成功压入了1.300000
弹出前top为1
弹出后top为0, 成功弹出了1.300000
弹出前top为0
弹出后top为-1, 成功弹出了1.200000
成功压入了2.500000
成功压入了2.000000
成功压入了4.200000
弹出前top为2
弹出后top为1, 成功弹出了4.200000
弹出前top为1
弹出后top为0, 成功弹出了2.000000
成功压入了8.400000
弹出前top为1
弹出后top为0, 成功弹出了8.400000
弹出前top为0
弹出后top为-1, 成功弹出了2.500000
成功压入了-5.900000
弹出前top为0
弹出后top为-1, 成功弹出了-5.900000
-5.9000
请按任意键继续. . .

*/