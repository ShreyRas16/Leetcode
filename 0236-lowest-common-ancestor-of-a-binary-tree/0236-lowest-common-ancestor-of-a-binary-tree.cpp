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
    pair<bool,bool> check(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return {false,false};
        bool checkp=false;
        bool checkq=false;
        if(root==p) checkp=true;
        if(root==q) checkq=true;
        pair<bool,bool> checkr=check(root->right,p,q);
        pair<bool,bool> checkl=check(root->left,p,q);
        if((checkr.first || checkl.first || checkp) && (checkr.second || checkl.second || checkq)){
            temp=root;
            if(temp!=NULL) return {false,false};
        }
        return {checkr.first || checkl.first || checkp,checkr.second || checkl.second || checkq};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        check(root,p,q);
        return temp;
    }
};