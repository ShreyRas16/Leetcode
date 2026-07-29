/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* temp=NULL;
    void check(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return;
        if(p->val>root->val && q->val>root->val){
            check(root->right,p,q);
            return;
        }
        if(p->val<root->val && q->val<root->val){
            check(root->left,p,q);
            return;
        }
        if(p->val<=root->val && q->val>=root->val){
            temp=root;
            return;
        }
        if(p->val>=root->val && q->val<=root->val){
            temp=root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        check(root,p,q);
        return temp;
    }
};