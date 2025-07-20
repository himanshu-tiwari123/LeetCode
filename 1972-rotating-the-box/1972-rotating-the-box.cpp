class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();

        for(int i=0;i<n;i++){
            int l=m-1,r=m-1;
            while(l>=0 and r>=0){
                if(boxGrid[i][l]=='#'){
                    boxGrid[i][r] = '#';
                    if(l!=r){
                        boxGrid[i][l]='.';
                    }
                    
                    r--;
                }else if(boxGrid[i][l] == '*'){
                    r = l-1;
                }
                l--;
            }
        }

       
        //Now how to rotate by 90 deree:
        vector<vector<char>>rotatedBox(m,vector<char>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               rotatedBox[i][j] = boxGrid[n-1-j][i];
            }
        }

        return rotatedBox;
        
    }
};