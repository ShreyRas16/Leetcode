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
    unordered_map<int,int> inord;
    void tree(int x,int low,int mid,int high,vector<int>& inorder,TreeNode* root,vector<int>& preorder,unordered_map<int,int>& inord){
        if(x>preorder.size()) return;
        if(mid>low){
            TreeNode* temp=new TreeNode();
            temp->val=preorder[x+1];
            root->left=temp;
            tree(x+1,low,inord[temp->val],mid-1,inorder,root->left,preorder,inord);
        }
        if(mid<high){
            TreeNode* temp=new TreeNode();
            temp->val=preorder[x+mid-low+1];
            root->right=temp;
            tree(x+mid-low+1,mid+1,inord[temp->val],high,inorder,root->right,preorder,inord);
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int mid;
        TreeNode* root=new TreeNode();
        root->val=preorder[0];
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==preorder[0]){
                mid=i;
                break;
            }
        }
        for(int i=0;i<inorder.size();i++) inord[inorder[i]]=i;
        tree(0,0,mid,inorder.size()-1,inorder,root,preorder,inord);
        return root;
    }
};