class Solution {
public:
    string longestPalindrome(string s) {
        
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;//初始的左右位置

        for(int center =0; center< s.length();center++)
        {
            int left = center; int right = center;
            while(left>=0 && right<s.length() && s[left]== s[right])
            {
                if(right-left +1 >maxLen)
                {
                    maxLen = right-left +1;
                    start =left; //修改新的左右端位置
                    
                }
                left--;
                right++;
            }
            left = center; right = center+1;
            while(left>=0 && right<s.length() && s[left]== s[right])
            {
                if(right-left +1 >maxLen)
                {
                    maxLen = right-left +1;
                    start =left; //修改新的左右端位置
                    
                }
                left--;
                right++;
            }
           
        }

         return s.substr(start, maxLen);

    }
};