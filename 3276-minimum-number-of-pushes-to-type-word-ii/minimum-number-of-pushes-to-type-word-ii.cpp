class Solution {
public:
    int minimumPushes(string word) {
        int n =word.size();
        vector<int> arr(26, 0);
        for(int i=0;i<n;i++){
            arr[word[i]-'a']++;
        }
        sort(arr.rbegin(),arr.rend());
        
        int res=0;
        for(int i=0;i<26;i++){
            if(arr[i]==0){
                break;
            }
            else if(i<8){
                res+=arr[i];
            }else if(i>7&&i<16){
                res+=2*arr[i];
            }else if(i>15 && i<24){
                res+=3*arr[i];
            }else{
                res+=4*arr[i];
            }
        }
        return res;
    }
};