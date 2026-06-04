class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int l=0,r=0;

        int ans = 0;

        unordered_map<char,int>mp;

        while(r<n){
            mp[s[r]]++;

            int max_freq = 0;

            for(auto &it: mp){
                max_freq = max(max_freq, it.second);
            }

            int replace = (r-l+1) - max_freq;

            if(replace > k){
                while(true){
                    
                    mp[s[l]]--;
                    if(mp[s[l]] == 0){
                        mp.erase(mp.find(s[l]));
                    }
                    l++;

                    int curr_freq = 0;

                    for(auto &it: mp){
                        curr_freq = max(curr_freq, it.second);
                    }

                    int replace = (r-l+1) - curr_freq;

                    if(replace <= k){
                        break;
                    }
                   
                   
                }
            }

            ans = max(ans, r-l+1);

            r++;

        }

        return ans;
    }
};