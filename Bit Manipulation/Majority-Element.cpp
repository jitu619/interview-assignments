class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0,votes=0;
        for(int i:nums){
            if(votes==0){
                candidate=i;
            }
            if(candidate==i) votes++;
            else votes--;
        }
        return candidate;
    }
};
