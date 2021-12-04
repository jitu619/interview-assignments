class Solution {
public:
    int quickselect(vector<int>& nums,int low,int high){
        int pivot=nums[high];
        int i=low-1;
        int j=low;
        for(j=low;j<=high-1;j++){
            if(nums[j]<=pivot){
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[high]);
        return i+1;
    }
    
    int partition(vector<int>& nums,int low,int high,int k){
        int idx=quickselect(nums,low,high);
        // cout<<idx<<"\n";
        if(idx==nums.size()-k){
            return nums[idx];
        }
        else if(idx<nums.size()-k){
            return partition(nums,idx+1,high,k);
        }
        else{
            return partition(nums,low,idx-1,k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums,0,nums.size()-1,k);
    }
};
