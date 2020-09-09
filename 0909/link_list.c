#include <stdio.h>

typedef  struct LNode* PtrToLNode;

struct LNode{
	ElementType Data;
	PtrToLNode Next;
};

typedef PtrToLNode Posision;  
typedef PtrToLNode List;  
List L;  //Lָ������ͷ����ʾһ������


//���
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


//����
//����Ų���
ElementType FindKth(List L, int K)
{
	/*ָ��k��������Ӧ��Ԫ��*/
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
 
 
//��ֵ����
#define ERROR NULL

Posision Find(List L, ElementType X)
{
	Posision p = L;//pָ������ĵ�һ���ڵ� 
	while (p && p->Data != X)

		p = p->Next;
	
	if (p)
		return p->Data;
	else
		return ERROR;
	
} 

//����

List Insert(List L, ElementType X, int i)
{
	Position tmp, pre;
	
	tmp = (Posision)malloc(sizeof(struct LNode));
	tmp->Data=X;
	if (i==1)
	{
		tmp->Next = L;
		return tmp;   //�����±�ͷָ�� 
	} 
	
	else
	{
		//����λ��Ϊi-1�Ľڵ� 
		int cnt = 1;
		pre = L;
		while (pre && cnt < i-1)
		{
			pre = pre->Next;
			cnt++;
		}
		if (pre == NULL || cnt != i-1)   //preָ����˻���cnt������i-1 
		{
			printf("����λ�ò�������\n");
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


//ɾ��

//ɾ����i���ڵ� 
bool Delete(List L, int i)
{
	Positon tmp, pre;
	int cnt=0;
	
	//����λ��Ϊi-1�Ľڵ�
	pre = L;
	while (pre && cnt < i-1)
	{
		pre = pre->Next;
		cnt++;
	}
	
	if (pre == NULL || cnt != i-1 || pre->Next == NULL) 
	{
		printf("����λ�ò�������\n");
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
