
class Router {
private:
    int memoryLimit;
    deque<array<int, 3>> q; 
    unordered_set<string> packetSet; 
    unordered_map<int, vector<int>> destToTimestamps; 

    
    string makeKey(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (packetSet.count(key)) return false; 

        
        if ((int)q.size() == memoryLimit) {
            auto old = q.front();
            q.pop_front();
            string oldKey = makeKey(old[0], old[1], old[2]);
            packetSet.erase(oldKey);

            
            auto &vec = destToTimestamps[old[1]];
            vec.erase(lower_bound(vec.begin(), vec.end(), old[2]));
        }

       
        q.push_back({source, destination, timestamp});
        packetSet.insert(key);
        destToTimestamps[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) return {};

        auto pkt = q.front();
        q.pop_front();

        string key = makeKey(pkt[0], pkt[1], pkt[2]);
        packetSet.erase(key);

        
        auto &vec = destToTimestamps[pkt[1]];
        vec.erase(lower_bound(vec.begin(), vec.end(), pkt[2]));

        return {pkt[0], pkt[1], pkt[2]};
    }

    int getCount(int destination, int startTime, int endTime) {
        if (!destToTimestamps.count(destination)) return 0;
        auto &vec = destToTimestamps[destination];
        auto l = lower_bound(vec.begin(), vec.end(), startTime);
        auto r = upper_bound(vec.begin(), vec.end(), endTime);
        return r - l;
    }
};