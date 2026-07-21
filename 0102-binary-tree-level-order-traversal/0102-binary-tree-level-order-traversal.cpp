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
    unordered_map<int,vector<int>> mp;
    void dfs(TreeNode* root,int level){
        if(root==NULL) return;
        mp[level].push_back(root->val);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        vector<vector<int>> ans;
        for(int i=0;i<mp.size();i++) ans.push_back(mp[i]);
        return ans;
    }
};