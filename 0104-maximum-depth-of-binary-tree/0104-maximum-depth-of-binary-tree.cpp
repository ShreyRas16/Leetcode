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
    int ans;
    int deep(TreeNode* root,int level){
        ans=max(ans,level);
        if(root==NULL) return ans;
        deep(root->right,level+1);
        deep(root->left,level+1);
        return ans;
    }
    int maxDepth(TreeNode* root) {
        return deep(root,0);
    }
};