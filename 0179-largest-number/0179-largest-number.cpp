bool compare(int a,int b)
{
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
class Solution {
public:
    string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        string ans = "";
        for(int i = 0;i<arr.size();i++)
        ans+=to_string(arr[i]);
        if(ans[0]=='0') return "0";
        return ans; 
    }
};
// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         vector<string>result;
//         for(int num : nums){
//             result.push_back(to_string(num));
//         }
//         sort(result.begin(),result.end(),[](string&s1,string&s2){
//             return s1+s2>=s2+s1;
//         });
//         if(result[0]=="0")return"0";
//         string ans;
//         for(string& s: result){
//             ans+=s;
//         }
//         return ans;
//     }
// };