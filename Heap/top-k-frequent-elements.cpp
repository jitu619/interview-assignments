class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> maxh;
        unordered_map<int,int> mp;
        vector<int> v;
        for(int i:nums){
            mp[i]++;
        }
        
        for(auto p:mp){
            maxh.push({p.second,p.first});
            while(maxh.size()>k){
                maxh.pop();
            }
        }
        while(!maxh.empty()){
            v.push_back(maxh.top().second);
            maxh.pop();
        }
        return v;
    }
};
