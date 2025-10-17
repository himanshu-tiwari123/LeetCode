class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0,r=0;
        unordered_map<char,int>mp;

        if(s.empty()) return 0;

        int max_len = 0;

        while(r<n){
            mp[s[r]]++;

            if(mp[s[r]] > 1){

                max_len = max(max_len,r-l);

                while(mp[s[r]] > 1){
                    mp[s[l]]--;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);

                    }

                    l++;
                }
              
            }

            r++;
          
        }
        max_len = max(max_len,r-l);
        return max_len;
    }
};