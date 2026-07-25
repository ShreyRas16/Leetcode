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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->left==NULL){
                preorder.push_back(temp->val);
                temp=temp->right;
            }
            else{
                TreeNode* prev=temp->left;
                while(prev->right!=NULL && prev->right!=temp) prev=prev->right;
                if(prev->right==NULL){
                    prev->right=temp;
                    preorder.push_back(temp->val);
                    temp=temp->left;
                }
                else{
                    prev->right=NULL;
                    temp=temp->right;
                }
            }
        }
        return preorder;
    }
};