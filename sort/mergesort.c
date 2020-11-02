//递归方法
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, NumElements, Tmp;
	int i;
	
	LeftEnd = R - 1;
	Tmp = L;
	NumElements = RightEnd - L + 1;
	
	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] < A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}
	
	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++];
	
	for (i=0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd];
}


void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
	int center;
	
	if (L < RightEnd)
	{
		center = (L+RightEnd)/2;
		Msort(A, TmpA, L, center);
		Msort(A, TmpA, center+1, RightEnd);
		Merge(A, TmpA, L, center+1, RightEnd);
	}
}


//统一接口
void MergeSort(ElementType A[], int N)
{
	ElementType *TmpA;
	TmpA = (*ElementType)malloc(N * sizeof(ElementType));
	if(TmpA != NULL)
	{
		Msort(A, TmpA, 0, N-1);
		free(TmpA);
	}
	
	else printf("空间不足")；
}



/*非递归方法*/
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length) /*length未当前子序列的长度*/
{
	for (i=0; i <= N - 2*length; i += 2*length)
		Merge1(A, TmpA, i, i+length, i+2*length-1); //merge1最终将A中的子列合并到TmpA,从最左边元素开始
	if(i + length < N)
		Merge1(A, TmpA,i, i+length, N-1);//合并最后两个子列
	else   //最后只剩一个子列，直接倒到TmpA
		for (j = i; j < N; j++)
			TmpA[j] = A[j];
}



void Merge_sort(ElementType A[], int N)
{
	int length = 1;
	ElementType *TmpA;
	TmpA = (*ElementType)malloc(N * sizeof(ElementType));
	if (TmpA != NULL)//申请到了空间
	{
		while(length < N)
		{
			Merge_pass(A, TmpA, N, length);  //一边merge， 从左到右
			length *= 2;
			Merge_pass(TmpA, A, N, length); //第二遍merge，最终从tmpa倒到A
			length *= 2;
		}
		
		free(TmpA);
	}
	
	else printf("空间不足");
}


		

