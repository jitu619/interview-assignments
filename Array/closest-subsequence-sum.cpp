class Solution {
public:
    
    vector<int> powerset(vector<int> &nums,int start,int end){
        vector<int> v;
        int n=end-start+1;
        // cout<<start<<" "<<end<<"\n";
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
        while(low<=high){
            int mid=low+(high-low)/2;
            // cout<<low<<" "<<mid<<" "<<high<<" "<<target<<"\n";
            if(nums[mid]==target){
                return nums[mid];
            }
            if(nums[mid]<target){
                ans=nums[mid];
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
    
    int upperBound(vector<int> &nums,int target){
        int low=0,high=nums.size()-1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            // cout<<low<<" "<<mid<<" "<<high<<" "<<target<<"\n";
            if(nums[mid]==target){
                return nums[mid];
            }
            if(nums[mid]<target){
                low=mid+1;
            }else{
                ans=nums[mid];
                high=mid-1;
            }
        }
        return ans;
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> firstHalf=powerset(nums,0,n/2);
        vector<int> secondHalf=powerset(nums,n/2+1,n-1);
        // for(int i:firstHalf){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // for(int i:secondHalf){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        int answer=INT_MAX;
        sort(secondHalf.begin(),secondHalf.end());
        for(int i=0;i<firstHalf.size();i++){
            // cout<<"i: "<<i<<"\n";
            int target=goal-firstHalf[i];
            int lb=lowerBound(secondHalf,target);
            int ub=upperBound(secondHalf,target);
            answer=min(answer,min(abs(target-lb),abs(target-ub)));
        }
        return answer;
    }
};

// 5596358 5531914
