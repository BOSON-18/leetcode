class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();

        int l = 0, h = n - 1;
        int maxi = 0;
        while (l < h) {
            maxi = max(maxi, ((h - l) * min(height[h], height[l])));
        // bada container for maximisign storage thats why going to right
            if (height[l] < height[h])
                l++;
                // Going left
            else
                h--;
        }
        return maxi;
    }
};