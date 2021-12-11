class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            int target=-nums[i];
            int a=i+1,b=n-1;
            while(a<b){
                int sum=nums[a]+nums[b];
                if(sum==target){
                    // cout<<-target<<" "<<nums[a]<<" "<<nums[b]<<"\n";
                    v.push_back({-target,nums[a],nums[b]});
                    while(a<b && nums[a]==nums[a+1]) a++;
                    while(a<b && nums[b]==nums[b-1]) b--;
                    a++;
                    b--;
                }else if(sum>target){
                    b--;
                }else{
                    a++;
                }
                
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        
        return v;
    }
};
