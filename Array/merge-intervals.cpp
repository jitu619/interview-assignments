class Solution {
public:
    static bool cmp (vector<int> &a,vector<int> &b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n=intervals.size();
        vector<vector<int>> v;
        int x=intervals[0][0],y=intervals[0][1];
        for(int i=0;i<n;i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            // cout<<intervals[i][0]<<" "<<intervals[i][1]<<"\n";
            
            if(x==a){
                if(y<b){
                    y=b;
                }
            }else if(y>=a){
                y=max(b,y);
            }else{
                v.push_back({x,y});
                x=a;
                y=b;
            }
            
            
            
        }
        v.push_back({x,y});
        return v;
    }
};
