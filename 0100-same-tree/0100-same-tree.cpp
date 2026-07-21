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
    int flag=true;
    bool check(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL) return flag;
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
           flag=false;
           return flag;
        }
        if((p!=NULL && q!=NULL) && (p->val!=q->val)){
            flag=false;
            return flag;
        }
        check(p->left,q->left);
        check(p->right,q->right);
        return flag;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};