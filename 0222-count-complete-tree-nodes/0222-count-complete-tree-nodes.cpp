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
    unordered_map<int,vector<TreeNode*>> mp;
    void count(TreeNode* root,int level){
        if(root==NULL) return;
        level++;
        mp[level].push_back(root);
        count(root->left,level);
        count(root->right,level);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        count(root,0);
        vector<vector<TreeNode*>> ans;
        for(int i=1;i<mp.size()+1;i++) ans.push_back(mp[i]);
        return (1<<(ans.size()-1))-1+ans[ans.size()-1].size();
    }
};