class Solution {
public:
    char shift(char& ch, int direction) {

        if (ch == 'a' && direction == 0)
            return 'z';
        if (ch == 'z' && direction == 1)
            return 'a';

        return direction == 1 ? ch + 1 : ch - 1;
    }
    void doStuff(int left, int right, int direction, string& s) {
        for (int i = left; i <= right; i++) {
            s[i] = shift(s[i], direction);
        }
    }

    void optimal(int left, int right, int direction, vector<int>& diff) {
        int n = diff.size();
        diff[left] += direction == 1 ? 1 : -1;

        if (right + 1 < n)
            diff[right] -= direction == 1 ? 1 : -1;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // Shift[i] -> shift[0]==startingIndex,shift[1]==endingIndex
        // shift[2]==1 move forward i.e right shift b->c c->d z->a
        // shift[1]==0 move backward i.e left shift b->a a->z z->y
        // LOWERCASE ONLY

        // Brutre FOrce
        int n = s.size();
        vector<int> diff(s.size(), 0);
        // First iterate through the shufts array
        for (auto it : shifts) {
            int left = it[0], right = it[1], direction = it[2];

            // doStuff(left, right, direction, s);
            // optimal(left,right,direction,diff);
            int x;
            if (direction == 1)
                x = 1;
            else
                x = -1;

            diff[left] += x;
            if (right + 1 < n)
                diff[right + 1] -= x;
        }

        // Cumulative SUm
        for (int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int shift = diff[i] % 26; //wrap around
         
            if (shift < 0) shift += 26; // Wrap Around

            // s[i] = (((s[i] - 'a') + shift) % 26) + 'a';

            int value = s[i]-'a';
            value+=shift;
            value%=26;
            value+='a';

            s[i]=value;
        }

        // for(int i=0;i<n;i++) cout<<diff[i]<<" ";
        return s;
    }
};