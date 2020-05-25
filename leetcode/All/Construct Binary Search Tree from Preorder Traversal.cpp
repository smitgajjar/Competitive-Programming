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
    TreeNode* insertInBst(int val, TreeNode* node)
    {
        if(node==NULL)
            return new TreeNode(val);
        else if(val<node->val)
            node->left=insertInBst(val, node->left);
        else
            node->right=insertInBst(val, node->right);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        int n=preorder.size();
        for(int i=1; i<n; i++)
            insertInBst(preorder[i], root);
        return root;
        
    }
};