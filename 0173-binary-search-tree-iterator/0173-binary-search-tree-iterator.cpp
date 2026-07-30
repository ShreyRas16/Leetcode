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
class BSTIterator {
public:
    stack<int> st;
    void insert(TreeNode*root){
        if(root==NULL) return;
        insert(root->right);
        st.push(root->val);
        insert(root->left);
    }
    BSTIterator(TreeNode* root) {
        insert(root);
    }
    
    int next() {
        int x;
        if(!st.empty()){
           x=st.top();
           st.pop();
           return x;
        }
        else return -1;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */