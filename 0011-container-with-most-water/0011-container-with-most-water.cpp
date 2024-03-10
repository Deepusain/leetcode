class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, i = 0, j = height.size()-1, res = 0;
        while (i < j) {
            if (height[i] <= height[j]) {
                res = height[i] * (j - i);
                i++;
            } else {
                res = height[j] * (j - i);
                j--;
            }
            if (res > area) area = res;
        }
        return area;
    }
};