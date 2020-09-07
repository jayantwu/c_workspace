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

//创建一个存储整数的单向链表
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

//入参为指向结构体指针的指针 ，之前入参是指向链表的指针，无法修改链表的头节点的地址 
void insert_element(PPtrToNode prtL, int e)
{
	/*tempL的值的为节点的地址，改变tempL的值不影响*prtL的值*/ 
	
	PtrToNode p, head, tempL;
	p = (PtrToNode)malloc(sizeof(struct Node));
	head = *prtL;  //head指向第一个节点，保存第一个节点的地址 
	tempL = *prtL;  //将指向结构体的指针保存在tempL临时变量中 
	p->Data = e;
	while (tempL != NULL)
	{
		
		if (head == tempL && e <= tempL->Data)    //小于等于第一个节点 时，插入到第一个节点前  
		{
			p->Next = head;
			*prtL = p;   //需要改变链表的头节点，p为新的头节点 
			break; 
		} 
		else if ((tempL->Next != NULL) && (e > tempL->Data) && (e <= tempL->Next->Data))
		{
			p->Next = tempL->Next;
			tempL->Next = p;
			
		}
		else if (tempL->Next == NULL && e > tempL->Data)
		{
			tempL->Next = p;
			p->Next = NULL;
			break;
		}
		tempL = tempL->Next;     //tempL指向下一个节点 ，此时 
		
	}

}
