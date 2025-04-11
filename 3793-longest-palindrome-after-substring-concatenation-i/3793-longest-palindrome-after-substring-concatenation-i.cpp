class Solution {
    bool isPalindrome(string &s){
        int l =0,r=s.size()-1;

        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }

            l++;r--;
        }

        return true;
    }
public:
    int longestPalindrome(string s, string t) {
        set<string>s1,t1;

        for(int i=0;i<s.size();i++){
            string str = "";
            str =s[i];
            s1.insert(str);
            for(int j=i+1;j<s.size();j++){
                str += s[j];
                s1.insert(str);
            }
        }

        for(int i=0;i<t.size();i++){
            string str ="";
            str = t[i];
            t1.insert(str);
            for(int j=i+1;j<t.size();j++){
                str += t[j];
                t1.insert(str);
            }
        }

        vector<string>v1;
        for(auto &it:s1){v1.push_back(it);}
        vector<string>v2 ;
        for(auto &it:t1){v2.push_back(it);}

        // for(auto &it:v1){
        //     cout<<it<<" ";
        // }cout<<"\n";

        // for(auto &it:v2){
        //     cout<<it<<" ";
        // }cout<<"\n";

        int max_len = 1;

        for(int i=0;i<v1.size();i++){
            string f = v1[i];
            if(isPalindrome(f)){
                max_len = max(max_len,(int)f.size());
            }

            for(int j=0;j<v2.size();j++){
                string s = v2[j];
                if(isPalindrome(s)){
                    max_len =  max(max_len,(int)s.size());
                }

                string t=f+s;
                // cout<<t<<" ";

                if(isPalindrome(t)){
                    max_len = max(max_len,(int)t.size());
                }
            }

        }

        return max_len;
    }
};