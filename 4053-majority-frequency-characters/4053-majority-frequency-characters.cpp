class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int>freq(26,0);

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        map<int,string>mp;

        int group_size= 0;

        for(char ch='a' ; ch<='z';ch++){
            if(freq[ch-'a'] > 0){
              mp[freq[ch-'a']].push_back(ch);
            
            }
        }

        for(auto &it: mp){
            group_size = max(group_size,(int)it.second.size());
        }

        // cout<<group_size;

        int max_freq = 0;
        for(auto &it: mp){
           if(it.second.size() == group_size){
              max_freq = max(max_freq,it.first);
           }
        }

        string ans ="";

        for(auto &s: mp[max_freq]){
            ans += s;
        }


        return ans;
    }
};