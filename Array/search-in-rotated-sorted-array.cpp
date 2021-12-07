class Solution {
public:
  
//   Note: Comparing mid with low/high to discard the sorted array will give wrong answer instead of that compare mid with arr[0]/arr[n-1].
    int pivot(vector<int>& nums,int low,int high){
        // cout<<low<<" "<<high<<"\n";
        // Below condition is to check if the given array is rotated or not.
        if(nums[0]<nums[nums.size()-1])
            return 0;
        int mid=low+(high-low)/2;
        if(low<=high){
            int prev=(mid-1+nums.size())%nums.size();
            int next=(mid+1)%nums.size();
            if(nums[prev]>=nums[mid] && nums[mid]<=nums[next])
                return mid;
            else if(nums[0]<=nums[mid])
                return pivot(nums,mid+1,high);
            else return pivot(nums,low,mid-1);
        }
        return -1;
    }
    
    int bs(vector<int>& nums,int low,int high,int target){
        // cout<<low<<" "<<high<<"\n";
        int mid=low+(high-low)/2;
        if(low<=high){
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                return bs(nums,mid+1,high,target);
            else return bs(nums,low,mid-1,target);
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int minElementIndex=pivot(nums,0,nums.size()-1);
        // cout<<minElementIndex<<"\n";
        // cout<<bs(nums,0,minElementIndex-1,target)<<" ";
        // cout<<bs(nums,minElementIndex,nums.size()-1,target)<<"\n";
        return max(bs(nums,0,minElementIndex-1,target),bs(nums,minElementIndex,nums.size()-1,target));
        return 0;
    }
};
