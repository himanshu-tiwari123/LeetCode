class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int m = logs.size();

        vector<int>res(n);

        stack<int>st;

        int prev_time = 0;

        for(int i=0;i<m;i++){
            string log = logs[i];

            stringstream ss(log);

            string part= "";

            //First lets get the function_name:
            getline(ss,part,':');
            int function_name = stoi(part);

            //Next lets get either the start/end:
            getline(ss, part,':');
            bool is_start = (part == "start");

            //Next lets get the timestamp:
            getline(ss,part,':');
            int time_stamp = stoi(part);

            if(is_start){
                //we can push:
                int prev_val = 0;
                if(!st.empty()){
                    prev_val = st.top();
                    res[prev_val] += time_stamp - prev_time;
                    
                }
                prev_time = time_stamp;
                st.push(function_name);
            }else{
                int prev_val = 0;
                if(!st.empty()){
                    prev_val = st.top();
                    res[prev_val] += time_stamp - prev_time + 1;
                    prev_time = time_stamp + 1;
                    st.pop();
                }


            }
        }


        return res;
    }
};