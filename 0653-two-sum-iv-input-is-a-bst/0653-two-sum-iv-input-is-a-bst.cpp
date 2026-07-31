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
    stack<TreeNode*> s;
    void inserts(TreeNode* root){
        if(root==NULL) return;
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }
    stack<TreeNode*> l;
    void insertl(TreeNode* root){
        if(root==NULL) return;
        while(root!=NULL){
            l.push(root);
            root=root->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        inserts(root);
        insertl(root);
        while(!s.empty() && !l.empty() && s.top()!=l.top()){
            if(s.top()->val+l.top()->val==k) return true;
            if(s.top()->val+l.top()->val<k){
                TreeNode* temp=s.top();
                s.pop();
                inserts(temp->right);
            }
            else if(s.top()->val+l.top()->val>k){
                TreeNode* temp=l.top();
                l.pop();
                insertl(temp->left);
            }
        }
        return false;
    }
};