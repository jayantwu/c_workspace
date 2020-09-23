typedef struct AVLNode *Position;
typedef Position AVLTree;
typedef struct AVLNode{
	ElementType Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int Max(int a, int b)
{
	return a > b ? a : b;
}
//递归函数
AVLTree Insert(AVLTree T, ElementType X)
{/*将x插入AVL树T中，并返回调整后的avl树*/
	if (!T)
	{
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Height = 1;
		T->Data = X;
		T->Left = T->Right = NULL;
	}
	
	else if (X < T->Data)
	{
		/*递归插入T的左子树*/
		T->Left = Insert(T->Left, X);
		if (GetHeight(T->Left) - GetHeight(T->Right) == 2)  //如果需要左旋
			if (X < T->Left->Data)
				T = SingleLeftRotaton(T);    //左单旋
			else
				T = DoubleLeftRightRotation(T);  //左右双旋
	}
	
	else if (X > T->Data)
	{   /*递归插入T的右子树*/
		T->Right = Insert(T->Right, X);
		if (GetHeight(T->Left) - GetHeight(T->Right) == -2)  //如果需要右旋
			if (X > T->Right->Data)
				T = SingleRightRotaton(T);       //右单旋
			else
				T = DoubleRightLeftRotation(T);     //右左双旋
	}
	
	
	/*更新树高*/
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	
	return T;
	
	
}

AVLTree SingleLeftRotaton(AVLTree A)
{
	/*左单旋,A为发现问题的结点， C为产生问题的结点
	    A               B
	  B     --->     C    A
	C
	
	*/
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	
	return B;
}


	
AVLTree SingleRightRotaton(AVLTree A)
{
	/*右单旋,A为发现问题的结点， C为产生问题的结点,逆时针转
	    A                B
	      B     --->  A     C 
	        C
	
	*/
	AVLTree B = A->Right;
	A->Right = B->Left
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(A->Height, GetHeight(B->Right)) + 1;
	
	return B;
}


AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotaton(A->Right);
	
	return SingleRightRotaton(A);
}



/*
      A               A                  B
    B       --->   B       --->       C     A
	  C         C
         右单旋             左单旋

*/
AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->Left = SingleRightRotaton(A->Left);
	
	return SingleLeftRotaton(A);
}
	
	
	
	
	
