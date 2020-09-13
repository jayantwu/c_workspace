typedef struct PolyNode* PtrToPolyNode; 
struct PolyNode{
	int coef, expon;
	PtrToPolyNode Next;	
};
typedef PtrToPolyNode Polynomial;


int Compare(int e1, int e2)
{
	if (e1 > e2)
		return 1;
	else if (e1 < e2)
		return -1;
	else
		return 0;
} 

void Attach(int coef, int expon, Polynomial *PtrRear)
{
	Polynomial P;
	/*�����µĽڵ㣬����ֵ*/
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = coef;
	P->expon = expon;
	P->Next = NULL;
	(*PtrRear)->Next = P;
	*PtrRear = P;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	while (P1 && P2)
	{
		switch(Compare(P1->coef, P2->coef))
		{
			case 1:
				Attach(P1->coef, P1->expon, &rear);
				P1 = P1->Next;
				break;
			case -1:
				Attach(P2->coef, P2->expon, &rear);
				P2= P2->Next;
				break;
			case 0:
				sum = P1->coef + P2->coef;
				if (sum)
					Attach(sum, P1->expon, &rear);
				P1 = P1->Next;
				P2 = P2->Next;
				break;	
		}	
	} 
	for (; P1; P1 = P1->Next) Attach(P1->coef, P1->expon, &rear); //P2��Ϊ��ʱ
	for (; P2; P2 = P2->Next) Attach(P2->coef, P2->expon, &rear); //P1��Ϊ��ʱ 
	rear->Next = NULL;
	temp = front;
	front = front->Next;  //��frontָ��������ʽ�ĵ�һ�������� 
	free(temp);  //�ͷ���ʱ�ձ�ͷ��� 
	return front;
	
}