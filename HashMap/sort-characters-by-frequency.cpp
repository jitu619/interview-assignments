class Solution {
public:
    static bool cmp(pair<char,int> &a,pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp);
        string str;
        for(auto i:v){
            for(int j=0;j<i.second;j++){
                str.push_back(i.first);
            }
        }
        return str;
    }
};
