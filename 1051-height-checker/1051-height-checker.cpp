class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
    int count=0;
	
	// copying the vector and sorting in non-decreasing order
    vector<int>v=heights;
    sort(v.begin(), v.end());
	
	// searching where heights[i] != v[i]
    for(int i=0; i<n; i++){
        if(v[i]!=heights[i])
            count++;
    }
    return count;

    }
};