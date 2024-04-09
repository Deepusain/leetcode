/*class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int x =   tickets[k];
        int count =  tickets[k];
        for(int i=0;i<k ; i++){
            if(tickets[i]<x){
                count+=tickets[i];
            } else if(tickets[i]>=x){
                count += x;
            }
        }
        for(int i=k+1;i<tickets.size(); i++){
            if(tickets[i]<x){
                count+=tickets[i];
            } else if(tickets[i]>=x){
                count += x-1;
            }
        }
        return count;
    }
};*/
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;

        // If person k only needs one ticket, return the time to buy it
        if (tickets[k] == 1)
            return k + 1;

        // Continue buying tickets until person k buys all their tickets
        while (tickets[k] > 0) {
            for (int i = 0; i < n; i++) {
                // Buy a ticket at index 'i' if available
                if (tickets[i] != 0) {
                    tickets[i]--;
                    time++;
                }

                // If person k bought all their rickets, return the time
                if (tickets[k] == 0)
                    return time;
            }
        }

        return time;
    }
};