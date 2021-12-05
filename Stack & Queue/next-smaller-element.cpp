vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> v(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            v[i]=-1;
            st.push(arr[i]);
        }else{
            v[i]=st.top();
            st.push(arr[i]);
        }
        
    }
    return v;
}
