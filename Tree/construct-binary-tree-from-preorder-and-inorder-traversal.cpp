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
    TreeNode* buildTreeHelper(TreeNode* curr,vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return NULL;
        
        curr=new TreeNode(preorder[0]);
        if(preorder.size()==1){
            curr->left=NULL;
            curr->right=NULL;
            return curr;
        }
        int idx=find(inorder.begin(),inorder.end(),preorder[0])-inorder.begin();
        vector<int> inleft=vector(inorder.begin(),inorder.begin()+idx);
        vector<int> inright=vector(inorder.begin()+idx+1,inorder.end());
       
        // cout<<idx<<" "<<inleft.size()<<" "<<inright.size();
        vector<int> preleft=vector(preorder.begin()+1,preorder.begin()+inleft.size()+1);
        vector<int> preright=vector(preorder.begin()+inleft.size()+1,preorder.end());
        
        // cout<<"\n"<<preleft.size()<<" "<<preright.size()<<"\n";
        // for(int i:preleft) cout<<i<<" ";
        // cout<<"\n";
        // for(int i:preright) cout<<i<<" ";
        // cout<<"\n";
        // for(int i:inleft) cout<<i<<" ";
        // cout<<"\n";
        // for(int i:inright) cout<<i<<" ";
        curr->left=buildTreeHelper(curr->left,preleft,inleft);
        curr->right=buildTreeHelper(curr->right,preright,inright);
        
        return curr;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=NULL;
        return buildTreeHelper(root,preorder,inorder);
    }
};
