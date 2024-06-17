// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         // Base case
//         if(c<0) return false;
        
//         // Two Pointers l = left and r =right
//         long int l =0;
//         long int r = sqrt(c);
            
//             while(l<=r){
//                 long int sum = l*l+r*r;
                
//                 if(sum == c) return true;
//                 else if(sum<c)l++;
//                 else r++;
//             }
//         return false;
//     }
// };
class Solution {
public:
    bool judgeSquareSum(int c) 
    {
    	if(c<0)
    		return false;
    	long int left=0,right=sqrt(c);
    	while(left<=right)
    	{
    		long int cur=left*left+right*right;
    		if(cur<c)
    			left++;
    		else if(cur>c)
    			right--;
    		else 
    			return true;
    	}    
    	return false;
    }
};