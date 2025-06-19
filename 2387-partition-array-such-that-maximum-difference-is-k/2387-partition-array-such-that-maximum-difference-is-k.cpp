class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n= nums.size();
        sort(nums.begin(),nums.end());

        int cnt = 0;

        for(int i=0;i<n;i++){
           int range = nums[i]+k;
        //    cout<<"->"<<i<<"\n";
        //    cout<<range<<"\n";
           bool kiyaKya = false;
           while(i<n){
              if(nums[i]<=range){
                kiyaKya = true;
                i++;
              }else{
                
                break;
              }
           }
        // cout<<"=>"<<i<<"\n";
           if(kiyaKya){
            cnt++;
            i--;
           }

          
        }

        return cnt;
    }
};