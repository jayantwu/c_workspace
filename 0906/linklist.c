/*将struct Node* 类型定义为PtrToNode */
typedef struct Node * PtrToNode;

struct Node{
	ElementType Data;
	PtrToNode Next;
};



/*双向链表*/
typedef struct DNode* PtrToDNode;
struct DNode {
	ElementType Data;
	PtrToDNode Next;
	PtrToDNode Previous;	
};
typedef PtrToDNode Dlist;


//单向链表的逆转
List Reverse(List L)
{
	PtrToNode Old_head, New_head, Temp;
	
	Old_head = L;
	New_head = NULL;
	while(Old_head)
	{
		Temp = Old_head->Next;
		Old_head->Next = New_head;
		New_head = Old_head;
		Old_head = Temp;
	}
	L = New_head;
	return L;
} 




