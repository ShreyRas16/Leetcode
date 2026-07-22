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
    void order(TreeNode* root,int level){
        if(root==NULL) return;
        mp[level].push_back(root->val);
        order(root->left,level+1);
        order(root->right,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        order(root,0);
        int s=mp.size();
        vector<int> ans;
        for(int i=0;i<s;i++) ans.push_back(mp[i].back());
        return ans;
    }
};