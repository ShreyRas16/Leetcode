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
    void build(int x,int low,int mid,int high,vector<int>& inorder,vector<int>& postorder,TreeNode* root){
        if(x<0) return;
        if(mid>low){
            TreeNode* temp=new TreeNode();
            temp->val=postorder[x-high+mid-1];
            root->left=temp;
            build(x-high+mid-1,low,inord[temp->val],mid-1,inorder,postorder,root->left);
        }
        if(mid<high){
            TreeNode* temp=new TreeNode();
            temp->val=postorder[x-1];
            root->right=temp;
            build(x-1,mid+1,inord[temp->val],high,inorder,postorder,root->right);
        }
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int mid;
        TreeNode* root=new TreeNode();
        root->val=postorder[postorder.size()-1];
        for(int i=0;i<inorder.size();i++){
            inord[inorder[i]]=i;
            if(inorder[i]==postorder[postorder.size()-1]) mid=i;
        }
        build(postorder.size()-1,0,mid,inorder.size()-1,inorder,postorder,root);
        return root;
    }
};