/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
void helper(TreeNode* root, string& s) {
    if(root == NULL) {
        s += "n ";
        return;
    }

    s += to_string(root->val);
    s += " ";

    helper(root->left, s);
    helper(root->right, s);
}

string serialize(TreeNode* root) {
    string s;
    helper(root, s);
    return s;
}

vector<string> s;
TreeNode* des(vector<string>& s, int& idx){
    if(idx >= s.size()) return NULL;

    if(s[idx] == "n"){
        idx++;
        return NULL;
    }

    TreeNode* root = new TreeNode(stoi(s[idx]));
    idx++;

    root->left = des(s, idx);
    root->right = des(s, idx);

    return root;
}

TreeNode* deserialize(string data) {
    s.clear();

    string curr;
    for(char c : data){
        if(c == ' '){
            s.push_back(curr);
            curr="";
        }
        else curr += c;
    }

    int idx=0;
    return des(s, idx);
}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));