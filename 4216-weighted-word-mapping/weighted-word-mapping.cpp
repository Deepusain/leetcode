class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = ""; // Vector ki jagah simple string banayi
        char alphabet[] = {'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
        
        for(string word : words){
            int sum = 0;
            for(char c : word){
                sum += weights[c - 'a'];
            }
            // string mein character ko '+' se directly joda (append) ja sakta hai
            res += alphabet[sum % 26]; 
        }
        return res; // Ab return type 'string' se match karega
    }
};