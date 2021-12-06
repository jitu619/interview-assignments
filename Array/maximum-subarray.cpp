class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx_so_far=INT_MIN,curr=0;
        for(auto i:nums){
            curr+=i;
            mx_so_far=max(curr,mx_so_far);
            if(curr<0){
                curr=0;
            }
        }
        return mx_so_far;
    }
};
