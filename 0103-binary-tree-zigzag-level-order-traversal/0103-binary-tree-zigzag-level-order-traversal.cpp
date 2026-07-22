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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*> st;
        vector<vector<int>> ans;
        bool flag=true;
        st.push(root);
        while(!st.empty()){
            vector<int> temp;
            int s=st.size();
            deque<TreeNode*> q;
            for(int i=0;i<s;i++){
                TreeNode* tem=st.top();
                st.pop();
                if(flag){
                   if(tem->left)  q.push_back(tem->left);
                   if(tem->right) q.push_back(tem->right);
                }
                else{
                   if(tem->right) q.push_front(tem->right);
                   if(tem->left)  q.push_front(tem->left);
                }
                temp.push_back(tem->val);
            }
            ans.push_back(temp);
            while(!q.empty()){
                if(flag){
                    st.push(q.front());
                    q.pop_front();
                }
                else{
                    st.push(q.back());
                    q.pop_back();
                }
            }
            if(flag) flag=false;
            else flag=true;
        }
        return ans;
    }
};