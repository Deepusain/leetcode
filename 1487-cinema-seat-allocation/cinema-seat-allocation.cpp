#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Yeh alag function hai jo sirf EK ROW ke liye check karega
    int checkSingleRow(const vector<int>& seats) {
        // Hum check karenge ki kya yeh teen positions block hui hain?
        bool left_blocked = false;  // 2,3,4,5
        bool right_blocked = false; // 6,7,8,9
        bool mid_blocked = false;   // 4,5,6,7
        
        for (int seat : seats) {
            if (seat == 2 || seat == 3) left_blocked = true;
            if (seat == 4 || seat == 5) { left_blocked = true; mid_blocked = true; }
            if (seat == 6 || seat == 7) { right_blocked = true; mid_blocked = true; }
            if (seat == 8 || seat == 9) right_blocked = true;
        }
        
        if (!left_blocked && !right_blocked) return 2; // Dono side khaali hain
        if (!left_blocked || !right_blocked || !mid_blocked) return 1; // Koi ek khaali hai
        return 0; // Kuch khaali nahi hai
    }

public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Step 1: Array ko sort kiya (Taaki same row aur uske seats ek saath aa jayein)
        sort(reservedSeats.begin(), reservedSeats.end());
        
        int max_families = 0;
        int i = 0;
        int m = reservedSeats.size();
        int processed_rows = 0;
        
        // Step 2: 2-Pointer/Loop se har ek row ka group alag karenge
        while (i < m) {
            int currentRow = reservedSeats[i][0];
            vector<int> current_row_seats;
            
            // Jab tak same row ke elements mil rahe hain, unhe ek list mein daalo
            while (i < m && reservedSeats[i][0] == currentRow) {
                current_row_seats.push_back(reservedSeats[i][1]);
                i++;
            }
            
            // Alag function ko call kiya is row ka ans nikalne ke liye
            max_families += checkSingleRow(current_row_seats);
            processed_rows++;
        }
        
        // Step 3: Jo rows bilkul khaali thin unka answer add karo
        int empty_rows = n - processed_rows;
        max_families += empty_rows * 2;
        
        return max_families;
    }
};
