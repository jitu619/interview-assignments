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
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int idx=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                q.push(q.front());
                v.push_back(q.front()->val);
                q.pop();
            }
            if(idx&1){
                reverse(v.begin(),v.end());
            }
            
            for(int i=0;i<n;i++){
                if(q.front()->left!=NULL) q.push(q.front()->left);
                if(q.front()->right!=NULL) q.push(q.front()->right);
                q.pop();
            }
            idx++;
            ans.push_back(v);
        }
        return ans;
    }
};
