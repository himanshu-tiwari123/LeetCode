class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0,r=0;

        if(n==0) return 0;

        int longest_length = 1;

        unordered_map<char,int>freq;

        while(r<n){
            freq[s[r]]++;

            while(freq[s[r]] > 1){
                freq[s[l]]--;
                l++;
            }

            longest_length = max(longest_length,r-l+1);

            r++;
        
        }



        return longest_length;
    }
};