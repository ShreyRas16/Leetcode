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
    void recoverTree(TreeNode* root) {
        TreeNode* temp1=root;
        TreeNode* temp=NULL;
        vector<TreeNode*> probs;
        while(temp1!=NULL){
            if(temp1->left==NULL){
                if(temp!=NULL){
                    if(temp1->val<=temp->val){
                        probs.push_back(temp);
                        probs.push_back(temp1);
                    }
                }
                temp=temp1;
                temp1=temp1->right;
            }
            else{
                    TreeNode* prev=temp1->left;
                    while(prev->right!=NULL && prev->right!=temp1) prev=prev->right;
                    if(prev->right==NULL){
                        prev->right=temp1;
                        temp1=temp1->left;
                    }
                    else{
                        prev->right=NULL;
                        if(temp!=NULL){
                            if(temp1->val<=temp->val){
                                probs.push_back(temp);
                                probs.push_back(temp1);
                            }
                        }
                        temp=temp1;
                        temp1=temp1->right;
                    }
                }
        }
        int temp2=probs[0]->val;
        probs[0]->val=probs[probs.size()-1]->val;
        probs[probs.size()-1]->val=temp2;
    }
};