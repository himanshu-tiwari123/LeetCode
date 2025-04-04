class Solution {
    double binExp(double base,int exp){
        //Base Case:
        if(exp == 0){
            return 1;
        }

        double half = binExp(base,exp/2);
        double result = half*half;

        if(exp&1){
            result *= base;
        }

        return result;
    }
public:
    double myPow(double x, int n) {
        
        double result = binExp(x,n);

        return (n<0 ? 1.0/result : result);
    }
};