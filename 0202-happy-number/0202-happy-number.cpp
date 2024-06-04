class Solution {
public:
    int solve(int n){
        int sum = 0;

        while(n){
            int digit = n%10;
            sum += (digit*digit);
            n/=10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = solve(slow);
            fast = solve(solve(fast));
        }while(slow != fast);

        return (slow == 1);
    }
};