class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int>prefix(n,0),suffix(n,0);
        //we use prefix to calculate the no of 1s and suffix to calculate the no of zeros:
        prefix[0] = (s[0]=='1' ? 1: 0);
        suffix[n-1] = (s[n-1] == '0' ? 1: 0);

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + (s[i] == '1' ? 1:0);
        }

        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1] + (s[i] == '0' ? 1: 0);
        }

        for(auto &it: prefix){
            cout<<it<<" ";
        }
        cout<<"\n";
        for(auto &it: suffix){
            cout<<it<<" ";
        }
        

        int min_flips = n;

        for(int i=0;i<n-1;i++){
            int curr_flips = prefix[i] + suffix[i+1];
            min_flips = min(min_flips,curr_flips);
        }

        min_flips = min(min_flips,prefix[n-1]);
        min_flips = min(min_flips,suffix[0]);

        return min_flips;
    }
};