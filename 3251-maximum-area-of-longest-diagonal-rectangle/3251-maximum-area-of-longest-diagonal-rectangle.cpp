class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_area = 0;

        int diagonal = 0;


        for(auto &it: dimensions){
            int a=it[0],b=it[1];

            int curr_diagonal = a*a + b*b;

            int area = a*b;

            if(curr_diagonal == diagonal){
                if(a*b > max_area){
                    max_area =a*b;
                }

            }else if(curr_diagonal > diagonal){
                diagonal = curr_diagonal;
                max_area = area;
            }
            
        }

       return max_area;
    }
};