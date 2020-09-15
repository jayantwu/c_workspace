
typedef struct* Position;	
typedef Position BinTree;		
struct TNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

//中序遍历 
void InorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->Left);
		printf("%d", BT->Data);
		InorderTraversal(BT->Right);
	}
}

//前序遍历 
void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		printf("%d", BT->Data);
		InorderTraversal(BT->Left);
		InorderTraversal(BT->Right);
	}
}

//后续遍历 
void PostorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->Left);
		InorderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}