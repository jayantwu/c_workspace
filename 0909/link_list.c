#include <stdio.h>

typedef  struct LNode* PtrToLNode;

struct LNode{
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode Posision;  
typedef PtrToLNode List;  
List L;  //L指向链表头，表示一个链表


//求表长
int length(List L)
{
	Posision p;
	int cnt = 0;
	p = L;
	while (p)
	{
		p = p->Next;
		cnt++;
	}
	return cnt;
	
} 


//查找
//按序号查找
ElementType FindKth(List L, int K)
{
	/*指定k，返回相应的元素*/
	Posision p;
	int cnt = 1;
	p = L; 
	while (p && cnt < K)
	{
		p = p->Next;
		cnt++;
	}
	
	if (cnt==K && p)
		return p->Data;
	else
		return ERROR
		 
} 
 
 
//按值查找
#define ERROR NULL

Posision Find(List L, ElementType X)
{
	Posision p = L;//p指向链表的第一个节点 
	while (p && p->Data != X)

		p = p->Next;
	
	if (p)
		return p->Data;
	else
		return ERROR;
	
} 

//插入

List Insert(List L, ElementType X, int i)
{
	Position tmp, pre;
	
	tmp = (Posision)malloc(sizeof(struct LNode));
	tmp->Data=X;
	if (i==1)
	{
		tmp->Next = L;
		return tmp;   //返回新表头指针 
	} 
	
	else
	{
		//查找位序为i-1的节点 
		int cnt = 1;
		pre = L;
		while (pre && cnt < i-1)
		{
			pre = pre->Next;
			cnt++;
		}
		if (pre == NULL || cnt != i-1)   //pre指向空了或者cnt不等于i-1 
		{
			printf("插入位置参数错误\n");
			free(tmp);
			return ERROR;
		}
		else
		{
			tmp->Next = pre->Next;
			pre->Next = tmp;
			return L;
		}	
	}	
} 


//删除

//删除第i个节点 
bool Delete(List L, int i)
{
	Positon tmp, pre;
	int cnt=0;
	
	//查找位序为i-1的节点
	pre = L;
	while (pre && cnt < i-1)
	{
		pre = pre->Next;
		cnt++;
	}
	
	if (pre == NULL || cnt != i-1 || pre->Next == NULL) 
	{
		printf("插入位置参数错误\n");
		return false;
	}
	
	else
	{
		tmp = pre->Next;
		pre->Next = tmp->Next;
		free(tmp);
		return true; 
	}
} 
