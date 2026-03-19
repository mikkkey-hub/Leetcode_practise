class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0) return 0;

        
        int i =0,sign =1;
        while(s[i] ==' ')
        {
            i++;
        }
            if (s[i] == '+' || s[i] == '-') 
            {
                sign =s[i] =='-'? -1:1;
                i++;
            }
            
        
        long long n = 0;
        while (isdigit(s[i])) {
        {
          int digit = s[i] -'0';
            if (n > (INT_MAX - digit) / 10) //n * 10 + digit > INT_MAX 如果写成直接这样可能就溢出(n已经等于INT_max)
            {
                return sign == 1 ? INT_MAX : INT_MIN;//增加一个条件判断溢出
            }
          n = n * 10 + digit; //合成为一个整数
          i++;
        }
        }
        n = n * sign;
        if (n > INT_MAX) return INT_MAX;
        if (n < INT_MIN) return INT_MIN;
        return n;
        



    }
};