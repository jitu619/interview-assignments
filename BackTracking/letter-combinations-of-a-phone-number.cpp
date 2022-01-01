class Solution {
public:
    vector<string> keys={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void recurse(string &digits,int idx,string &str){
        if(idx==digits.size()){
            ans.push_back(str);
            return;
        }
        
        for(char ch:keys[digits[idx]-'0']){
            str.push_back(ch);
            recurse(digits,idx+1,str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string str="";
        if(digits.size()==0) return {};
        recurse(digits,0,str);
        return ans;
    }
};
