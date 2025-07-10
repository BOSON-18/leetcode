class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

int n=startTime.size();

        vector<int> freeArray;
        freeArray.push_back(startTime[0]);

        for(int i=1;i<n;i++){
            freeArray.push_back(startTime[i]-endTime[i-1]);
        }

        freeArray.push_back(eventTime-endTime[n-1]);

        int m=freeArray.size();

        vector<int> maxRight(m,0),maxLeft(m,0);

        for(int i=m-2;i>=0;i--){
            maxRight[i]=max(maxRight[i+1],freeArray[i+1]);
        }

        for(int i=1;i<m;i++){
            maxLeft[i]=max(maxLeft[i-1],freeArray[i-1]);
        }

        int result=0;

        for(int i=1;i<m;i++){
            int currEvent = endTime[i-1]-startTime[i-1];
    //case 1 moving out
            if(currEvent <=max(maxLeft[i-1],maxRight[i])){
                result = max(result,freeArray[i-1]+currEvent+freeArray[i]);
            }

            //case 2 shift in adjacent
            result = max(result,freeArray[i-1]+freeArray[i]);
        }

    return result;
        
    }
};