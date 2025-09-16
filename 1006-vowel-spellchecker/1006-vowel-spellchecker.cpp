class Solution {
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch == 'i' || ch=='o' || ch=='u');
    }

    string Lowercase(string &s){
        for(int i=0;i<s.size();i++){
            s[i]  = tolower(s[i]);
        }

        return s;
    }

    string wildCard(string &s){
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]='*';
            }
        }

        return s;
    }
public:

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,int>mp1;
        unordered_map<string,string>mp2,mp3;

        for(auto &it: wordlist){
            // cout<<it<<" ";
            mp1[it]++;
        }

        for(auto &it: wordlist){
            // cout<<"->"<<" "<<it<<"\n";
            string t = it;
            string s = Lowercase(t);

            if(mp2.find(s)==mp2.end()){
                mp2[s] = it;
            }

            // cout<<"mp2"<<" "<<s<<" "<<it<<"\n";

            string temp = wildCard(s);

            if(mp3.find(temp) == mp3.end()){
                mp3[temp ] = it;
            }
            // cout<<"mp3"<<" "<<temp<<" "<<it<<"\n";


        }
        
        vector<string>ans;

        for(auto &it: queries){

            string t = it;

            if(mp1.count(it)){
                ans.push_back(it);
                continue;
            }

            string s = Lowercase(t);

            if(mp2.count(s)){
                ans.push_back(mp2[s]);
                continue;
            }
            
            string temp = wildCard(s);

            if(mp3.count(temp)){
                ans.push_back(mp3[temp]);
                continue;
            }

            ans.push_back("");
            
           
        }

        return ans;
    }
};