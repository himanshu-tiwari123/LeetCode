class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;

        map<string,vector<string>>mp;

        for(int i=0;i<strs.size();i++){
            string temp = strs[i];

            vector<int>freq(26,0);

            for(int i=0;i<temp.size();i++){
                freq[temp[i]-'a']++;
            }
            string curr = "";
            for(int i=0;i<26;i++){
                while(freq[i]>0){
                    curr += (i+'a');
                    freq[i]--;
                }
            }

            mp[curr].push_back(strs[i]);
        }

        for(auto &it: mp){
            ans.push_back(it.second);
        }


        return ans;

        
    }
};