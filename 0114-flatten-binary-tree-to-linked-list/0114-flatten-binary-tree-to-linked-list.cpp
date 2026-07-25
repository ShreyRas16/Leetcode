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
    void flatten(TreeNode* root) {
        TreeNode* temp=root;
        while(temp!=NULL){
            if(temp->left==NULL) temp=temp->right;
            else{
                TreeNode* prev=temp->left;
                while(prev->right!=NULL) prev=prev->right;
                if(prev->right==NULL){
                    if(temp->right!=NULL) prev->right=temp->right;
                    temp=temp->left;
                }
            }
        }
        TreeNode* temp1=root;
        while(temp1!=NULL){
            if(temp1->left==NULL){
                temp1->left=temp1->right;
                temp1->right=NULL;
            }
            temp1=temp1->left;
        }
        TreeNode* temp2=root;
        while(temp2!=NULL){
            if(temp2->left!=NULL){
                temp2->right=temp2->left;
                temp2->left=NULL;
            }
            temp2=temp2->right;
        }
    }
};