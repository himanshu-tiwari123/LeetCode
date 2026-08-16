class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for(auto &it: stones){
            if(it%3 == 0) cnt0++;
            if(it%3 == 1) cnt1++;

            if(it%3 ==2) cnt2++;
        }

        if(cnt0%2 == 0){
            //No one cant force other:
            if(cnt1 >=1 and cnt2 >= 1){
              return true;
            }

            return false;
        }

        return abs(cnt1-cnt2) >=3 ;


         
    }
};