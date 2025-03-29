class Solution {
    #define ll long long 
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(),m=mana.size();
        
        vector<ll>prevEndTime(n,0);

        for(int potion=0;potion<m;potion++){
            ll lastEndTime = 0;

            for(int wizard = 0;wizard<n;wizard++){
                ll startTime = max(lastEndTime,prevEndTime[wizard]);
                lastEndTime = startTime + (skill[wizard]*mana[potion]);
                prevEndTime[wizard] = lastEndTime;
            }
            // for(int i=0;i<n;i++){
            //     cout<<prevEndTime[i]<<" ";
            // }cout<<"\n";

            for(int i=n-1;i>=1;i--){
                prevEndTime[i-1] = prevEndTime[i]-(skill[i]*mana[potion]);
            }

            // for(int i=0;i<n;i++){
            //     cout<<prevEndTime[i]<<" ";
            // }cout<<"\n";
        }

        return prevEndTime[n-1];
    }
};