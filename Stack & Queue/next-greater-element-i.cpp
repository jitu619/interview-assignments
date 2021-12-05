class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size()-1;
        stack<int> st;
        map<int,int> mp;
        vector<int> v;
        for(int i=n;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]=-1;
                st.push(nums2[i]);
            }else{
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        for(int i=0;i<nums1.size();i++){
            v.push_back(mp[nums1[i]]);
        }
        return v;
    }
};
