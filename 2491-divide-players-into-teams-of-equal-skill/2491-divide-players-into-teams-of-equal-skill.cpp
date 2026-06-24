class Solution {
    using ll = long long;
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());

        ll ans = 0;

        int sum = skill[0] + skill[n-1];

        ans += (skill[0] * skill[n-1]);

        int l=1,r=n-2;

        while(l<r){
            int curr_sum = skill[l] + skill[r];

            if(curr_sum == sum){
                ans += skill[l] * skill[r];
            }else{
                return -1;
            }

            l++;
            r--;
        }


        return ans;
    }
};