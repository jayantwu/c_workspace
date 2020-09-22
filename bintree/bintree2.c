//中序遍历 
void InorderTraversal(BinTree BT)
{
	BinTree T;
	Stack S = CreateStack();
	T = BT; //从根节点出发；
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		
		T = Pop(S); //当左子树为空时，节点弹出栈，并访问 
		printf("%d", T->Data);  //访问该节点 
		T = T->Right;  //转向右子树 
		 
	} 
} 

//先序遍历，栈中的节点都已经打印 
void PreorderTraversal(BinTree BT)
{
	BinTree T;
	Stack S = CreateStack();
	T = BT; //从根节点出发；
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			printf("%d", T->Data);
			Push(S, T);
			T = T->Left;
		}
		
		T = Pop(S);  //当左子树为空时，节点弹出来，转向右子树 
		T = T->Right;
	
	}
	
} 




//层序遍历
void LevelorderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	
	if (!BT) return; //树为空时  直接返回 
	
	Q = CreateQueue();   //创建一个空队列 
	addQ(Q, BT);     //将树的根节点入队 
	while (!IsEmpty(Q))
	{
		T = deleteQ(Q);   //出队操作，如果其左右子树不为空，就分别入队左右节点 
		printf("%d", T->Data);
		if (T->Left)  addQ(Q, T->Left);
		if (T->Right)  addQ(Q, T->Right);		 
	}
} 
 
 
 
 //输出二叉树的所有叶子节点
 //前序遍历 
 void PreorderPrintLeaves(BinTree BT)
 {
 	if(BT)
 	{
	 	if(!BT->Left && !BT->Right)
	 		printf("%d", BT->Data);
 		PreorderPrintLeaves(BT->Left);
		PreorderPrintLeaves(BT->Right);  
	 }
	 
 } 
 
 
 //求二叉树的高度,采用后序遍历 
 int GetHeight(BinTree BT)
 {
 	int HL, HR, MaxH;
	
	if(BT)
	{
		HL = GetHeight(BT->Left);
		HR = GetHeight(BT->Right);
		MaxH = HL > HR ? HL : HR;
		return (MaxH + 1); 
	}
	
	else return 0; 
 } 