class Solution {
public:
    bool isMatch(string s, string p) {
        
    
    int m = s.size(); int   n = p.size();

    vector<vector<bool>>dp(m+1 ,vector<bool>(n +1,false)); //dp(i,j)中的元素值表示s[1-i]和p [1-j]中元素得匹配情况,默认全为false,表示完全没有成功字符

    dp[m][n] =true; //两个都为空串 m =n =0;return [0][0] 返回true

    //处理s走完,但p还有剩余的情况(剩下一些 a*,每次匹配零个,因此每次往前走两个字符)

    for(int j = n-2;j>=0;j-=2) //因为 s已经遍历完了,此时i 应该等于 m,j从 n-2开始才对,因为`一次`走两格
    {
        if(p[j+1] == '*') //必须为 *时才为true,p[j+1] 不是 * 就停止，因为后面没法匹配零个了
        {
            dp[m][j] = dp[m][j+2];
        }
    }


    for( int i = m-1;i>=0;i--)
    {
        for(int j = n-1 ;j>=0;j--)
        {
           bool success  = s[i] == p[j] || p[j] == '.';
           if(p[j+1] == '*' && j+1<p.size())
           {
                dp[i][j] = dp[i][j+2] || (success && dp[i+1][j]);
           }
           else
           {
            dp[i][j] =  success && dp[i+1][j+1];
           }
        }
    }
    
    return dp[0][0];
    }
};