#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // 1. बेस केस और बाउंड्री कंडीशंस को शामिल करें
        restrictions.push_back({1, 0}); // Building 1 की हाइट हमेशा 0 होती है
        restrictions.push_back({n, n - 1}); // Building n की मैक्सिमम पॉसिबल हाइट n-1 हो सकती है
        
        // 2. बिल्डिंग ID के आधार पर सॉर्ट करें
        sort(restrictions.begin(), restrictions.end());
        
        int m = restrictions.size();
        
        // 3. Left-to-Right Pass: बायीं तरफ की बिल्डिंग्स का असर दायीं तरफ पर देखें
        for (int i = 1; i < m; ++i) {
            int id1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            
            // दो बिल्डिंग्स के बीच की दूरी
            int dist = id2 - id1; 
            // करंट बिल्डिंग की हाइट पिछली बिल्डिंग की हाइट + दूरी से ज्यादा नहीं हो सकती
            restrictions[i][1] = min(h2, h1 + dist);
        }
        
        // 4. Right-to-Left Pass: दायीं तरफ की पाबंदियों का असर वापस बायीं तरफ पर देखें
        for (int i = m - 2; i >= 0; --i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i + 1][0], h2 = restrictions[i + 1][1];
            
            int dist = id2 - id1;
            // करंट बिल्डिंग की हाइट अगली बिल्डिंग की हाइट + दूरी से ज्यादा नहीं हो सकती
            restrictions[i][1] = min(h1, h2 + dist);
        }
        
        // 5. किन्हीं भी दो पाबंदियों के बीच की मैक्सिमम हाइट निकालें
        int max_ans = 0;
        for (int i = 1; i < m; ++i) {
            int id1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            
            int dist = id2 - id1;
            // दो पॉइंट्स के बीच सबसे ऊंची चोटी (Peak) की गणना
            int peak = (h1 + h2 + dist) / 2;
            max_ans = max(max_ans, peak);
        }
        
        return max_ans;
    }
};
