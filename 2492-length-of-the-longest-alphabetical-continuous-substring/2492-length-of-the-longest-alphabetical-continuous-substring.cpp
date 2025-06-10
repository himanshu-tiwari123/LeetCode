class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int longest =1;
        for(int i=0;i<n-1;i++){
           int curr_length = 1;

            while(i<n-1 and (s[i]-'a')==((s[i+1]-'a')-1)){
              curr_length++;
              i++;
            }

           longest = max(longest,curr_length);
        }

        return longest;
    }
};