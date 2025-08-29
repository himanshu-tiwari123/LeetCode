#define ll long long

class Solution {
  
public:

    long long flowerGame(int n, int m) {
        ll ans = 0;

        ll odd = (m+1)/2,even = m-odd;

        for(int i=1;i<=n;i++){
            if(i&1){
                ans += (even);
            }else{
                ans += (odd);
            }
        }

        return ans;
    }
};