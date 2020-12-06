/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* find(struct TreeNode* root, int *k)
{
    struct TreeNode* target = NULL;   //默认为空
    
//第k大  先右再左 ；第k小  先左再右
    if(root->right)
        target = find(root->right, k);  //遍历右子树

    if (!target)
    {
        if(*k == 1)
            target = root;
        (*k)--;   //访问一个结点之后 *k-1
    }
    //有条件的遍历左子树，如果k > 1 则target一定为空 ，也就是target不为空时不需要再遍历左子树
    if (!target && root->left)
        target = find(root->left, k);
    
    return target;

}

int kthLargest(struct TreeNode* root, int k){

    struct TreeNode* t;
    if (!root || k == 0)
        return 0;
    t = find(root, &k);
    if (t)
        return  t->val;
    else
        return 0;
}

