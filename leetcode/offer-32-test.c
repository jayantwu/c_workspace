#include <stdio.h>
#include <stdlib.h>
#define maxsize 1000
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode*  ElementType;
struct stack{
	ElementType *data;
	int top;
	int size;
};

struct stack* createstack(int Maxsize)
{
	struct stack* S = (struct stack*)malloc(sizeof(struct stack));
	S->data = (ElementType*)malloc(500*sizeof(ElementType)); //栈的元素为树结点指针
	S->size = Maxsize;
	S->top = -1;  //-1表示空栈
	return S;
}


void push(struct stack* S, ElementType x)
{
	if(S->top < (S->size)-1)
	{
		
		(S->top)++;
		S->data[S->top] = x;
	}
	else
		return;
}

ElementType pop(struct stack* S)
{
	if (S->top != -1)
	{
		(S->top)--;
		return S->data[(S->top)+1];
	}
	else
		return NULL;
}



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int ** ret = (int **)malloc(1000*sizeof(int*));
    (*returnColumnSizes)=(int*)malloc(1000*sizeof(int));
    if (!root)
    {
        *returnSize = 0;
        *returnColumnSizes = 0;
        return NULL;
    }
		
	int current = 0;  //标记现在用的是哪个栈 curren 为0表示用S1
	int next =1;
	int level = 0;//结果数组的行
    int row=0;  //记录每行的列数
	
	struct stack* S1 = createstack(1000);
	struct stack* S2 = createstack(1000);
	struct stack* S[2] = {S1, S2};
	ElementType tnode;
    
	push(S[current], root);  //将根结点入栈
	while (S[current]->top != -1)
	{
		if (row  == 0)  //新的一行刚开始时，需要计算该行需要的元素个数
        {
            //先计算新的一行多少个结点
            int cnt=1;
            int temp = S[current]->top;
            while(temp != -1)
            {
                cnt++;
                temp--;
            }
            ret[level] = (int*)malloc(cnt*sizeof(int));
        }
        tnode = pop(S[current]);  //弹出栈顶元素
		//printf("%d", tnode->val);
        ret[level][row] = tnode->val;
		if (current == 0)
		{
			if (tnode->left)
				push(S[next], tnode->left);
			if (tnode->right)
				push(S[next], tnode->right);
           
		}
		else
		{
			if (tnode->right)
				push(S[next], tnode->right);
			if (tnode->left)
				push(S[next], tnode->left);
          
		}
		if (S[current]->top == -1)
		{
			//printf("\n");
            (*returnColumnSizes)[level] = row+1; //先记录原来行的列数
            level++;  //栈为空时吗，进入下一行
            row = 0; //列数从0开始计  //下一行row从0开始
			current = 1-current; 
			next = 1-next;
		}
        else
            row++;
	}
    *returnSize = level;
    return ret;

}



int main()
{
	return 0;
}	