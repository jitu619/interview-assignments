class Solution {
public:
    vector<string> ans;
    bool isvalid(string &s){
        stack<char> st;
        for(char i:s){
            if(i=='(')
                st.push('(');
            else{
                if(st.empty() || st.top()==')'){
                    return false;
                }else st.pop();
            }
        }
        return st.empty()?true:false;
    }
    
    void traverse(int n,string &str){
        if(n==str.size()){
            if(isvalid(str)){
                ans.push_back(str);
            }
            return;
        }
        str.push_back('(');
        traverse(n,str);
        str.pop_back();
        
        str.push_back(')');
        traverse(n,str);
        str.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        string s="";
        traverse(2*n,s);
        return ans;
    }
};
