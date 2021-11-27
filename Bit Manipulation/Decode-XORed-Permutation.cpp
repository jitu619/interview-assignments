class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size()+1;
        int xor_onetilln;
        vector<int> v;
        if(n%4==1){
            xor_onetilln=1;
        }else if(n%4==2){
            xor_onetilln=n+1;
        }else if(n%4==3){
            xor_onetilln=0;
        }else{
            xor_onetilln=n;
        }
        int ans=0;
        int x=0;
        for(int i=0;i<encoded.size();i++){
            x^=encoded[i];
            encoded[i]=x;
        }

        for(int i=0;i<encoded.size();i++){
            ans^=encoded[i];
        }
        ans^=xor_onetilln;
        v.push_back(ans);
        for(int i=0;i<encoded.size();i++){
            v.push_back(ans^encoded[i]);
        }
        
        
        return v;
    }
};
