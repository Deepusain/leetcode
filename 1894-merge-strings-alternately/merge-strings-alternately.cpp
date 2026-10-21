class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word = "";
        int i = 0;
        int n = min(word1.size(), word2.size());
        while(i < n){
            word += word1[i];
            word += word2[i];
            i++;
        }
        while(i < word1.size()){
            word += word1[i];
            i++;
        }
        while(i < word2.size()){
            word += word2[i];
            i++;
        }
        return word;
    }
};
