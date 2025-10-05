class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>v(numRows);

        if(numRows == 1 or numRows >= s.size()) return s;

        int index=  0,dir = 1;

        for(auto &c: s){
           v[index].push_back(c);

            if(index == 0){
               dir = 1;
            }else if(index == numRows-1){
                dir = -1; 
            }

            index += dir;
        }

        string ans = "";

        for(int i=0;i<numRows;i++){
            for(auto &c: v[i]){
                ans += c;
            }
        }

        return ans;
    }
};