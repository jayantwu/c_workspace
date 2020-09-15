
typedef struct* Position;	
typedef Position BinTree;		
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

//������� 
void InorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->Left);
		printf("%d", BT->Data);
		InorderTraversal(BT->Right);
	}
}

//ǰ����� 
void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		printf("%d", BT->Data);
		InorderTraversal(BT->Left);
		InorderTraversal(BT->Right);
	}
}

//�������� 
void PostorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->Left);
		InorderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}