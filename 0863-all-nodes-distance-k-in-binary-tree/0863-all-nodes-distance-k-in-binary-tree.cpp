/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> parent;
    void parentify(TreeNode* root){
        if(root==NULL) return;
        if(root->right!=NULL) parent[root->right]=root;
        if(root->left!=NULL) parent[root->left]=root;
        parentify(root->left);
        parentify(root->right);
    }
    vector<int> ans;
    unordered_map<TreeNode*,bool> visited;
    void bfs(TreeNode* target,TreeNode* root,int k,int dist){
        if(target==NULL) return;
        if(dist==k) ans.push_back(target->val);
        if(dist>k) return;
        visited[target]=true;
        if(target!=root && !visited[parent[target]]) bfs(parent[target],root,k,dist+1);
        if(target->left!=NULL && !visited[target->left]) bfs(target->left,root,k,dist+1);
        if(target->right!=NULL && !visited[target->right]) bfs(target->right,root,k,dist+1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL) return {};
        if(target==NULL) return {};
        parentify(root);
        bfs(target,root,k,0);
        return ans;
    }
};