#define MaxDigit 4
#define Radix 10

/*桶元素结点*/
typedef struct Node* PtrToNode;
struct Node{
	int key;
	PtrToNode next;
}

/*桶头结点*/
struct HeadNode{
	PtrToNode head, tail;
}
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X, int D)
{
	//默认此为D=1，主位D<=MaxDigit  ，即个位用1表示
	int d, i;
	for (i = 1; i <= D; i++)
	{
		d = X % Radix;
		X /= Radix;
	}
	return d;
}


void LSDRadxSort(ElementType A[], int N)
{
	/*基数排序，次位优先*/
	int D, Di, i; //D为位数 可以为个位 十位 百位等； Di为某一位的值，也就是代表桶的下表
	Bucket B; //这句相当于：struct HeadNode B[Radix];
	PtrToNode tmp, p, List=NULL;
	for (i = 0; i < Radix; i++) /*初始化每个桶为空链表*/
		B[i].head = B[i].tail = NULL;
	for (i = 0; i < N; i++) /*将原始序列逆序存入初始链表List*/
	{
		tmp = (PtrToNode)malloc(sizeof(struct Node));
		tmp -> key = A[i];
		tmp -> next = List;
		List = tmp;
	}
	/*开始排序*/
	for (D = 1; D <= MaxDigit; D++)
	{
		/*分配过程*/
		p = List;
		while (p)
		{
			Di = GetDigit(p->key, D);
			tmp = p;
			p = p->next;
			tmp->next = NULL;
			if (B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else
			{
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}
		
		/*收集过程*/
		List = NULL;
		for (Di = Radix-1; Di >= 0; Di--) //从最后一个桶开始
		{
			if (B[Di].head)
			{
				B[Di].tail->next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL; //清空桶
			}
		}
	}
	
	//将List 倒入A[]并释放空间
	for (i = 0; i < N; i++)
	{
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	}
}

			
		
		
	
	