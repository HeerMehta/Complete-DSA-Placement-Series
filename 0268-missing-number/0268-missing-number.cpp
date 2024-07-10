class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
       
        int ans = 0;

        //0, 1, 2, 3  ---> All numbers from 0 to n
        for(int i=0; i<=n; i++){
            ans = ans^i;
        }
        
        //0, 1, 3, --> Available in array 
        for(int i=0; i<n; i++){
            ans = ans^nums[i];
        }

        return ans;
    }
};