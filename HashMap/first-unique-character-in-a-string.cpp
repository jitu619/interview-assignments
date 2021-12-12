class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]]=1000001;
            }else mp[s[i]]=i;
        }
        int idx=INT_MAX;
        for(auto i:mp){
            idx=min(idx,i.second);
        }
        return idx==1000001?-1:idx;
    }
};
