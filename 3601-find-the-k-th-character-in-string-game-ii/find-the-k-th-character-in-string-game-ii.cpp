class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        if (k == 1)
            return 'a';
        long long len = 1;
        int n = operations.size();
        long long newK = -1;
        int operationType = -1;
        for (int i = 0; i < n; i++) {
            len *= 2;

            if(len>=k){
                operationType = operations[i];
                newK = k-len/2;
                break;
            }
        }

        char ch=kthCharacter(newK,operations);

        if(operationType == 0){
            return ch;
        }

        return ch=='z'?'a':ch+1;
    }
};