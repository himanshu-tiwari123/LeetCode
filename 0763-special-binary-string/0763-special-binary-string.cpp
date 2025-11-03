class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.empty()){
            return s;
        }

        vector<string>ans;

        int balance = 0;

        int i = 0;

        for(int j=0;j<s.size();j++){
            balance += (s[j] == '1' ? 1 : -1);

            if(balance == 0){
                string innerString = s.substr(i+1,j-i-1);
                string special = "1" + makeLargestSpecial(innerString) +"0";

                ans.push_back(special);

                i = j+1;

            }
        }

        sort(ans.rbegin(),ans.rend());

        string res="";

        for(auto &it: ans){
            res += it;
        }

        return res;
    }
};