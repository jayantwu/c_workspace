/*��struct Node* ���Ͷ���ΪPtrToNode */
typedef struct Node * PtrToNode;

struct Node{
	ElementType Data;
	PtrToNode Next;
};



/*˫������*/
typedef struct DNode* PtrToDNode;
struct DNode {
	ElementType Data;
	PtrToDNode Next;
	PtrToDNode Previous;	
};
typedef PtrToDNode Dlist;


//�����������ת
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




