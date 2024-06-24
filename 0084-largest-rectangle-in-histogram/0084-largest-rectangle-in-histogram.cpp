class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n, n);
        vector<int> prev(n, -1);

        stack<int> st;
        st.push(n-1);

        for(int i=n-2; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(!st.empty()){
                next[i] = st.top();
            }

            st.push(i);
        }

        st = stack<int>();

        st.push(0);

        for(int i=1; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(!st.empty()){
                prev[i] = st.top();
            }

            st.push(i);
        }

        int max_area = INT_MIN;

        for(int i=0; i<n; i++){
            max_area = max(max_area, (next[i]-prev[i]-1)*heights[i]);
        }

        return max_area;
    }
};