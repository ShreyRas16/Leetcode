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
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    void order(TreeNode* root,int y,int x){
        if(root==NULL) return;
        vector<int> info;
        info.push_back(y);
        info.push_back(x);
        info.push_back(root->val);
        pq.push(info);
        order(root->left,y-1,x+1);
        order(root->right,y+1,x+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};
        order(root,0,0);
        int curr=pq.top()[0];
        vector<int> level;
        vector<vector<int>> ans;
        while(!pq.empty()){
            if(pq.top()[0]==curr){
                level.push_back(pq.top()[2]);
                pq.pop();
            }
            else{
                curr=pq.top()[0];
                ans.push_back(level);
                level={};
                level.push_back(pq.top()[2]);
                pq.pop();
            }
        }
        ans.push_back(level);
        return ans;
    }
};