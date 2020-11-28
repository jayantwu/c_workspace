/**二叉树的镜像
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 
 /***迭代法***/
typedef struct TreeNode* ElementType;
typedef struct QNode* PtrToQNode;
struct QNode{
    ElementType *data;  //存放树结点的地址
    int front, rear;
    int maxsize;
};
typedef PtrToQNode Queue;

Queue createQ(int maxsize)
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->data = (ElementType*)malloc(maxsize*sizeof(ElementType));
    Q->front = Q->rear = 0;
    Q->maxsize = maxsize;
    return Q;
}

bool isFull(Queue Q)
{
    return ((Q->rear+1) % Q->maxsize == Q->front);
}

void addQ(Queue Q, ElementType X)
{
    if (isFull(Q))
        return;
    else
    {
        Q->rear = (Q->rear+1)%Q->maxsize;
        Q->data[Q->rear] = X;
    }
}

bool isEmpty(Queue Q)
{
    return (Q->front == Q->rear);
}

ElementType delQ(Queue Q)
{
    if (isEmpty(Q))
        return;
    else
    {
        Q->front = (Q->front+1) %  Q->maxsize;
        return Q->data[Q->front];
    }
}

struct TreeNode* mirrorTree(struct TreeNode* root){

    Queue Q = createQ(500);
    struct TreeNode* node;
    struct TreeNode* temp;
    if (!root)
        return NULL;

    addQ(Q, root);

    while(!isEmpty(Q))
    {
        node = delQ(Q);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
        if (node->left)
            addQ(Q, node->left);
        if (node->right)
            addQ(Q, node->right);
    }
    return root;
 
}



/****递归法****/
struct TreeNode* mirrorTree(struct TreeNode* root){

    struct TreeNode* temp;
    if (!root)
        return NULL;
    else
    {
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->right);
        mirrorTree(root->left); 
    }
    return root;

}