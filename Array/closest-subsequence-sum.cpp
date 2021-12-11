class Solution {
public:
    
    vector<int> powerset(vector<int> &nums,int start,int end){
        vector<int> v;
        int n=end-start+1;
        for(int msk=0;msk<(1<<n);msk++){
            int ans=0;
            for(int i=0;i<n;i++){
                if(msk&(1<<i)){
                    ans+=nums[start+i];
                }
            }
            v.push_back(ans);
        }
        return v;
    }
    
    int lowerBound(vector<int> &nums,int target){
        int low=0,high=nums.size()-1;
        int ans=0;
        bool flag=false;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                low=mid+1;
            }else{
                ans=mid;
                flag=true;
                high=mid-1;
            }
        }
        return flag?ans:nums.size();
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> firstHalf=powerset(nums,0,n/2);
        vector<int> secondHalf=powerset(nums,n/2+1,n-1);
      
        int answer=INT_MAX;
        sort(secondHalf.begin(),secondHalf.end());
        for(int i=0;i<firstHalf.size();i++){
            int target=goal-firstHalf[i];
            int lbIdx=lowerBound(secondHalf,target);
            // Comparing both j-1 and jth index to find out minium difference.
            if(lbIdx>0){
                answer=min(answer,abs(target-secondHalf[lbIdx-1]));
            }
            if(lbIdx<secondHalf.size()){
                answer=min(answer,abs(target-secondHalf[lbIdx]));
            }
        }
        return answer;
    }
};
