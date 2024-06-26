class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        stack<char> st;
        st.push(num[0]);

        for(int i=1; i<n; i++){
            while(!st.empty() && (st.top()-'0') > (num[i]-'0') && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }


        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        n = st.size();

        string ans(n, '0');

        for(int i=n-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }

        int start = 0;
        while(start < n && ans[start] == '0') start++;

        ans = ans.substr(start);

        if(ans == "") ans = "0";

        return ans;
    }
};