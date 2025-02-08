class NumberContainers {
public:
    unordered_map<int,int> mpp;
 unordered_map<int,priority_queue<int,vector<int>,greater<int>>> pq;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       mpp[index]=number;

       pq[number].push(index);
    }
    
    int find(int number) {
        if(!pq.count(number)) return -1;

        auto& q=pq[number];

        while(!q.empty()){
            int idx=q.top();

            if(mpp[idx] == number) return idx;

            q.pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */