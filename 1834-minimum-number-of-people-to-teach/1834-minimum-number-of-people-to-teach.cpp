class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {

        unordered_set<int>badPairs;

        // step 1: First find the no of bad pairs of friends:
        for(auto &it: friendships){
            int u=it[0],v=it[1];
            u--;v--;
            unordered_set<int>st;

            for(auto &it: languages[u]){
                st.insert(it);
            }

            bool isCommon = false;

            for(auto &it: languages[v]){
                if(st.find(it)!=st.end()){
                    isCommon = true;
                    break;
                }
            }

            if(!isCommon){
                badPairs.insert(u);
                badPairs.insert(v);
            }


        }
        // step 2: Next find the most widely spoken language,cause we aim to teach the bad pairs the most widely spoken language

        unordered_map<int,int>mp;

        for(auto &it: badPairs){
            int val = it;

            for(auto &it: languages[val]){
                mp[it]++;
            }
        }
        int widely_spoken_language = 0;

        for(auto &it: mp){
            widely_spoken_language = max(widely_spoken_language,it.second);
        }
        //step 3:Our answer will be then the no of bad pairs - max spoken language.

        return badPairs.size()-widely_spoken_language;
        // In this way we have minimized the no of users that we need to teach



       
        
    }
};