typedef struct HTNode *HuffmanTree;
struct HTNode{
	int Weight;  //结点权值
	HuffmanTree Left;
	HuffmanTree Right;
};

HuffmanTree Huffman(MinHeap H)   //入参是一棵二叉树
{
	int i, N;
	HuffmanTree T;
	BuildHeap(H);  //将二叉树调整为最小堆
	N = H->Size;
	for (i=1; i < N; i++)
	{
		T = (HuffmanTree)malloc(sizeof(struct HTNode));
		T->Left = DeleteMin(H);  //从最小堆中删除最小的元素，作为新树的左子节点
		T->Right = DeleteMin(H);  //再次删除一个结点，作为右子节点
		T->Weight = T->Left->Weight + T->Right->Weight;  //计算新的权值
		Insert(H, T);
	}
	return DeleteMin(H);
}
		