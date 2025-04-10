class Router {
    map<vector<int>,int>mp;//For duplicates:
    unordered_map<int,int>ump;//To keep count of removed packets;
    unordered_map<int,vector<int>>timeStamps;// for timestamps tracking
    queue<vector<int>>q;
public:
    int limit = 0;
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>packet = {source,destination,timestamp};

        if(mp.find(packet)!=mp.end()){return false;}

        if(q.size() == limit){
            vector<int>oldest = q.front();
            q.pop();
            mp.erase(oldest);
            ump[oldest[1]]++;
        }

        q.push(packet);
        mp[packet]++;
        timeStamps[packet[1]].push_back(packet[2]);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()){
            return {};
        }
        vector<int>packet = q.front();
        q.pop();
        mp.erase(packet);
        ump[packet[1]]++;

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(timeStamps.find(destination) == timeStamps.end()){
            return 0;
        }
        auto &p = timeStamps[destination];
        int forward = ump[destination];
        auto lb = lower_bound(p.begin()+forward,p.end(),startTime);

        auto ub = upper_bound(p.begin()+forward,p.end(),endTime);

        return (int)(ub-lb);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */