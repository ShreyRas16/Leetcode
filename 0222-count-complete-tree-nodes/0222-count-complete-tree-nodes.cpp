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
    int lefth(TreeNode* root){
        if(root==NULL) return 0;
        return 1+lefth(root->left);
    }
    int righth(TreeNode* root){
        if(root==NULL) return 0;
        return 1+righth(root->right);
    }
    int sum=0;
    int count(TreeNode* root){
        if(root==NULL) return 0;
        if(lefth(root)==righth(root)) return (1<<lefth(root))-1;
        int l=count(root->left);
        int r=count(root->right);
        return 1+l+r;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return count(root);
    }
};