class Solution {
public:
    int reverse(int x) {
        long reverse = 0;

        for(int i=x; i!=0; i/=10){
            reverse = reverse*10 + i%10;

            if(reverse > INT_MAX || reverse < INT_MIN){
                return 0;
            }
        }

        return (int)reverse;
    }
};