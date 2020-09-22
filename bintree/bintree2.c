//������� 
void InorderTraversal(BinTree BT)
{
	BinTree T;
	Stack S = CreateStack();
	T = BT; //�Ӹ��ڵ������
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			Push(S, T);
			T = T->Left;
		}
		
		T = Pop(S); //��������Ϊ��ʱ���ڵ㵯��ջ�������� 
		printf("%d", T->Data);  //���ʸýڵ� 
		T = T->Right;  //ת�������� 
		 
	} 
} 

//���������ջ�еĽڵ㶼�Ѿ���ӡ 
void PreorderTraversal(BinTree BT)
{
	BinTree T;
	Stack S = CreateStack();
	T = BT; //�Ӹ��ڵ������
	while (T || !IsEmpty(S))
	{
		while (T)
		{
			printf("%d", T->Data);
			Push(S, T);
			T = T->Left;
		}
		
		T = Pop(S);  //��������Ϊ��ʱ���ڵ㵯������ת�������� 
		T = T->Right;
	
	}
	
} 




//�������
void LevelorderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	
	if (!BT) return; //��Ϊ��ʱ  ֱ�ӷ��� 
	
	Q = CreateQueue();   //����һ���ն��� 
	addQ(Q, BT);     //�����ĸ��ڵ���� 
	while (!IsEmpty(Q))
	{
		T = deleteQ(Q);   //���Ӳ��������������������Ϊ�գ��ͷֱ�������ҽڵ� 
		printf("%d", T->Data);
		if (T->Left)  addQ(Q, T->Left);
		if (T->Right)  addQ(Q, T->Right);		 
	}
} 
 
 
 
 //���������������Ҷ�ӽڵ�
 //ǰ����� 
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
 
 
 //��������ĸ߶�,���ú������ 
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