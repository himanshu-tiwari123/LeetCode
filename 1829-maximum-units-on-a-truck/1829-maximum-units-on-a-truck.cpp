class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        
        auto compare =[&](vector<int>&a,vector<int>&b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] > b[1];
        };

        sort(boxTypes.begin(),boxTypes.end(),compare);

        int max_units = 0;

        for(int i=0;i<n;i++){
            if(truckSize >= boxTypes[i][0]){
                truckSize -= boxTypes[i][0];
                max_units += (boxTypes[i][0] * boxTypes[i][1]);
            }else{
                
                max_units += (truckSize * boxTypes[i][1]);
                break;
            }
        }

        return max_units;

    }
};