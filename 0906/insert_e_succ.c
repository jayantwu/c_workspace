#include <stdio.h>
#include <stdlib.h>
typedef struct Node* PtrToNode;
typedef struct Node** PPtrToNode;
typedef int ElementType; 
	
struct Node{
	ElementType Data;
	PtrToNode Next;
};

PtrToNode Creat_list();
void Print_list(PtrToNode L);
void insert_element(PPtrToNode L, int e);


int main()
{

    int num;
	PtrToNode L;
	L = Creat_list();
    Print_list(L);
    printf("input a num to insert: ");
	scanf("%d", &num);
	//printf("%p\n-----",L );
	insert_element(&L, num);
	//printf("%p\n+++++",L );
	Print_list(L);
	
}

//����һ���洢�����ĵ�������
PtrToNode Creat_list()
{
	ElementType num;
	PtrToNode head, tail, p;
	head = tail = NULL;
	printf("input the nums:\n");
	scanf("%d", &num);
	while (num != 0)
	{
		p = (PtrToNode) malloc(sizeof(struct Node));
		p->Data = num;
		p->Next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->Next = p;
		tail = p;
		scanf("%d", &num); 			
	}
	return head;

}


void Print_list(PtrToNode L)
{	
	while (L != NULL)
	{
		printf("%d", L->Data);
		L = L->Next;
		if (L != NULL)
			printf("-->");
		else
			printf("\n");
	} 		
}


void insert_element(PPtrToNode prtL, int e)
{
	PtrToNode p, head;
	p = (PtrToNode)malloc(sizeof(struct Node));
	head = *prtL;  //headָ���һ���ڵ㣬�����һ���ڵ�ĵ�ַ 
	p->Data = e;
	while (*prtL != NULL)
	{
		
		if (head == *prtL && e <= (*prtL)->Data)   //С�ڵ��ڵ�һ���ڵ� ʱ�����뵽��һ���ڵ�ǰ 
		{
			p->Next = head;
			*prtL = p;
			break; 
		} 
		else if (((*prtL)->Next != NULL) && (e > (*prtL)->Data) && (e <= (*prtL)->Next->Data))
		{
			p->Next = (*prtL)->Next;
			(*prtL)->Next = p;
			*prtL = (*prtL)->Next;
			break;
		}
		else if ((*prtL)->Next == NULL && e > (*prtL)->Data)
		{
			(*prtL)->Next = p;
			p->Next = NULL;
			break;
		}
		*prtL = (*prtL)->Next;
		
	}

}
