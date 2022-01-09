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
    vector<int> ans;
    void solve(TreeNode* root,vector<int> &v,int level){
        if(!root) return;
        if(ans.size()==level) ans.push_back(root->val);
        solve(root->right,v,level+1);
        solve(root->left,v,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        solve(root,v,0);
        return ans;
    }
};
