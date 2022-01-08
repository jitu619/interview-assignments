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
    int count=0;
    
    void solve(TreeNode* root,int mn){
        if(root==NULL) return;
        if(root->val>=mn) count++;
        
        int prev=mn;
        if(root->val>mn){
            mn=root->val;
        }
        solve(root->left,mn);
        solve(root->right,mn);
        mn=prev;
    }
    
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return count;
    }
};
