class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int freq[26]={0};
        int sub[26]={0};
        int l=0,r=-1;
        bool flag;
        vector<int> v;
        for(char ch:p) freq[ch-'a']++;
        for(int i=0;i<s.size();i++){
            flag=true;
            sub[s[i]-'a']++;
            r++;
            if(r-l+1>p.size()){
                sub[s[l]-'a']--;
                l++;
            }
            for(int j=0;j<26;j++){
                if(freq[j]!=sub[j]){
                    // cout<<l<<" "<<r<<"\n";
                    flag=false;
                    break;
                }
            }
            if(flag){
                v.push_back(l);
            }
        }
        return v;
    }
};
