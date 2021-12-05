class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0 && nums[i-1]>=nums[i]){
            i--;
        }
        reverse(nums.begin()+i,nums.end());
        for(int j=i;j<nums.size()&&j>0;j++){
            // cout<<i<<" "<<j<<"\n";
            if(nums[j]>nums[i-1]){
                swap(nums[j],nums[i-1]);
                break;
            }
        }
        
    }
};
