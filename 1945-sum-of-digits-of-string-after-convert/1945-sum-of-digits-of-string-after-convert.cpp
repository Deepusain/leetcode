class Solution {
public:
    int getLucky(string s, int k) {
        string number="";
        for(char i : s) number += to_string(i-'a'+1);

        while(k>0){
            int temp=0;
            for(char i : number) temp+=i-'0'; //sum the digit of the current number

            number = to_string(temp);  // Convert the sum back to a string
            k--;
        }
        return stoi(number);   // Return the final result as an integer
    }
};