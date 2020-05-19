/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt;
    void traverse(TreeNode* node)
    {
        if(node==NULL)
            return;
        if(node->left!=NULL)
        {
            if(node->left->val>=node->val)
            {
                cnt++;
            }
            else
            {
                node->left->val=node->val;
            }
        }
        traverse(node->left);
        if(node->right!=NULL)
        {
            if(node->right->val>=node->val)
            {
                cnt++;
            }
            else
            {
                node->right->val=node->val;
            }
        }
        traverse(node->right);
    }
    int goodNodes(TreeNode* root) {
        cnt=1;
        traverse(root);
        return cnt;
    }
};