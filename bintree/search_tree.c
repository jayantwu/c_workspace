//二叉搜索树
//递归方式 
Position Find(BinTree BST, ElementType X)
{
	if(!BST)   return NULL;
	
	if (X > BST->Data)
		return Find(BST->Right, X);
	else if (X < BST->Data)
		return Find(BST->Left, X);
	else
		return BST;
} 

//非递归方式
 Position Find(BinTree BST, ElementType X)
 {
 	while (BST)
 	{
	 	if (X > BST->Data)
	 		BST = BST->Right;
 		else if (X < BST->Data)
 			BST  = BST->Left;
		else
			break;
	 }
	 return BST;
 } 
 
 
 //find min
 //递归
 Position FindMin(BinTree BST)
 {
 	if (!BST) return NULL;
 	else if (!BST->Left) return BST;
 	else  return FindMin(BST->Left);
 } 
 
 //非递归 
 Position FindMin(BinTree BST)
 {
 	if (BST)
 		while (BST->Left)
 			BST = BST->Left;
	return BST;	
 }
 
 
 //fin max
 //递归
 Position FindMax(BinTree BST)
 {
 	if(!BST)  return NULL;
 	else if (!BST->Right) return BST;
 	else return FindMax(BST->Right);
 } 
 
  //非递归 
 Position FindMax(BinTree BST)
 {
 	if (BST)
 		while (BST->Right)
 			BST = BST->Right;
	return BST;	
 }
 
 
 
 //插入
 BinTree Insert(BinTree BST, ElementType X)
 {
 	if (!BST)   //原树为空，生成并返回一个节点的二叉搜索树 
 	{
	 	BST = (BinTree)malloc(sizeof(struct TNode));
		 BST->Data = X;
		 BST->Left = BST->Right = NULL; 
    }
    
    else
	{
    	if (X < BST->Data)
    		BST->Left = Insert(BST->Left, X);
   		else if (X > BST->Data)
   			BST->Right = Inset(BST->Right, X);
	
    }
    return BST;
 } 
 
 
 //删除
 /*
 1、叶子节点 直接删除
 2、有一个孩子的节点，删除该节点，并把他的孩子连到他的父节点上
 3、有两个孩子的节点，选择器右孩子的最小元素或者左孩子的最大元素，填到删除的节点上，并删除该最大或最小元素 
 */ 
 
BinTree Delete(BinTree BST, ElementType X)
{
	Position Tmp;
 	if (!BST) printf("no element  to delete!");
 	
 	else
 	{
 		if (X < BST->Data)
 			BST->Left = Delete(BST->Left, X);//从左子树删除 
		else if (X > BST->Data)
			BST->Right = Delete(BST->Right, X);//从右子树找元素删除
		else  //找到要删除的元素 
		{
			if (BST->Left && BST->Right)  //左右子树都不为空	
			{
				/*从右子树找最小的元素进行替换和删除*/
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				BST->Right = Delete(BST->Right, Tmp->Data);  //从右子树删除该最小元素 
			} 
			else  //要删除的节点只有一个孩子或没有孩子 
			{
				Tmp = BST;
				if (!BST->Left)
					BST = BST->Right;
				else
					BST =  BST->Left;
				free(Tmp);
			}
		} 	
	}
	return BST;  
} 
 /*最后一次递归调用时返回的BST是要删除的节点的孩子的地址 ，空或有值
 同时，最后一次递归调用还做了一次连接被删除节点的父节点和其子节点 
 
 */ 