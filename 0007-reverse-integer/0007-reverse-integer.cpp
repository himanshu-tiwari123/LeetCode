class Solution {
public:
    int reverse(int x) {
        bool isNegative = x < 0 ? true: false;
        int ans = 0;
        if(x == INT_MIN) return 0;
        x = abs(x);

        while(x){
            int digit = x%10;

            if(ans <= (INT_MAX)/10){
               ans *= 10;
            }else{
                return 0;
            }
            
            ans += digit;
            
            
            x/=10;
        }


        if(isNegative){
            return -1*ans;
        }

        return ans;
    }
};