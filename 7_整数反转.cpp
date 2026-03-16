class Solution {
public:
    int reverse(int x) {

        if (x == 0) return 0;

        bool isNegative = (x < 0);
        
        string s = to_string(x);
        if (isNegative) {
        std::reverse(s.begin() + 1, s.end());  // 跳过 '-'，只反转数字部分
        } 
        else {
        std::reverse(s.begin(), s.end());       // 直接反转
        }
        
        int start = isNegative? 1:0;
        while(s[start] =='0')
        {
            s.erase(s.begin()+start);
        }
        long long num = stoll(s);
            if (num > INT_MAX || num < INT_MIN) return 0;
            else return num;
    }
};