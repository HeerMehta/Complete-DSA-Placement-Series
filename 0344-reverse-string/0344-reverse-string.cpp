class Solution {
public:
    void reverseString(vector<char>& arr) {
        int n = arr.size();

        for(int i=0; i<n/2; i++){
            int j = n-i-1;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }
};