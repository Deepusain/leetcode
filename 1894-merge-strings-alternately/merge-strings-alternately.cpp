// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         string word = "";
//         int i = 0;
//         int n = min(word1.size(), word2.size());
//         while(i < n){
//             word += word1[i];
//             word += word2[i];
//             i++;
//         }
//         while(i < word1.size()){
//             word += word1[i];
//             i++;
//         }
//         while(i < word2.size()){
//             word += word2[i];
//             i++;
//         }
//         return word;
//     }
// };

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word = "";
        int i = 0;
        int n = min(word1.size(), word2.size());
        
        // Dono ke characters alternately add kiye
        while(i < n){
            word.push_back(word1[i]);
            word.push_back(word2[i]);
            i++;
        }
        
        // Baaki bache characters ko bina loop chalaye ek baar mein append kar diya
        word += word1.substr(i);
        word += word2.substr(i);
        
        return word;
    }
};
