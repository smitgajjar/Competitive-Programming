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
    int ans, cnt;
    void traverse(TreeNode* node, int k)
    {
        if(node==NULL)
            return;
        
        traverse(node->left, k);
        if(++cnt==k)
        {
            ans=node->val;
            return;
        }
        traverse(node->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        cnt=0;
        traverse(root, k);
        return ans;
    }
};