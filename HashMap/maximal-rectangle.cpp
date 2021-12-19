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
    
    int largestRectangleArea1D(vector<int>& heights) {
        vector<int> right=NSR(heights);
        vector<int> left=NSL(heights);
        int mx=INT_MIN;
        for(int i=0;i<heights.size();i++){
            mx=max(mx,(right[i]-left[i]-1)*heights[i]);
        }
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        for(int i=0;i<matrix[0].size();i++){
            v.push_back(matrix[0][i]-'0');
        }
        int ans=largestRectangleArea1D(v);
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='0')
                    v[j]=0;
                else v[j]=v[j]+1;
            }
            ans=max(ans,largestRectangleArea1D(v));
        }
        return ans;
    }
};
