class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;

        queue<pair<string,int>>q;

        q.push({beginWord,1});
        
        st.insert(beginWord);
    
        unordered_set<string>list(wordList.begin(),wordList.end());

        if(list.find(endWord) == list.end()) return 0;

        while(!q.empty()){
            auto [str,level] = q.front();
            q.pop();

            if(str == endWord){
                return level;
            }

            for(int i=0;i<str.size();i++){
                string temp = str;
                for(char ch='a';ch<='z';ch++){
                    temp[i] = ch;

                    if(list.find(temp)!=list.end() and st.find(temp)==st.end()){
                        st.insert(temp);
                        q.push({temp,level+1});
                    }
                  
                }
            }
        }

        return 0;
    }
};