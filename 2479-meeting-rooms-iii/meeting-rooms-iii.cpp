class Solution {
public:
typedef pair<long long,int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {

        int m=meetings.size();
        sort(begin(meetings),end(meetings));

        vector<int> roomCount(n,0);

        priority_queue<P,vector<P>,greater<P>> usedRoom;
        priority_queue<int,vector<int>,greater<int>> unusedRoom;

        for(int room=0;room<n;room++){
            unusedRoom.push(room);
        }

        for(vector<int>& meet:meetings){
            int start=meet[0],end=meet[1];


            while(!usedRoom.empty() && usedRoom.top().first<=start){
                int room = usedRoom.top().second;
                usedRoom.pop();
                unusedRoom.push(room);
            }

            if(!unusedRoom.empty()){
                int room = unusedRoom.top();
                unusedRoom.pop();
                usedRoom.push({end,room});
                roomCount[room]++;

            }else{
                int room=usedRoom.top().second;
                long long endTime = usedRoom.top().first;
                usedRoom.pop();
                usedRoom.push({endTime+(end-start),room});
                roomCount[room]++;
            }
        }

        int result=-1,maxuse=0;

        for(int room=0;room<n;room++){
            if(roomCount[room]>maxuse){
                maxuse = roomCount[room];
                result=room;
            }
        }
        return result;
    }
};