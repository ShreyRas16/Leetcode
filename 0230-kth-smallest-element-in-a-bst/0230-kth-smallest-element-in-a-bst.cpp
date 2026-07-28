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
    void check(TreeNode* root,int k,int& count){
        if(root==NULL) return;
        if(count>k) return;
        check(root->left,k,count);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        check(root->right,k,count);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        int count=0;
        check(root,k,count);
        return ans;
    }
};