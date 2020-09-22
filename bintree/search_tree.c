//����������
//�ݹ鷽ʽ 
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

//�ǵݹ鷽ʽ
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
 //�ݹ�
 Position FindMin(BinTree BST)
 {
 	if (!BST) return NULL;
 	else if (!BST->Left) return BST;
 	else  return FindMin(BST->Left);
 } 
 
 //�ǵݹ� 
 Position FindMin(BinTree BST)
 {
 	if (BST)
 		while (BST->Left)
 			BST = BST->Left;
	return BST;	
 }
 
 
 //fin max
 //�ݹ�
 Position FindMax(BinTree BST)
 {
 	if(!BST)  return NULL;
 	else if (!BST->Right) return BST;
 	else return FindMax(BST->Right);
 } 
 
  //�ǵݹ� 
 Position FindMax(BinTree BST)
 {
 	if (BST)
 		while (BST->Right)
 			BST = BST->Right;
	return BST;	
 }
 
 
 
 //����
 BinTree Insert(BinTree BST, ElementType X)
 {
 	if (!BST)   //ԭ��Ϊ�գ����ɲ�����һ���ڵ�Ķ��������� 
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
 
 
 //ɾ��
 /*
 1��Ҷ�ӽڵ� ֱ��ɾ��
 2����һ�����ӵĽڵ㣬ɾ���ýڵ㣬�������ĺ����������ĸ��ڵ���
 3�����������ӵĽڵ㣬ѡ�����Һ��ӵ���СԪ�ػ������ӵ����Ԫ�أ��ɾ���Ľڵ��ϣ���ɾ����������СԪ�� 
 */ 
 
BinTree Delete(BinTree BST, ElementType X)
{
	Position Tmp;
 	if (!BST) printf("no element  to delete!");
 	
 	else
 	{
 		if (X < BST->Data)
 			BST->Left = Delete(BST->Left, X);//��������ɾ�� 
		else if (X > BST->Data)
			BST->Right = Delete(BST->Right, X);//����������Ԫ��ɾ��
		else  //�ҵ�Ҫɾ����Ԫ�� 
		{
			if (BST->Left && BST->Right)  //������������Ϊ��	
			{
				/*������������С��Ԫ�ؽ����滻��ɾ��*/
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				BST->Right = Delete(BST->Right, Tmp->Data);  //��������ɾ������СԪ�� 
			} 
			else  //Ҫɾ���Ľڵ�ֻ��һ�����ӻ�û�к��� 
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
 /*���һ�εݹ����ʱ���ص�BST��Ҫɾ���Ľڵ�ĺ��ӵĵ�ַ ���ջ���ֵ
 ͬʱ�����һ�εݹ���û�����һ�����ӱ�ɾ���ڵ�ĸ��ڵ�����ӽڵ� 
 
 */ 