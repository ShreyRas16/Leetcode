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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     if(root==NULL){
        TreeNode* temp=new TreeNode();
        temp->val=val;
        root=temp;
        return root;
     }
     if(root->right==NULL && val>root->val){
        TreeNode* temp=new TreeNode();
        temp->val=val;
        root->right=temp;
        return root;
     }   
     if(root->left==NULL && val<root->val){
        TreeNode* temp=new TreeNode();
        temp->val=val;
        root->left=temp;
        return root;
     }
     if(val>root->val) insertIntoBST(root->right,val);
     else if(val<root->val) insertIntoBST(root->left,val);
     return root;
    }
};