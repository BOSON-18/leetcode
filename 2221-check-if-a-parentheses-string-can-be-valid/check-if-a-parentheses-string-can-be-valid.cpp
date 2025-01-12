class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2!=0) return false;


        // O(1) space complexity
        int open=0,close=0;

        for(int i=0;i<n;i++){
            if(s[i]=='(' || locked[i]=='0') open++;
            else if(s[i]==')') open--;
            if(open<0) return false;
            if(s[n-1-i]==')' || locked[n-1-i]=='0') close++;
            else if(s[n-1-i]=='(') close--;
            if(close<0) return false;
        }

        return true;

    //O(N) space leli
        // stack<int> open,openClose;

        // for(int i=0;i<n;i++){
        //     if(locked[i]=='0'){
        //         openClose.push(i);
        //     }else if(s[i]=='('){
        //         open.push(i);
        //     }else if(s[i]==')'){
        //         if(!open.empty()) open.pop();
        //         else if(!openClose.empty()) openClose.pop();
        //         else return false;
        //     }
        // }

        // while(!open.empty() && !openClose.empty() && open.top()<openClose.top()){
        //     open.pop();
        //     openClose.pop();
        // }

        // return open.empty();
        
    }
};