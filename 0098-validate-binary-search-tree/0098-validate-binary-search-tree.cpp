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
    bool corr=true;
    void check(TreeNode* root,long long up,long long low){
        if(root==NULL) return;
        if(root->val>=up){
            corr=false;
            return;
        }
        if(root->val<=low){
            corr=false;
            return;
        }
        check(root->right,up,root->val);
        check(root->left,root->val,low);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return corr;
        check(root,LLONG_MAX,LLONG_MIN);
        return corr;
    }
};