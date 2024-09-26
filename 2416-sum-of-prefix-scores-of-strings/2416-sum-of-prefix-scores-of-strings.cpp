struct trieNode{
    int countp=0;
    trieNode* children[26];
};

class Solution {
public:
    trieNode* getTrieNode(){
        trieNode* newNode = new trieNode();
        for(int i=0;i<26;i++){
            newNode->children[i]=nullptr;
        }
        newNode->countp =0;
        return newNode;
    }
    void insert(string& word , trieNode* root){
        trieNode* crawl= root;
        for(char &ch : word){
            int idx = ch-'a';
            if(!crawl->children[idx]){
                crawl->children[idx]=getTrieNode();
            }
            crawl->children[idx]->countp += 1;
            crawl = crawl->children[idx];
        }
    }
    
    int getScore(string& word , trieNode* root){
        trieNode* crawl = root;
        int score =0;
        for(char &ch : word){
            int idx = ch-'a';
            score += crawl->children[idx]->countp;
            crawl = crawl->children[idx];
        }
        return score;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        trieNode* root=getTrieNode();
        for(string& word : words){
            insert(word,root);
        }
        vector<int>result(n);
        for(int i=0;i<n;i++){
            result[i]=getScore(words[i],root);
        }
        return result;
        
    }
};
// class Solution {
// public:
//     vector<int> sumPrefixScores(vector<string>& words) {
        
//         unordered_map<string , long long>mp;
        
//         for(auto i : words){
//             for(int j=1;j<=i.length();j++){
//                 mp[i.substr(0,j)]++;
//             }
//         }
        
//         vector<int> scores;
//         for(auto i: words){
//             int score= 0; 
//             for(int j=1;j<=i.length();j++){
//                 score += mp[i.substr(0,j)];
//             }
        
//             scores.push_back(score);
//         }
        
//         return scores; 
//     }
// };