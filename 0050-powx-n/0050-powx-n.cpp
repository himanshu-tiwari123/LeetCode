class Solution {
    double binExp(double base,int exp){

        if(exp == 0){
            return 1;
        }
        double half = binExp(base,exp/2);

        double res = half*half;

        if(exp&1){
            res *= base;
        }

        return res;
    }
public:
    double myPow(double x, int n) {
        double ans = binExp(x,n);

        return n<0 ? 1.0/ans : ans;
    }
};