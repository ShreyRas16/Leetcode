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
    unordered_map<int,pair<unsigned __int128,unsigned __int128>> mp;
    void check(TreeNode* root,int level,unsigned __int128 id){
       if(root==NULL) return;
       if(!mp.contains(level)) mp[level]={id,id};
       else mp[level].second=id;
       check(root->left,level+1,2*id);
       check(root->right,level+1,2*id+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        check(root,1,1);
        unsigned __int128 maxi=0;
        for(int i=1;i<mp.size()+1;i++) maxi=max(maxi,mp[i].second-mp[i].first+1);
        return maxi;
    }
};