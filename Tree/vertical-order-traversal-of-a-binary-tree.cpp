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
    vector<pair<pair<int,int>,int>> ans;
    static bool cmp(pair<pair<int,int>,int> &a ,pair<pair<int,int>,int> &b){
        if(a.first.first==b.first.first){
            if(a.first.second==b.first.second){
                return a.second<b.second;
            }
            return a.first.second<b.first.second;
        }
        
        return a.first.first<b.first.first;
        
    }
    
    void solve(TreeNode* root,int x,int y){
        if(!root) return;
        ans.push_back({{x,y},root->val});
        solve(root->left,x-1,y+1);
        solve(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>> v;
        sort(ans.begin(),ans.end(),cmp);
        int startidx=ans[0].first.first;
        vector<int> temp;
        for(auto p:ans){
            // cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<"\n";
            if(startidx==p.first.first){
                temp.push_back(p.second);
            }else{
                v.push_back(temp);
                temp.clear();
                startidx=p.first.first;
                temp.push_back(p.second);
            }
        }
        if(!temp.empty()) v.push_back(temp);
        return v;
    }
};
