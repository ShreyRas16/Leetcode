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
    TreeNode* insert(vector<int>& preorder,int& i,int up){
        if(i>preorder.size()-1) return NULL;
        if(preorder[i]>=up) return NULL;
        TreeNode* root=new TreeNode();
        root->val=preorder[i++];
        root->left=insert(preorder,i,root->val);
        root->right=insert(preorder,i,up);
        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return insert(preorder,i,INT_MAX);
    }
};