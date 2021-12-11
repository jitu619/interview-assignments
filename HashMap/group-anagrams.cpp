class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> rr;
        string st;
        map<string,vector<string>> mp;
        for(string s:strs){
            st=s;
            sort(s.begin(),s.end());
            mp[s].push_back(st);
            
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            rr.push_back(it->second);
        }
        return rr;
    }
};
