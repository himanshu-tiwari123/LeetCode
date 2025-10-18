class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int ones_cnt = 0,flips = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones_cnt++;
            }else{
                flips = min(flips+1,ones_cnt);
            }
        }

        return flips;
    }
};