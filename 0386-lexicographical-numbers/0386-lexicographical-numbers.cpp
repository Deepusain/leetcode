class Solution {
public:
    void helper(int num , int n , vector<int>& result){
         if(num>n)return;
        result.push_back(num);
        for(int append=0;append<=9;append++){
            int newnum = (num*10)+append;
            if(newnum>n)return;
            helper(newnum,n,result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int num=1;num<=9;num++){
            helper(num,n,result);
        }
        return result;
    }
};