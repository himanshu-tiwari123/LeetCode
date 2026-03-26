class Solution {
public:
    int minOperations(int n) {
        int cnt = 0;
        while(n){
            if((n&1)){
                //the value of n is odd:
                if((n&3) == 3){
                    //last 2 bits are 11, so we add 1 ,to make them 0;
                    n +=1;
                }else{
                    //last 2 bits are 01, so we subtract 1 to make them 0:
                    n -= 1;
                }
                cnt++;
            }else{
                //its even , so we just right shift man:
                n >>= 1;
            }
        }
        

        return cnt;


    }
};