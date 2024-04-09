class Solution {
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
};