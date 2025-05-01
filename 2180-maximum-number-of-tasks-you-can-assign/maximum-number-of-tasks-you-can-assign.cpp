class Solution {
public:
bool check(vector<int>& tasks,vector<int>& workers,int pills,int strength,int mid){

    int pillsUsed=0;
    multiset<int> st(begin(workers),begin(workers)+mid);// best mid workers

    for(int i=mid-1;i>=0;i--){
        int required = tasks[i];
        auto it = prev(st.end());
        if(*it >= required){
            st.erase(it);
        }else if(pillsUsed>=pills) {return false;}
        else{
            //find the weakest worker which can do this strong task using pills
            auto weakestWorker = st.lower_bound(required-strength);
            if(weakestWorker == st.end()){
                return false;
            }

            st.erase(weakestWorker);
            pillsUsed++;
        }
    }
    return true;
}
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());

        int n=tasks.size(),m=workers.size();

        int l= 0;
        int r= min(m,n); // tasks 100 worker 2 take min
    int count=0;

    while(l<=r){
        int mid=l+(r-l)/2;

        if(check(tasks,workers,pills,strength,mid)){
            count=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

        return count;
    }
};