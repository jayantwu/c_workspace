/*剑指offer 18题*/
void DeletDuplication(ListNode **pHead) //因为头节点有可能改变，传入指针的指针
{
	if (pHead == null || *pHead == null)
		return;
	
	ListNode* pPreNode = null;
	ListNode* pNode = *pHead;
	while (pNode != null)
	{
		ListNode* pNext = pNode->next;
		bool needDelete = false;
		if (pNext != null  && pNext->value == pNode->value)
			needDelete = true;
		
		if (!needDelete)  //跟下一个元素不重复时
		{
			pPreNode = pNode;
			pNode = pNode->next;
		}
		else  //跟下一个元素重复时
		{
			int value = pNode->value;
			ListNode* pToBeDel = pNode;   //当前结点需要删除
			while (pToBeDel != null && pToBeDel->value == value)
			{
				//第一次肯定时满足条件的
				pNext = pToBeDel->next;
				free(pToBeDel);
				pToBeDel = pNext;
			}
			//删完之后pNext更新到了重复元素的后一个元素
			if (pPreNode == null)
				*pHead = pNext;
			else
				pPreNode->next = pNext; //指向pNext所指向的内容
			pNode = pNext;  //从当前pNext所指的地方继续开始循环，因此pNode指向这个 新的开始
		}
	}
}
			
		
			