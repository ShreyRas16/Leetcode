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
    TreeNode* temp=NULL;
    TreeNode* temp1=NULL;
    bool found=false;
    void find(TreeNode* root,int key){
        if(root==NULL) return;
        if(found==true) return;
        if(root->val==key){
            temp=root;
            temp1=NULL;
            found=true;
            return;
        }
        if(root->right!=NULL && root->right->val==key){
            temp1=root;
            temp=root->right;
            found=true;
            return;
        }
        if(root->left!=NULL && root->left->val==key){
            temp1=root;
            temp=root->left;
            found=true;
            return;
        }
        if(root->val>key) find(root->left,key);
        else if(root->val<key) find(root->right,key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        find(root,key);
        if(!found) return root;
        else{
            if(temp->left==NULL && temp->right==NULL){
                delete temp;
                if(temp1==NULL) root=NULL;
                else if(temp1!=NULL && temp1->left==temp) temp1->left=NULL;
                else if(temp1!=NULL && temp1->right==temp) temp1->right=NULL;
            }
            else if(temp->left==NULL || temp->right==NULL){
                if(temp1==NULL){
                    if(temp->left==NULL){
                        root=temp->right;
                        temp->right=NULL;
                        delete temp;
                    }
                    else{
                        root=temp->left;
                        temp->left=NULL;
                        delete temp;
                    }
                }
                else if(temp->left==NULL){
                    TreeNode* child=temp->right;
                    if(temp1->left==temp) temp1->left=child;
                    else temp1->right=child;
                    delete temp;
                }
                else if(temp->right==NULL){
                    TreeNode* child=temp->left;
                    if(temp1->left==temp) temp1->left=child;
                    else temp1->right=child;
                    delete temp;
                }
            }
            else{
                TreeNode* temp2=temp->left;
                TreeNode* temp3=temp;
                while(temp2->right!=NULL){
                    temp3=temp2;
                    temp2=temp2->right;
                }
                temp->val=temp2->val;
                if(temp2->left!=NULL){
                    if(temp3==temp) temp3->left=temp2->left;
                    else temp3->right=temp2->left;
                }
                else{
                    if(temp3!=temp) temp3->right=NULL;
                    else temp3->left=NULL;
                }
                delete temp2;
            }
        }
        return root;
    }
};