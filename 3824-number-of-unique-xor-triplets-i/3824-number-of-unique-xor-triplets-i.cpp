class Solution {
    using ll = long long;
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1 or n==2){
            return n;
        }
        vector<int>powers;
        for(int i=0;i<=25;i++){
            powers.push_back(pow(2,i));
        }

        auto ub = upper_bound(powers.begin(),powers.end(),n);

        return *ub;

    }
};