class Solution {
    using ll = long long;

public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size() , m =units[0].size();
        ll ans = 0;

        for(int i=0;i<n;i++){
            sort(units[i].begin() , units[i].end());
        }
 
        if(m==1){
           for(int i=0;i<n;i++){
            ans += units[i][0];

           }

           return ans;
        }

        int first_min = INT_MAX;

        for(int i=0;i<n;i++){
            first_min = min(first_min, units[i][0]);
        }

        int second_min = INT_MAX;

        int index = -1;

        for(int i=0;i<n;i++){
            if(units[i][1] < second_min){
                second_min = units[i][1];
                index = i;
            }
        }

        cout<<first_min<<" "<<second_min<<"\n";



        for(int i=0;i<n;i++){
            if(i!=index){
                ans += units[i][1];
            }else{
                ans += first_min;
            }
        }


        return ans;

        
    }
};