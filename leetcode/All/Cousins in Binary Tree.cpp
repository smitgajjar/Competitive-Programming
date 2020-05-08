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
    pair<int, TreeNode*> getDepth(TreeNode* root, int x, int depth) {
        if(root == NULL)
            return {-1, root};
        if(root->val == x)
                return {depth, root};
        pair<int, TreeNode*> obt_depth = getDepth(root->left, x, depth+1);
        if(obt_depth.first!=-1)
            return obt_depth;

        obt_depth = getDepth(root->right, x, depth+1);
        
        return obt_depth;
    }
    int isSibling(TreeNode* root, TreeNode *a, TreeNode *b) 
    { 
    
        if (root==NULL)  return 0; 

        return ((root->left==a && root->right==b)|| 
                (root->left==b && root->right==a)|| 
                isSibling(root->left, a, b)|| 
                isSibling(root->right, a, b)); 
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, TreeNode*> a=getDepth(root, x, 0);
        pair<int, TreeNode*> b=getDepth(root, y, 0);
        return (a.first==b.first and !isSibling(root, a.second, b.second));
    }
};