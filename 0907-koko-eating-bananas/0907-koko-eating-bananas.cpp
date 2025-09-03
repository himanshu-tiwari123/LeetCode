class Solution {
    #define ll long long
    bool isPossible(ll mid,vector<int>& piles,int h){
        int  n = piles.size();
        ll curr_possible = 0;

        for(int i=0;i<n;i++){
            ll curr_val = ((ll)ceil((double)piles[i]/mid));
            curr_possible += curr_val;
        }

        return curr_possible <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1,high = *max_element(piles.begin(),piles.end());
        ll ans = LLONG_MAX;

        while(low<=high){
           ll mid = low + (high-low)/2;

            if(isPossible(mid,piles,h)){
               ans = min(ans,mid);
               high = mid-1;
            }else{
                low = mid+1;
            }
        }

        return ans;
    }
};