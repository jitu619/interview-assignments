class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> maxh;
        string str;
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(auto p:mp){
            maxh.push({p.second,p.first});
        }
        while(!maxh.empty()){
            for(int i=0;i<maxh.top().first;i++){
                str.push_back(maxh.top().second);
            }
            maxh.pop();
        }
        return str;
    }
};
