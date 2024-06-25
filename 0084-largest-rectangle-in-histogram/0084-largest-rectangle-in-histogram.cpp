class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prev(n, -1);
        vector<int> next(n, n);

        stack<int> st;

        st.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) next[i] = st.top();

            st.push(i);
        }

        st = stack<int>();

        st.push(0);
        for(int i=1; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }

            if(!st.empty()) prev[i] = st.top();

            st.push(i);
        }

        int ans = 0;

        for(int i=0; i<n; i++){
            ans = max(ans, (next[i]-prev[i]-1)*heights[i]);
        }

        return ans;
    }
};