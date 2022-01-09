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
    unordered_map<int,pair<int,int>> mp;
    
    void solve(TreeNode* root,int depth,int parent){
        if(!root) return;
        mp[root->val]={depth,parent};
        solve(root->left,depth+1,root->val);
        solve(root->right,depth+1,root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root,0,-1);
        if(mp[x].first==mp[y].first && mp[x].second!=mp[y].second)
            return true;
        return false;
    }
};
