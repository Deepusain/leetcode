class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[] = {0, 0}, n = students.size(), k;
        for (int a : students) count[a]++;
        for (k = 0; k < n && count[sandwiches[k]] > 0; ++k) count[sandwiches[k]]--;
        return n - k;
    }
};