class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i:nums){
            if(mp.find(i)!=mp.end()){
               mp[i]=mp[i]+1; 
            }else mp[i]=1;   
        }
        vector<pair<int,int>> vmp(mp.begin(),mp.end());
        sort(vmp.begin(),vmp.end(),cmp);
        for(auto i:vmp){
            if(v.size()<k){
                v.push_back(i.first);
            }
        }
        return v;
    }
};
