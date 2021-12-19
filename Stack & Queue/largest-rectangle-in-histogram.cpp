class Solution {
public:
    vector<int> NSR(vector<int> &arr){
        stack<int> s;
        vector<int> v;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                v.push_back(n);
                s.push(i);
            }
            else if(arr[s.top()]<arr[i]){
                v.push_back(s.top());
                s.push(i);
            }else{
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    v.push_back(n);
                }else v.push_back(s.top());
                s.push(i);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
    vector<int> NSL(vector<int> &arr){
        stack<int> s;
        vector<int> v;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(s.empty()){
                v.push_back(-1);
                s.push(i);
            }
            else if(arr[s.top()]<arr[i]){
                v.push_back(s.top());
                s.push(i);
            }else{
                while(!s.empty() && arr[s.top()]>=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    v.push_back(-1);
                }else v.push_back(s.top());
                s.push(i);
            }
        }
        return v;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right=NSR(heights);
        vector<int> left=NSL(heights);
        int mx=INT_MIN;
        for(int i=0;i<heights.size();i++){
            mx=max(mx,(right[i]-left[i]-1)*heights[i]);
        }
        return mx;
    }
};
