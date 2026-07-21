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
    int maxi=-10001;
    int x=0;
    int sum(TreeNode* root){
        if(root==NULL) return 0;
        int l=sum(root->left);
        int r=sum(root->right);
        maxi=max(max(maxi,l+r+root->val),max(l,r)+root->val);
        return max(0,max(l,r)+root->val);
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return maxi;
    }
};