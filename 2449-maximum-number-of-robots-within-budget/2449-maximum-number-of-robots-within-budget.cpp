class Solution {
    using ll = long long;
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        ll l=0,r=0;

        multiset<ll>st;

        ll max_robots = 0,running_cost = 0,curr_cost=0;

        while(r<n){

           st.insert(chargeTimes[r]);
           running_cost += runningCosts[r];
           curr_cost = (*st.rbegin()) + (r-l+1)*running_cost;

            while(l<=r and curr_cost > budget){
                running_cost -= runningCosts[l];

                st.erase(st.find(chargeTimes[l]));

                if(!st.empty()){
                    curr_cost = (*st.rbegin()) + (r-l+1)*running_cost;
                }

                l++;

            }
            

            max_robots = max(max_robots,r-l+1);

            r++;
            
        }

        return max_robots;
        
   }
};