class EventManager {
private:
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            if(a.first == b.first)
                return a.second > b.second;

            return a.first < b.first;
        }
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
    unordered_map<int,int> mp;
        
public:
    EventManager(vector<vector<int>>& events) {
        for(auto e:events){
            mp[e[0]] = e[1];
            pq.push({e[1],e[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority,eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto [priority,id] = pq.top();
            pq.pop();

            if(mp[id] == priority){
                mp.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
