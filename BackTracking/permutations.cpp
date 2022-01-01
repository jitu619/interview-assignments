class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> ans;
    
    void recurse(vector<int> &nums,vector<int> &v){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=nums[i];
                v.push_back(nums[i]);
                recurse(nums,v);
                v.erase(find(v.begin(),v.end(),nums[i]));
                mp.erase(mp.find(nums[i]));
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        recurse(nums,v);
        return ans;
    }
};
