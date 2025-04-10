class Router {
    map<vector<int>,int> mp; // For duplicates
    unordered_map<int,int> ump; // Removed packets count
    unordered_map<int,vector<int>> timeStamps; // Timestamps
    queue<vector<int>> q; // Using queue instead of deque
public:
    int limit;
    
    Router(int memoryLimit) : limit(memoryLimit) {}
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};

        if(mp.count(packet)) return false;

        if(q.size() == limit) {
            vector<int> oldest = q.front();
            q.pop();
            mp.erase(oldest);
            ump[oldest[1]]++;
        }

        q.push(packet);
        mp[packet]++;
        timeStamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        vector<int> packet = q.front();
        q.pop();
        mp.erase(packet);
        ump[packet[1]]++;
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(!timeStamps.count(destination)) return 0;
        auto& p = timeStamps[destination];
        int forward = ump[destination];
        auto lb = lower_bound(p.begin()+forward, p.end(), startTime);
        auto ub = upper_bound(p.begin()+forward, p.end(), endTime);
        return ub - lb;
    }
};