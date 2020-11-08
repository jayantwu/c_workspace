List Reverse(List L)
{
	PtrToNode oldhead, newhead, tmp;
	
	oldhead = L;
	newhead = NULL;
	while (oldhead)
	{
		tmp = oldhead->next;
		oldhead->next = newhead;
		newhead = oldhead;
		oldhead = tmp;
	}
	L = newhead;
	return L;
}
