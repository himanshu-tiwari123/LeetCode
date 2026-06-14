class Solution {
    using ll = long long;
public:
    bool checkGoodInteger(int n) {
        ll dig_sum = 0, sq_sum = 0;
        while(n){

            int dig = n%10;

            dig_sum += dig;

            sq_sum += (dig * dig);


            n/=10;
 
        }

        return sq_sum - dig_sum >= 50;
    }
};